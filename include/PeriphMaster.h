/**
 *  \file PeriphMaster.h
 *  \brief header must be updated for remove hardware ref
 */
 #ifndef PERIPHMASTER_H_INCLUDED
#define PERIPHMASTER_H_INCLUDED

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


#endif // MAIN_H_INCLUDED
