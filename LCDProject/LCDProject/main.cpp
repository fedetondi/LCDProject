#include "phase1.h"
#include "hitachiLCD.h"

using namespace std;
#include <string>

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
		Sleep(500);
		display << "bajo";
		Sleep(2000);
		display.lcdMoveCursorUp();
		display << "subo";
	}
	else
	{
		cout << "Display no inicializado" << endl;
	}
	return 0;
}