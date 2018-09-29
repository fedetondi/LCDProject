#include "hitachiLCD.h"



hitachiLCD::hitachiLCD()
{
}


hitachiLCD::~hitachiLCD()
{
}

bool hitachiLCD::lcdInitOk()
{
	return false;
}

FT_STATUS hitachiLCD::lcdGetError()
{
	return FT_STATUS();
}

bool hitachiLCD::lcdClear()
{
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
