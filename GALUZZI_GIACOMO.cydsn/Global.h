/* ======================================== */
/* -------------- GLOBAL H ---------------- */
/* ======================================== */

#define BYTE_TO_SEND 4
#define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1

#include "stdio.h"
#include "cytypes.h"

extern uint8 DataBuffer[TRANSMIT_BUFFER_SIZE];
extern volatile uint8 PacketReadyFlag;

/* [] END OF FILE */
