#pragma once

#include <iostream>
#include "ftd2xx.h"
#include<cstdio>
#include<windows.h>

#define MY_LCD_DESCRIPTION "EDA LCD 5 B"

// PINES LOGICOS DEL PUERTO PARALELO
#define PORT_P0	0
#define PORT_P1	1
#define PORT_P2	2
#define PORT_P3	3
#define PORT_P4	4
#define PORT_P5	5
#define PORT_P6	6
#define PORT_P7	7

//	MASCARAS Y FUNCIONALIDADES
#define LCD_E	(1 << PORT_P0)
#define	LCD_RS	(1 << PORT_P1)
#define	LCD_D4	(1 << PORT_P4)
#define	LCD_D5	(1 << PORT_P5)
#define	LCD_D6	(1 << PORT_P6)
#define	LCD_D7	(1 << PORT_P7)

#define MSN	0XF0	//Most Significant Nybble
#define LSN 0X0F	//Least Significant Nybble
//#define corrimiento para bits validos


//	NIVELES LOGICOS
#define LCD_E_ON	LCD_E
#define LCD_E_OFF	(LCD_E ^ LCD_E)

#define LCD_RS_ON	LCD_RS
#define LCD_RS_OFF	(LCD_RS ^ LCD_RS)

#define LCD_D4_ON	LCD_D4
#define LCD_D4_OFF	(LCD_D4 ^ LCD_D4)

#define LCD_D5_ON	LCD_D5
#define LCD_D5_OFF	(LCD_D5 ^ LCD_D5)

#define LCD_D5_ON	LCD_D5
#define LCD_D5_OFF	(LCD_D5 ^ LCD_D5)

#define LCD_D6_ON	LCD_D6
#define LCD_D6_OFF	(LCD_D6 ^ LCD_D6)

#define LCD_D7_ON	LCD_D7
#define LCD_D7_OFF	(LCD_D7 ^ LCD_D7)

//	INSTRUCCIONES
#define CLEAR_DISPLAY	0000000001b
#define RETURN_HOME		0000000010b
#define ENTRY_MODE_SET	0000000110b
#define	CURSOR_MOVE		0000010100b
#define FUNCTION_SET	0000101000b


//
typedef unsigned char BYTE;


//	PROTOTIPOS

class FT_LCD
{
public:
	/*	lcdInit
	*	Recibe:
	*	Devuelve: puntero a controlador FTDI
	*	Funcion: Inicializa el FTDI y el LCD
	*/
	FT_HANDLE	*lcdInit(int iDevice);

	/*	lcdWriteIR
	*	Recibe:		puntero al FTDI y valor de la instruccion
	*	Devuelve:	"true" en caso de exito en la escritura
	*	Funcion:	escribit un byte al IR
	*/
	bool lcdWriteIR(FT_HANDLE * deviceHandler, BYTE valor);

	/*	lcdWriteDR
	*	Recibe:		puntero al FTDI y valor del dato a mostrar
	*	Devuelve:	"true" en caso de exito en la escritura
	*	Funcion:	escribit un byte al DR
	*/
	bool lcdWriteDR(FT_HANDLE * deviceHandler, BYTE valor);

	/*	lcdWriteNybble
	*	Recibe:		puntero al FTDI y valor del dato a mostrar
	*	Devuelve:	"true" en caso de exito en la escritura
	*	Funcion:	pasarle al display en modo 4 bits el valor a mostrar, proveniente de lcdWriteDR
	*/
	bool lcdWriteNybble(FT_HANDLE *deviceHandler, BYTE valor);

	/*	lcdWriteByte
	*	Recibe:		puntero al FTDI, valor del dato a mostrar o instruccion y valor del RS
	*	Devuelve:	"true" en caso de exito en la escritura
	*	Funcion:	Sirve en modo 8 bits y si se trabaja en modo 4 bits se llama dos veces a lcdWriteNybble
	*/
	bool lcdWriteByte(FT_HANDLE * deviceHandler, BYTE value, BYTE RS);
private:
	DWORD sizeSent;
	FT_STATUS status;
};