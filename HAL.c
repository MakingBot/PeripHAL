/**
 *  \file HAL.c
 *  \brief implémantation de la couche d'abstraction matérielle
 *  \details This file include all driver header or wrapper but not hardware file
 */
#include <stdlib.h>
#include <string.h>
#include "include/globaletypedef.h"
#include "include/HAL.h"
#include "include/mapping.h"
#include "include/init.h"
#include "include/DALI2C.h"  //wrapper for driver I2C come fram atmel
#include "include/isr.h" //driver of interruption
#include "include/pwm.h"
#include "include/utility.h" //wrapper




sPort* initCom(const ePortType porttype,const uchar PortNum,const sParam param)
{
    sPort* pPort = malloc(sizeof(sPort));
    pPort->statu = IDLE;
    pPort->num = newNumCom();
    pPort->data.id = PortNum;
    pPort->data.rw = READ;
    pPort->data.DataType = PINGI2C;
    pPort->data.pData = malloc(1); //on aloue 1 octet par defaut
    switch(porttype)
    {
    case I2CSLAVE :
        initComI2CSlave(PortNum); //general call always activated

        break;

    default:
        break;
    }
    return pPort;
}



/**
*  \brief ferme le port
*
*  \param [in] spData pointeur vers les donnes du port
*  \return rien
*
*  \details Details
*/
void closeCom(sPort * port )
{
}

/**
*  \brief récuopére les données du port
*
*  \param [in] port pointeur sur le port
*  \return pointeur sur les données
*
*  \details Details
*/
uchar* getData(const sPort *port)
{
    switch(port->type)
    {
    case I2CSLAVE :
        return getDataI2CSlave(port); //general call always activated
    default:
        break;
    }
return NULL;
}

/**
*  \brief set data on port
*
*  \param [in] port pointer on port
*  \return status of port
*
*  \details Details
*/eStatus setData(const sPort *port)
{
switch(port->type)
    {
    case I2CSLAVE :
        setDataI2CSlave(port); //general call always activated
        break;
    default:
        break;
    }
return (getStatus(port));
   
}
/**
*  \brief renvoie la longueur de la donnée
*
*  \param [in] port pointeur sur le port
*  \return longueur des donnees
*
*  \details Details
*/
uint getDataLength(const sPort *port)
{
    uint len;
    switch(port->data.DataType)
    {
    case PINGI2C :
        len = PINGLENGHT;
        break;
    case GPIOBIT :
        len = GPIOBITLENGTH;
        break;
    case GPIOPORT :
        len = GPIOPORTLENGTH;
        break;
    case CURRENTCHANNEL :
        len = CURRENTCHANNELLENGTH;
        break;
    default:
    len = 0;
        break;
    }
    return len;
}

/**
*  \brief renvoi le statu du port
*
*  \param [in] port pointeur sur le port
*  \return statu
*
*  \details Details
*/
eStatus getStatus(const sPort *port)
{
    return port->statu;
}

/**
*  \brief return unique id for a new port
*
*  \return unique id
*
*  \details limited to 254 device from 1 to 254 return 0 if fail
*/
uchar newNumCom()
{
    static uchar id = 0;
    if (id==255)
        id = 0;
    else
        id++;
    return id;
}

/**
*  \brief give num of port
*
*  \param [in] port pointer to port
*  \return num port
*
*  \details Details
*/
uchar numCom(const sPort *port)
{
    return port->num;
}

/**
 *  \brief Brief
 *  
 *  \param [in] port port to change
 *  \param [in] bit bit in port to change
 *  \return nothing
 *  
 *  \details Details
 */void setGpioBit(const uchar numgpio,eBool val)
 {
   /*switch(numgpio)
	 {
	 case 0 :
	 GPIO(0,val); //c'est une macro
	 break;
	 case 1 :
	 GPIO(1,val); //c'est une macro le premier caractére est substituer et ne peut donc par etre variable
	 break;
	 case 2 :
	 GPIO(2,val); //c'est une macro
	 break;
	 default:
	 break;
	 }*/
	if (val==true)
	setGPIO(numgpio);
	else
	resetGPIO(numgpio);
 
 
 }
