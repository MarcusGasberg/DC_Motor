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
#include <stdbool.h>
#include "StepperMotor.h"



//Prototypes
CY_ISR_PROTO(ISR_UART_rx_handler); //UART Interrupt
CY_ISR_PROTO(ISR_Timer1_handler); //Timer1 Interrupt

void handleByteReceived(uint8_t byteReceived); //Helper function for UART isr

//Global Variable
char buffer[256]; //Used for output on terminal


int main(void)
{
    CyGlobalIntEnable; //Enable global interrupts.
    //Inits
    isr_uart_rx_StartEx(ISR_UART_rx_handler); 
    timer1_isr_StartEx(ISR_Timer1_handler);
    UART_1_Start();
    initStepperMotor();
    //Start up message
    UART_1_PutString("DC-Motor-PWM application started\r\n");
    UART_1_PutString("0: Stop\r\n");
    UART_1_PutString("1: FullDrive\r\n");
    UART_1_PutString("2: WaveDrive\r\n");
    UART_1_PutString("q: Decrease speed\r\n");
    UART_1_PutString("w: Increase speed\r\n");
    UART_1_PutString("a: Go forward\r\n");
    UART_1_PutString("s: Go backward\r\n");
    UART_1_PutString("e: For one rotation\r\n");

    for(;;)
    {
       //Empty
    }
}

CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    //Read bytes...
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived); // echo back
        
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

CY_ISR(ISR_Timer1_handler)
{
    //Handle the current Drive
    switch(currentDrive)
    {
        case None:
            currentDrive = None;
            break;
        case WaveDrive:
            waveDrive();
            break;
        case FullDrive:
            fullDrive();
            break;
        case HalfDrive:
            halfDrive();
            break;
        case OneRotation:
            oneRotaion();
            break;
        default:
            break;
    }
}


void handleByteReceived(uint8_t byteReceived)
{
    //Handle the bytes received
    switch(byteReceived)
    {
        case 'q' :
            increaseSpeed();
            snprintf(buffer,sizeof(buffer),"Speed is %d \r\n", speed);
            UART_1_PutString(buffer);
            break;
        
        case 'w' :
            decreaseSpeed();
            snprintf(buffer,sizeof(buffer),"Speed is %d \r\n", speed);
            UART_1_PutString(buffer);
            break;
            
        case 'a' :
            direction = true; //Forward
            snprintf(buffer,sizeof(buffer),"Direction is forward\r\n");
            UART_1_PutString(buffer);
            break;
            
        case 's' :
            direction = false; //Backward
            snprintf(buffer,sizeof(buffer),"Direction is backward\r\n");
            UART_1_PutString(buffer);
            break;
        
        case '1' :
            currentDrive = WaveDrive;
            snprintf(buffer,sizeof(buffer),"Drive is Wave-drive\r\n");
            UART_1_PutString(buffer);
            break;
        
        case '2' :
            currentDrive = FullDrive;
            snprintf(buffer,sizeof(buffer),"Drive is full-drive\r\n");
            UART_1_PutString(buffer);
            break;
        
        case '3' :
            currentDrive = HalfDrive;
            snprintf(buffer,sizeof(buffer),"Drive is half-drive\r\n");
            UART_1_PutString(buffer);
            break;
        
        case 'e':
            currentDrive = OneRotation;
            snprintf(buffer,sizeof(buffer),"One rotation\r\n");
            UART_1_PutString(buffer);
            break;
        
        case '0' :
            currentDrive = None;
            snprintf(buffer,sizeof(buffer),"STOP\r\n");
            UART_1_PutString(buffer);
            break;
        
        default :
            // nothing
            break;
    }
}


/* [] END OF FILE */
