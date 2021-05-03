// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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

/*******************************************************************************
  MPLAB Harmony Generated Driver Header File

  File Name:
    drv_gfx_vgpu.h

  Summary:
    Build-time generated header file for virtual GPU driver.
	
  Description:
    Build-time generated header file for top-level virtual GPU driver.
 * 
    Created with MPLAB Harmony Version 3
*******************************************************************************/
//DOM-IGNORE-END

#include "gfx/driver/gfx_driver.h"
#include "gfx/driver/processor/vgpu/drv_gfx_vgpu.h"

typedef enum
{
    DRV_VGPU_INIT,
	DRV_VGPU_RUN,
} DRV_VGPU_STATE;

static DRV_VGPU_STATE state;

void DRV_VGPU_Initialize(void)
{

}

void DRV_VGPU_Task(void)
{
	switch (state)
	{
		case DRV_VGPU_INIT:
		{
			break;
		}
		case DRV_VGPU_RUN:
		{
			break;
		}
		default:
			break;
	}
}
