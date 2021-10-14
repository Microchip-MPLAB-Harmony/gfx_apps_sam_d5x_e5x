/**
 * This software is provided for demo purposes only. You may use this software, 
 * and any derivatives, exclusively for demonstration purposes with Microchip 
 * Technology Inc's (Microchip) products. Motion Gestures retains all ownership 
 * and intellectual property rights in the accompanying software and in all 
 * derivatives hereto. You agree not to remove from view this notice appearing 
 * on the software. You further agree not to adapt, translate, deconstruct, 
 * reverse engineer, decompile, or otherwise derive the source code for the 
 * software. 
 * SOFTWARE IS "AS IS." NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, 
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
 * MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL 
 * MOTION GESTURES BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR 
 * CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO 
 * THE SOFTWARE, HOWEVER CAUSED, EVEN IF MOTION GESTURES HAS BEEN ADVISED OF THE 
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY 
 * LAW, MOTION GESTURE?S TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE 
 * WILL NOT EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MOTION GESTURES
 * FOR THIS SOFTWARE.
 */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "./mg_touch_processing.h"
#include "definitions.h"


/*
 * The maximum number of gesture points we are ready to recognize
 */
#define POINTS_DEFAULT_CAPACITY 500


/*
 * input: The array of SGRE_FLOAT that we use to store x and y coordinates. 
 * X coordinates are stored at the beginning of the array, while Y coordinates
 * are store at position+points_capacity
 */
static SGRE_FLOAT input[2*POINTS_DEFAULT_CAPACITY];
static SGRE_FLOAT temp1[POINTS_DEFAULT_CAPACITY];
static SGRE_FLOAT temp2[POINTS_DEFAULT_CAPACITY];


/*
 * The points capacity
 */
static int points_capacity =  POINTS_DEFAULT_CAPACITY;


/*
 * The number of coordinates stored
 */
static int points_length = 0;


/*
 * Recognized gesture name for printing, or Rejected
 */
static uint8_t text[50];


/*
 * The minimum distance that a point has to be from another point
 * for us to consider it.
 */
static uint16_t distanceThreshold = 3;


/*
 * Motion Gestures 2D Process
 */
uint8_t pred_done = 1u;
extern  qtm_surface_cs2t_control_t qtm_surface_cs_control1;

touch_ret_t motion_gestures_2d_process(void)
{
    if (qtm_surface_cs_control1.qtm_surface_cs2t_data->qt_surface_cs2t_status != 0u) {
        
        collect_coordinates(qtm_surface_cs_control1.qtm_surface_contact_data->h_position,
                qtm_surface_cs_control1.qtm_surface_contact_data->v_position);
            
        pred_done = 0u;
    }
    if (qtm_surface_cs_control1.qtm_surface_cs2t_data->qt_surface_cs2t_status == 0u && pred_done == 0u) {
        
        process_touch_gesture_result();
        pred_done = 1u;
    }    
    return TOUCH_SUCCESS;
}  


/*
 * Collect Touch Coordinates
 */
void collect_coordinates(uint16_t x,uint16_t y)
{
    //do not collect more points that we have room for
    if(points_length>=points_capacity-1) {
        return;
    }
        
    y = 255 - y;    
    SGRE_FLOAT xf = convert_to_float(x);
    SGRE_FLOAT yf = convert_to_float(y);

    if(points_length == 0)
    {
        input[points_length] = xf;
        input[points_length+points_capacity] = yf;
        points_length++;
    } 
    else 
    {
        SGRE_FLOAT d = calculate_distance(xf,yf,input[points_length-1],input[points_length+points_capacity-1]);
        if(d > convert_to_float(distanceThreshold))
        {
            input[points_length] = xf;
            input[points_length+points_capacity] = yf;
            points_length++;
        }
    }
}


/*
 * Clear Coordinates
 */
void clear_coordinates(void){
    points_length = 0;
}


/*
 * Initialize Memory Labels to Names
 */
const char init_mem_label2name[16][14] = {
"2",
"Check",
"",
"",
"Alpha",
"S",
"",
"",
"Star",
"Dummy-M",
"Dummy-S",
"Dummy-S-2",
"Dummy-Check-1",
"Dummy-Check-2",
"Dummy-Alpha",
"M",
};
const char* project_name="Motion_Gestures_Touch_Demo";


/*
 * Process Touch Gesture Result
 */
extern qtm_gestures_2d_control_t   qtm_gestures_2d_control1;

void process_touch_gesture_result(void)
{         
    //ignore calls with less than 6 points
    if(points_length < 6) 
    {
        clear_coordinates();
        return;
    }
    
    SGRE_touch_predict_result predict_result;          
    predict_result.status = SGRE_TOUCH_GESTURE_REJECTED;  
    
    touch_predict(input,  points_capacity, points_length, temp1, temp2, &predict_result);  
    
    memset(text,0,sizeof(text));
    if(predict_result.status == SGRE_TOUCH_GESTURE_ACCEPTED)
    {
        qtm_gestures_2d_clearGesture();
        qtm_gestures_2d_control1.qtm_gestures_2d_data->gestures_status = 1u;
        
        switch (predict_result.label)
        {
            case 15:
                qtm_gestures_2d_control1.qtm_gestures_2d_data->gestures_which_gesture = MG_M;
                break;
            case 5:
                qtm_gestures_2d_control1.qtm_gestures_2d_data->gestures_which_gesture = MG_S;
                break;
            case 0:
                qtm_gestures_2d_control1.qtm_gestures_2d_data->gestures_which_gesture = MG_2;
                break;                
            case 1:
                qtm_gestures_2d_control1.qtm_gestures_2d_data->gestures_which_gesture = MG_CHECK;
                break;
            case 4:
                qtm_gestures_2d_control1.qtm_gestures_2d_data->gestures_which_gesture = MG_ALPHA;
                break;
            case 8:
                qtm_gestures_2d_control1.qtm_gestures_2d_data->gestures_which_gesture = MG_STAR;
                break;
            default:
                qtm_gestures_2d_control1.qtm_gestures_2d_data->gestures_which_gesture = MG_ERROR;
                break;
        }
    }
    clear_coordinates();  
}

/* *****************************************************************************
 End of File
 */
