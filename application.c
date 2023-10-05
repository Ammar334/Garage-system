/* 
 * 
 * File:   application.c
 * Author: Ammar.Yasser
 *
 * Created on 21 ?????, 2023, 06:12 ?
 */

#include "application.h"

Std_ReturnType ret = E_NOT_OK; 



uint8 numper_places = 5;
uint8 numper_places_str[7] = {0};
uint8 pir1_state = 0;
uint8 pir2_state = 0;
uint8 pir1_flag = 0;
uint8 pir2_flag = 0;



int main() {
    
    application_initialize();
    
    ret = lcd_8bit_send_string_pos(&lcd_1,1,1,"Available Places : ");
    while(1)
    {
        ret = convert_byte_to_string(numper_places,numper_places_str);
        ret = lcd_8bit_send_string_pos(&lcd_1,2,1,numper_places_str);
        ret = PIR_sensor_read(&pir1,&pir1_state);
        if((pir1_state == PIR_SENSOR_ON)&&(numper_places>0)&&(pir1_flag == 0))
        {
            numper_places--;
            pir1_flag = 1;
            ret = convert_byte_to_string(numper_places,numper_places_str);
            ret = lcd_8bit_send_string_pos(&lcd_1,2,1,numper_places_str);
            ret = dc_motor_move_right(&motor_1);
            __delay_ms(750);
            ret = dc_motor_stop(&motor_1);
            __delay_ms(500);
            ret = dc_motor_move_left(&motor_1);            
            __delay_ms(750);
            ret = dc_motor_stop(&motor_1);
        }
        else if(pir1_state == PIR_SENSOR_OFF)
        {
            pir1_flag = 0;
        }
        ret = PIR_sensor_read(&pir2,&pir2_state);
        if((pir2_state == PIR_SENSOR_ON)&&(numper_places<5)&&(pir2_flag == 0))
        {
            numper_places++;
            pir2_flag = 1;
            ret = convert_byte_to_string(numper_places,numper_places_str);
            ret = lcd_8bit_send_string_pos(&lcd_1,2,1,numper_places_str);
            ret = dc_motor_move_right(&motor_2);
             __delay_ms(750);
            ret = dc_motor_stop(&motor_2);
            __delay_ms(500);
            ret = dc_motor_move_left(&motor_2);            
            __delay_ms(750);
            ret = dc_motor_stop(&motor_2);
        }
        else if(pir2_state == PIR_SENSOR_OFF)
        {
            pir2_flag = 0;
        }
    }
    return (0);
}

void application_initialize (void)
{
    ecu_initialize();
    Mcal_initialize();
}


