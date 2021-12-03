#pragma once
//Nicolas Perdomo
#include<iostream>
#include<string>
#include"ConsoleWriter.h"
#include"Time.hh"

class Player
{
private: 
	int level; 
	int score;
	utility::Time lastTime;

	utility::Time timer;
	utility::Time elapsedTime;
	std::string playerName;

	//private methods
	void setLevel(int level);
	void incrementScore(int amount);

	//Tools
	int alignCursorY(int top, int bottom);//
	static utility::Time startElapsedTime();
public:
	Player();

	int getLevel();
	int getScore();

	utility::Time getElapsedTime();
	std::string getPlayerName();
	void incrementScore(int amount, float multiplier);

	
	//updateMethods
	void setPlayerName(std::string playerName);
	void displayLevel(int left, int top, int right, int bottom);//
	void displayTimer(int left, int top, int right, int bottom);//
	void displayScore(int left, int top, int right, int bottom);//
	void updateTimer();
	void timeScore();
	void setScore();

	std::string toString();
};

