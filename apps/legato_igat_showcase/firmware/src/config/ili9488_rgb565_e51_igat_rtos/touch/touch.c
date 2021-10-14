/*******************************************************************************
  Touch Library v3.10.1 Release

  Company:
    Microchip Technology Inc.

  File Name:
    touch.c

  Summary:
    QTouch Modular Library

  Description:
    Provides Initialization, Processing and ISR handler of touch library,
    Simple API functions to get/set the key touch parameters from/to the
    touch library data structures
*******************************************************************************/

/*******************************************************************************
Copyright (c)  2021 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS  WITHOUT  WARRANTY  OF  ANY  KIND,
EITHER EXPRESS  OR  IMPLIED,  INCLUDING  WITHOUT  LIMITATION,  ANY  WARRANTY  OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A  PARTICULAR  PURPOSE.
IN NO EVENT SHALL MICROCHIP OR  ITS  LICENSORS  BE  LIABLE  OR  OBLIGATED  UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,  BREACH  OF  WARRANTY,  OR
OTHER LEGAL  EQUITABLE  THEORY  ANY  DIRECT  OR  INDIRECT  DAMAGES  OR  EXPENSES
INCLUDING BUT NOT LIMITED TO ANY  INCIDENTAL,  SPECIAL,  INDIRECT,  PUNITIVE  OR
CONSEQUENTIAL DAMAGES, LOST  PROFITS  OR  LOST  DATA,  COST  OF  PROCUREMENT  OF
SUBSTITUTE  GOODS,  TECHNOLOGY,  SERVICES,  OR  ANY  CLAIMS  BY  THIRD   PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE  THEREOF),  OR  OTHER  SIMILAR  COSTS.
*******************************************************************************/


/*----------------------------------------------------------------------------
 *     include files
 *----------------------------------------------------------------------------*/
#include "touch/touch.h"
#include "definitions.h" 
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
#include "motion-gestures/mg_touch_processing.h"
//END OF CUSTOM CODE
/*----------------------------------------------------------------------------
 *   prototypes
 *----------------------------------------------------------------------------*/

/*! \brief configure keys, wheels and sliders.
 */
static touch_ret_t touch_sensors_config(void);

/*! \brief Touch measure complete callback function example prototype.
 */
static void qtm_measure_complete_callback(void);

/*! \brief Touch Error callback function prototype.
 */
static void qtm_error_callback(uint8_t error);

//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
#if (DEF_TOUCH_LOWPOWER_ENABLE == 1u)
void touch_enable_lowpower_measurement(void);
void touch_disable_lowpower_measurement(void);
void touch_enable_nonlp_sensors(void);
void touch_disable_nonlp_sensors(void);
#endif
//END OF CUSTOM CODE

/*----------------------------------------------------------------------------
 *     Global Variables
 *----------------------------------------------------------------------------*/
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
#if DEF_TOUCH_LOWPOWER_ENABLE == 1u
uint16_t current_lp_sensor = 12u;
uint16_t time_drift_wakeup_counter;
uint8_t measurement_in_progress = 0;
#endif
//END OF CUSTOM CODE

/* Flag to indicate time for touch measurement */
volatile uint8_t time_to_measure_touch_var = 0;
/* post-process request flag */
volatile uint8_t touch_postprocess_request = 0;

/* Measurement Done Touch Flag  */
volatile uint8_t measurement_done_touch = 0;

/* Error Handling */
uint8_t module_error_code = 0;

//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
/* Low-power measurement variables */
uint16_t measurement_period_store = DEF_TOUCH_MEASUREMENT_PERIOD_MS;
//END OF CUSTOM CODE


/* Acquisition module internal data - Size to largest acquisition set */
uint16_t touch_acq_signals_raw[DEF_NUM_CHANNELS];
/* Acquisition set 1 - General settings */
qtm_acq_node_group_config_t ptc_qtlib_acq_gen1
    = {DEF_NUM_CHANNELS, DEF_SENSOR_TYPE, DEF_PTC_CAL_AUTO_TUNE, DEF_SEL_FREQ_INIT, DEF_PTC_INTERRUPT_PRIORITY};

/* Node status, signal, calibration values */
qtm_acq_node_data_t ptc_qtlib_node_stat1[DEF_NUM_CHANNELS];

