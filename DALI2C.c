/**
 *  \file DALI2C.c
 *  \brief wrapper beetween HAL and atmel I2C driver
 *  \details implementation
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "include/TWI_slave.h"
#include "include/HAL.h"
// Sample TWI transmission commands
#define TWI_CMD_MASTER_WRITE 0x10
#define TWI_CMD_MASTER_READ  0x20

// The AVR can be waken up by a TWI address match from all sleep modes,
// But it only wakes up from other TWI interrupts when in idle mode.
// If POWER_MANAGEMENT_ENABLED is defined the device will enter power-down
// mode when waiting for a new command and enter idle mode when waiting
// for TWI receives and transmits to finish.
#define POWER_MANAGEMENT_ENABLED

// Compiler-independent macros (was previously IAR intrinsics)

#define SEI()     sei()
#define SLEEP()   sleep_cpu()
#define NOP()     __asm__ __volatile__ ("nop" ::)
#define OVERRUN 0xFF

// When there has been an error, this function is run and takes care of it
//unsigned char TWI_Act_On_Failure_In_Last_Transmission ( unsigned char TWIerrorMsg );




//end of atmel include code
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "include/DALI2C.h"




  /**
 *  \brief Open I2C port
 *
 *  \param [in] data pointer to data
 *  \param [in] add adress i2C
 *
 *  \return Status of port
 *
 *  \details Details
 */
  eStatus initComI2CSlave(uchar add)
 {

	//configuration fréquance I2C pas utile en slave
    TWBR = 0x02; //Set SCL Frequency to 400Khz
    TWSR &= !(1<<TWPS1) & !(1<<TWPS0); //SetPrescaler (for SCL frequency)

    // Initialise TWI module for slave operation. Include address and/or enable General Call.
    unsigned char TWI_slaveAddress = add;

  // Initialise TWI module for slave operation. Include address and/or enable General Call.
  TWI_Slave_Initialise( (unsigned char)((TWI_slaveAddress<<TWI_ADR_BITS) | (TRUE<<TWI_GEN_BIT) ));
	
    TWI_Start_Transceiver_With_Data( &TWI_slaveAddress, 1 );
	return getStatusI2CSlave();

 }

 /**
 *  \brief close port
 *
 *
 *  \return nothing
 *
 *
 *  \details disable interruption interuption
 */
 void closeComI2CSlave(sPort * port)
 {
  //extinction de l'interface physique car nopn implémenter dans le driver
  TWCR = (0<<TWEN)|                                 // disable TWI-interface and release TWI pins.
         (0<<TWIE)|(0<<TWINT)|                      // Disable TWI Interupt.
         (0<<TWEA)|(0<<TWSTA)|(0<<TWSTO)|           // Do not ACK on any requests, yet.
         (0<<TWWC);                                 //
//  extern TWI_busy = 0;

  free(port->data.pData); //delete data
  free(port); //delete port himself  //à voir car peut etre supprimer plus haut


 }

 /**
 *  \brief get data on port
 *
 *
 *  \return pointer on data
 *
 *  \details Details
 */
 uchar * getDataI2CSlave(sPort * port)
 {
	uint msglength = getDataLength(port);

if (msglength>TWI_BUFFER_SIZE)
    port->data.pData[0] = OVERRUN;
else
	{
		unsigned char* ptemp = malloc(msglength);
		if ( ! TWI_Transceiver_Busy() )
		{
		  if ( TWI_statusReg.RxDataInBuf )
			{
				TWI_Get_Data_From_Transceiver(ptemp,msglength);
				port->data.DataType = ptemp[0];
				memcpy(port->data.pData,&ptemp[1],msglength-1);
				port->statu = FULL;
			}
		else
				port->statu = EMPTY;
		}
	free(ptemp);

	}

return port->data.pData;

    //ajouter ici le traitement d'erreur
 }

 /**
 *  \brief set data on port
 *
 *  \param [in] port pointer on port
 *  \return status of port
 *
 *  \details Details
 */
 eStatus setDataI2CSlave(const sPort * port)
 {
 TWI_Start_Transceiver_With_Data(port->data.pData , getDataLength(port) );
  return getStatusI2CSlave();
  }


 /**
 *  \brief renvoi le statu du port
 *
 *  \param [in] port pointeur sur le port
 *  \return statu
 *
 *  \details ne renvoie que BUSY ou IDLE par de gestion d'erreur
 */
 eStatus getStatusI2CSlave()
 {
 if (TWI_Transceiver_Busy()==true)
 return BUSY;
 else
 return IDLE;
 }










