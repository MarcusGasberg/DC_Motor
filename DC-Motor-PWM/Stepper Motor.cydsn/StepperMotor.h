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
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define SPEEDMAX 25
#define SPEEDMIN 3


//The different modes of the Stepper Motor
enum Drive
{
    None = 0,
    WaveDrive = 1,
    FullDrive = 2,
    HalfDrive = 3,
    OneRotation = 4,
};

extern volatile uint8_t speed;//The speed is controlled with a delay. Lower variable = Higher speed
extern volatile bool direction; //True if forward
extern volatile enum Drive currentDrive; //The Current drive

extern volatile uint32_t currentStep;

//Inits the stepper motor
void initStepperMotor(void);

//Decreases the speed of the motor
void decreaseSpeed(void);

//Increases the speed of the motor
void increaseSpeed(void);

//Stops the motor
void stop(void);

//Sets the motors mode to fulldrive
void fullDrive(void);

//Sets the motors mode to wavedrive
void waveDrive(void);

//Sets the motors mode to halfdrive
void halfDrive(void);

//Rotates one revolution
void oneRotaion(void);

//Move forward steps with mode wave drive
void step(uint32_t steps);

//Set the steps aka. enable the different input on coil a and coil b
void setStep(uint8_t a1, uint8_t a2,uint8_t b1,uint8_t b2);

/* [] END OF FILE */
