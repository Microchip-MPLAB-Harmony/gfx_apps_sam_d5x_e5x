/*******************************************************************************
 System Tasks File

  File Name:
    tasks.c

  Summary:
    This file contains source code necessary to maintain system's polled tasks.

  Description:
    This file contains source code necessary to maintain system's polled tasks.
    It implements the "SYS_Tasks" function that calls the individual "Tasks"
    functions for all polled MPLAB Harmony modules in the system.

  Remarks:
    This file requires access to the systemObjects global data structure that
    contains the object handles to all MPLAB Harmony module objects executing
    polled in the system.  These handles are passed into the individual module
    "Tasks" functions to identify the instance of the module to maintain.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "configuration.h"
#include "definitions.h"

//CUSTOM CODE - DO NOT REMOVE OR MODIFY ANYTHING IN THIS FILE!!!
#include "task.h"

//#define SHOW_RTOS_IDLE_TASK 1

enum
{
    APP_TASK_ID,
    LEGATO_TASK_ID,    
    ITD_TASK_ID,
    ILI_TASK_ID,
    USBD_TASK_ID,
    USB_FSV_TASK_ID,
    SYS_INPUT_TASK_ID,
    FLASH_TASK_ID,
    PM_TASK_ID,
#ifdef SHOW_RTOS_IDLE_TASK
    IDLE_TASK_ID,
#endif
    MAX_TASK_ID
};

typedef struct
{
    TaskHandle_t handle;
    char * name;
    uint32_t lastCount;
    uint32_t count;
} APP_TASK_STRUCT_t;

APP_TASK_STRUCT_t tasks[MAX_TASK_ID] = 
{
    [ITD_TASK_ID] = 
    {
        .name = "Touch Task",
    },
    [ILI_TASK_ID] = 
    {
        .name = "Display Task",
    },
    [USBD_TASK_ID] =
    {
        .name = "USBD Task",
    },
    [USB_FSV_TASK_ID] = 
    {
        .name = "USBFSV1 Task",
    },
    [LEGATO_TASK_ID] = 
    {
        .name = "GFX Task",
    },
    [SYS_INPUT_TASK_ID] = 
    {
        .name = "Input Task",
    },
    [APP_TASK_ID] = {
        .name = "User IDLE Task",
    },
    [FLASH_TASK_ID] = {
        .name = "Flash Task",
    },
    [PM_TASK_ID] = {
        .name = "Power Mgr Task",
    },    
#ifdef SHOW_RTOS_IDLE_TASK    
    [IDLE_TASK_ID] = {
        .name = "RTOS IDLE Task",
    },
#endif
};

unsigned int Task_Usage(void)
{
    static uint32_t ulLastTotalTime = 0;
    unsigned int i = 0;
    uint32_t ulTotalTime;
    uint32_t pctRunTime;
    TaskStatus_t xTaskDetails;
    uint32_t app_usage = 0;

#ifdef SHOW_RTOS_IDLE_TASK        
    tasks[IDLE_TASK_ID].handle = xTaskGetIdleTaskHandle();
#endif    
    
    //gather the new total time
    for (i = 0; i < MAX_TASK_ID; i++)
    {
        // Use the handle to obtain further information about the task.
        vTaskGetInfo( tasks[i].handle,
                      &xTaskDetails,
                      pdTRUE, // Include the high water mark in xTaskDetails.
                      eInvalid ); // Include the task state in xTaskDetails.

        tasks[i].count = xTaskDetails.ulRunTimeCounter;
    }

    printf("\n\r........................................... \n\r");
    printf("Task Usage \t%%   @ %u fps, %ukB sBuff\n\r", 
                fps, 
                (unsigned int) leGetScratchBufferSizeKB());
    printf("........................................... \n\r");
    
    ulTotalTime = portGET_RUN_TIME_COUNTER_VALUE(); /* get total time passed in system */
    
    for (i = 0; i < MAX_TASK_ID; i++)
    {
        pctRunTime = (((tasks[i].count - tasks[i].lastCount) * 100)/(ulTotalTime - ulLastTotalTime));
        pctRunTime = (pctRunTime > 100) ? 100 : pctRunTime;
        
        if (pctRunTime > 0)
        {
            printf("%.20s \t%u",
                    tasks[i].name,
                    (unsigned int) pctRunTime);
        }
        else
        {
            printf("%.20s \t<1",
                    tasks[i].name);
        }
        tasks[i].lastCount = tasks[i].count;
        
        if (i == APP_TASK_ID)
        {
            app_usage = pctRunTime;
            printf(" (free) \n\r");
        }
        else
        {
            printf("\n\r");
        }
    }
    
    ulLastTotalTime = ulTotalTime;
    
    return app_usage;
            
}

// *****************************************************************************
// *****************************************************************************
// Section: RTOS "Tasks" Routine
// *****************************************************************************
// *****************************************************************************
void _USB_DEVICE_Tasks(  void *pvParameters  )
{
    while(1)
    {
				 /* USB Device layer tasks routine */
        USB_DEVICE_Tasks(sysObj.usbDevObject0);
        vTaskDelay(0 / portTICK_PERIOD_MS);
    }
}

