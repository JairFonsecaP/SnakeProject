#include "Game.h"

using std::vector;

Game::Game()
	:
	map(),
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
		map.initialDisplay(&player, &snake);
		updateApple();
		while (!gameOver)
		{
			update();
		}
		scores.push_back(new Score(player.getPlayerName(), player.getScore(), player.getLevel()));
		updateScores();
		play = playAgain();
	} while (play);
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
	COORD appleCoordinate;
	do
	{
		apple.randomizePosition();
		appleCoordinate = apple.getCoordinate();
	} while (snakeHitSelf(appleCoordinate));
	map.displayApple(appleCoordinate.X, appleCoordinate.Y, apple.getCharacter());
}

void Game::updateSnake()
{
	map.updateTailSnake(&snake);
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
		snake.move();
	
	gameOver = hasGameEnded();
	if (gameOver)
		return;
	setNewSnakeDirection();
	map.updateHeadSnake(&snake);
	map.updateScoreAndTime(&snake, &player);
}


void Game::setNewSnakeDirection()
{
	short newDirection = snake.getDirection();
	for (short i = 0; i < 7; i++)
	{
		short temp = map.getNewSnakeDirection(&snake);
		if (temp != -1)
			newDirection = temp;
		Sleep(45 / snake.getSpeed());
	}
	snake.setDirection(newDirection);
}


bool Game::hasGameEnded()
{
	return snakeHitSelf(snake.getHead()) || snakeHitWall();
}

bool Game::snakeHitWall()
{
	utility::Coordinate head = snake.getHead();
	return head.X <= Map::getBorderLeft() || head.X >= Map::getBorderRight()
		|| head.Y <= Map::getBorderTop() || head.Y >= Map::getBorderBottom();
}

bool Game::snakeHitSelf(COORD coordenate)
{
	std::vector<utility::Coordinate> bodyPoints = snake.getBodyPoints();
	for (size_t i = 0; i < (snake.getLength() - 1); i++)
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
	bool response = map.playAgain();
	if (response)
	{
		gameOver = false;
		restart();
		return response;
	};
	return response;
}

void Game::restart()
{
	snake.restart();
	apple.restart();
	player.restart();
}

void Game::updateScores()
{

	Score::sortScores(scores);
	map.displayScores(scores);
}