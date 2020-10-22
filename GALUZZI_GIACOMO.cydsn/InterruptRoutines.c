/* ======================================== */
/* ----------------- ISR C ---------------- */
/* ======================================== */

#include "InterruptRoutines.h"

/* ======================================== */
/* ---------------- ISR ADC --------------- */
/* ======================================== */

int32 value_digit;

CY_ISR(MY_ISR_ADC)
{
    Timer_ReadStatusRegister();
    
    /* Photoresistor channel */ 
    AMux_FastSelect(PHOTOR_MUX_CHANNEL);
    
    value_digit = ADC_DelSig_Read32();
    if(value_digit < 0) value_digit = 0;
    if(value_digit > 65535) value_digit = 65535;
    
    DataBuffer[1] = value_digit >> 8;
    DataBuffer[2] = value_digit & 0xFF;
    
    if(value_digit <= BRIGHTNESS_THRESHOLD) /*...*/
    
    
    
    /* Potentiometer channel */ 
    AMux_FastSelect(POTEN_MUX_CHANNEL);
    
    value_digit = ADC_DelSig_Read32();
    if(value_digit < 0) value_digit = 0;
    if(value_digit > 65535) value_digit = 65535;
    
    DataBuffer[3] = value_digit >> 8;
    DataBuffer[4] = value_digit & 0xFF;
    
    
}    

/* ======================================== */
/* ---------------- ISR RX ---------------- */
/* ======================================== */

uint8 ch_received;

CY_ISR(MY_ISR_RX)
{
    if(UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)
    {
        ch_received = UART_GetChar();
        
        switch(ch_received)
        {
            case 'B':
            case 'b':
                    /*...*/ //start all
                    break;
            case 'S':
            case 's':
                    /*...*/ //stop all
                    break;
            default:
                    /*...*/ //wrong char  
                    break;
        }    
    }    
} 

/* [] END OF FILE */
