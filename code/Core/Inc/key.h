#ifndef INC_KEY_H_
#define INC_KEY_H_

#include "main.h"
#include "led.h"
#include "lcd.h"
#include "tim.h"

//#define KEY1_STATE  HAL_GPIO_ReadPin(GPIOA, KAY1_Pin)
//#define KEY2_STATE  HAL_GPIO_ReadPin(GPIOC, KAY2_Pin)
//
//#define KEY_ON GPIO_PIN_SET
//#define KEY_OFF GPIO_PIN_RESET

void KEY1_EXIT_Callback();
void KEY2_EXIT_Callback();


#endif /* INC_KEY_H_ */
