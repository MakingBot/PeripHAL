/**
 *  \file protocole.h
 *  \brief Brief
 *  \details Details
 */
 
 
 
 
 /**
 *  \brief start communication
 *  
 *  
 *  \return nothing
 *  
 *  \details choice of com port and param are set in this function
 */void launchCom();
 
 /**
 *  \brief receive data
 *  
 *  \return nothing
 *  
 *  \details flush internal data buffer 
 */void getRefresh();
 
 /**
 *  \brief send data
 *  
 *  \return nothing
 *  
 *  \details 
 */void setRefresh();
 
  /**
 *  \brief compute data
 *  
 *  \return nothing
 *  
 *  \details Details
 */void compute();
 /**
 *  \brief stop com 
 *  
 *  \return nothing
 *  
 *  \details delete dynamic buffer and stop communication
 */void closeCom();