#pragma once
#include "ConsoleWriter.h"
#include "ConsoleReader.h"
#include "ConsoleMenu.h"
#include "Apple.h"
#include "Snake.h"
#include "Player.h"
#include "Score.h"
#include <vector>



class Game
{
public:
	static int const BorderTop = 4;
	static int const BorderRight = 50;
	static int const BorderBottom = 32;
	static int const BorderLeft = 1;

private:
	int countApples;
	bool gameOver;
	Apple apple;
	Snake snake;
	Player player;
	utility::ConsoleWriter writer;
	utility::ConsoleReader reader;
	utility::ConsoleMenu menu;
	std::vector <Score*> scores;

public:
	Game();
	~Game();
	void start();
	static int getBorderTop();
	static int getBorderRight();
	static int getBorderBottom();
	static int getBorderLeft();
private:
	void welcome();
	void displayBoard();
	void displayInitialSnake();
	void update();
	void updateApple();
	void updateSnake();

	short getNewSnakeDirection();
	void setNewSnakeDirection();

	bool hasGameEnded();
	bool snakeHitWall();
	bool snakeHitSelf(COORD coordenate);

	bool isEating();
	bool playAgain();

	void restart();
	void displayScores();

};

