#include "ConsoleWriter.h"
#include "Console.h"
#include "Random.h"

using utility::Random;
using utility::ConsoleWriter;
using utility::Console;
bool gameOver;
void program();
int appleX, appleY;

int main()
{
	program();
	return 0;
}

void program()
{
		ConsoleWriter windowGame = ConsoleWriter();
		windowGame.setCursorVisible(false);
		//windowGame.setWindowSize(200, 50);
		windowGame.drawRectangle(10, 5, 100, 10);
		windowGame.drawRectangle(10, 10, 100, 35);
	while (true)
	{
		windowGame.setCursorPosition(0, 0);
		COORD topLeft = { appleX, appleY };
		COORD bottomRight = { appleX, appleY };
		windowGame.clearRegion(topLeft, bottomRight);
		appleX = Random::getRandomInteger(10 + 1, 100 - 1);
		appleY = Random::getRandomInteger(10 + 1, 35 - 1);
		windowGame.setCharacterAtPosition(appleX, appleY, /*254*/ 64);
		Console::pause();
	}
}