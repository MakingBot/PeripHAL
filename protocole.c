/**
 *  \file protocole.c
 *  \brief Brief
 *  \details Details
 */
 #include "include/HAL.h"
 #include "include/globaletypedef.h"
 #include "include/protocole.h"
 #include "include/PeriphMaster.h"


 #include <string.h>

 static sPort* comport;
 static uchar* data;
 static eBool allocated;
 static uchar allocatedlen; //taille alloué



 /**
 *  \brief start communication
 *
 *
 *  \return nothing
 *
 *  \details choice of com port and param are set in this function
 */void launchCom()
 {
 sParam param;
 comport = initCom(I2CSLAVE,ADRESSE,param);

 }

 /**
 *  \brief update data
 *
 *  \return nothing
 *
 *  \details flush internal data buffer and update value in struct defined
 *  in main if com acting this function does nothing
 */void getRefresh()
 {
	 eDataType cmd;


	 switch (getStatus(comport))
	 {
		uchar lentemp;
		case BUSY:
		break;
		case IDLE :
		/* lentemp = getDataLength(comport);
		if(!allocated)
		{
		data = malloc((size_t)lentemp);
		len = lentemp;
		}
		else
		{
			if (lentemp>len)
			{
			free(data);
			data = malloc((size_t)lentemp);
			}
		} */
		getData(comport);

		/* cmd = comport->data.Datatype;
		switch (cmd)
		{
			case PINGI2C:
			break;
			case GPIOBIT:
			break;
			case GPIOPORT:
			break;
			case CURRENTCHANNEL:
    		break;
		} */
	}


 }

 /**
 *  \brief update data
 *
 *  \return nothing
 *
 *  \details flush internal data buffer and update value in struct defined
 *  in main if com acting this function does nothing
 */void setRefresh()
 {
	 eDataType cmd;


	 switch (getStatus(comport))
	 {
		uchar lentemp;
		case BUSY:
		break;
		case IDLE :
		/* lentemp = getDataLength(comport);
		if(!allocated)
		{
		data = malloc((size_t)lentemp);
		len = lentemp;
		}
		else
		{
			if (lentemp>len)
			{
			free(data);
			data = malloc((size_t)lentemp);
			}
		} */
		setData(comport);

		/* cmd = comport->data.Datatype;
		switch (cmd)
		{
			case PINGI2C:
			break;
			case GPIOBIT:
			break;
			case GPIOPORT:
			break;
			case CURRENTCHANNEL:
    		break;
		} */
	}


 }

 /**
 *  \brief compute data
 *
 *  \return nothing
 *
 *  \details Details
 */void compute()
 {
 uchar channel;
	 switch(comport->data.DataType)
	 {
		case PINGI2C:
		comport->data.pData[0] = ADRESSE;
		break;
		case GPIOBIT:
		setGpioBit(comport->data.pData[0],comport->data.pData[1]);
		break;
		case GPIOPORT:
		break;
		case CURRENTCHANNEL: //c'est une lecture
		channel = comport->data.pData[0]; //on recupére le reste de la demande
		comport->data.pData[0] = system_data.periphcurrent[channel]; //et on met à jour
		//le transfert dans le buffer d'emmision est effectuer par interruption cyclique et l'envoie à la demande du master
    	break;
	 }
}
 /**
 *  \brief stop com
 *
 *  \return nothing
 *
 *  \details delete dynamic buffer and stop communication
 *//*void closeCom()
 {
 }*/
