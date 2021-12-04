#include "Game.h"
#include <iostream>

using std::vector;
using std::cin;

Game::Game()
	:
	writer(), 
	reader(), 
	menu(),
	apple(64), 
	snake(), 
	gameOver(false), 
	player(),
	countApples(0)
{  }

Game::~Game()
{
	for (size_t i = 0; i < scores.size() - 1; i++)
	{
		delete scores.at(i);
	}
}
void Game::start()
{
	bool play;
	do {
		writer.clear();
		welcome();
		writer.clear();
		displayBoard();
		displayInitialSnake();
		updateApple();
		while (!gameOver)
		{
			update();
		}
		scores.push_back(new Score(player.getPlayerName(), player.getScore(), player.getLevel()));
		displayScores();
		play = playAgain();
	} while (play);
}
void Game::welcome()
{
	writer.clear();
	writer.setCursorPosition({ 5,5 });
	writer.writeLine("Welcome to snake game!");
	writer.setCursorPosition({ 5,6 });
	player.setPlayerName(reader.readWord("Please enter your name in one word"));
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
	Sleep(45/snake.getSpeed());
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
		if (countApples % 5 == 0 && snake.getSpeed() != 15)
		{
			int level = player.getLevel();
			level++;
			player.setLevel(level);
			snake.setSpeed(level);
		}
		updateApple();
		snake.moveAndGrow();
		player.incrementScore();
	}
	else
	{
		snake.move();
		gameOver = hasGameEnded();
		if (gameOver)
			return;
	}

	writer.setCharacterAtPosition(snake.getHead(), 'O');
	setNewSnakeDirection();
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
void Game::setNewSnakeDirection()
{
	for (short i = 0; i < 7; i++)
	{
		snake.setDirection(getNewSnakeDirection());
		Sleep(45 / snake.getSpeed());
	}
}

short Game::getNewSnakeDirection()
{
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

bool Game::playAgain()
{
	const int countOptions = 4;
	char options[countOptions] = { 'Y', 'y', 'N', 'n' };
	char response = reader.readCharacter("Do you want play again? y/n", options, 4);
	if (response == 'Y' || response == 'y')
	{
		gameOver = false;
		restart();
		return true;
	}
	else
	{
		return false;
	}
}

void Game::restart()
{
	snake.restart();
	apple.restart();
	player.restart();
}

void Game::displayScores()
{
	writer.clear();
	Score::sortScores(scores);
	menu.setTitle("SCORES");
	vector<std::string>toDisplay = Score::scoresToString(scores);
	menu.setOptions(toDisplay);
	writer.setWindowSize(800, 600);
	menu.displayMenu();
}