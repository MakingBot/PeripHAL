/**
 *  \file gpio.c
 *  \brief manipulation des gpio
 */

 #include "include/gpio.h"
 #include "include/globaletypedef.h"

 /**
 *  \brief met a un la gpio correspondante
 *
 *  \param [in] gpionum numéro de la gpio recu sur l'i2c
 *  \return rien
 *
 *  \details
 */
void setGPIO(uchar gpionum)
{
if(gpionum < (sizeof(GPIO)/3)) //vérification de la validité de la gpio
{
uchar *porttemp = (uchar*)GPIO[gpionum][0];
GPIO[gpionum][0]|=(1<<(GPIO[gpionum][2])); //revient a faire PORTX|=(_BV(PORTBIT)); c-a-d mettre a zero PORTBIT de PORTX
}
}
/**
 *  \brief met a zero la gpio correspondante
 *
 *  \param [in] gpionum numéro de la gpio recu sur l'i2c
 *  \return rien
 *
 *  \details
 */
void resetGPIO(uchar gpionum)
{
  if(gpionum < (sizeof(GPIO)/3))//vérification de la validité de la gpio
  {
  int *porttemp = GPIO[gpionum][0];
  *porttemp &=~((1<<(GPIO[gpionum][2])));
  }
}
