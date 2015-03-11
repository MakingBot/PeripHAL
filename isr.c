/*
 * isr.c
 *
 * Created: 4/11/2014
 *  Author:Damien
 */
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "include/isr.h"
#include "include/PeriphMaster.h"
#include "include/protocole.h"
#include <util/delay.h>

void isr_init()
{
//gestion du bouton
EIMSK |=_BV(INT4); //validation interruption  4
EICRB |=_BV(ISC40)|_BV(ISC41); // on rising edge
//action périodique sur timer 0 timer1 utilisé par pwm
TCCR0 |= _BV(CS00)|_BV(CS01) |_BV(CS02);//normal mode presacaler /1024 inter toutes le 16ms@16MHz
TIMSK|= _BV(TOIE0); //interruption sut timer0 overflot validé
return;
}

/**
 *  \brief POWER OFF SYSTEM
 *
 *  \param [in] INT4_vect interruption vector
 *  \return nothing
 *
 *  \details détecte l'appui sur le bouton on et éteint la carte
 */ISR(INT4_vect)
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


/**
 *  \brief Brief
 *
 *  \param [in] TIMER0_OVF Parameter_Description
 *  \return Return_Description
 *
 *  \details à chaque interruption on passe à l'action suivante
 *  peut étre interrompu
 */
 ISR(TIMER0_OVF_vect)
{
	static eState state;
	switch (state)
	{
		case GET :
		getRefresh();
		state = SET;
		break;
		case SET:
		setRefresh();
		state = COMPUTE;
		break;
		case COMPUTE:
		compute();
		state = GET;
		break;
	}

}