/* Node configurations */
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
qtm_acq_same51_node_config_t ptc_seq_node_cfg1[DEF_NUM_CHANNELS] = {NODE_0_PARAMS,NODE_1_PARAMS,NODE_2_PARAMS,NODE_3_PARAMS,NODE_4_PARAMS,NODE_5_PARAMS,NODE_6_PARAMS,NODE_7_PARAMS,NODE_8_PARAMS,NODE_9_PARAMS,NODE_10_PARAMS,NODE_11_PARAMS,NODE_12_PARAMS};
//END OF CUSTOM CODE
/* Container */
qtm_acquisition_control_t qtlib_acq_set1 = {&ptc_qtlib_acq_gen1, &ptc_seq_node_cfg1[0], &ptc_qtlib_node_stat1[0]};

/**********************************************************/
/*********** Frequency Hop Auto tune Module **********************/
/**********************************************************/

/* Buffer used with various noise filtering functions */
uint16_t noise_filter_buffer[DEF_NUM_CHANNELS * NUM_FREQ_STEPS];
uint8_t  freq_hop_delay_selection[NUM_FREQ_STEPS] = {DEF_MEDIAN_FILTER_FREQUENCIES};
uint8_t  freq_hop_autotune_counters[NUM_FREQ_STEPS];

/* Configuration */
qtm_freq_hop_autotune_config_t qtm_freq_hop_autotune_config1 = {DEF_NUM_CHANNELS,
                                                                NUM_FREQ_STEPS,
                                                                &ptc_qtlib_acq_gen1.freq_option_select,
                                                                &freq_hop_delay_selection[0],
                                                                DEF_FREQ_AUTOTUNE_ENABLE,
                                                                FREQ_AUTOTUNE_MAX_VARIANCE,
                                                                FREQ_AUTOTUNE_COUNT_IN};

/* Data */
qtm_freq_hop_autotune_data_t qtm_freq_hop_autotune_data1
    = {0, 0, &noise_filter_buffer[0], &ptc_qtlib_node_stat1[0], &freq_hop_autotune_counters[0]};

/* Container */
qtm_freq_hop_autotune_control_t qtm_freq_hop_autotune_control1
    = {&qtm_freq_hop_autotune_data1, &qtm_freq_hop_autotune_config1};

/**********************************************************/
/*********************** Keys Module **********************/
/**********************************************************/

/* Keys set 1 - General settings */
qtm_touch_key_group_config_t qtlib_key_grp_config_set1 = {DEF_NUM_SENSORS,
                                                          DEF_TOUCH_DET_INT,
                                                          DEF_MAX_ON_DURATION,
                                                          DEF_ANTI_TCH_DET_INT,
                                                          DEF_ANTI_TCH_RECAL_THRSHLD,
                                                          DEF_TCH_DRIFT_RATE,
                                                          DEF_ANTI_TCH_DRIFT_RATE,
                                                          DEF_DRIFT_HOLD_TIME,
                                                          DEF_REBURST_MODE};

qtm_touch_key_group_data_t qtlib_key_grp_data_set1;

/* Key data */
qtm_touch_key_data_t qtlib_key_data_set1[DEF_NUM_SENSORS];

/* Key Configurations */
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
qtm_touch_key_config_t qtlib_key_configs_set1[DEF_NUM_SENSORS] = { KEY_0_PARAMS, KEY_1_PARAMS, KEY_2_PARAMS, KEY_3_PARAMS, KEY_4_PARAMS, KEY_5_PARAMS, KEY_6_PARAMS, KEY_7_PARAMS, KEY_8_PARAMS, KEY_9_PARAMS, KEY_10_PARAMS, KEY_11_PARAMS, KEY_12_PARAMS}; 
//END OF CUSTOM CODE
/* Container */
qtm_touch_key_control_t qtlib_key_set1
    = {&qtlib_key_grp_data_set1, &qtlib_key_grp_config_set1, &qtlib_key_data_set1[0], &qtlib_key_configs_set1[0]};


/**********************************************************/
/***************** Surface 2t Module ********************/
/**********************************************************/

