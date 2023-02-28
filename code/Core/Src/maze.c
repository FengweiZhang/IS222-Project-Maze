#include "maze.h"
#include "lcd.h"

extern maze_t maze;
extern int32_t score[];

void MAZE_INIT(void)
{
	SPI_FLASH_BufferRead(score, SCORE_ADDER, 8);
	if (score[0] == SCORE_FLAG)
	{
		if(score[1] > 999 || score[1] <= 0)
		{
			score[1] = 999;
			SPI_FLASH_SectorErase(SCORE_ADDER);
			SPI_FLASH_BufferWrite(score, SCORE_ADDER, 8);
		}
//		printf("yes\n");
	}
	else
	{
		score[1] = 999;
		score[0] = 0xCCCCCCCC;
		SPI_FLASH_SectorErase(SCORE_ADDER);
		SPI_FLASH_BufferWrite(score, SCORE_ADDER, 8);
	}
	SPI_FLASH_BufferRead(score, SCORE_ADDER, 8);
//	printf("%x, %d\n", score[0], score[1]);
	maze.best = score[1];

	int m[600] = {
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,0,
				0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,
				0,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
				0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,
				0,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,
				0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,
				0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,
				0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,
				0,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,
				0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,
				0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,
				0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,
				0,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,
				0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,
				0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,
				0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,3,0,0,
				0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
			};

	maze.step = 0;

	maze.player[0] = 2;
	maze.player[1] = 2;

	maze.enter[0] = 2;
	maze.enter[1] = 2;

	maze.exit[0] = 17;
	maze.exit[1] = 27;

	for(int i=0; i<MAZE_X; i++)
	{
		for (int j=0; j<MAZE_Y; j++)
		{
//			if(i==0 || j==0 || i==MAZE_X-1 || j==MAZE_Y-1){
//				maze.map[i][j] = WALL_S;
//			}else{
//				maze.map[i][j] = ROAD_S;
//			}
			maze.map[i][j] = m[i*30+j];
		}
	}
//	maze.map[maze.enter[0]][maze.enter[1]] = ENTER_S;
//	maze.map[maze.exit[0]][maze.exit[1]] = EXIT_S;

}

void MAZE_PKAYER_Move(uint8_t direct)
{
	switch (direct){
		case MOVE_UP:
		{
			if (maze.player[1]-1 < 0) break;
			else if (maze.map[maze.player[0]][maze.player[1]-1] == WALL_S) break;
			else if (maze.map[maze.player[0]][maze.player[1]-1] == ROAD_S
					|| maze.map[maze.player[0]][maze.player[1]-1] == EXIT_S
					|| maze.map[maze.player[0]][maze.player[1]-1] == ENTER_S
					)
			{
				maze.step++;
				maze.player[1]--;
			}
			break;
		}
		case MOVE_DOWN:
		{
			if (maze.player[1]+1 >= MAZE_Y) break;
			else if (maze.map[maze.player[0]][maze.player[1]+1] == WALL_S) break;
			else if (maze.map[maze.player[0]][maze.player[1]+1] == ROAD_S
					|| maze.map[maze.player[0]][maze.player[1]+1] == ENTER_S
					|| maze.map[maze.player[0]][maze.player[1]+1] == EXIT_S
					)
			{
				maze.step++;
				maze.player[1]++;
			}
			break;
		}
		case MOVE_LEFT:
		{
			if (maze.player[0]-1 < 0) break;
			else if (maze.map[maze.player[0]-1][maze.player[1]] == WALL_S) break;
			else if (maze.map[maze.player[0]-1][maze.player[1]] == ROAD_S
					|| maze.map[maze.player[0]-1][maze.player[1]] == ENTER_S
					|| maze.map[maze.player[0]-1][maze.player[1]] == EXIT_S
					)
			{
				maze.step++;
				maze.player[0]--;
			}
			break;
		}
		case MOVE_RIGHT:
		{
			if (maze.player[0]+1 >= MAZE_Y) break;
			else if (maze.map[maze.player[0]+1][maze.player[1]] == WALL_S) break;
			else if (maze.map[maze.player[0]+1][maze.player[1]] == ROAD_S
					|| maze.map[maze.player[0]+1][maze.player[1]] == ENTER_S
					|| maze.map[maze.player[0]+1][maze.player[1]] == EXIT_S
					)
			{
				maze.step++;
				maze.player[0]++;
			}
			break;
		}
		default: break;

	}
	if (maze.step > 999)
	{
		MAZE_PLAYER_Restart();
	}
//	LCD_MAZE_Refresh();

}

