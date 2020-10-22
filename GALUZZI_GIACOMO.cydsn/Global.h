/* ======================================== */
/* -------------- GLOBAL H ---------------- */
/* ======================================== */

#define BYTE_TO_SEND 4
#define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1

#define PHOTOR_MUX_CHANNEL 0
#define POTEN_MUX_CHANNEL 1

#define BRIGHTNESS_THRESHOLD XXXXX

#include "stdio.h"
#include "cytypes.h"
#include "UART.h"
#include "ADC_DelSig.h"
#include "Timer.h"
#include "AMux.h"



extern uint8 DataBuffer[TRANSMIT_BUFFER_SIZE];
extern volatile uint8 PacketReadyFlag;

/* [] END OF FILE */
