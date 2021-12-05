#pragma once

#include "Map.h"
#include "Apple.h"
#include "Snake.h"
#include "Player.h"
#include "Score.h"
#include <vector>



class Game
{
private:
	int countApples;
	bool gameOver;
	Apple apple;
	Snake snake;
	Player player;
	Map map;
	std::vector <Score*> scores;


public:
	Game();
	~Game();
	void start();

private:

	void update();
	void updateApple();
	void updateSnake();

	void setNewSnakeDirection();

	bool hasGameEnded();
	bool snakeHitWall();
	bool snakeHitSelf(COORD coordenate);

	bool isEating();
	bool playAgain();

	void restart();
	void updateScores();
};


