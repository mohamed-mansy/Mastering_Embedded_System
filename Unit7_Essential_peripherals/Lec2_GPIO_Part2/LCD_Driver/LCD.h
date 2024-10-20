/****************************************************************************************************
 * 	FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------
 *  File:			lcd.h
 *
 *  DESCRIPTION:    Header file for the LCD driver
 *
 *  -------------------------------------------------------------------------------------------------
 *  Author: 		Mohamed_Ayman
 ***************************************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "DIO_Types.h"
#include "std_Types.h"

/****************************************************************************************************
 *											Definitions
 ***************************************************************************************************/

#define LCD_BIT_MODE       		4

#define LCD_RS_PORT_ID          PORTA_ID
#define LCD_RS_PIN_ID			PIN1_ID

#define LCD_E_PORT_ID			PORTA_ID
#define LCD_E_PIN_ID			PIN2_ID

#if(LCD_BIT_MODE == 4)
#define LCD_DATA_PORT_ID		PORTA_ID
#define LCD_DATA_PIN0_ID		PIN3_ID
#define LCD_DATA_PIN1_ID		PIN4_ID
#define LCD_DATA_PIN2_ID		PIN5_ID
#define LCD_DATA_PIN3_ID		PIN6_ID

#elif(LCD_BIT_MODE == 8)
#define LCD_DATA_PORT_ID		PORTB_ID
#endif


/*LCD commands */
#define LCD_CLEAR_SCREEN 				0x01
#define LCD_GO_TO_HOME 					0x02
#define LCD_TWO_LINES_8_MODE 			0x38
#define LCD_TWO_lines_4_mode 			0x28
#define LCD_CURSOR_OFF 					0x0C
#define LCD_CURSOR_on 					0x0E
#define LCD_CURSOR_BLINK 				0x0F
#define LCD_TWO_LINES_4_BITS_MODE_INIT1	0x33
#define LCD_TWO_LINES_4_BITS_MODE_INIT2	0x32
#define LCD_CURSOR_FIRST_LINE			0x80
#define LCD_CURSOR_SECOND_LINE			0xc0

/****************************************************************************************************
 *											Functions
 ***************************************************************************************************/

void LCD_Sendcommand(uint8 command);

/*before used while(1) write this function */
void IntLCD(void);

void LCD_displayCharacter(uint8 data);

void LCD_displayString(const uint8* Str);

void LCD_integerToString(int Data);

void LCD_clearScreen(void);

void LCD_MoveCursor(uint8 Row , uint8 Col);

void LCD_displayStringRowColumn(uint8 Row , uint8 Col , const uint8* Str);

#endif
