#ifndef INC_BEEP_H_
#define INC_BEEP_H_

#include "main.h"

#define BEEP_Up 	HAL_GPIO_WritePin(GPIOA, BEEP_Pin, GPIO_PIN_SET);
#define BEEP_Down 	HAL_GPIO_WritePin(GPIOA, BEEP_Pin, GPIO_PIN_RESET);

#endif /* INC_BEEP_H_ */