void _drv_touch_itd_task(  void *pvParameters  )
{
    while(1)
    {
        drv_touch_itd_task();
        vTaskDelay(0 / portTICK_PERIOD_MS);
    }
}

void _DRV_USBFSV1_Tasks(  void *pvParameters  )
{
    while(1)
    {
				 /* USB FS Driver Task Routine */
        DRV_USBFSV1_Tasks(sysObj.drvUSBFSV1Object);
        vTaskDelay(0 / portTICK_PERIOD_MS);
    }
}




void _APP_Tasks(  void *pvParameters  )
{   
    while(1)
    {
        APP_Tasks();
    }
}

void _APP_PWRMGR_Tasks(  void *pvParameters  )
{   
    while(1)
    {
        APP_PWRMGR_Tasks();
        vTaskDelay(0 / portTICK_PERIOD_MS);
    }
}

void _FLASHUPDATE_Tasks(  void *pvParameters  )
{   
    while(1)
    {
        APP_IMGFLASH_Tasks();
        vTaskDelay(0 / portTICK_PERIOD_MS);
    }
}

void _LEGATO_Tasks(  void *pvParameters  )
{
    while(1)
    {
        Legato_Tasks();
        vTaskDelay(0 / portTICK_PERIOD_MS);
    }
}

void _SYS_INPUT_Tasks(  void *pvParameters  )
{
    while(1)
    {
        SYS_INP_Tasks();
        vTaskDelay(0 / portTICK_PERIOD_MS);
    }
}

void _ILI9488_Tasks(  void *pvParameters  )
{
    while(1)
    {
        DRV_ILI9488_Update();
        vTaskDelay(0 / portTICK_PERIOD_MS);
    }
}




// *****************************************************************************
// *****************************************************************************
// Section: System "Tasks" Routine
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void SYS_Tasks ( void )

  Remarks:
    See prototype in system/common/sys_module.h.
*/
void SYS_Tasks ( void )
{
    /* Maintain system services */
    

    /* Maintain Device Drivers */
        xTaskCreate( _drv_touch_itd_task,
        "drv_touch_itd_task",
        512,
        (void*)NULL,
        1,
        (TaskHandle_t*)&tasks[ITD_TASK_ID]
    );

    xTaskCreate( _ILI9488_Tasks,
        "ILI9488_Tasks",
        512,
        (void*)NULL,
        1,
        (TaskHandle_t*)&tasks[ILI_TASK_ID]
    );



    /* Maintain Middleware & Other Libraries */
        /* Create OS Thread for USB_DEVICE_Tasks. */
    xTaskCreate( _USB_DEVICE_Tasks,
        "USB_DEVICE_TASKS",
        512,
        (void*)NULL,
        1,
        (TaskHandle_t*)&tasks[USBD_TASK_ID]
    );

	/* Create OS Thread for USB Driver Tasks. */
    xTaskCreate( _DRV_USBFSV1_Tasks,
        "DRV_USBFSV1_TASKS",
        512,
        (void*)NULL,
        1,
        (TaskHandle_t*)&tasks[USB_FSV_TASK_ID]
    );


    xTaskCreate( _LEGATO_Tasks,
        "LEGATO_Tasks",
        512,
        (void*)NULL,
        1,
        (TaskHandle_t*)&tasks[LEGATO_TASK_ID]
    );


    xTaskCreate( _SYS_INPUT_Tasks,
        "SYS_INPUT_Tasks",
        512,
        (void*)NULL,
        1,
        (TaskHandle_t*)&tasks[SYS_INPUT_TASK_ID]
    );



    /* Maintain the application's state machine. */
        /* Create OS Thread for APP_Tasks. */
    xTaskCreate((TaskFunction_t) _APP_Tasks,
                "APP_Tasks",
                512,
                NULL,
                1,
                (TaskHandle_t*)&tasks[APP_TASK_ID]);

    /* Create OS Thread for APP_PWRMGR_Tasks. */
    xTaskCreate((TaskFunction_t) _APP_PWRMGR_Tasks,
                "APP_PWRMGR_Tasks",
                128,
                NULL,
                1,
                (TaskHandle_t*)&tasks[PM_TASK_ID]);

    /* Create OS Thread for FLASHUPDATE_Tasks. */
    xTaskCreate((TaskFunction_t) _FLASHUPDATE_Tasks,
                "FLASHUPDATE_Tasks",
                512,
                NULL,
                1,
                (TaskHandle_t*)&tasks[FLASH_TASK_ID]);



    /* Start RTOS Scheduler. */
    
     /**********************************************************************
     * Create all Threads for APP Tasks before starting FreeRTOS Scheduler *
     ***********************************************************************/
    vTaskStartScheduler(); /* This function never returns. */

}

/*******************************************************************************
 End of File
 */

