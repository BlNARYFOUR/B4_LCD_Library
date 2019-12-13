
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
	
    B4Lcd(LiquidCrystal& lcd);  
	B4Lcd(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
	B4Lcd(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    B4Lcd(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
	B4Lcd(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
	void begin(uint16_t cols, uint16_t rows);
	
	LiquidCrystal& getLiquidCrystal();
	void loadCustomChars();
	void init(uint16_t cols = 16, uint16_t rows = 2);
	void clearRow(uint16_t row);
	void clearAnimate(uint16_t _delay);
	void showPaddingLeft(String str);
	void showPaddingRight(String str);
	void format(String str, char toReplace, char replacedBy);
	void formatCenter(uint16_t row, String str, char toReplace, char replacedBy);
	void center(String str, uint16_t row);
	void showLoading(uint16_t row, char loadChar, uint16_t _delay, bool clear = true, bool rightToLeft = false);
	
  private:
    LiquidCrystal _lcd;
	uint16_t _cols = 0, _rows = 0;
};

#endif