void MAZE_CHECK(void)
{
	switch(ui_stat)
	{
		case PLAY_UI:
		{
			if (maze.player[0] == maze.exit[0] && maze.player[1] == maze.exit[1])
			{
				LCD_SetColors(RED, WHITE);
				MAZE_UI_Change(WIN_UI);
				if (maze.step < maze.best)
				{
					score[1] = maze.step;
					score[0] = 0xCCCCCCCC;
					SPI_FLASH_SectorErase(SCORE_ADDER);
					SPI_FLASH_BufferWrite(score, SCORE_ADDER, 8);
				}
				LCD_WIN_Draw();
			}
			break;
		}
	}
}

void MAZE_PLAYER_Restart()
{
	maze.player[0] = maze.enter[0];
	maze.player[1] = maze.enter[1];
	maze.step = 0;
}


void PLAY_UI_HandelDown(int16_t x, int16_t y)
{
	if (x>=UP_BUTTON_X && x<=UP_BUTTON_X+BUTTON_WIDTH && y>=UP_BUTTON_Y && y<+UP_BUTTON_Y+BUTTON_HEIGHT)
	{
		LCD_MAZE_BUTTON_Down(UP_BUTTON);
	}
	else if(x>=DOWN_BUTTON_X && x<=DOWN_BUTTON_X+BUTTON_WIDTH && y>=DOWN_BUTTON_Y && y<+DOWN_BUTTON_Y+BUTTON_HEIGHT)
	{
		LCD_MAZE_BUTTON_Down(DOWN_BUTTON);
	}
	else if(x>=LEFT_BUTTON_X && x<=LEFT_BUTTON_X+BUTTON_WIDTH && y>=LEFT_BUTTON_Y && y<+LEFT_BUTTON_Y+BUTTON_HEIGHT)
	{
		LCD_MAZE_BUTTON_Down(LEFT_BUTTON);
	}
	else if(x>=RIGHT_BUTTON_X && x<=RIGHT_BUTTON_X+BUTTON_WIDTH && y>=RIGHT_BUTTON_Y && y<+RIGHT_BUTTON_Y+BUTTON_HEIGHT)
	{
		LCD_MAZE_BUTTON_Down(RIGHT_BUTTON);
	}
	else if(x>=RESTART_BUTTON_X && x<=RESTART_BUTTON_X+BUTTON_WIDTH && y>=RESTART_BUTTON_Y && y<+RESTART_BUTTON_Y+BUTTON_HEIGHT)
	{
		LCD_MAZE_BUTTON_Down(RESTART_BUTTON);
	}
	else
	{
		LCD_MAZE_BUTTON_Down(NO_BUTTON);
	}
}

