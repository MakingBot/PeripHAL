/**
 *  \file PeriphMaster.c
 *  \brief application carteperiph
 *  \details this file is the main application it don't must any reference to any hardware
 */


#include <stdint.h>
#include "include/HAL.h" // Hardware abstraction layer
#include "include/globaletypedef.h"
#include "include/PeriphMaster.h"
#include "include/utility.h"
#include "include/init.h"
#include "include/pwm.h"
#include "include/isr.h" //driver of interruption
#include "include/protocole.h"


extern struct data system_data;

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
     #ifdef __DEBUG__
    set_color(0,0,255,255); //a priori 25ms d'execution
    #endif // __DEBUG__

    // launchCom();
    HAL_sei();

   while(1)
   {

        getRefresh();
  #ifdef __DEBUG__
    set_color(0,0,255,255); //a priori 25ms d'execution
    #endif // __DEBUG__

        compute();

        setRefresh();
        HALdelay_ms(100);
  #ifdef __DEBUG__
    set_color(255,0,0,255); //a priori 25ms d'execution
    #endif // __DEBUG__



   }
}
