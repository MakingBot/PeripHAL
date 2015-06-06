#include <stdint.h>
#include <avr/io.h>
#include "include/init.h"
#include "include/PeriphMaster.h"
#include "include/globaletypedef.h"


void periph_power_on(void)
{
    PERIPH_POWERUP_PORT |= (1<<PERIPH_POWERUP_PIN);
    system_data.power=true;
}

void init(void)
{
    PERIPH_POWERUP_DDR |= (1<<PERIPH_POWERUP_PIN);	// Powerup pin as output
    periph_power_on();

    BUTTON_PUSH_DDR &= ~(1<<BUTTON_PUSH_PIN);		// Button pin as input

    PERIPH_LED_DDR |= (1<<PERIPH_BLUE_PIN) |(1<<PERIPH_GREEN_PIN) |(1<<PERIPH_RED_PIN);
    	// LED Output
    PERIPH_LED_PORT|= RED;
}