qtm_surface_cs_config_t qtm_surface_cs_config1 = {
    /* Config: */
    SURFACE_CS_START_KEY_H,
    SURFACE_CS_NUM_KEYS_H,
    SURFACE_CS_START_KEY_V,
    SURFACE_CS_NUM_KEYS_V,
    SURFACE_CS_RESOL_DB,
    SURFACE_CS_POS_HYST,
    SURFACE_CS_FILT_CFG,
    SURFACE_CS_MIN_CONTACT,
    &qtlib_key_data_set1[0]};

/* surface Configurations */
/* Surface Data */
qtm_surface_cs2t_data_t qtm_surface_cs_data1;

/* Contact Data */
qtm_surface_contact_data_t qtm_surface_contacts[2];

/* Container */
qtm_surface_cs2t_control_t qtm_surface_cs_control1
    = {&qtm_surface_cs_data1, &qtm_surface_contacts[0], &qtm_surface_cs_config1};

/**********************************************************/
/***************** Gesture Module ********************/
/**********************************************************/

/* Gesture Configurations */
qtm_gestures_2d_config_t qtm_gestures_2d_config = {&qtm_surface_contacts[0].h_position,
                                                   &qtm_surface_contacts[0].v_position,
                                                   &qtm_surface_contacts[0].qt_contact_status,
                                                   &qtm_surface_contacts[1].h_position,
                                                   &qtm_surface_contacts[1].v_position,
                                                   &qtm_surface_contacts[1].qt_contact_status,
                                                   SCR_RESOLUTION(SURFACE_CS_RESOL_DB),
                                                   TAP_RELEASE_TIMEOUT,
                                                   TAP_HOLD_TIMEOUT,
                                                   SWIPE_TIMEOUT,
                                                   HORIZONTAL_SWIPE_DISTANCE_THRESHOLD,
                                                   VERTICAL_SWIPE_DISTANCE_THRESHOLD,
                                                   0,
                                                   TAP_AREA,
                                                   SEQ_TAP_DIST_THRESHOLD,
                                                   EDGE_BOUNDARY,
                                                   WHEEL_POSTSCALER,
                                                   WHEEL_START_QUADRANT_COUNT,
                                                   WHEEL_REVERSE_QUADRANT_COUNT,

                                                   PINCH_ZOOM_THRESHOLD

};
qtm_gestures_2d_data_t qtm_gestures_2d_data;

qtm_gestures_2d_control_t qtm_gestures_2d_control1 = {&qtm_gestures_2d_data, &qtm_gestures_2d_config};

/*----------------------------------------------------------------------------
 *   function definitions
 *----------------------------------------------------------------------------*/


/*============================================================================
static touch_ret_t touch_sensors_config(void)
------------------------------------------------------------------------------
Purpose: Initialization of touch key sensors
Input  : none
Output : none
Notes  :
============================================================================*/
/* Touch sensors config - assign nodes to buttons / wheels / sliders / surfaces / water level / etc */
static touch_ret_t touch_sensors_config(void)
{
    uint16_t    sensor_nodes;
    touch_ret_t touch_ret = TOUCH_SUCCESS;

    /* Init acquisition module */
    qtm_ptc_init_acquisition_module(&qtlib_acq_set1);
    qtm_ptc_qtlib_assign_signal_memory(&touch_acq_signals_raw[0]);

    /* Initialize sensor nodes */
    for (sensor_nodes = 0u; sensor_nodes < DEF_NUM_CHANNELS; sensor_nodes++) {
        /* Enable each node for measurement and mark for calibration */
        qtm_enable_sensor_node(&qtlib_acq_set1, sensor_nodes);
        qtm_calibrate_sensor_node(&qtlib_acq_set1, sensor_nodes);
    }


    /* Enable sensor keys and assign nodes */
    for (sensor_nodes = 0u; sensor_nodes < DEF_NUM_SENSORS; sensor_nodes++) {
			qtm_init_sensor_key(&qtlib_key_set1, sensor_nodes, &ptc_qtlib_node_stat1[sensor_nodes]);
    }


	touch_ret |= qtm_init_surface_cs2t(&qtm_surface_cs_control1);
	touch_ret |= qtm_init_gestures_2d();

    return (touch_ret);
}

