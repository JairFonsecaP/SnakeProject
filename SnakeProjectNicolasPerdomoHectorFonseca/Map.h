#pragma once
#include"Coordinate.h"
#include "ConsoleWriter.h"
#include "ConsoleReader.h"
#include "ConsoleMenu.h"
#include "Strings.h"
#include "Snake.h"
#include "Player.h"
#include "Score.h"

class Map
{
private:
public:
	static int const BorderTop;
	static int const BorderRight;
	static int const BorderBottom;
	static int const BorderLeft;

private:
	utility::Coordinate topLeft;
	utility::Coordinate bottomRight;

	utility::ConsoleWriter writer;
	utility::ConsoleReader reader;
	utility::ConsoleMenu menu;

public:
	Map();

	void initialDisplay(Player* player, Snake* snake);
	void displayApple(short X, short y, char character);



	utility::Coordinate getTopRigth();
	utility::Coordinate getBottomLeft();
	int getSize();
	int getWidth();
	int getHeight();

	static int getBorderTop();
	static int getBorderRight();
	static int getBorderBottom();
	static int getBorderLeft();

	void updateTailSnake(Snake* snake);
	void updateHeadSnake(Snake* snake);
	void updateScoreAndTime(Snake* snake, Player* player);
	short getNewSnakeDirection(Snake* snake);
	bool playAgain();
	void displayScores(std::vector<Score*> scores);
private:
	void welcome(Player* player);
	void displayBoard();
	void displayInitialSnake(Snake* snake);
	static utility::Coordinate getInitialTopLeft();
	static utility::Coordinate getInitialBottomRight();
};