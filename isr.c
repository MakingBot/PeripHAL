/*
 * isr.c
 *
 * Created: 4/11/2014
 *  Author:Damien
 */
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "include/PeriphMaster.h"
#include <util/delay.h>

void isr_init()
{
EIMSK |=_BV(INT4); //validation interruption  4
EICRB |=_BV(ISC40)|_BV(ISC41); // on rising edge
return;
}

ISR(INT4_vect)
{
cli();
	_delay_ms(100); //anti-rebond
	// avoir ce que l'on fait ici on garde le fonctionnement précédent
    while (BUTTON_PUSH_PORT & (1<<BUTTON_PUSH_PIN))  //attend que le bouton soit relaché
    {
        PERIPH_LED_PORT = RED;
        _delay_ms(1000); 	//resolution dégradé car > 216ms
        PERIPH_LED_PORT = RED | BLUE | GREEN;
        _delay_ms(1000); 	//resolution dégradé car > 216ms
    }

    PERIPH_POWERUP_PORT &= ~(1<<PERIPH_POWERUP_PIN);
	while(1) //fonction ou on ne doit aller souf si le cavalier est mis ou transistor en cc
	{
		PERIPH_LED_PORT = 0x02; //rouge et off
        _delay_ms(1000); 	//resolution dégradé car > 216ms
        PERIPH_LED_PORT = 0x01; // bleu et off
        _delay_ms(1000); 	//resolution dégradé car > 216ms
	}
}
