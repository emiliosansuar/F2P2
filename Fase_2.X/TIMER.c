/*
 * File:   timer.c
 * Author: Noctis
 *
 * Created on 2 de mayo de 2023, 21:44
 */


#include "TIMER.h"

//STATIC

static uint8_t minutes;
static uint8_t seconds;

//FUNCTIONS

void TIMER_T0Init(TIMER_ConfigStruct cfg){
    RCON    =  0x80;
    INTCON  =  0xC0;
    T0CON   =  0xC0;
    T0CON  |= (cfg.prescValue & T0_PRESC_MASK);
}

void TIMER_T0Reload(void){
    TMR0IF = 0;
    TMR0L = 0x00;
}

void TIMER_T0RSI(void){
    
}