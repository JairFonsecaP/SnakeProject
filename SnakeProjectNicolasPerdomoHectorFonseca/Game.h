#pragma once
#include "ConsoleWriter.h"
#include "ConsoleReader.h"
#include "Apple.h"
#include "Snake.h"
#include "Player.h"
#include <vector>

class Game
{
public:
	static int const BorderTop = 4;
	static int const BorderRight = 50;
	static int const BorderBottom = 32;
	static int const BorderLeft = 1;
	
private:
	bool gameOver;
	utility::ConsoleWriter writer;
	utility::ConsoleReader reader;
	Apple apple;
	Snake snake;
	//Player player;

public:
	Game();
	void start();
	static int getBorderTop();
	static int getBorderRight();
	static int getBorderBottom();
	static int getBorderLeft();
private:
	void displayBoard();
	void displayInitialSnake();
	void update();
	void updateApple();
	void updateSnake();
	short turnSnake();
	void keepOnPlaying();
	bool isEating();

};


