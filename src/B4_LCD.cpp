
/*
 * Author:        BinaryFour
 * Description:   Basic Library for Arduino LCD screen;
 *
 */



#include "B4_LCD.h"



const static byte B4Lcd::CUSTOM_CHARS[][8] = {
  // CHAR_BLUETOOTH
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
  // CHAR_WIFI
  {
	B00000,
	B01110,
	B10001,
	B00100,
	B01010,
	B00000,
	B00100,
	B00000
  },
  // CHAR_GPS
  {
	B00000,
	B01110,
	B10001,
	B10101,
	B10001,
	B01010,
	B00100,
	B00000
  },
  // CHAR_LOCK
  {
	B00000,
	B01110,
	B10001,
	B10001,
	B11111,
	B11111,
	B11111,
	B00000
  },
  // CHAR_BATTERY
  {
	B01110,
	B11111,
	B11111,
	B11111,
	B11111,
	B11111,
	B11111,
	B11111
  },
  // CHAR_FONT_UP
  {
	B11111,
	B11111,
	B00000,
	B00000,
	B00000,
	B00000,
	B00000,
	B00000
  },
  // CHAR_FONT_DOWN
  {
	B00000,
	B00000,
	B00000,
	B00000,
	B00000,
	B00000,
	B11111,
	B11111
  },
  // CHAR_FONT_DUAL
  {
	B11111,
	B11111,
	B00000,
	B00000,
	B00000,
	B00000,
	B11111,
	B11111
  },
  // CHAR_LOCK_UNLOCKED
  {
	B00000,
	B01110,
	B10001,
	B10000,
	B11111,
	B11111,
	B11111,
	B00000
  },
  // CHAR_BATTERY_5
  {
	B01110,
	B10001,
	B11111,
	B11111,
	B11111,
	B11111,
	B11111,
	B11111
  },
  // CHAR_BATTERY_4
  {
	B01110,
	B10001,
	B10001,
	B11111,
	B11111,
	B11111,
	B11111,
	B11111
  },
  // CHAR_BATTERY_3
  {
	B01110,
	B10001,
	B10001,
	B10001,
	B11111,
	B11111,
	B11111,
	B11111
  },
  // CHAR_BATTERY_2
  {
	B01110,
	B10001,
	B10001,
	B10001,
	B10001,
	B11111,
	B11111,
	B11111
  },
  // CHAR_BATTERY_1
  {
	B01110,
	B10001,
	B10001,
	B10001,
	B10001,
	B10001,
	B11111,
	B11111
  },
  // CHAR_BATTERY_0
  {
	B01110,
	B10001,
	B10001,
	B10001,
	B10001,
	B10001,
	B10001,
	B11111
  },
  // CHAR_BATTERY_CHARGING
  {
	B01110,
	B11111,
	B10101,
	B10001,
	B11011,
	B11011,
	B11111,
	B11111
  },
  // CHAR_LOCK_BIG_SIDE_LEFT
  {
	B00011,
	B00111,
	B00110,
	B00110,
	B00110,
	B00110,
	B00110,
	B00110
  },
  // CHAR_LOCK_BIG_SIDE_RIGHT
  {
	B11000,
	B11100,
	B01100,
	B01100,
	B01100,
	B01100,
	B01100,
	B01100
  },
  // CHAR_LOCK_BIG_SIDE_UNLOCKED
  {
	B11000,
	B11100,
	B01100,
	B01100,
	B00000,
	B00000,
	B00000,
	B00000
  }
};

const static byte B4Lcd::CHAR_BLOCK = (byte) 255;

