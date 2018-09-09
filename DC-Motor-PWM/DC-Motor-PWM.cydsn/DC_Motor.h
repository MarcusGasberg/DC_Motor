/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>

#define SPEEDMAX 100
#define SPEEDMIN 0

extern volatile uint8_t speed;

//Decreases the speed of the DC-Motor
void decreaseSpeed(void);

//Increases the speed of the DC-Motor
void increaseSpeed(void);

//The DC-Motor drives forward
void driveForwards(void);

//The DC-Motor drives backward
void driveBackwards(void);

//Stops the DC-Motor
void stop(void);

/* [] END OF FILE */
