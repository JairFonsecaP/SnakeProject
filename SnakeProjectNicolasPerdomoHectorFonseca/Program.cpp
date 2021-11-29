#include "ConsoleWriter.h"
#include "Console.h"
#include "Random.h"
#include "Apple.h"
#include "Player.h"

using utility::Random;
using utility::ConsoleWriter;
using utility::Console;
bool gameOver;
void program();
int appleX, appleY;
int snakeX, snakeY;

int main()
{
	program();
	return 0;
}

void program()
{
	Player player;

	ConsoleWriter windowGame = ConsoleWriter();
	windowGame.setCursorVisible(false);
	windowGame.setWindowSize(200, 50);
	windowGame.drawRectangle(10, 5, 100, 9);

		
	windowGame.setCursorPosition(20, 7); //setCursorPosition To display Current Level
	windowGame.writeLine("level = ");

	
	windowGame.setCursorPosition(52, 7); //setCursorPosition To display timer
	
	windowGame.setCursorPosition(80, 7); //setCursorPosition To display score
	windowGame.writeLine("score = ");
	
		
	windowGame.drawRectangle(10, 10, 100, 35);

	player.startElapsedTime();

	while (true)
	{
		player.updateTimer();
		windowGame.setCursorPosition(0, 0);
		COORD topLeft = { appleX, appleY };
		COORD bottomRight = { appleX, appleY };
		//windowGame.clearRegion(topLeft, bottomRight);
		appleX = Random::getRandomInteger(10 + 1, 100 - 1);
		appleY = Random::getRandomInteger(10 + 1, 35 - 1);

		player.displayLevel(27, 6, 45, 8);
		player.displayTimer(52,6,86,8);

		player.timeScore();
		player.displayScore(87, 6, 99, 8);  

		windowGame.setCharacterAtPosition( appleX, appleY , /*254*/ 64);
		
		Sleep(500);

		windowGame.setCharacterAtPosition(appleX, appleY, /*254*/ ' ');
	}

}

