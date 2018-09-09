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
#include "StepperMotor.h"
#include "project.h"


volatile uint8_t speed = 10; //The speed is controlled with a delay. Lower variable = Higher speed
volatile bool direction = true; //True if forward
volatile enum Drive currentDrive = None; //The Current drive
volatile uint32_t currentStep = 0;


void initStepperMotor(void)
{
    Timer_1_Start();
}


void increaseSpeed(void)
{
    if((--speed) < SPEEDMIN)
        speed = SPEEDMIN;
}

void decreaseSpeed(void)
{
    if((++speed) > SPEEDMAX)
        speed = SPEEDMAX;
    char buffer[256];
    snprintf(buffer,sizeof(buffer),"Speed is %d \r\n", speed);
    UART_1_PutString(buffer);
    
}

void stop(void)
{
    UART_1_PutString("Stop\r\n");
    
}


void fullDrive(void)
{
    if (direction)
    {
        setStep(1,1,0,0);
        setStep(0,1,1,0);
        setStep(0,0,1,1);
        setStep(1,0,0,1);
    }
    else
    {
        setStep(1,0,0,1);
        setStep(0,0,1,1);
        setStep(0,1,1,0);
        setStep(1,1,0,0);
    }
}

void waveDrive(void)
{
    if (direction)
    {
        setStep(1,0,0,0);
        setStep(0,1,0,0);
        setStep(0,0,1,0);
        setStep(0,0,0,1);
    }
    else
    {
        setStep(0,0,0,1);
        setStep(0,0,1,0);
        setStep(0,1,0,0);
        setStep(1,0,0,0);
    }
}

void halfDrive(void)
{
    if (direction)
    {
        setStep(1,1,0,0);
        setStep(0,1,0,0);
        setStep(0,1,1,0);
        setStep(0,0,1,0);
        setStep(0,0,1,1);
        setStep(0,0,0,1);
        setStep(1,0,0,1);
        setStep(1,0,0,0);
    }
    else
    {
        setStep(1,0,0,0);
        setStep(1,0,0,1);
        setStep(0,0,0,1);
        setStep(0,0,1,1);
        setStep(0,0,1,0);
        setStep(0,1,1,0);
        setStep(0,1,0,0);
        setStep(1,1,0,0);
    }
}


void step(uint32_t steps)
{
    for (uint32_t i = 0; i < steps; i++)
    {
        waveDrive();
    }
}

void oneRotaion()
{
    if(currentStep++ != 512)
    {
        waveDrive();
    }
    else
    {
        currentStep = 0;
        currentDrive = None; 
    }
}
            
void setStep(uint8_t a1, uint8_t a2,uint8_t b1,uint8_t b2)
{
    a1_Write(a1);
    a2_Write(a2);
    b1_Write(b1);
    b2_Write(b2);
    CyDelay(speed);
}
/* [] END OF FILE */
