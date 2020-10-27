/* ======================================== */
/* ---------------- MAIN ------------------ */
/* ======================================== */

#include "InterruptRoutines.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    UART_Start();
    isr_ADC_StartEx(MY_ISR_ADC);
    isr_UART_StartEx(MY_ISR_RX);

    DataBuffer[0] = 0xA0;
    DataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    
    for(;;)
    {
        MicroManager();  
    }
    
}

/* [] END OF FILE */
