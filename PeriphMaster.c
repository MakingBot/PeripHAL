/**
 *  \file PeriphMaster.c
 *  \brief application carteperiph
 *  \details this file is the main application it don't must any reference to any hardware
 */


#include <stdint.h>
#include "include/HAL.h" // Hardward abstraction layer

#include "include/PeriphMaster.h"
#include "include/utility.h"
#include "include/init.h"
#include "include/pwm.h"
#include "include/isr.h" //driver of interruption




/**
 *  \brief main
 *
 *  \return none
 *
 *  \details Details
 */int main()
{
    HAL_cli();
     init();
     pwm_init();
     isr_init();
//     initCom(); //to implemente
    HAL_sei();

   while(1)
   {

        set_color(255,0,0,255); //a priori 25ms d'execution
        HALdelay_ms(10); //need to be wrapped
        set_color(0,0,255,255); //a priori 25ms d'execution
        HALdelay_ms(10);
        set_color(255,255,255,0); //a priori 25ms d'execution
        HALdelay_ms(10);


   }
}
