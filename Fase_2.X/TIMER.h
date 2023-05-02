
#ifndef TIMER_H
#define	TIMER_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

//DEFINES

#define T0_PRESC_MASK       0x07

//TYPDEFS

typedef struct{
    uint8_t prescValue; //3 bits
}TIMER_ConfigStruct;

//HEADERS

void TIMER_T0Init(TIMER_ConfigStruct cfg);
void TIMER_T0Reload(void);
void TIMER_T0RSI(void);
#endif	

