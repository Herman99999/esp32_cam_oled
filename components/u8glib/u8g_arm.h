/**
  ******************************************************************************
  * @file    u8g_arm.h
  * @author  xtoe
  * @brief   beer Mac config
  *
  */

#ifndef _U8G_ARM_H  
#define _U8G_ARM_H  
 
 
#include "u8g.h"  
//#include "stm32f4xx_hal.h"
#include "esp_log.h"
#include "driver/i2c.h"
 
#define DATA_BUFFER_SIZE 1000  
#define I2C_TIMEOUT 10000  
#define DEVICE_ADDRESS 0x78 //device address is written on back side of your display  
#define I2C_HANDLER hi2c1  
 
//extern I2C_HandleTypeDef hi2c1; // use your i2c handler
 

#define _I2C_NUMBER(num) I2C_NUM_##num
#define I2C_NUMBER(num) _I2C_NUMBER(num)
/*i2c pin config*/
#define I2C_MASTER_SCL_IO CONFIG_I2C_MASTER_SCL               /*!< gpio number for I2C master clock */
#define I2C_MASTER_SDA_IO CONFIG_I2C_MASTER_SDA               /*!< gpio number for I2C master data  */
#define I2C_MASTER_NUM I2C_NUMBER(CONFIG_I2C_MASTER_PORT_NUM) /*!< I2C port number for master dev */
#define I2C_MASTER_FREQ_HZ CONFIG_I2C_MASTER_FREQUENCY        /*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE 0                           /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE 0                           /*!< I2C master doesn't need buffer */


uint8_t u8g_com_hw_i2c_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr);  
 
#endif 
