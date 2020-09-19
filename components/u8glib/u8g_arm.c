#include "u8g_arm.h"  
#include "freertos/FreeRTOS.h"
#include "driver/i2c.h"
uint8_t buffer[DATA_BUFFER_SIZE]; 

static uint8_t control = 0;  
static const char* TAG = "u8g_arm";

#define ESP_SLAVE_ADDR 0x3c
#define WRITE_BIT I2C_MASTER_WRITE
#define ACK_CHECK_EN 0x01	/*!< I2C master will check ack from slave*/
void u8g_Delay(uint16_t val)  
{  
 
//	HAL_Delay(val);
}  
 
void u8g_MicroDelay(void)  
{  
	int i;  
	for (i = 0; i < 1000; i++);  
}  
 
void u8g_10MicroDelay(void)  
{  
    int i;  
    for (i = 0; i < 10000; i++);  
}  
 
static esp_err_t i2c_master_write_slave(i2c_port_t i2c_num, uint8_t *data_wr, size_t size)
{
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (ESP_SLAVE_ADDR << 1) | WRITE_BIT, ACK_CHECK_EN);
    i2c_master_write(cmd, data_wr, size, ACK_CHECK_EN);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(i2c_num, cmd, 1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);
    return ret;
}

uint8_t u8g_com_hw_i2c_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr)  
{  
	ESP_LOGE(TAG, "u8g_com_hw_i2c_fn : msg %d", msg);
	switch(msg)  
	{  
	 case U8G_COM_MSG_STOP:  
	  break;  
	 
	 case U8G_COM_MSG_INIT:  
	  u8g_MicroDelay();  
	  break;  
	 
	 case U8G_COM_MSG_ADDRESS:           /* define cmd (arg_val = 0) or data mode (arg_val = 1) */  
	  u8g_10MicroDelay();  
	  if (arg_val == 0)  
	  {  
	       control = 0;  
	  }  
	  else  
	  {  
	       control = 0x40;  
	  }  
	  break;  
	 
	 case U8G_COM_MSG_WRITE_BYTE:  
	 {  
//	      uint8_t buffer[2];  
	      buffer[0] = control;  
	      buffer[1] = arg_val;  
//	      HAL_I2C_Master_Transmit(&I2C_HANDLER, DEVICE_ADDRESS, (uint8_t*) buffer, 2, I2C_TIMEOUT);
	      i2c_master_write_slave(I2C_MASTER_NUM, buffer, 0x02);
	 }  
	      break;  
	 
	 case U8G_COM_MSG_WRITE_SEQ:  
	 case U8G_COM_MSG_WRITE_SEQ_P:  
	 {  
//			uint8_t buffer[DATA_BUFFER_SIZE];  
			uint8_t *ptr = arg_ptr;  
			buffer[0] = control;  
			for (int i = 1; i <= arg_val; i++)  
			{  
			    buffer[i] = *(ptr++);  
			}  
//			HAL_I2C_Master_Transmit(&I2C_HANDLER, DEVICE_ADDRESS, (uint8_t *)buffer, arg_val, I2C_TIMEOUT);
			i2c_master_write_slave(I2C_MASTER_NUM, buffer, arg_val);
	 }  
	 
	 break;  
	}  
	return 1;  
}  
