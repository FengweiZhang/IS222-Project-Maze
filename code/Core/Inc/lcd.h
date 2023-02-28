#ifndef INC_LCD_H_
#define INC_LCD_H_


#include "main.h"
#include "fonts.h"
#include "maze.h"

#include <stdio.h>

/* our code begin */
#define MAZE_START_X 20
#define MAZE_START_Y 20

#define STEP_X	170
#define STEP_Y	20

#define BEST_X	170
#define BEST_Y	70

#define RESTART_BUTTON	6
#define RESTART_BUTTON_X STEP_X
#define RESTART_BUTTON_Y 150



#define CELL_SIZE	7

#define UP_BUTTON	1
#define UP_BUTTON_X	(20+BUTTON_WIDTH+10)
#define UP_BUTTON_Y	(MAZE_START_Y+MAZE_Y*CELL_SIZE+10)

#define DOWN_BUTTON	2
#define DOWN_BUTTON_X	(20+BUTTON_WIDTH+10)
#define DOWN_BUTTON_Y	(MAZE_START_Y+MAZE_Y*CELL_SIZE+20+BUTTON_HEIGHT)

#define LEFT_BUTTON	3
#define LEFT_BUTTON_X	20
#define LEFT_BUTTON_Y	(MAZE_START_Y+MAZE_Y*CELL_SIZE+30)

#define RIGHT_BUTTON	4
#define RIGHT_BUTTON_X	(20+BUTTON_WIDTH*2+10+10)
#define RIGHT_BUTTON_Y	(MAZE_START_Y+MAZE_Y*CELL_SIZE+30)


#define NO_BUTTON	5



#define BUTTON_WIDTH	60
#define BUTTON_HEIGHT	30


#define WIN_X	LEFT_BUTTON_X
#define WIN_Y	UP_BUTTON_Y+15

#define		LCD_Clear(a,b,c,d)	ILI9341_Clear(a,b,c,d)




// 支持HAL库
#define GPIO_ResetBits(GPIOx, PIN) HAL_GPIO_WritePin(GPIOx, PIN, GPIO_PIN_RESET)
#define GPIO_SetBits(GPIOx, PIN) HAL_GPIO_WritePin(GPIOx, PIN, GPIO_PIN_SET)

/* our code end */



/******************************* ILI9341 显示屏的 FSMC 参数定义 ***************************/
//FSMC_Bank1_NORSRAM用于LCD命令操作的地址
#define      FSMC_Addr_ILI9341_CMD         ( ( uint32_t ) 0x60000000 )

//FSMC_Bank1_NORSRAM用于LCD数据操作的地址
#define      FSMC_Addr_ILI9341_DATA        ( ( uint32_t ) 0x60020000 )

//由片选引脚决定的NOR/SRAM块
#define      FSMC_Bank1_NORSRAMx           FSMC_Bank1_NORSRAM1

/******************************* ILI9341 显示屏8080通讯引脚定义 ***************************/
/******控制信号线******/
//片选，选择NOR/SRAM块
#define      ILI9341_CS_CLK                RCC_APB2Periph_GPIOD
#define      ILI9341_CS_PORT               GPIOD
#define      ILI9341_CS_PIN                GPIO_PIN_7

//DC引脚，使用FSMC的地址信号控制，本引脚决定了访问LCD时使用的地址
//PD11为FSMC_A16
#define      ILI9341_DC_CLK                RCC_APB2Periph_GPIOD
#define      ILI9341_DC_PORT               GPIOD
#define      ILI9341_DC_PIN                GPIO_PIN_11

//写使能
#define      ILI9341_WR_CLK                RCC_APB2Periph_GPIOD
#define      ILI9341_WR_PORT               GPIOD
#define      ILI9341_WR_PIN                GPIO_PIN_5

//读使能
#define      ILI9341_RD_CLK                RCC_APB2Periph_GPIOD
#define      ILI9341_RD_PORT               GPIOD
#define      ILI9341_RD_PIN                GPIO_PIN_4

//复位引脚
#define      ILI9341_RST_CLK               RCC_APB2Periph_GPIOE
#define      ILI9341_RST_PORT              GPIOE
#define      ILI9341_RST_PIN               GPIO_PIN_1

