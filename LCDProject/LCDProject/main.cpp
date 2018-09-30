#include "phase1.h"

using namespace std;
#include <string>

int main(void)
{
	FT_LCD display(5);
	if ((display.getError()).type == NO_ERR)
	{
		display.lcdWriteDR(0X41);
		display.lcdWriteIR(CURSOR_MOVE);	//hay que fijarnos si esto no lo hace solo FT_Write y si no ver si no conviene agregarlo en el metodo IR y DR
	}
	cout << (display.getError()).detail << endl;

	return 0;
}