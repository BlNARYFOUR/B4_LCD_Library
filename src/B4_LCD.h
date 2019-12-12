
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
    const static byte CUSTOM_CHARS[3][8];
	const static byte CHAR_BLOCK;
	const static byte CHAR_BLOCK_HALF_BOTTOM;
	const static byte CHAR_BLOCK_HALF_TOP;
	const static byte CHAR_BLUETOOTH;
	
    B4Lcd(LiquidCrystal& lcd);  
    void loadCustomChars();
	void init();
	void clearLine(bool top);
	void showPaddingLeft(String str);
	void showPaddingRight(String str);
	void showLoading(String str, char loadChar, char customChar);
	void showLoading(String str, char loadChar);
	void fadeFullScreen();
	
  private:
    LiquidCrystal _lcd;
};

#endif

