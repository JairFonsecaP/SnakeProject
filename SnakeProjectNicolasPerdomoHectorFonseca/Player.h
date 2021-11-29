#pragma once
//Nicolas Perdomo
#include<iostream>
#include<string>
#include"ConsoleWriter.h"
#include"Time.hh"

class Player
{
private: 
	bool gameOver;

	int level; 

	utility::Time timer;
	utility::Time elapsedTime;
	int score;

	std::string playerName;

	int currentSnakeLength;
	int maxSnakeLength;

	//private methods
	void setLevel(int level);

	//Tools
	int alignCursorY(int top, int bottom);

public:
	Player();

	bool isGameOver();

	int getLevel();
	void incrementScore();

	utility::Time getElapsedTime();
	int getScore();
	std::string getPlayerName();
	int getCurrentSnakeLength();
	int getMaxSnakeLength();
	
	void startElapsedTime();

	void setPlayerName(std::string playerName);

	//updateMethods
	void displayLevel(int left, int top, int right, int bottom);
	void displayTimer(int left, int top, int right, int bottom);
	void displayScore(int left, int top, int right, int bottom);
	void updateTimer();

	void incrementScore(int amount);
	void incrementScore(int amount, float multiplier);

	void timeScore();


};

