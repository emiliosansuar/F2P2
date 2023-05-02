/*
 * File:   main.c
 * Author: Noctis
 *
 * Created on 1 de mayo de 2023, 11:46
 */

#include "pic18f4321.h"
#include "TIMER.h"
#include <xc.h>



static void RSI(void){
    if(TMR0IF == 1) TIMER_T0RSI(void);
}

void setup(void){
    TIMER_ConfigStruct cfg;
    cfg.prescValue = 0x7;
    TIMER_T0Init(cfg);
}

void main(void) {
    setup();
    
    
    while(1){
    
    }
    return;
}
