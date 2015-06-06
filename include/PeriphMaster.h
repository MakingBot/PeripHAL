/**
 *  \file PeriphMaster.h
 *  \brief header must be updated for remove hardware ref
 */
 #ifndef PERIPHMASTER_H_INCLUDED
#define PERIPHMASTER_H_INCLUDED
#include "globaletypedef.h"
#include <avr/io.h>

//#define F_CPU 1000000UL // 1 MHz
#define CYAN		0x45	// 0b01000010
#define JAUNE        0x46
#define WHITE       0x47
#define RED	    0x42
#define GREEN   0x44
#define BLUE    0x41

#define PERIPH_LED_PORT             PORTA
#define PERIPH_LED_DDR              DDRA
#define PERIPH_RED_PIN              PORT1
#define PERIPH_GREEN_PIN            PORT2
#define PERIPH_BLUE_PIN             PORT0

#define PERIPH_POWERUP_DDR			DDRA
#define PERIPH_POWERUP_PORT			PORTA
#define PERIPH_POWERUP_PIN			PORTA6

#define BUTTON_PUSH_DDR					DDRE
#define BUTTON_PUSH_PORT				PINE
#define BUTTON_PUSH_PIN					PIN4
#define ADRESSE							0x48

#define GPIO0_PORT                  PORTC
#define GPIO1_PORT                  PORTC
#define GPIO2_PORT                  PORTC

#define GPIO0BIT                    PORT0
#define GPIO1BIT                    PORT1
#define GPIO2BIT                    PORT2
struct data
 {
	eBool periphstate[19];  //�tat des p�riph�riques true allum� false �teint
	uchar periphcurrent[19]; //valeur de courant des p�riph�rique
	eBool power; //�tat du syst�me true allum� false �teint

 }system_data;
#endif // MAIN_H_INCLUDED
