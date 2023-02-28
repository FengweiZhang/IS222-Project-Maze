#ifndef SRC_LED_H_
#define SRC_LED_H_

#include "main.h"

#define LED_B_Up 	HAL_GPIO_WritePin(GPIOB, LED_B_Pin, GPIO_PIN_RESET);
#define LED_B_Down 	HAL_GPIO_WritePin(GPIOB, LED_B_Pin, GPIO_PIN_SET);
#define LED_B_Toggle	HAL_GPIO_TogglePin(GPIOB, LED_B_Pin);

#define LED_R_Up 	HAL_GPIO_WritePin(GPIOB, LED_R_Pin, GPIO_PIN_RESET);
#define LED_R_Down 	HAL_GPIO_WritePin(GPIOB, LED_R_Pin, GPIO_PIN_SET);
#define LED_R_Toggle	HAL_GPIO_TogglePin(GPIOB, LED_R_Pin);

#define LED_G_Up 	HAL_GPIO_WritePin(GPIOB, LED_G_Pin, GPIO_PIN_RESET);
#define LED_G_Down 	HAL_GPIO_WritePin(GPIOB, LED_G_Pin, GPIO_PIN_SET);
#define LED_G_Toggle	HAL_GPIO_TogglePin(GPIOB, LED_G_Pin);



#endif /* SRC_LED_H_ */
