/**
 *  \file HAL.h
 *  \brief fichier d'entête de la couche d'abstraction matériel
 */
#ifndef HAL_H
#define HAL_H
#include "globaletypedef.h"
#define READ false
#define WRITE true
// definition of datatype length
#define PINGLENGHT 0
#define GPIOBITLENGTH 2
#define GPIOPORTLENGTH 2
#define CURRENTCHANNELLENGTH 2
//macros

 #define GPIO(num,val)\
 if (!val )\
 GPIO ## num ## _PORT &= ~(1<<GPIO ## num ## BIT);\
 else\
 GPIO ## num ## _PORT |=(1<<GPIO ## num ## BIT);
//supression car devenue inutile avec gpio.c
/******************************************
 *  définition des type enuméré
 */

// /brief type de data

//longueur data 0
//longueur data 2 1er octect numéro gpio, 2eme etat gpio type bool
// numéro du port suivi data la dir est fixé dans le code
//voie courant suivie de la valeur
typedef enum
{
    PINGI2C,
    GPIOBIT,
    GPIOPORT,
    CURRENTCHANNEL
} eDataType;


// /brief type de port
typedef enum
{
    I2CSLAVE,
    I2CMASTER,
    FULLDUPLEX
} ePortType;

// /brief liste des type de parité
typedef enum
{
    EVEN,
    ODD,
    NONE
} eParity;

// /brief liste des status possible pour un port
typedef enum
{
    BUSY,
    IDLE,
    CLOSED,
    EMPTY,
    FULL,
    ERROR
} eStatus;

/****************
 *  définition des structures en mémoire
 */
// /brief structure des données en mémoire
typedef  struct
{
    uchar id;  //identifiant du device
    eBool rw;	//action sur le device vaut TRUE en ecriture
    eDataType DataType;
    uchar * pData;
} sData;

// /brief structure represantant un port
typedef struct
{
    sData data;
    uchar num; //identifiant unique du port voir si utile
    eStatus statu;
	ePortType type;
} sPort;


// /brief structure des paramétre de port
typedef struct
{
    uchar bauds; //vitesse du port
    eParity parity; //parité du port
    uchar start; // nombre de bit de start
    uchar stop;
} sParam;

/**
 *  \brief fonction d'initialisation et de création de port
 *
 *  \param [in] porttype type de port à ouvrir
 *  \param [in] PortNum numéro du port à ouvrir
 *  \param [in] param liste des paramétre du port
 *  \return renvoie un pointeur sur les données du port
 *
 *  \details Details
 */
sPort* initCom(const ePortType porttype,const uchar PortNum,const sParam param);

/**
*  \brief ferme le port
*
*  \param [in] spData pointeur vers les donnes du port
*  \return rien
*
*  \details Details
*/
//void closeCom(sPort * port);

/**
*  \brief récuopére les données du port
*
*  \param [in] port pointeur sur le port
*  \return pointeur sur les données
*
*  \details Details
*/
uchar* getData(const sPort * port);

/**
*  \brief set data on port
*
*  \param [in] port pointer on port
*  \return status of port
*
*  \details Details
*/
eStatus setData(const sPort * port);

/**
*  \brief renvoie la longueur de la donnée
*
*  \param [in] port pointeur sur le port
*  \return longueur des donnees
*
*  \details Details
*/
uint getDataLength(const sPort * port);

/**
*  \brief renvoi le statu du port
*
*  \param [in] port pointeur sur le port
*  \return statu
*
*  \details Details
*/
eStatus getStatus(const sPort * port);

/**
 *  \brief return unique id for a new port
 *
 *  \return Return_Description
 *
 *  \details Details
 */
uchar newNumCom();

/**
*  \brief return unique id of port
*
*  \param [in] port pointer on port
*  \return unique id
*
*  \details Details
*/
uchar numCom(const sPort * port);

/**
 *  \brief Brief
 *
 *  \param [in] port port to change
 *  \param [in] bit bit in port to change
 *  \return nothing
 *
 *  \details Details
 */void setGpioBit(const uchar numgpio,eBool val);


#endif //a bouger en fin de fichier