/*============================================================================
static void qtm_measure_complete_callback( void )
------------------------------------------------------------------------------
Purpose: Callback function called after the completion of
         measurement cycle. This function sets the post processing request
         flag to trigger the post processing.
Input  : none
Output : none
Notes  :
============================================================================*/
static void qtm_measure_complete_callback(void)
{
    touch_postprocess_request = 1u;
}

/*============================================================================
static void qtm_error_callback(uint8_t error)
------------------------------------------------------------------------------
Purpose: Callback function called after the completion of
         post processing. This function is called only when there is error.
Input  : error code
Output : decoded module error code
Notes  :
Derived Module_error_codes:
    Acquisition module error =1
    post processing module1 error = 2
    post processing module2 error = 3
    ... and so on

============================================================================*/
static void qtm_error_callback(uint8_t error)
{
	module_error_code = error + 1u;

}

/*============================================================================
void touch_init(void)
------------------------------------------------------------------------------
Purpose: Initialization of touch library. PTC, timer, and
         datastreamer modules are initialized in this function.
Input  : none
Output : none
Notes  :
============================================================================*/
void touch_init(void)
{
	touch_timer_config();
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
#if (DEF_TOUCH_LOWPOWER_ENABLE == 1u)
	touch_disable_lowpower_measurement();
#endif
//END OF CUSTOM CODE

	/* Configure touch sensors with Application specific settings */
	touch_sensors_config();

	
}

/*============================================================================
void touch_process(void)
------------------------------------------------------------------------------
Purpose: Main processing function of touch library. This function initiates the
         acquisition, calls post processing after the acquistion complete and
         sets the flag for next measurement based on the sensor status.
Input  : none
Output : none
Notes  :
============================================================================*/
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
volatile bool mg_enabled;
//END OF CUSTOM CODE

void touch_process(void)
{
    touch_ret_t touch_ret;
    
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
#if DEF_TOUCH_DRIFT_PERIOD_MS != 0u && DEF_TOUCH_LOWPOWER_ENABLE == 1u
	if ((time_drift_wakeup_counter >= DEF_TOUCH_DRIFT_PERIOD_MS) && (measurement_period_store != DEF_TOUCH_MEASUREMENT_PERIOD_MS)) {
		time_drift_wakeup_counter = 0u;
		touch_enable_nonlp_sensors();
	}
#endif
//END OF CUSTOM CODE

    /* check the time_to_measure_touch for Touch Acquisition */
    if (time_to_measure_touch_var == 1u) {        

        /* Do the acquisition */
         touch_ret = qtm_ptc_start_measurement_seq(&qtlib_acq_set1, qtm_measure_complete_callback);
         
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
         measurement_in_progress = 1;
//END OF CUSTOM CODE

        /* if the Acquistion request was successful then clear the request flag */
        if (TOUCH_SUCCESS == touch_ret) {
            /* Clear the Measure request flag */
			time_to_measure_touch_var = 0;            
        }
    }
    /* check the flag for node level post processing */
    if (touch_postprocess_request == 1u){
        /* Reset the flags for node_level_post_processing */
        touch_postprocess_request = 0u;
        /* Run Acquisition module level post processing*/
        touch_ret = qtm_acquisition_process();
        /* Check the return value */
        if (TOUCH_SUCCESS == touch_ret) {
            /* Returned with success: Start module level post processing */
            
            touch_ret = qtm_freq_hop_autotune(&qtm_freq_hop_autotune_control1);
            if (TOUCH_SUCCESS != touch_ret) {
                qtm_error_callback(1);
            }
            touch_ret = qtm_key_sensors_process(&qtlib_key_set1);
            if (TOUCH_SUCCESS != touch_ret) {
                qtm_error_callback(2);
            }
            touch_ret = qtm_surface_cs2t_process(&qtm_surface_cs_control1);
            if (TOUCH_SUCCESS != touch_ret) {
                qtm_error_callback(3);
            }
            touch_ret = qtm_gestures_2d_process(&qtm_gestures_2d_control1);
            if (TOUCH_SUCCESS != touch_ret) {
                qtm_error_callback(4);
            }
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
            if (mg_enabled == true) {
                motion_gestures_2d_process();
            }
//END OF CUSTOM CODE
         }else {
           /* Acq module Error Detected: Issue an Acq module common error code 0x80 */
            qtm_error_callback(0);
        }


        if (0u != (qtlib_key_set1.qtm_touch_key_group_data->qtm_keys_status & QTM_KEY_REBURST)) {
            time_to_measure_touch_var = 1u;
        } else {
            measurement_done_touch = 1u;
            
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
#if DEF_TOUCH_LOWPOWER_ENABLE == 1u
            measurement_in_progress = 0u;
#endif
//END OF CUSTOM CODE
            
        }
    }
}

