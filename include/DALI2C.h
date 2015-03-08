 /**
 *  \file DALI2C.h
 *  \brief wrapper beetween HAL and atmel I2C driver
 */

 #ifndef DALI2C_H
 #define DALI2C_H






 /**
 *  \brief Open I2C port
 *
 *  \param [in] data pointer to data
 *  \param [in] add address I2C
 *  \return  Status of port
 *
 *  \details Details
 */
 eStatus initComI2CSlave(uchar add);

 /**
 *  \brief close port
 *
 *
 *  \return nothing
 *
 *
 *  \details disable interruption interuption
 */
 void closeComI2CSlave();

 /**
 *  \brief get data on port
 *
 *
 *  \return pointer on data
 *
 *  \details Details
 */
 uchar * getDataI2CSlave(sPort  *port);

 /**
 *  \brief set data on port
 *
 *  \param [in] port pointer on port
 *  \return status of port
 *
 *  \details Details
 */eStatus setDataI2CSlave(const sPort *port);
 /**
 *  \brief renvoie la longueur de la donnée
 *
 *  \param [in] port pointeur sur le port
 *  \return longueur des donnees
 *
 *  \details Details
 */
 uint getDataLengthI2CSlave(const sPort *port);

 /**
 *  \brief renvoi le statu du port
 *
 *  \param [in] port pointeur sur le port
 *  \return statu
 *
 *  \details Details
 */
 eStatus getStatusI2CSlave();
  #endif //a bouger en fin de fichier
