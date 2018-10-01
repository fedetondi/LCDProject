#include "phase1.h"

using namespace std;
#include <string>

int main(void)
{
	cout << "Incializando display..." << endl;
	FT_LCD display(5);
	cout << (display.getError()).detail << endl;
	cout << "Presione Enter para continuar" << endl;
	getchar();
	if ((display.getError()).type == NO_ERR)
	{
		display.lcdWriteDR('A');
		display.lcdWriteIR(CURSOR_MOVE);	//hay que fijarnos si esto no lo hace solo FT_Write y si no ver si no conviene agregarlo en el metodo IR y DR
	}
	else
	{
		cout << "No se envio nada al display porque hubo error previo" << endl;
	}
	cout << (display.getError()).detail << endl;
	getchar();
	return 0;
}