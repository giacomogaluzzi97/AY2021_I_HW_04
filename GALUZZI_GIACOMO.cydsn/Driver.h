/* ======================================== */
/* -------------- DRIVER H ---------------- */
/* ======================================== */

/* General */
#include "stdio.h"
#include "cytypes.h"
#include "UART.h"
#include "ADC_DelSig.h"
#include "Timer.h"
#include "AMux.h"
#include "PWM_REDLed.h"

/* Packet */
#define BYTE_TO_SEND 4
#define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1

extern uint8 DataBuffer[TRANSMIT_BUFFER_SIZE];
extern volatile uint8 PacketReadyFlag;

/* AMux */
#define PHOTOR_MUX_CHANNEL 0
#define POTEN_MUX_CHANNEL 1

/* ADC */
extern int32 value_digit;

/* Environment brightness */
#define BRIGHTNESS_THRESHOLD XXXXX
#define UNDER_THRESHOLD 0 //the environment it's poorly illuminated
#define OVER_THRESHOLD 1 //the environment it's very illuminated

extern _Bool environment_status;
extern _Bool IntensityFlag;

/* Remote control */
#define START 0
#define STOP 1

extern _Bool remote_activation;

/* ======================================== */
/* -------------- FUNCTIONS --------------- */
/* ======================================== */

void REDLed_Intensity();

/* [] END OF FILE */
