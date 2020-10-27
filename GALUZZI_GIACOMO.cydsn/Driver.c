/* ======================================== */
/* -------------- DRIVER C ---------------- */
/* ======================================== */

#include "Driver.h"

/* ADC */
int32 value_digit;

/* Environment brightness */
uint8_t environment_status;
_Bool IntensityFlag = 0;

/* Remote control */
uint8_t remote_activation = 0;
_Bool FlagWrongCharacter = 0;

/* Packet */
uint8 DataBuffer[TRANSMIT_BUFFER_SIZE];
volatile uint8 PacketReadyFlag = 0;

/* ======================================== */
/* -------------- FUNCTIONS --------------- */
/* ======================================== */

void REDLed_Intensity()
{
    if(IntensityFlag) PWM_REDLed_WriteCompare(value_digit);
    IntensityFlag = 0;
}    

void MicroManager()
{
    switch(remote_activation)
        {
            case START:
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
                                        /*...*/
                                        break;
                            case OVER_THRESHOLD:
                                        /*...*/
                                        break;
                            default:
                                        break;
                        }    
                        break;
                        
            case STOP:
                        PWM_REDLed_Stop();
                        ADC_DelSig_Stop();
                        Timer_Stop();
                        PIN_INTLed_Write(0);
                        remote_activation = -1;
                        break;
            default:
                        break;
                          
        }
        
        if(FlagWrongCharacter)
        {
            UART_PutString("Wrong Characte: press B to START or S to STOP\r\n");
            FlagWrongCharacter = 0;
        }  
}    

/* [] END OF FILE */