void PLAY_UI_HandelUp(int16_t x, int16_t y)
{
	if (x>=UP_BUTTON_X && x<=UP_BUTTON_X+BUTTON_WIDTH && y>=UP_BUTTON_Y && y<+UP_BUTTON_Y+BUTTON_HEIGHT)
	{
		MAZE_PKAYER_Move(MOVE_UP);
		HAL_TIM_Base_Start_IT(&htim6);
		BEEP_Up;

	}
	else if(x>=DOWN_BUTTON_X && x<=DOWN_BUTTON_X+BUTTON_WIDTH && y>=DOWN_BUTTON_Y && y<+DOWN_BUTTON_Y+BUTTON_HEIGHT)
	{
		MAZE_PKAYER_Move(MOVE_DOWN);
		HAL_TIM_Base_Start_IT(&htim6);
		BEEP_Up;
	}
	else if(x>=LEFT_BUTTON_X && x<=LEFT_BUTTON_X+BUTTON_WIDTH && y>=LEFT_BUTTON_Y && y<+LEFT_BUTTON_Y+BUTTON_HEIGHT)
	{
		MAZE_PKAYER_Move(MOVE_LEFT);
		HAL_TIM_Base_Start_IT(&htim6);
		BEEP_Up;
	}
	else if(x>=RIGHT_BUTTON_X && x<=RIGHT_BUTTON_X+BUTTON_WIDTH && y>=RIGHT_BUTTON_Y && y<+RIGHT_BUTTON_Y+BUTTON_HEIGHT)
	{
		MAZE_PKAYER_Move(MOVE_RIGHT);
		HAL_TIM_Base_Start_IT(&htim6);
		BEEP_Up;
	}
	else if(x>=RESTART_BUTTON_X && x<=RESTART_BUTTON_X+BUTTON_WIDTH && y>=RESTART_BUTTON_Y && y<+RESTART_BUTTON_Y+BUTTON_HEIGHT)
	{
		MAZE_PLAYER_Restart();
		HAL_TIM_Base_Start_IT(&htim6);
		BEEP_Up;
	}
	else
	{
//		LCD_MAZE_BUTTON_Down(NO_BUTTON);
	}
	LCD_MAZE_Refresh();
}

void WIN_UI_HandelDown(int16_t x, int16_t y)
{
	if(x>=RESTART_BUTTON_X && x<=RESTART_BUTTON_X+BUTTON_WIDTH && y>=RESTART_BUTTON_Y && y<+RESTART_BUTTON_Y+BUTTON_HEIGHT)
	{
		LCD_MAZE_BUTTON_Down(RESTART_BUTTON);
	}
	else
	{
		LCD_MAZE_BUTTON_Down(NO_BUTTON);
	}
}

void WIN_UI_HandelUp(int16_t x, int16_t y)
{
	if(x>=RESTART_BUTTON_X && x<=RESTART_BUTTON_X+BUTTON_WIDTH && y>=RESTART_BUTTON_Y && y<+RESTART_BUTTON_Y+BUTTON_HEIGHT)
	{
		MAZE_PLAYER_Restart();
		HAL_TIM_Base_Start_IT(&htim6);
		BEEP_Up;
		MAZE_UI_Change(PLAY_UI);
		MAZE_INIT();
		LCD_MAZE_Refresh();
	}
	else
	{
//		LCD_MAZE_BUTTON_Down(NO_BUTTON);
	}


}

void MAZE_UI_Change(int stat)
{
	ui_stat = stat;
}

void WELCOM_UI_HandelUp()
{
	MAZE_UI_Change(PLAY_UI);
	HAL_TIM_Base_Start_IT(&htim6);
	BEEP_Up;
	LCD_MAZE_Refresh();
}


void MAZE_UI_HandelDown(int16_t x, int16_t y)
{

	switch (ui_stat)
	{
		case WELCOME_UI:
		{
			break;
		}
		case PLAY_UI:
		{
			PLAY_UI_HandelDown(x, y);
			break;
		}
		case WIN_UI:
		{
			WIN_UI_HandelDown(x, y);
		}
	}
}

void MAZE_UI_HandelUp(int16_t x, int16_t y)
{

	switch (ui_stat)
	{
		case WELCOME_UI:
		{
			WELCOM_UI_HandelUp();
			break;
		}
		case PLAY_UI:
		{
			PLAY_UI_HandelUp(x, y);
			break;
		}
		case WIN_UI:
		{
			WIN_UI_HandelUp(x, y);
		}
	}
}



