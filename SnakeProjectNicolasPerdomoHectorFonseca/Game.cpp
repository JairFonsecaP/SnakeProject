#include "Game.h"

using std::vector;

Game::Game()
	:
	writer(), 
	reader(), 
	apple(64), 
	snake(), 
	gameOver(false), 
	player(),
	countApples(0),
	levels{1,2,3,5,8,13,21}
{  }

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
	Sleep(100/snake.getSpeed());
	player.updateTimer();
	player.timeScore();
}

void Game::updateApple()
{
	do
	{
		apple.randomizePosition();
	} while (snakeHitSelf(apple.getCoordinate()));
	writer.setCharacterAtPosition(apple.getCoordinate(), apple.getCharacter());
}

void Game::updateSnake()
{
	writer.clearRegion(snake.getTail(), snake.getTail());
	if (isEating())
	{
		countApples++;
		if (countApples % 2 == 0 && snake.getSpeed() != levels[6])
		{
			int index;
			for (short i = 0; i < 7; i++)
			{
				if (snake.getSpeed() == levels[i])
				{
					snake.setSpeed(levels[i + 1]);
					break;
				}
			}

		}
		updateApple();
		snake.moveAndGrow();
		player.incrementScore(1, snake.getSpeed());
	}
	else
	{
		snake.move();
		gameOver = hasGameEnded();
		if (gameOver)
			return;
	}

	writer.setCharacterAtPosition(snake.getHead(), 'O');
	for (short i = 0; i < 7; i++)
	{
		snake.setDirection(getNewSnakeDirection());
		Sleep(10);
	}
	writer.setCursorPosition(2, 2);
	writer.writeLine(player.toString() + "  Length: " + std::to_string(snake.getLength()));
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

short Game::getNewSnakeDirection()
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

bool Game::hasGameEnded()
{
	return snakeHitSelf(snake.getHead()) || snakeHitWall();
}

bool Game::snakeHitWall()
{
	utility::Coordinate head = snake.getHead();
	return head.X <= BorderLeft || head.X >= BorderRight
		|| head.Y <= BorderTop || head.Y >= BorderBottom;
}

bool Game::snakeHitSelf(COORD coordenate)
{
	std::vector<utility::Coordinate> bodyPoints = snake.getBodyPoints();
	for (size_t i = 0; i < snake.getLength() - 1; i++)
	{
		if (bodyPoints[i] == coordenate)
			return true;
	}
	return false;
}

bool Game::isEating()
{
	return snake.getHead() == apple.getCoordinate();
}
