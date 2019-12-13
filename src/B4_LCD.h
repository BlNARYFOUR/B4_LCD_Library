
/*
 * Author:        BinaryFour
 * Description:   Basic Library for Arduino LCD screen;
 *
 */

#ifndef B4_LCD_h
#define B4_LCD_h

#include <Arduino.h>
#include <LiquidCrystal.h>



class B4Lcd {
  public:
    const static byte CUSTOM_CHARS[][8];
	
	const static byte CHAR_BLOCK;
	
	const static byte CHAR_BLUETOOTH;
	const static byte CHAR_WIFI;
	const static byte CHAR_GPS;
	const static byte CHAR_LOCK;
	const static byte CHAR_BATTERY;
	const static byte CHAR_FONT_UP;
	const static byte CHAR_FONT_DOWN;
	const static byte CHAR_FONT_DUAL;
	
	const static byte CHAR_LOCK_UNLOCKED;
	const static byte CHAR_BATTERY_5;
	const static byte CHAR_BATTERY_4;
	const static byte CHAR_BATTERY_3;
	const static byte CHAR_BATTERY_2;
	const static byte CHAR_BATTERY_1;
	const static byte CHAR_BATTERY_0;
	const static byte CHAR_BATTERY_CHARGING;
	const static byte CHAR_LOCK_BIG_SIDE_LEFT;
	const static byte CHAR_LOCK_BIG_SIDE_RIGHT;
	const static byte CHAR_LOCK_BIG_SIDE_UNLOCKED;
	
    B4Lcd(LiquidCrystal& lcd);  
	B4Lcd(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
	B4Lcd(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    B4Lcd(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
	B4Lcd(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
	void begin(uint16_t cols, uint16_t rows);
	
	LiquidCrystal& super();
	void loadCustomChars();
	void init(uint16_t cols = 16, uint16_t rows = 2);
	void showAllCustomChars(uint16_t col, uint16_t row);
	void clearRow(uint16_t row);
	void clearAnimate(uint16_t _delay);
	void showPaddingLeft(String str);
	void showPaddingRight(String str);
	void format(String str, char toReplace, char replacedBy);
	void formatCenter(uint16_t row, String str, char toReplace, char replacedBy);
	void center(String str, uint16_t row);
	void showLoading(uint16_t row, char loadChar, uint16_t _delay, bool clear = true, bool rightToLeft = false);
	void fontCenter(uint16_t num, uint16_t maxDigits, uint16_t row);
	void font(uint16_t num, uint16_t maxDigits, uint16_t col, uint16_t row);
	void write(byte b, uint8_t col, uint8_t row);
	void font(uint8_t digit, const uint8_t &col, const uint8_t &row);
	void replaceCustomChar(char toReplace, char replaceBy);
	void toggleBigLockFont();
	void printBigLock(bool locked = true);
	
  private:
    LiquidCrystal _lcd;
	uint16_t _cols = 0, _rows = 0;
};

#endif

