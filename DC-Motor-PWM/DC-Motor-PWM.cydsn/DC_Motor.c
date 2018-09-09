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
#include "DC_Motor.h"

volatile uint8_t speed = 50;

void decreaseSpeed()
{
    if((speed -= 5 )< SPEEDMIN) //Decrease speed if above SPEEDMIN
        speed = SPEEDMIN;
    PWM_1_WriteCompare(speed); //Update the PWM
    char buffer[256];
    snprintf(buffer,sizeof(buffer),"PWM is on %d percent duty cycle\r\n", speed);
    UART_1_PutString(buffer);
}



void increaseSpeed()
{
    if((speed += 5) > SPEEDMAX) //Increase speed variable if below SPEEDMAX
        speed = SPEEDMAX;
    PWM_1_WriteCompare(speed); //Update the PWM
    char buffer[256];
    snprintf(buffer,sizeof(buffer),"PWM is on %d percent duty cycle\r\n", speed);
    UART_1_PutString(buffer);
    
}

void driveForwards()
{
    UART_1_PutString("Set direction: forwards\r\n");
    FW_Pin_Write(1u); //Enable the forward pin
    BW_Pin_Write(0u); //Disable the backward pin
}

void driveBackwards()
{
    UART_1_PutString("Set direction: backwards\r\n");
    FW_Pin_Write(0u); //Disable the forward pin
    BW_Pin_Write(1u); //Enable the backward pin
}

void stop()
{
    UART_1_PutString("Stop\r\n");
    PWM_1_WriteCompare(0); //Set the duty cycle to 0.
}

/* [] END OF FILE */
