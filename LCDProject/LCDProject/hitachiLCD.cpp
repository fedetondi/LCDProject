#include "hitachiLCD.h"
#define CLEAR_DISPLAY 0x01
#define RETURN_HOME 0x02
#define EOL1 16
#define EOL2 32
#define SET_DDRAM_ADD(x) ((x) | (0x80))		//porque la instruccion pide ese bit en 1

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
	bool val = false;
	if (display.lcdWriteIR(CLEAR_DISPLAY))
	{
		cadd = 1;
		val = true;
	}
	return val;
}

bool hitachiLCD::lcdClearToEOL()
{
	bool val;
	int count;
	cursorPosition initial = lcdGetCursorPosition();
	if (cadd <= EOL1)
	{
		for (count = cadd; count <= EOL1; count++)
		{
			val = display.lcdWriteDR(' ');						
		}
	}
	else
	{
		for (count = cadd; count >= EOL1 && count <= EOL2; count++)
		{
			val = display.lcdWriteDR(' ');						
		}
	}
	val = lcdSetCursorPosition(initial);
	return val;
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
	bool val = false;
	cursorPosition cursor;
	if (cadd <= EOL2 && cadd > EOL1)
	{
		cadd = cadd - 16;	
		cursor.row = 1;
		cursor.column = cadd;
		val = lcdSetCursorPosition(cursor);
	}
	return val;
}

bool hitachiLCD::lcdMoveCursorDown()			
{
	bool val = false;
	cursorPosition cursor;
	if (cadd <= EOL1)
	{
		cadd = cadd + EOL1;
		cursor.row = 2;
		cursor.column = cadd - EOL1;
		val = lcdSetCursorPosition(cursor);
	}
	return val;
}

bool hitachiLCD::lcdMoveCursorRight()			
{
	bool val = false;
	cursorPosition cursor;
	if (cadd < EOL2)
	{
		cadd++;
		if (cadd <= EOL1)
		{
			cursor.row = 1;
			cursor.column = cadd;
		}
		else
		{
			cursor.row = 2;
			cursor.column = cadd - EOL1;
		}
		val = lcdSetCursorPosition(cursor);
	}
	return val;
}

bool hitachiLCD::lcdMoveCursorLeft()			
{
	bool val = false;
	cursorPosition cursor;
	if (cadd > 1)
	{
		cadd--;
		if (cadd <= EOL1)
		{
			cursor.row = 1;
			cursor.column = cadd;
		}
		else
		{
			cursor.row = 2;
			cursor.column = cadd - EOL1;
		}
		val = lcdSetCursorPosition(cursor);
	}
	return val;
}

bool hitachiLCD::lcdSetCursorPosition(const cursorPosition pos)		
{
	bool val;
	if (pos.row == 1)
	{
		cadd = pos.column;
		val = display.lcdWriteIR(SET_DDRAM_ADD(cadd - 1));				//TENGO DUDAS ACA
	}
	else
	{
		cadd = pos.column + 16;
		val = display.lcdWriteIR(SET_DDRAM_ADD((cadd & 0x0F) + 0x40) - 1);		//TENGO DUDAS
	}
	return val;
}

cursorPosition hitachiLCD::lcdGetCursorPosition()
{
	cursorPosition pos;
	if (cadd <= EOL1)
	{
		pos.row = 1;
		pos.column = cadd;
	}
	else
	{
		pos.row = 2;
		pos.column = cadd - 16;
	}
	return pos;
}