//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
#if (DEF_TOUCH_LOWPOWER_ENABLE == 1u)
/*============================================================================
static void touch_disable_lowpower_measurement(void)
------------------------------------------------------------------------------
Purpose: 
Input  : none
Output : none
Notes  :
============================================================================*/
void touch_disable_lowpower_measurement(void)
{
//    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_COUNT_Msk) == RTC_MODE0_SYNCBUSY_COUNT_Msk)
//    {
//        /* Wait for Synchronization before reading value from Count Register */
//    }
//	RTC_Timer32Stop();
    
    RTC_Timer32CounterSet((uint32_t) 0);
    RTC_Timer32Compare0Set(DEF_TOUCH_MEASUREMENT_PERIOD_MS);
	/* Store the measurement period */
	measurement_period_store = DEF_TOUCH_MEASUREMENT_PERIOD_MS;
    
//    RTC_Timer32Start();
}

/*============================================================================
static void touch_enable_lowpower_measurement(void)
------------------------------------------------------------------------------
Purpose: 
Input  : none
Output : none
Notes  :
============================================================================*/
void touch_enable_lowpower_measurement(void)
{
//    while((RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_COUNT_Msk) == RTC_MODE0_SYNCBUSY_COUNT_Msk)
//    {
//        /* Wait for Synchronization before reading value from Count Register */
//    }
//	RTC_Timer32Stop();
    
    RTC_Timer32CounterSet((uint32_t) 0);
    RTC_Timer32Compare0Set(QTM_LOWPOWER_TRIGGER_PERIOD);
    /* Store the measurement period */
	measurement_period_store = QTM_LOWPOWER_TRIGGER_PERIOD;
    
//    RTC_Timer32Start();
}

void touch_disable_nonlp_sensors(void)
{
	for (uint16_t cnt = 0u; cnt < DEF_NUM_CHANNELS; cnt++) {
		if(cnt != current_lp_sensor) {
			qtm_key_suspend(cnt, &qtlib_key_set1);
		}
    }
}


void touch_enable_nonlp_sensors(void)
{
	for (uint16_t cnt = 0u; cnt < DEF_NUM_CHANNELS; cnt++) {
		if(cnt != current_lp_sensor) {
			qtm_key_resume(cnt, &qtlib_key_set1);
		}
	}
}

void touch_enter_lowpower_mode(void)
{
    // increase touch measurement period to QTM_LOWPOWER_TRIGGER_PERIOD
    touch_enable_lowpower_measurement();
    
    // resume scanning of proximity sensor and mark for calibration
    qtm_key_resume(12u, &qtlib_key_set1);
    calibrate_node(12u);

    // suspend scanning of 2D surface sensors
    touch_disable_nonlp_sensors();
}

void touch_exit_lowpower_mode(void)
{   
    // resume scanning of 2D surface sensors
    touch_enable_nonlp_sensors();

    qtm_key_suspend(12u, &qtlib_key_set1);

    // re init surface and gestures module now so it is ready for waking from low-power
    qtm_init_surface_cs2t(&qtm_surface_cs_control1);
    qtm_init_gestures_2d();
    
    // decrease touch measurement period to DEF_TOUCH_MEASUREMENT_PERIOD_MS
    touch_disable_lowpower_measurement();
}
#endif
//END OF CUSTOM CODE