const static byte B4Lcd::CHAR_BLUETOOTH = (byte) 0;
const static byte B4Lcd::CHAR_WIFI = (byte) 1;
const static byte B4Lcd::CHAR_GPS = (byte) 2;
const static byte B4Lcd::CHAR_LOCK = (byte) 3;
const static byte B4Lcd::CHAR_BATTERY = (byte) 4;
const static byte B4Lcd::CHAR_FONT_UP = (byte) 5;
const static byte B4Lcd::CHAR_FONT_DOWN = (byte) 6;
const static byte B4Lcd::CHAR_FONT_DUAL = (byte) 7;
const static byte B4Lcd::CHAR_LOCK_UNLOCKED = (byte) 8;
const static byte B4Lcd::CHAR_BATTERY_5 = (byte) 9;
const static byte B4Lcd::CHAR_BATTERY_4 = (byte) 10;
const static byte B4Lcd::CHAR_BATTERY_3 = (byte) 11;
const static byte B4Lcd::CHAR_BATTERY_2 = (byte) 12;
const static byte B4Lcd::CHAR_BATTERY_1 = (byte) 13;
const static byte B4Lcd::CHAR_BATTERY_0 = (byte) 14;
const static byte B4Lcd::CHAR_BATTERY_CHARGING = (byte) 15;
const static byte B4Lcd::CHAR_LOCK_BIG_SIDE_LEFT = (byte) 16;
const static byte B4Lcd::CHAR_LOCK_BIG_SIDE_RIGHT = (byte) 17;
const static byte B4Lcd::CHAR_LOCK_BIG_SIDE_UNLOCKED = (byte) 18;

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

LiquidCrystal& B4Lcd::super() { return _lcd; };

void B4Lcd::loadCustomChars() {
  for(short i = 0; i < sizeof(B4Lcd::CUSTOM_CHARS)/sizeof(*B4Lcd::CUSTOM_CHARS) && i < 8; i++) {
    _lcd.createChar(i, B4Lcd::CUSTOM_CHARS[i]);
  }
}

void B4Lcd::init(uint16_t cols = 16, uint16_t rows = 2) {
	begin(cols, rows);
	loadCustomChars();
}

