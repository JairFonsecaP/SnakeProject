#include "ConsoleWriter.h"
using utility::ConsoleWriter;

void program();

int main()
{
	program();
	return 0;
}

void program()
{
	ConsoleWriter ventana = ConsoleWriter();
	ventana.setWindowSize(200, 50);
	ventana.drawRectangle(20, 10, 70, 40);


	
}