//背光引脚
#define      ILI9341_BK_CLK                RCC_APB2Periph_GPIOD
#define      ILI9341_BK_PORT               GPIOD
#define      ILI9341_BK_PIN                GPIO_PIN_12


/********数据信号线***************/
#define      ILI9341_D0_CLK                RCC_APB2Periph_GPIOD
#define      ILI9341_D0_PORT               GPIOD
#define      ILI9341_D0_PIN                GPIO_PIN_14

#define      ILI9341_D1_CLK                RCC_APB2Periph_GPIOD
#define      ILI9341_D1_PORT               GPIOD
#define      ILI9341_D1_PIN                GPIO_PIN_15

#define      ILI9341_D2_CLK                RCC_APB2Periph_GPIOD
#define      ILI9341_D2_PORT               GPIOD
#define      ILI9341_D2_PIN                GPIO_PIN_0

#define      ILI9341_D3_CLK                RCC_APB2Periph_GPIOD
#define      ILI9341_D3_PORT               GPIOD
#define      ILI9341_D3_PIN                GPIO_PIN_1

#define      ILI9341_D4_CLK                RCC_APB2Periph_GPIOE
#define      ILI9341_D4_PORT               GPIOE
#define      ILI9341_D4_PIN                GPIO_PIN_7

#define      ILI9341_D5_CLK                RCC_APB2Periph_GPIOE
#define      ILI9341_D5_PORT               GPIOE
#define      ILI9341_D5_PIN                GPIO_PIN_8

#define      ILI9341_D6_CLK                RCC_APB2Periph_GPIOE
#define      ILI9341_D6_PORT               GPIOE
#define      ILI9341_D6_PIN                GPIO_PIN_9

#define      ILI9341_D7_CLK                RCC_APB2Periph_GPIOE
#define      ILI9341_D7_PORT               GPIOE
#define      ILI9341_D7_PIN                GPIO_PIN_10

#define      ILI9341_D8_CLK                RCC_APB2Periph_GPIOE
#define      ILI9341_D8_PORT               GPIOE
#define      ILI9341_D8_PIN                GPIO_PIN_11

#define      ILI9341_D9_CLK                RCC_APB2Periph_GPIOE
#define      ILI9341_D9_PORT               GPIOE
#define      ILI9341_D9_PIN                GPIO_PIN_12

#define      ILI9341_D10_CLK                RCC_APB2Periph_GPIOE
#define      ILI9341_D10_PORT               GPIOE
#define      ILI9341_D10_PIN                GPIO_PIN_13

#define      ILI9341_D11_CLK                RCC_APB2Periph_GPIOE
#define      ILI9341_D11_PORT               GPIOE
#define      ILI9341_D11_PIN                GPIO_PIN_14

#define      ILI9341_D12_CLK                RCC_APB2Periph_GPIOE
#define      ILI9341_D12_PORT               GPIOE
#define      ILI9341_D12_PIN                GPIO_PIN_15

#define      ILI9341_D13_CLK                RCC_APB2Periph_GPIOD
#define      ILI9341_D13_PORT               GPIOD
#define      ILI9341_D13_PIN                GPIO_PIN_8

#define      ILI9341_D14_CLK                RCC_APB2Periph_GPIOD
#define      ILI9341_D14_PORT               GPIOD
#define      ILI9341_D14_PIN                GPIO_PIN_9

#define      ILI9341_D15_CLK                RCC_APB2Periph_GPIOD
#define      ILI9341_D15_PORT               GPIOD
#define      ILI9341_D15_PIN                GPIO_PIN_10

/*************************************** 调试预用 ******************************************/
#define      DEBUG_DELAY()

/***************************** ILI934 显示区域的起始坐标和总行列数 ***************************/
#define      ILI9341_DispWindow_X_Star		    0     //起始点的X坐标
#define      ILI9341_DispWindow_Y_Star		    0     //起始点的Y坐标

#define 			ILI9341_LESS_PIXEL	  							240			//液晶屏较短方向的像素宽度
#define 			ILI9341_MORE_PIXEL	 								320			//液晶屏较长方向的像素宽度




