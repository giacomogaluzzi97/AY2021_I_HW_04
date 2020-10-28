/* ======================================== */
/* -------------- DRIVER H ---------------- */
/* ======================================== */

/* General */
#include "project.h"
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
#define BRIGHTNESS_THRESHOLD 2000
#define OVER_THRESHOLD 0 //the environment it's very illuminated
#define UNDER_THRESHOLD 1 //the environment it's poorly illuminated

extern uint8_t environment_status;
extern _Bool IntensityFlag;

/* Remote control */
#define STOP 0
#define START 1
#define WORKING 2

extern uint8_t remote_activation;
extern _Bool FlagWrongCharacter;

/* ======================================== */
/* -------------- FUNCTIONS --------------- */
/* ======================================== */

void REDLed_Intensity();

void MicroManager();

void SendPacket();

void CheckErrors();

/* [] END OF FILE */
