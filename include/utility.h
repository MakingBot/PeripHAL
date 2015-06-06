 /**
 *  \file utility.h
 *  \brief wrapper to util
 */

 #ifndef UTILITY_H
 #define UTILITY_H
 #include <util/delay.h>
 #ifdef AVR
 #include <avr/io.h>
 #include <avr/interrupt.h>
     #ifndef __DEBUG__
     #define HALdelay_ms(ms)
     #else
     #define HALdelay_ms(ms) _delay_ms(ms)
     #endif // __DEBUG__
 #define HAL_sei()   sei()
 #define HAL_cli()	cli()
 #endif
 #endif