uint8_t touch_gesture_time_cnt;
/*============================================================================
void touch_timer_handler(void)
------------------------------------------------------------------------------
Purpose: This function updates the time elapsed to the touch key module to
         synchronize the internal time counts used by the module.
Input  : none
Output : none
Notes  :
============================================================================*/
void touch_timer_handler(void)
{
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
	touch_gesture_time_cnt += measurement_period_store;
//END OF CUSTOM CODE

	if (touch_gesture_time_cnt >= DEF_GESTURE_TIME_BASE_MS) {
		qtm_update_gesture_2d_timer(touch_gesture_time_cnt / DEF_GESTURE_TIME_BASE_MS);
		touch_gesture_time_cnt = touch_gesture_time_cnt % DEF_GESTURE_TIME_BASE_MS;
	}
    
    time_to_measure_touch_var = 1;
    
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
#if DEF_TOUCH_LOWPOWER_ENABLE == 1u
    time_drift_wakeup_counter += measurement_period_store;
    qtm_update_qtlib_timer(measurement_period_store);
#else
//END OF CUSTOM CODE

    qtm_update_qtlib_timer(DEF_TOUCH_MEASUREMENT_PERIOD_MS);
    
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
#endif
//END OF CUSTOM CODE
}

void rtc_cb( RTC_TIMER32_INT_MASK intCause, uintptr_t context )
{
    touch_timer_handler();
}
uintptr_t rtc_context;

void touch_timer_config(void)
{  
    RTC_Timer32CallbackRegister(rtc_cb, rtc_context);
    RTC_Timer32CounterSet((uint32_t) 0);
#if ((KRONO_GESTURE_ENABLE == 1u) || (DEF_TOUCH_DATA_STREAMER_ENABLE == 1u))
    RTC_Timer32Compare0Set(1);
#else
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
    RTC_Timer32Compare0Set((uint32_t) measurement_period_store);
//END OF CUSTOM CODE
#endif
    RTC_Timer32Start();
}

uint16_t get_sensor_node_signal(uint16_t sensor_node)
{
    return (ptc_qtlib_node_stat1[sensor_node].node_acq_signals);
}

void update_sensor_node_signal(uint16_t sensor_node, uint16_t new_signal)
{
    ptc_qtlib_node_stat1[sensor_node].node_acq_signals = new_signal;
}

uint16_t get_sensor_node_reference(uint16_t sensor_node)
{
    return (qtlib_key_data_set1[sensor_node].channel_reference);
}

void update_sensor_node_reference(uint16_t sensor_node, uint16_t new_reference)
{
    qtlib_key_data_set1[sensor_node].channel_reference = new_reference;
}

uint16_t get_sensor_cc_val(uint16_t sensor_node)
{
    return (ptc_qtlib_node_stat1[sensor_node].node_comp_caps);
}

void update_sensor_cc_val(uint16_t sensor_node, uint16_t new_cc_value)
{
    ptc_qtlib_node_stat1[sensor_node].node_comp_caps = new_cc_value;
}

uint8_t get_sensor_state(uint16_t sensor_node)
{
    return (qtlib_key_set1.qtm_touch_key_data[sensor_node].sensor_state);
}

void update_sensor_state(uint16_t sensor_node, uint8_t new_state)
{
    qtlib_key_set1.qtm_touch_key_data[sensor_node].sensor_state = new_state;
}

void calibrate_node(uint16_t sensor_node)
{
    /* Calibrate Node */
    qtm_calibrate_sensor_node(&qtlib_acq_set1, sensor_node);
    /* Initialize key */
    qtm_init_sensor_key(&qtlib_key_set1, sensor_node, &ptc_qtlib_node_stat1[sensor_node]);
}


uint8_t get_surface_status(void)
{
  return (qtm_surface_cs_control1.qtm_surface_cs2t_data->qt_surface_cs2t_status);
}

uint8_t get_surface_position(uint8_t ver_or_hor, uint8_t contact)
{
	uint8_t temp_pos = 0;
	/*
	*	ver_or_hor, 0 = hor, 1 = ver
	* contact, determines which contact point,
	*	0 is for the first contact point, and 1 is for the second contact point
	*/
	if(ver_or_hor == VER_POS)
	{
		temp_pos = qtm_surface_cs_control1.qtm_surface_contact_data[contact].v_position;
	}
	else
	{
		temp_pos = qtm_surface_cs_control1.qtm_surface_contact_data[contact].h_position;
	}
  return temp_pos;
}

/*============================================================================
void PTC_Handler_EOC(void)
------------------------------------------------------------------------------
Purpose: Interrupt service handler for PTC EOC interrupt
Input  : none
Output : none
Notes  : none
============================================================================*/
void ADC0_1_Handler(void)
{
    ADC0_REGS->ADC_INTFLAG |=1u;
	qtm_same54_ptc_handler();
}