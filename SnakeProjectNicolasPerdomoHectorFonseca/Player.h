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
	utility::Time stopWatch;
	utility::Time lastTime;
	utility::Time elapsedTime;
	std::string playerName;

	//private methods

	//Tools
	int alignCursorY(int top, int bottom);
	static utility::Time startElapsedTime();
public:
	Player();

	void restart();
	int getLevel();
	int getScore();
	void incrementScore();
	void setLevel(int level);

	utility::Time getElapsedTime();
	std::string getPlayerName();


	
	//updateMethods
	void setPlayerName(std::string playerName);
	void updateTimer();
	void timeScore();

	std::string toString();
};