void B4Lcd::showAllCustomChars(uint16_t col, uint16_t row) {
  _lcd.setCursor(col, row);
  for(uint8_t i = 0; i < 8; i++) {
    _lcd.write((byte) i);
  }
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

void B4Lcd::fontCenter(uint16_t num, uint16_t maxDigits, uint16_t row) {
	font(num, maxDigits, (_cols - maxDigits * 3 - (maxDigits - 1) * 2) / 2, row);
}

void B4Lcd::font(uint16_t num, uint16_t maxDigits, uint16_t col, uint16_t row) {
	uint16_t centi = 1;
	uint16_t digits = 0;
	
	if(num == 0) {
		do {
			font((byte)0, col, row);
			col += 5;
		} while (0 < --maxDigits);
		
		return;
	}
	
	while (0 < num / centi) {
		centi *= 10;
		digits++;
	}
	
	do {
		font((byte)0, col, row);
		col += 5;
	} while (0 < --digits); 
	
	do {
		centi /= 10;
		uint8_t digit = num / centi;
		num -= digit * centi;
		font(digit, col, row);
		col += 5;
	} while (0 < centi); 
}

void B4Lcd::write(byte b, uint8_t col, uint8_t row) {
	_lcd.setCursor(col, row);
	if(0 <= col && col < _cols && 0 <= row && row < _rows) _lcd.write(b);
}

void B4Lcd::font(uint8_t digit, const uint8_t &col, const uint8_t &row) {
	_lcd.setCursor(col, row);
	
	switch(digit) {
		case 0:
			write(CHAR_BLOCK, col, row);
			write(CHAR_FONT_UP, col + 1, row);
			write(CHAR_BLOCK, col + 2, row);
			write(CHAR_BLOCK, col, row + 1);
			write(CHAR_FONT_DOWN, col + 1, row + 1);
			write(CHAR_BLOCK, col + 2, row + 1);
			break;
		case 1:
			write(' ', col, row);
			write(' ', col + 1, row);
			write(CHAR_BLOCK, col + 2, row);
			write(' ', col, row + 1);
			write(' ', col + 1, row + 1);
			write(CHAR_BLOCK, col + 2, row + 1);
			break;
		case 2:
			write(CHAR_FONT_DUAL, col, row);
			write(CHAR_FONT_DUAL, col + 1, row);
			write(CHAR_BLOCK, col + 2, row);
			write(CHAR_BLOCK, col, row + 1);
			write(CHAR_FONT_DUAL, col + 1, row + 1);
			write(CHAR_FONT_DUAL, col + 2, row + 1);
			break;
		case 3:
			write(CHAR_FONT_DUAL, col, row);
			write(CHAR_FONT_DUAL, col + 1, row);
			write(CHAR_BLOCK, col + 2, row);
			write(CHAR_FONT_DUAL, col, row + 1);
			write(CHAR_FONT_DUAL, col + 1, row + 1);
			write(CHAR_BLOCK, col + 2, row + 1);
			break;
		case 4:
			write(CHAR_BLOCK, col, row);
			write(CHAR_FONT_DOWN, col + 1, row);
			write(CHAR_BLOCK, col + 2, row);
			write(CHAR_FONT_UP, col, row + 1);
			write(CHAR_FONT_UP, col + 1, row + 1);
			write(CHAR_BLOCK, col + 2, row + 1);
			break;
		case 5:
			write(CHAR_BLOCK, col, row);
			write(CHAR_FONT_DUAL, col + 1, row);
			write(CHAR_FONT_DUAL, col + 2, row);
			write(CHAR_FONT_DUAL, col, row + 1);
			write(CHAR_FONT_DUAL, col + 1, row + 1);
			write(CHAR_BLOCK, col + 2, row + 1);
			break;
		case 6:
			write(CHAR_BLOCK, col, row);
			write(CHAR_FONT_DUAL, col + 1, row);
			write(CHAR_FONT_DUAL, col + 2, row);
			write(CHAR_BLOCK, col, row + 1);
			write(CHAR_FONT_DUAL, col + 1, row + 1);
			write(CHAR_BLOCK, col + 2, row + 1);
			break;
		case 7:
			write(CHAR_FONT_UP, col, row);
			write(CHAR_FONT_UP, col + 1, row);
			write(CHAR_BLOCK, col + 2, row);
			write(' ', col, row + 1);
			write(' ', col + 1, row + 1);
			write(CHAR_BLOCK, col + 2, row + 1);
			break;
		case 8:
			write(CHAR_BLOCK, col, row);
			write(CHAR_FONT_DUAL, col + 1, row);
			write(CHAR_BLOCK, col + 2, row);
			write(CHAR_BLOCK, col, row + 1);
			write(CHAR_FONT_DUAL, col + 1, row + 1);
			write(CHAR_BLOCK, col + 2, row + 1);
			break;
		case 9:
			write(CHAR_BLOCK, col, row);
			write(CHAR_FONT_DUAL, col + 1, row);
			write(CHAR_BLOCK, col + 2, row);
			write(CHAR_FONT_DUAL, col, row + 1);
			write(CHAR_FONT_DUAL, col + 1, row + 1);
			write(CHAR_BLOCK, col + 2, row + 1);
			break;
		default:
			break;
	}
	
	write(' ', col + 3, row);
	write(' ', col + 4, row);
	write(' ', col + 3, row + 1);
	write(' ', col + 4, row + 1);
}

void B4Lcd::replaceCustomChar(char toReplace, char replaceBy) {
	_lcd.createChar((uint16_t)toReplace, B4Lcd::CUSTOM_CHARS[(uint16_t)replaceBy]);
}

void B4Lcd::toggleBigLockFont() {
	static bool lockActive = false;
	if(lockActive) {
		replaceCustomChar(CHAR_FONT_DOWN, CHAR_FONT_DOWN);
		replaceCustomChar(CHAR_FONT_DUAL, CHAR_FONT_DUAL);
		replaceCustomChar(CHAR_LOCK, CHAR_LOCK);
	}
	else {
		replaceCustomChar(CHAR_FONT_DOWN, CHAR_LOCK_BIG_SIDE_LEFT);
		replaceCustomChar(CHAR_FONT_DUAL, CHAR_LOCK_BIG_SIDE_RIGHT);
		replaceCustomChar(CHAR_LOCK, CHAR_LOCK_BIG_SIDE_UNLOCKED);
	}
	lockActive = !lockActive;
}

void B4Lcd::printBigLock(bool locked = true) {
	uint16_t col = (_cols - 4) / 2;
	uint16_t row = (_rows - 2) / 2;
	write(CHAR_FONT_DOWN, col, row);
	write(CHAR_FONT_UP, col + 1, row);
	write(CHAR_FONT_UP, col + 2, row);
	if(locked)
		write(CHAR_FONT_DUAL, col + 3, row);
	else
		write(CHAR_LOCK, col + 3, row);
	write(CHAR_BLOCK, col, row + 1);
	write(CHAR_BLOCK, col + 1, row + 1);
	write(CHAR_BLOCK, col + 2, row + 1);
	write(CHAR_BLOCK, col + 3, row + 1);
}

