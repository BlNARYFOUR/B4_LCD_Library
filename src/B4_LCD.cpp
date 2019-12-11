
/*
 * Author:        BinaryFour
 * Description:   Basic Library for Arduino LCD screen;
 *
 */



#include "B4_LCD.h"



const static byte B4Lcd::CUSTOM_CHARS[3][8] = {
  {
    B00100,
    B10110,
    B01101,
    B00110,
    B00110,
    B01101,
    B10110,
    B00100
  },
  {
	B00000,
	B00000,
	B00000,
	B00000,
	B11111,
    B11111,
	B11111,
	B11111
  },
  {
	B11111,
    B11111,
	B11111,
	B11111,
	B00000,
	B00000,
	B00000,
	B00000
  }
};

const static byte B4Lcd::CHAR_BLOCK = (byte) 255;
const static byte B4Lcd::CHAR_BLOCK_HALF_BOTTOM = (byte) 1;
const static byte B4Lcd::CHAR_BLOCK_HALF_TOP = (byte) 2;
const static byte B4Lcd::CHAR_BLUETOOTH = (byte) 0;

B4Lcd::B4Lcd(LiquidCrystal& lcd) : _lcd(lcd) {}

void B4Lcd::loadCustomChars() {
  for(short i = 0; i < sizeof(B4Lcd::CUSTOM_CHARS)/sizeof(*B4Lcd::CUSTOM_CHARS) && i < 8; i++) {
    _lcd.createChar(i, B4Lcd::CUSTOM_CHARS[i]);
  }
}

void B4Lcd::init() {
	loadCustomChars();
	_lcd.begin(16, 2);
}

void B4Lcd::clearLine(bool top) {
  _lcd.setCursor(0, 1 - top);
  _lcd.print("                ");
}

void B4Lcd::showPaddingLeft(String str) {
  if(str.length() <= 0) {
    return;
  }
  
  short paddingLength = (16 - str.length()) / 2;
  
  for(short i = 0; i < paddingLength; i++) {
    _lcd.print(' ');
  }
}

void B4Lcd::showPaddingRight(String str) {
  if(str.length() <= 0) {
    return;
  }
  
  short paddingLength = 16 - (16 - str.length()) / 2;
  
  for(short i = 0; i < paddingLength; i++) {
    _lcd.print(' ');
  }
}

void B4Lcd::showLoading(String str, char loadChar, char customChar) {
  unsigned short index = str.indexOf('@');
  _lcd.clear();
  showPaddingLeft(str);
  _lcd.print(str.substring(0, index));
  _lcd.write(customChar);
  _lcd.print(str.substring(index + 1));
  showPaddingRight(str);
  showLoading("", loadChar);
}

void B4Lcd::showLoading(String str, char loadChar) {
  _lcd.home();
  showPaddingLeft(str);
  _lcd.print(str);
  showPaddingRight(str);
  clearLine(false);
  delay(40);
  _lcd.setCursor(0, 1);
  
  for(int i = 0; i < 16; i++) {
    _lcd.write(loadChar);
    delay(40);
  }
}

void B4Lcd::fadeFullScreen() {
  
}

