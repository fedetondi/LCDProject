#include "hitachiLCD.h"
#define CLEAR_DISPLAY 0x01
#define RETURN_HOME 0x02

hitachiLCD::hitachiLCD() : display(5)
{

}


hitachiLCD::~hitachiLCD()
{
}

bool hitachiLCD::lcdInitOk()
{
	if ()							//NO SE QUE VA
	{
		return true;
	}
	else
	{
		return false;
	}
}

FT_STATUS hitachiLCD::lcdGetError()
{
	return display.getStatus();
}

bool hitachiLCD::lcdClear()
{
	display.lcdWriteIR(CLEAR_DISPLAY);
	display.lcdWriteIR(RETURN_HOME);

	return false;
}

bool hitachiLCD::lcdClearToEOL()
{
	return false;
}

basicLCD & hitachiLCD::operator<<(const unsigned char c)
{
	// TODO: insert return statement here
}

basicLCD & hitachiLCD::operator<<(const unsigned char * c)
{
	// TODO: insert return statement here
}

bool hitachiLCD::lcdMoveCursorUp()
{
	return false;
}

bool hitachiLCD::lcdMoveCursorDown()
{
	return false;
}

bool hitachiLCD::lcdMoveCursorRight()
{
	return false;
}

bool hitachiLCD::lcdMoveCursorLeft()
{
	return false;
}

bool hitachiLCD::lcdSetCursorPosition(const cursorPosition pos)
{
	return false;
}

cursorPosition hitachiLCD::lcdGetCursorPosition()
{
	return cursorPosition();
}
