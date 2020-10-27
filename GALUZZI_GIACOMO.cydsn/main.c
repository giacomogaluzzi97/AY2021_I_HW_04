/* ======================================== */
/* ---------------- MAIN ------------------ */
/* ======================================== */

#include "InterruptRoutines.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    UART_Start();
    isr_ADC_StartEx(MY_ISR_ADC);
    isr_RX_StartEx(MY_ISR_RX);

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
