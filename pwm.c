/*
 * pwm.c
 *
 * Created: 31/10/2014
 *  Author:Damien
 */
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/cpufunc.h>
#include "include/globaletypedef.h"
#include "include/PeriphMaster.h"
#include "include/pwm.h"



void pwm_init()
{
    //disable interruption


    //TCCR1A : COM1A1 COM1A0 COM1B1 COM1B0 COM1C1 COM1C0 WGM11 WGM10
    TCCR1A  = 0b0000011;   //fast pwm 10 bits
    //TCCR1B : ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10
    TCCR1B  = 0b0001010; //presaler clk/64 mode fast pwm
    OCR1A   = 0x0000;    //12%
    OCR1B   = 0x0000;
    OCR1C   = 0x0000;
    //TIMSK : OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0
    TIMSK   = 0b00011100; // validation interruption sur comparateur A et B et overflow
    //ETIMSK : – – TICIE3 OCIE3A OCIE3B TOIE3 OCIE3C OCIE1C
    ETIMSK  = 0b00000001; //validation interruption sur comparateur C
	//jetonPwm = 1; //jeton pris par defaut


}

ISR(TIMER1_COMPC_vect,ISR_NAKED)
{
__asm__("cbi 0x1b,0" );

reti();
}

ISR(TIMER1_COMPB_vect,ISR_NAKED)
{
 __asm__("cbi	0x1b,2" );

reti();
}

ISR(TIMER1_COMPA_vect,ISR_NAKED)
{
__asm__("cbi	0x1b,1" );

reti();
}

ISR(TIMER1_OVF_vect) //naked suprimé sinon ça marche pas...
{
//allume les 3 leds

/*__asm__("sbi	0x1b,0" );
__asm__("sbi	0x1b,1" );
__asm__("sbi	0x1b,2" );*/
PERIPH_LED_PORT|= 0x07;
}

uint set_color(uint R,uint G,uint B,uint Alpha)
{

uint erreur=0;
OCR1A   = R*Alpha/41;
OCR1B   = G*Alpha/41;
OCR1C   = B*Alpha/41;

return erreur;
}

