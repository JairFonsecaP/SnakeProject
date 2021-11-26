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
	ventana.setWindowSize(50, 50);

	ventana.drawRectangle(1, 1, 50, 50);
}