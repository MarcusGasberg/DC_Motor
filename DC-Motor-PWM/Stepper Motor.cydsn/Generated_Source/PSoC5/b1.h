/*******************************************************************************
* File Name: b1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_b1_H) /* Pins b1_H */
#define CY_PINS_b1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "b1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 b1__PORT == 15 && ((b1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    b1_Write(uint8 value);
void    b1_SetDriveMode(uint8 mode);
uint8   b1_ReadDataReg(void);
uint8   b1_Read(void);
void    b1_SetInterruptMode(uint16 position, uint16 mode);
uint8   b1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the b1_SetDriveMode() function.
     *  @{
     */
        #define b1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define b1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define b1_DM_RES_UP          PIN_DM_RES_UP
        #define b1_DM_RES_DWN         PIN_DM_RES_DWN
        #define b1_DM_OD_LO           PIN_DM_OD_LO
        #define b1_DM_OD_HI           PIN_DM_OD_HI
        #define b1_DM_STRONG          PIN_DM_STRONG
        #define b1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define b1_MASK               b1__MASK
#define b1_SHIFT              b1__SHIFT
#define b1_WIDTH              1u

/* Interrupt constants */
#if defined(b1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in b1_SetInterruptMode() function.
     *  @{
     */
        #define b1_INTR_NONE      (uint16)(0x0000u)
        #define b1_INTR_RISING    (uint16)(0x0001u)
        #define b1_INTR_FALLING   (uint16)(0x0002u)
        #define b1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define b1_INTR_MASK      (0x01u) 
#endif /* (b1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define b1_PS                     (* (reg8 *) b1__PS)
/* Data Register */
#define b1_DR                     (* (reg8 *) b1__DR)
/* Port Number */
#define b1_PRT_NUM                (* (reg8 *) b1__PRT) 
/* Connect to Analog Globals */                                                  
#define b1_AG                     (* (reg8 *) b1__AG)                       
/* Analog MUX bux enable */
#define b1_AMUX                   (* (reg8 *) b1__AMUX) 
/* Bidirectional Enable */                                                        
#define b1_BIE                    (* (reg8 *) b1__BIE)
/* Bit-mask for Aliased Register Access */
#define b1_BIT_MASK               (* (reg8 *) b1__BIT_MASK)
/* Bypass Enable */
#define b1_BYP                    (* (reg8 *) b1__BYP)
/* Port wide control signals */                                                   
#define b1_CTL                    (* (reg8 *) b1__CTL)
/* Drive Modes */
#define b1_DM0                    (* (reg8 *) b1__DM0) 
#define b1_DM1                    (* (reg8 *) b1__DM1)
#define b1_DM2                    (* (reg8 *) b1__DM2) 
/* Input Buffer Disable Override */
#define b1_INP_DIS                (* (reg8 *) b1__INP_DIS)
/* LCD Common or Segment Drive */
#define b1_LCD_COM_SEG            (* (reg8 *) b1__LCD_COM_SEG)
/* Enable Segment LCD */
#define b1_LCD_EN                 (* (reg8 *) b1__LCD_EN)
/* Slew Rate Control */
#define b1_SLW                    (* (reg8 *) b1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define b1_PRTDSI__CAPS_SEL       (* (reg8 *) b1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define b1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) b1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define b1_PRTDSI__OE_SEL0        (* (reg8 *) b1__PRTDSI__OE_SEL0) 
#define b1_PRTDSI__OE_SEL1        (* (reg8 *) b1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define b1_PRTDSI__OUT_SEL0       (* (reg8 *) b1__PRTDSI__OUT_SEL0) 
#define b1_PRTDSI__OUT_SEL1       (* (reg8 *) b1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define b1_PRTDSI__SYNC_OUT       (* (reg8 *) b1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(b1__SIO_CFG)
    #define b1_SIO_HYST_EN        (* (reg8 *) b1__SIO_HYST_EN)
    #define b1_SIO_REG_HIFREQ     (* (reg8 *) b1__SIO_REG_HIFREQ)
    #define b1_SIO_CFG            (* (reg8 *) b1__SIO_CFG)
    #define b1_SIO_DIFF           (* (reg8 *) b1__SIO_DIFF)
#endif /* (b1__SIO_CFG) */

/* Interrupt Registers */
#if defined(b1__INTSTAT)
    #define b1_INTSTAT            (* (reg8 *) b1__INTSTAT)
    #define b1_SNAP               (* (reg8 *) b1__SNAP)
    
	#define b1_0_INTTYPE_REG 		(* (reg8 *) b1__0__INTTYPE)
#endif /* (b1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_b1_H */


/* [] END OF FILE */
