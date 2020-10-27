/* ======================================== */
/* -------------- DRIVER C ---------------- */
/* ======================================== */

#include "Driver.h"

/* ADC */
int32 value_digit;

/* Environment brightness */
_Bool environment_status;
_Bool IntensityFlag = 0;

/* Remote control */
_Bool remote_activation;

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


/* [] END OF FILE */
