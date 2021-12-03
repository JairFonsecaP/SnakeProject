#include "Player.h"
using std::string;
using utility::Time;

Player::Player()
	:level(1), elapsedTime(startElapsedTime() ), timer(0, 0, 0), score(0), playerName(""), lastTime(Time::getNow())
{ 
}


//getters


int Player::getLevel()
{
	return level;
}

utility::Time Player::getElapsedTime()
{
	return elapsedTime;
}

int Player::getScore()
{
	return score;
}

std::string Player::getPlayerName()
{
	return playerName;
}

//setters
void Player::setPlayerName(std::string playerName)
{
	this->playerName = playerName;
}
/// <summary>
/// 
/// </summary>
/// <param name="level"></param>
void Player::setLevel(int level)
{
	this->level = level;
}


//on update
Time Player::startElapsedTime()
{
	return Time(Time::getNow()); //Get the time at the moment that this method is called.
}

void Player::updateTimer() //Get the diference between initial time and now();
{
	int seconds = Time::getSecondsBetween(elapsedTime,Time::getNow());
	int hours = seconds / 3600;
	seconds %= 3600;
	int minutes = seconds / 60;
	seconds %= 60;
	timer = Time(hours, minutes, seconds);
}


void Player::incrementScore(int amount) //TO DO: o) When the snake eat an apple.
{
	score += amount;
}
void Player::incrementScore(int amount, float multiplier)
{
	incrementScore(amount * multiplier);   //Overflow, note: (multiplier) could be replaced by (level).
}

void Player::timeScore() //Every second the score increase, THIS IS MULTIPLIED BY LEVEL vv
{
	score += (Time::getSecondsBetween(lastTime, Time::getNow()));
	lastTime = Time::getNow();
}



//Tools
int Player::alignCursorY(int top, int bottom) //align-text:center; (just in Y).
{
	int alignY;
	((top + bottom) % 2 == 0 ? alignY = (top + bottom)/2 : alignY = ((top+bottom)/2)-1); //Center cursor in Y. 
	return alignY;
}

string Player::toString()
{
	return "Level: " + std::to_string(level) +  "  Score: " + std::to_string(score) + "  Time: " + timer.toString();
}