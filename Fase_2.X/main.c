/*
 * File:   main.c
 * Author: Noctis
 *
 * Created on 1 de mayo de 2023, 11:46
 */

#include <pic18f4321.h>
#include <xc.h>
#include "TITIMER.h"

void __interrupt(high_priority) RSI_High(void);
void main(void);
void InitSistema(void);
void InitTeclado(void);
void initCPU(void){
    
#pragma config OSC = HSPLL 
#pragma config PBADEN = DIG
#pragma config MCLRE = ON
#pragma config DEBUG = OFF
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config WDT = OFF
#pragma config LVP = OFF

}

int tick_count;
//Important: NO es poden cridar les funcions d'interrupcions des del codi
//ja que les seves funcions de retorn en asm són diferents.
//Definició d'una interrupció d'alta prioritat. 
void __interrupt(high_priority) RSI_High(void){
    if(INTCONbits.TMR0IF == 1) RSI_Timer0();
     
}

static char t;
static char mask;

void main(void) {
    
    initCPU();
    InitSistema();
    
    while(1){
        //motorLCD();
        //motorMenu();
        //motorTeclado();
        //motorADCON();
        //motorSIO();
        //motorSpeaker();
        //motorEEPROM();
        //motorTiempo();
        
	}			
    return;
}

void InitSistema(void){
    //Puerto A
    TRISA = 0x07;           //b'00000111'  los primeros 3 entrada y el resto salida
    ADCON0bits.ADON = 1;    //Habilitamos el ADCON
    ADCON1 = 0x0C;          //Habilitamos el canal AN0, AN1 y AN2 com analogicos. Seleccionamos VSS y VDD.
    ADCON2 = 0x0E;          //Conversion clock :fosc/64, 2 TAD y Justificacion izquierda
    //Puerto B
    TRISB = 0x0F;           //b'00000111'
    //Puerto C
    TRISC = 0x80;           //b'10000000', RX entrada y TX y el resto salidas 
    //Configuracion de las interrupciones
    INTCON = 0xE0;          //b'11100000', Habilitamos las interrupciones globales y el TIMER0, deshabilitamos las interrupciones del INT0
    RCONbits.IPEN = 0;      //Desactivamos las prioridades de las interrupciones
    INTCON2bits.RBPU = 0;   //Habilitamos los pull-ups internos. 
    INTCON3 = 0x00;         //Deshabilitamos las interrupciones del INT1 e INT2
    LATA = 0;
    LATAbits.LATA4 = 0;
    //Inicializamos motores
    //TiInit();
    //InitMenu();
    //InitTeclado();
    //InitADCON();
    //InitTiempo();
    //InitSIO();
    //InitSpeaker();
    //__EEPROM_DATA(0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    //LcInit(2,16);
    //LcClear();
    //LATCbits.LATC0 = 0;
}

