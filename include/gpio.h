/**
 *  \file gpio.h
 *  \brief tableau d'adressage des sortie
 *
 */
#include "periphmaster.h"
#ifndef GPIO_H
#define GPIO_H
#define RED_LED 0
#define GREEN_LED 1
#define BLUE_LED 2
#define POWERUP 3
#define BUTTON_PUSH 4
//déclaration des gpio
uchar GPIO[][3] = {
          {PERIPH_LED_PORT,PERIPH_LED_DDR,PERIPH_RED_PIN}, //définition GPIO0 --> led rouge
          {PERIPH_LED_PORT,PERIPH_LED_DDR,PERIPH_GREEN_PIN},//on pourrais remplcer par un gros define
          {PERIPH_LED_PORT,PERIPH_LED_DDR,PERIPH_BLUE_PIN},
          {PERIPH_POWERUP_PORT,PERIPH_POWERUP_DDR,PERIPH_POWERUP_PIN},
          {BUTTON_PUSH_PORT,BUTTON_PUSH_DDR,BUTTON_PUSH_PIN},
          };
/**
 *  \brief met a un la gpio correspondante
 *
 *  \param [in] gpionum numéro de la gpio recu sur l'i2c
 *  \return rien
 *
 *  \details 
 */
setGPIO(uchar gpionum);
/**
 *  \brief met a zero la gpio correspondante
 *
 *  \param [in] gpionum numéro de la gpio recu sur l'i2c
 *  \return rien
 *
 *  \details 
 */
resetGPIO(uchar gpionum);
#endif
