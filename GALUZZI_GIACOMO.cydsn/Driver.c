/* ======================================== */
/* -------------- DRIVER C ---------------- */
/* ======================================== */

#include "Driver.h"

/* ADC */
int32 value_digit;

/* Environment brightness */
uint8_t environment_status = -1;
_Bool IntensityFlag = 1;

/* Remote control */
uint8_t remote_activation = 0;
_Bool FlagWrongCharacter = 0;

/* Packet */
uint8 DataBuffer[TRANSMIT_BUFFER_SIZE];
volatile uint8 PacketReadyFlag = 0;

/* ======================================== */
/* -------------- FUNCTIONS --------------- */
/* ======================================== */

/* control the led intenisty with PWM */
void REDLed_Intensity()
{
    if(IntensityFlag) PWM_REDLed_WriteCompare(65535 - value_digit);
    IntensityFlag = 0;
}    

/* send the Data Buffer */
void SendPacket()
{
    if(PacketReadyFlag)
    {
        UART_PutArray(DataBuffer, TRANSMIT_BUFFER_SIZE);
        UART_PutString("\r\n");
        PacketReadyFlag = 0;
    }    
}

/* wrong character check */
void CheckErrors()
{
    if(FlagWrongCharacter)
        {
            UART_PutString("Wrong Characte: press B to START or S to STOP\r\n");
            FlagWrongCharacter = 0;
        } 
}    

/* function for main file */
void MicroManager()
{
    switch(remote_activation)
        {
            case START:
                        FlagWrongCharacter = 0;
                        PIN_INTLed_Write(1);
                        Timer_Start();
                        ADC_DelSig_Start();
                        remote_activation = WORKING;
                        break;
                        
            case WORKING:
                        /*environment dependance*/
                        switch(environment_status)
                        {
                            case UNDER_THRESHOLD:
                                        PWM_REDLed_Start();
                                        REDLed_Intensity();
                                        SendPacket();
                                        CheckErrors();
                                        break;
                            case OVER_THRESHOLD:
                                        PWM_REDLed_WriteCompare(0);
                                        PWM_REDLed_Stop();
                                        SendPacket();
                                        CheckErrors();
                                        break;
                            default:
                                        break;
                        }    
                        break;
                        
            case STOP:
                        FlagWrongCharacter = 0;
                        PWM_REDLed_Stop();
                        ADC_DelSig_Stop();
                        Timer_Stop();
                        PIN_INTLed_Write(0);
                        remote_activation = -1;
                        PacketReadyFlag = 0;
                        environment_status = -1;
                        IntensityFlag = 1;
                        
                        break;
            default:
                        CheckErrors();
                        break;
                          
        }
         
}    

/* [] END OF FILE */
