#ifndef INC_MAZE_H_
#define INC_MAZE_H_

#include "main.h"
#include "tim.h"

extern uint8_t ui_stat;
extern uint8_t light;

#define WELCOME_UI 	0
#define PLAY_UI		1
#define WIN_UI		2



#define WALL_S 	(uint8_t)0
#define ROAD_S 	(uint8_t)1
#define ENTER_S (uint8_t)2
#define EXIT_S 	(uint8_t)3

#define MAZE_X 20
#define MAZE_Y 30

#define MOVE_UP		(uint8_t)0
#define MOVE_LEFT	(uint8_t)1
#define MOVE_RIGHT	(uint8_t)2
#define MOVE_DOWN	(uint8_t)3


#define SCORE_FLAG 0xCCCCCCCC
#define SCORE_ADDER	0x1000

typedef struct _maze_t
{
  int32_t	step;
  int32_t	best;
  uint8_t	map[MAZE_X][MAZE_Y];
  int32_t	player[2];
  int32_t	enter[2];
  int32_t	exit[2];
} maze_t;

void MAZE_INIT(void);
void MAZE_PKAYER_Move(uint8_t direct);
void MAZE_CHECK(void);
void MAZE_PLAYER_Restart();

void MAZE_UI_Change(int stat);

void MAZE_UI_HandelDown(int16_t x, int16_t y);
void MAZE_UI_HandelUp(int16_t x, int16_t y);

void PLAY_UI_HandelDown(int16_t x, int16_t y);
void PLAY_UI_HandelUp(int16_t x, int16_t y);
void WIN_UI_HandelDown(int16_t x, int16_t y);
void WIN_UI_HandelUp(int16_t x, int16_t y);
void WELCOM_UI_HandelUp();

#endif /* INC_MAZE_H_ */
