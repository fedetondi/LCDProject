#include "phase1.h"


FT_HANDLE* FT_LCD::lcdInit(int iDevice)
{
	FT_HANDLE lcdHandle;
	/*std::chrono::seconds MaxTime(CONNECTING_TIME);/*The display has a settling time after the physical connection so the attempt to connect
	will be done for a few seconds

	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::chrono::time_point<std::chrono::system_clock> current = start;*/

	while (status != FT_OK /*&& ((current - start) < MaxTime)*/)//loop till succesful connection o max connecting time is exceeded
	{
		status = FT_OpenEx((void *)MY_LCD_DESCRIPTION, FT_OPEN_BY_DESCRIPTION, &lcdHandle);

		if (status == FT_OK)
		{
			UCHAR Mask = 0xFF;	//Selects all FTDI pins.
			UCHAR Mode = 1; 	// Set asynchronous bit-bang mode
			if (FT_SetBitMode(lcdHandle, Mask, Mode) == FT_OK)	// Sets LCD as asynch bit mode. Otherwise it doesn't work.
			{
				//Finally executes the action "write to LCD"...
				if (lcdWriteDR(&lcdHandle, ) == true)
				{
					//If success continue with the program (...)
				}
				else
					printf("Error writing to the LCD\n");
			}
			else
				printf("Couldn't configure LCD\n");

			FT_Close(lcdHandle);
		}
		//current = std::chrono::system_clock::now();
	}
}

bool FT_LCD::lcdWriteDR(FT_HANDLE * deviceHandler, BYTE valor)
{
	BYTE temp = valor & MSN;	//me quedo con la parte alta del nybble
	temp = temp | LCD_RS_ON;		
	if (lcdWriteNybble(deviceHandler, temp) == true)
	temp = ((valor & LSN) << 4) & MSN;
	temp = temp | LCD_RS_ON;
	lcdWriteNybble(deviceHandler, temp);
}

bool FT_LCD::lcdWriteIR(FT_HANDLE * deviceHandler, BYTE valor)
{
	BYTE temp = valor & MSN;
	temp = temp | LCD_RS_OFF;	//register select para IR
	if (lcdWriteNybble(deviceHandler, temp) == true)
	{
		temp = ((valor & LSN) << 4) & MSN;
		temp = temp | LCD_RS_OFF;
		if (lcdWriteNybble(deviceHandler, temp) == true)
		{
			return true;
		}
	}
	return false;
}

bool FT_LCD::lcdWriteNybble(FT_HANDLE *deviceHandler, BYTE valor)
{
	BYTE temp = valor & (~PORT_P0);	//pongo el bit E en bajo nivel...  fijarse que pasa con el casteo entre int del define y el unsigned char, seria 0XFE
	status = FT_Write(deviceHandler, &temp, sizeof(BYTE), &sizeSent);
	if (status == FT_OK)
	{
		Sleep(1);
		temp = valor | PORT_P0;		//prendo el bit del enable
		status = FT_Write(deviceHandler, &temp, sizeof(BYTE), &sizeSent);
		if (status == FT_OK)
		{
			Sleep(3);
			temp = valor & (~PORT_P0);	//apago el enable para terminar de tomar el dato
			status = FT_Write(deviceHandler, &temp, sizeof(BYTE), &sizeSent);
			if (status == FT_OK)
			{
				Sleep(1);
				return true;
			}
		}
	}
	return false;
}
