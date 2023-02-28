#include "key.h"
#include "maze.h"
#include "flash.h"
extern int32_t score[];
extern uint8_t ui_stat;

void KEY1_EXIT_Callback()
{
//	printf("KEY1 DOWN\n");
	static uint8_t stat;
	if (stat == 0)
	{
		LED_G_Up;
		LED_B_Down;
		LED_R_Down;
		stat++;
	}
	else if (stat == 1)
	{
		LED_G_Down;
		LED_B_Up;
		LED_R_Down;
		stat++;
	}
	else if (stat == 2)
	{
		LED_G_Down;
		LED_B_Down;
		LED_R_Up;
		stat = 0;
	}
	else
	{
		LED_G_Up;
		LED_B_Down;
		LED_R_Down;
		stat = 0;
	}

}

void KEY2_EXIT_Callback()
{
//	printf("KEY2 DOWN\n");
//	score ++ ;
	if (ui_stat == PLAY_UI)
	{
		uint32_t a[2] = {SCORE_FLAG, 9999};
		SPI_FLASH_SectorErase(SCORE_ADDER);
		SPI_FLASH_BufferWrite(&a,SCORE_ADDER,8);
		SPI_FLASH_BufferRead(score, SCORE_ADDER, 8);

	//	printf("%x %d\n", score[0], score[1]);
		MAZE_INIT();
		LCD_MAZE_Refresh();

	}
}
