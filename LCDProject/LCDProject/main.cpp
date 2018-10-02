#include "hitachiLCD.h"

using namespace std;
#include <string>

/*Main de prueba de las funciones de la fase 2*/
int main(void)
{
	hitachiLCD display(5);
	if (display.lcdInitOk())
	{
		cout << "Display inicializado" << endl;
		display << "Hola" << ' ' << "Mundo";
		Sleep(1000);
		display.lcdClear();
		display << "Probando";
		display.lcdMoveCursorDown();
		Sleep(1000);
		display << "bajo";
		Sleep(2000);
		display.lcdMoveCursorUp();
		display << "subo";
		Sleep(1000);
		display.lcdClear();
		display.lcdSetCursorPosition({ 2,3 });
		display << "me muevo aca";
		Sleep(1000);
		display.lcdSetCursorPosition({1,1});
		display << "o para aca";
		Sleep(1000); 
		display.lcdClear();
		display << "Chau";
		Sleep(2000);
		display.lcdClear();
	}
	else
	{
		cout << "Display no inicializado" << endl;
	}
	return 0;
}