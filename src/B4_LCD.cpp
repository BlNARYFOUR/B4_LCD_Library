
/*
 * Author:        BinaryFour
 * Description:   Basic Library for Arduino LCD screen;
 *
 */



#include "B4_LCD.h"



const static byte B4Lcd::CUSTOM_CHARS[][8] = {
  {
    B00100,
    B10110,
    B01101,
    B00110,
    B00110,
    B01101,
    B10110,
    B00100
  }
};

const static byte B4Lcd::CHAR_BLOCK = (byte) 255;
const static byte B4Lcd::CHAR_BLUETOOTH = (byte) 0;

B4Lcd::B4Lcd(LiquidCrystal& lcd) : _lcd(lcd) {}
B4Lcd::B4Lcd(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) : _lcd(rs, enable, d4, d5, d6, d7) {}
B4Lcd::B4Lcd(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) : _lcd(rs, rw, enable, d4, d5, d6, d7) {}
B4Lcd::B4Lcd(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) : _lcd(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7) {}
B4Lcd::B4Lcd(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) : _lcd(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7) {}

void B4Lcd::begin(uint16_t cols, uint16_t rows) {
	_cols = cols;
	_rows = rows;
	_lcd.begin(cols, rows);
}

LiquidCrystal& B4Lcd::getLiquidCrystal() { return _lcd; };

void B4Lcd::loadCustomChars() {
  for(short i = 0; i < sizeof(B4Lcd::CUSTOM_CHARS)/sizeof(*B4Lcd::CUSTOM_CHARS); i++) {
    _lcd.createChar(i, B4Lcd::CUSTOM_CHARS[i]);
  }
}

void B4Lcd::init(uint16_t cols = 16, uint16_t rows = 2) {
	begin(cols, rows);
	loadCustomChars();
}

void B4Lcd::clearRow(uint16_t row) {
  _lcd.setCursor(0, row);
  _lcd.print("                ");
}

void B4Lcd::clearAnimate(uint16_t _delay) {
	for(uint16_t i = 0; i < _cols / 2 + 1; i++) {
		delay(_delay);
		for(uint16_t j = 0; j < _rows; j++) {
			_lcd.setCursor(i, j);
			_lcd.write(CHAR_BLOCK);
			_lcd.setCursor(_cols - i - 1, j);
			_lcd.write(CHAR_BLOCK);
		}
	}
	for(uint16_t i = 0; i < _cols / 2 + 1; i++) {
		delay(_delay);
		for(uint16_t j = 0; j < _rows; j++) {
			_lcd.setCursor(i, j);
			_lcd.write(' ');
			_lcd.setCursor(_cols - i - 1, j);
			_lcd.write(' ');
		}
	}
}

void B4Lcd::showPaddingLeft(String str) {
  if(str.length() <= 0) {
    return;
  }
  
  short paddingLength = (_cols - str.length()) / 2;
  
  for(short i = 0; i < paddingLength; i++) {
    _lcd.print(' ');
  }
}

void B4Lcd::showPaddingRight(String str) {
  if(str.length() <= 0) {
    return;
  }
  
  short paddingLength = _cols - (_cols - str.length()) / 2;
  
  for(short i = 0; i < paddingLength; i++) {
    _lcd.print(' ');
  }
}

void B4Lcd::format(String str, char toReplace, char replacedBy) {
	unsigned short index = str.indexOf(toReplace);
	_lcd.print(str.substring(0, index));
	_lcd.write(replacedBy);
	_lcd.print(str.substring(index + 1));
}

void B4Lcd::formatCenter(uint16_t row, String str, char toReplace, char replacedBy) {
	_lcd.setCursor(0, row);
	showPaddingLeft(str);
	format(str, toReplace, replacedBy);
	showPaddingRight(str);
}

void B4Lcd::center(String str, uint16_t row) {
	_lcd.setCursor(0, row);
	showPaddingLeft(str);
	_lcd.print(str);
	showPaddingRight(str);
}

void B4Lcd::showLoading(uint16_t row, char loadChar, uint16_t _delay, bool clear = true, bool rightToLeft = false) {
	if(clear) clearRow(row);
	_lcd.setCursor(0, row);
  
	for(uint16_t i = 0; i < _cols; i++) {
		if(rightToLeft) _lcd.setCursor(_cols - i - 1, row);
		delay(_delay);
		_lcd.write(loadChar);
	}
}

