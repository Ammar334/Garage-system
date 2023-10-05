/* 
 * File:   ecu_initialize.h
 * Author: ammar.yasser
 *
 * Created on 06 ?????, 2023, 05:59 ?
 */

#include "ecu_initialize.h"

lcd_8bit_t lcd_1 = {
    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_rs.pin = GPIO_PIN0,
    .lcd_rs.port = GPIO_PORT_C,
    .lcd_enable.direction = GPIO_OUTPUT,
    .lcd_enable.logic = GPIO_LOW,
    .lcd_enable.pin = GPIO_PIN1,
    .lcd_enable.port = GPIO_PORT_C,
    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[0].pin = GPIO_PIN0,
    .lcd_data[0].port = GPIO_PORT_D,
    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[1].pin = GPIO_PIN1,
    .lcd_data[1].port = GPIO_PORT_D,
    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[2].pin = GPIO_PIN2,
    .lcd_data[2].port = GPIO_PORT_D,
    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
    .lcd_data[3].pin = GPIO_PIN3,
    .lcd_data[3].port = GPIO_PORT_D,
    .lcd_data[4].direction = GPIO_OUTPUT,
    .lcd_data[4].logic = GPIO_LOW,
    .lcd_data[4].pin = GPIO_PIN4,
    .lcd_data[4].port = GPIO_PORT_D,
    .lcd_data[5].direction = GPIO_OUTPUT,
    .lcd_data[5].logic = GPIO_LOW,
    .lcd_data[5].pin = GPIO_PIN5,
    .lcd_data[5].port = GPIO_PORT_D,
    .lcd_data[6].direction = GPIO_OUTPUT,
    .lcd_data[6].logic = GPIO_LOW,
    .lcd_data[6].pin = GPIO_PIN6,
    .lcd_data[6].port = GPIO_PORT_D,
    .lcd_data[7].direction = GPIO_OUTPUT,
    .lcd_data[7].logic = GPIO_LOW,
    .lcd_data[7].pin = GPIO_PIN7,
    .lcd_data[7].port = GPIO_PORT_D
    
};

dc_motor_t motor_1 = {
  
    .dc_motor_pin[0].direction = GPIO_OUTPUT,
    .dc_motor_pin[0].logic = GPIO_LOW,
    .dc_motor_pin[0].pin = GPIO_PIN2,
    .dc_motor_pin[0].port = GPIO_PORT_C,
    .dc_motor_pin[1].direction = GPIO_OUTPUT,
    .dc_motor_pin[1].logic = GPIO_LOW,
    .dc_motor_pin[1].pin = GPIO_PIN3,
    .dc_motor_pin[1].port = GPIO_PORT_C,
    
};

dc_motor_t motor_2 = {
  
    .dc_motor_pin[0].direction = GPIO_OUTPUT,
    .dc_motor_pin[0].logic = GPIO_LOW,
    .dc_motor_pin[0].pin = GPIO_PIN4,
    .dc_motor_pin[0].port = GPIO_PORT_C,
    .dc_motor_pin[1].direction = GPIO_OUTPUT,
    .dc_motor_pin[1].logic = GPIO_LOW,
    .dc_motor_pin[1].pin = GPIO_PIN5,
    .dc_motor_pin[1].port = GPIO_PORT_C,
    
};

PIR_sensor_t pir1 = {
    .pin.direction = GPIO_INPUT,
    .pin.logic = GPIO_LOW,
    .pin.pin = GPIO_PIN6,
    .pin.port = GPIO_PORT_C
};

PIR_sensor_t pir2 = {
    .pin.direction = GPIO_INPUT,
    .pin.logic = GPIO_LOW,
    .pin.pin = GPIO_PIN7,
    .pin.port = GPIO_PORT_C
};


void ecu_initialize (void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = dc_motor_initialize(&motor_1);
    ret = dc_motor_initialize(&motor_2);
    ret = lcd_8bit_initialize(&lcd_1);
    ret = PIR_sensor_initialize(&pir1);
    ret = PIR_sensor_initialize(&pir2);
    
}