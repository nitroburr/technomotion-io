/*******************************************************************************
* File Name: LIGHTS_LOW_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "LIGHTS_LOW.h"

/* Check for removal by optimization */
#if !defined(LIGHTS_LOW_Sync_ctrl_reg__REMOVED)

static LIGHTS_LOW_BACKUP_STRUCT  LIGHTS_LOW_backup = {0u};

    
/*******************************************************************************
* Function Name: LIGHTS_LOW_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LIGHTS_LOW_SaveConfig(void) 
{
    LIGHTS_LOW_backup.controlState = LIGHTS_LOW_Control;
}


/*******************************************************************************
* Function Name: LIGHTS_LOW_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void LIGHTS_LOW_RestoreConfig(void) 
{
     LIGHTS_LOW_Control = LIGHTS_LOW_backup.controlState;
}


/*******************************************************************************
* Function Name: LIGHTS_LOW_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LIGHTS_LOW_Sleep(void) 
{
    LIGHTS_LOW_SaveConfig();
}


/*******************************************************************************
* Function Name: LIGHTS_LOW_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LIGHTS_LOW_Wakeup(void)  
{
    LIGHTS_LOW_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */