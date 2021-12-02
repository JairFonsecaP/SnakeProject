#include "Game.h"

using std::vector;

Game::Game()
	:writer(), reader(), apple(64), snake(), gameOver(false)//, player()
{ }

void Game::start()
{
	displayBoard();
	displayInitialSnake();
	updateApple();
	while (!gameOver)
	{	
		update();
	}
}

void Game::displayBoard()
{
	writer.setCursorVisible(false);
	writer.setWindowSize(BorderRight + 3, BorderBottom + 3);
	writer.drawRectangle({ BorderLeft, 1 }, { BorderRight, (BorderTop - 1) });
	writer.drawRectangle({ BorderLeft,BorderTop }, { BorderRight,BorderBottom });
}
void Game::displayInitialSnake()
{
	for (size_t i = (snake.getLength() - 1); i > 0; i--)
	{
		writer.setCharacterAtPosition(snake.getBodyPoints()[i], 'O');
	}
}

void Game::update()
{
	updateSnake();
	Sleep(10);
}

void Game::updateApple()
{
	apple.update();
	writer.setCharacterAtPosition(apple.getCoordinate(), apple.getCharacter());
}
bool Game::isEating()
{
	return snake.getHead() == apple.getCoordinate();
}
void Game::updateSnake()
{
	if (isEating())
	{
		updateApple();
		snake.updateEating();
	}
	else
	{
		snake.update();
		keepOnPlaying();
		if (gameOver)
			return;
	}

	writer.setCharacterAtPosition(snake.getHead(), 'O');
	for (short i = 0; i < 7; i++)
	{
		snake.setDirection(turnSnake());
		Sleep(10);
	}
	writer.clearRegion(snake.getTail(), snake.getTail());
}

int Game::getBorderTop()
{
	return BorderTop;
}

int Game::getBorderRight()
{
	return BorderRight;
}

int Game::getBorderBottom()
{
	return BorderBottom;
}

int Game::getBorderLeft()
{
	return BorderLeft;
}

short Game::turnSnake()
{
	if (reader.isShiftPressed())
		writer.pause();

	if (reader.isUpArrowPressed() && snake.getDirection() != Snake::goUp && snake.getDirection() != Snake::goDown)
		return  Snake::goUp;
	else if (reader.isRightArrowPressed() && snake.getDirection() != Snake::goLeft && snake.getDirection() != Snake::goRight)
		return Snake::goRight;
	else if (reader.isDownArrowPressed() && snake.getDirection() != Snake::goUp && snake.getDirection() != Snake::goDown)
		return Snake::goDown;
	else if (reader.isLeftArrowPressed() && snake.getDirection() != Snake::goLeft && snake.getDirection() != Snake::goRight)
		return Snake::goLeft;
	else
		return snake.getDirection();
}

void Game::keepOnPlaying()
{
	char character = writer.getCharacterAtPosition(snake.getHead());
	if (character != ' ' && snake.getHead() != apple.getCoordinate())
		gameOver = true;
}