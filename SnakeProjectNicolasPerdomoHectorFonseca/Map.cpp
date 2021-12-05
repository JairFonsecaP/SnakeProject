#include "Map.h"
using utility::Coordinate;
using utility::Strings;
using std::vector;

int const Map::BorderTop = 4;
int const Map::BorderRight = 50;
int const Map::BorderBottom = 32;
int const Map::BorderLeft = 1;

Map::Map()
	:
	topLeft(getInitialTopLeft()),
	bottomRight(getInitialBottomRight()),
	writer(),
	reader(),
	menu()
{}

void Map::initialDisplay(Player* player, Snake* snake)
{
	writer.clear();
	welcome(player);
	writer.clear();
	displayBoard();
	displayInitialSnake(snake);
}

void Map::welcome(Player* player)
{
	writer.clear();
	writer.setCursorPosition({ 5,5 });
	writer.writeLine("Welcome to snake game!");
	writer.setCursorPosition({ 5,6 });
	player->setPlayerName(reader.readWord("Please enter your name in one word"));
}

void Map::displayBoard()
{
	writer.setCursorVisible(false);
	writer.setWindowSize(BorderRight + 3, BorderBottom + 3);
	writer.drawRectangle({ BorderLeft, 1 }, { BorderRight, (BorderTop - 1) });
	writer.drawRectangle({ BorderLeft,BorderTop }, { BorderRight,BorderBottom });
}
void Map::displayInitialSnake(Snake* snake)
{
	for (size_t i = (snake->getLength() - 1); i > 0; i--)
	{
		writer.setCharacterAtPosition(snake->getBodyPoints()[i], 'O');
	}
}

void Map::updateTailSnake(Snake* snake)
{
	writer.clearRegion(snake->getTail(), snake->getTail());
}

void Map::updateHeadSnake(Snake* snake)
{
	writer.setCharacterAtPosition(snake->getHead(), 'O');
}

void Map::updateScoreAndTime(Snake* snake, Player* player)
{
	writer.setCursorPosition(2, 2);
	writer.writeLine(player->toString() + "  Length: " + Strings::integerToString(snake->getLength()));
}

void Map::displayApple(short X, short Y, char character)
{
	writer.setCharacterAtPosition(X, Y, character);
}


short Map::getNewSnakeDirection(Snake* snake)
{
	if (reader.isUpArrowPressed() && snake->getDirection() != Snake::goUp && snake->getDirection() != Snake::goDown)
		return  Snake::goUp;
	else if (reader.isRightArrowPressed() && snake->getDirection() != Snake::goLeft && snake->getDirection() != Snake::goRight)
		return Snake::goRight;
	else if (reader.isDownArrowPressed() && snake->getDirection() != Snake::goUp && snake->getDirection() != Snake::goDown)
		return Snake::goDown;
	else if (reader.isLeftArrowPressed() && snake->getDirection() != Snake::goLeft && snake->getDirection() != Snake::goRight)
		return Snake::goLeft;
	else
		return -1;
}

bool Map::playAgain()
{
	const int countOptions = 4;
	char options[countOptions] = { 'Y', 'y', 'N', 'n' };
	char response = reader.readCharacter("Do you want play again? y/n", options, 4);
	return response == 'Y' || response == 'y';
}

void Map::displayScores(vector<Score*> scores)
{
	writer.clear();
	menu.setTitle("SCORES");
	vector<std::string>toDisplay = Score::scoresToString(scores);
	menu.setOptions(toDisplay);
	writer.setWindowSize(800, 600);
	menu.displayMenu();
}


Coordinate Map::getBottomLeft()
{
	return { topLeft.X, bottomRight.Y };
}

Coordinate Map::getTopRigth()
{
	return { bottomRight.X,topLeft.Y };
}

int Map::getWidth()
{
	return bottomRight.X - topLeft.X;
}

int Map::getHeight()
{
	return bottomRight.Y - topLeft.Y;
}

int Map::getBorderTop()
{
	return BorderTop;
}

int Map::getBorderRight()
{
	return BorderRight;
}

int Map::getBorderBottom()
{
	return BorderBottom;
}

int Map::getBorderLeft()
{
	return BorderLeft;
}


int Map::getSize()
{
	return getWidth() * getHeight();
}

Coordinate Map::getInitialTopLeft()
{
	return COORD({BorderTop, BorderLeft});
}

Coordinate Map::getInitialBottomRight()
{
	return  COORD({BorderBottom, BorderRight});
}