//根据液晶扫描方向而变化的XY像素宽度
//调用ILI9341_GramScan函数设置方向时会自动更改
extern uint16_t LCD_X_LENGTH,LCD_Y_LENGTH;

//液晶屏扫描模式
//参数可选值为0-7
extern uint8_t LCD_SCAN_MODE;





/******************************* 定义 ILI934 显示屏常用颜色 ********************************/
#define      BACKGROUND		                BLACK   //默认背景颜色

#define      WHITE		 		                  0xFFFF	   //白色
#define      BLACK                         0x0000	   //黑色
#define      GREY                          0xF7DE	   //灰色
#define      BLUE                          0x001F	   //蓝色
#define      BLUE2                         0x051F	   //浅蓝色
#define      RED                           0xF800	   //红色
#define      MAGENTA                       0xF81F	   //红紫色，洋红色
#define      GREEN                         0x07E0	   //绿色
#define      CYAN                          0x7FFF	   //蓝绿色，青色
#define      YELLOW                        0xFFE0	   //黄色
#define      BRED                          0xF81F
#define      GRED                          0xFFE0
#define      GBLUE                         0x07FF

#define		M_GREY		0x8410

/******************************* 定义 ILI934 常用命令 ********************************/
#define      CMD_SetCoordinateX		 		    0x2A	     //设置X坐标
#define      CMD_SetCoordinateY		 		    0x2B	     //设置Y坐标
#define      CMD_SetPixel		 		          0x2C	     //填充像素


/********************************** 声明 ILI934 函数 ***************************************/
void                     ILI9341_Init                    ( void );
void                     ILI9341_Rst                     ( void );
void                     ILI9341_BackLed_Control         ( FunctionalState enumState );
void                     ILI9341_GramScan                ( uint8_t ucOtion );
void                     ILI9341_OpenWindow              ( uint16_t usX, uint16_t usY, uint16_t usWidth, uint16_t usHeight );
void                     ILI9341_Clear                   ( uint16_t usX, uint16_t usY, uint16_t usWidth, uint16_t usHeight );
void    ILI9341_SetPointPixel           ( uint16_t usX, uint16_t usY );
uint16_t     ILI9341_GetPointPixel           ( uint16_t usX , uint16_t usY );
void    ILI9341_DrawLine                ( uint16_t usX1, uint16_t usY1, uint16_t usX2, uint16_t usY2 );
void	ILI9341_DrawRectangle           ( uint16_t usX_Start, uint16_t usY_Start, uint16_t usWidth, uint16_t usHeight,uint8_t ucFilled );
void    ILI9341_DrawCircle              ( uint16_t usX_Center, uint16_t usY_Center, uint16_t usRadius, uint8_t ucFilled );
void    ILI9341_DispChar_EN             ( uint16_t usX, uint16_t usY, const char cChar );
void    ILI9341_DispStringLine_EN      ( uint16_t line, char * pStr );
void	ILI9341_DispString_EN      			( uint16_t usX, uint16_t usY, char * pStr );
void	ILI9341_DispString_EN_YDir 		(   uint16_t usX,uint16_t usY ,  char * pStr );

void	LCD_SetFont		(sFONT *fonts);
sFONT	*LCD_GetFont	(void);
void	LCD_ClearLine	(uint16_t Line);
void	LCD_SetBackColor	(uint16_t Color);
void	LCD_SetTextColor	(uint16_t Color)	;
void	LCD_SetColors		(uint16_t TextColor, uint16_t BackColor);
void	LCD_GetColors		(uint16_t *TextColor, uint16_t *BackColor);



/* our code begin */

void	LCD_WELCOME_Draw();

void 	LCD_WIN_Draw();

void 	LCD_MAZE_Refresh();
void	LCD_MAZE_DrawMap();
void	LCD_MAZE_DrawPlayer();
void	LCD_MAZE_DrawButton();
void	LCD_MAZE_DrawStep();
void	LCD_MAZE_DrawRestart();
void 	LCD_MAZE_DrawBest();

void 	LCD_MAZE_BUTTON_Down(uint8_t type);

/* our code end */

#endif /* INC_LCD_H_ */
