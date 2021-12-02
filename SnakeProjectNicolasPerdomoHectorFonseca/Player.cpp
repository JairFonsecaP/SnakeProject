#include "Player.h"
using std::string;

Player::Player()
	:gameOver(false), level(1), elapsedTime(0,0,0), timer(0,0,0), score(0), currentSnakeLength(10), maxSnakeLength(currentSnakeLength)
{}


//getters
bool Player::isGameOver()
{
	return gameOver;
}

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

int Player::getCurrentSnakeLength()
{
	return currentSnakeLength;
}

int Player::getMaxSnakeLength()
{
	return maxSnakeLength;
}



//setters
void Player::setPlayerName(std::string playerName)
{
	this->playerName = playerName;
}

void Player::setLevel(int level)
{
	this->level = level;
}



//on update
void Player::displayLevel(int left, int top, int right, int bottom) //{x,y} where to clear the region and rewrite level and score values.
{
	utility::ConsoleWriter writer;
	writer.clearRegion(left,top,right,bottom);
	writer.setCursorPosition(left+1, alignCursorY(top, bottom));
	writer.writeLine(std::to_string(level));
}

void Player::displayScore(int left, int top, int right, int bottom)
{
	utility::ConsoleWriter writer;
	writer.clearRegion(left, top, right, bottom);
	writer.setCursorPosition(left+1, alignCursorY(top, bottom));
	writer.writeLine(std::to_string(score));
}

void Player::startElapsedTime()
{
	elapsedTime = utility::Time(utility::Time::getNow()); //Get the time at the moment that this method is called.
}

void Player::updateTimer() //Get the diference between initial time and now();
{
	int hour = utility::Time::getHoursBetween(elapsedTime, utility::Time::getNow());
	int minute = utility::Time::getMinutesBetween(elapsedTime, utility::Time::getNow());
	int second = utility::Time::getSecondsBetween(elapsedTime,utility::Time::getNow());

	if (minute >= 60)
		minute = minute % 60;

	if (second >= 60)
		second = second % 60;

	timer = utility::Time(hour, minute, second);
}

void Player::displayTimer(int left, int top, int right, int bottom) //{x,y} where to clear the region and rewrite timer.
{
	utility::ConsoleWriter writer;
	writer.clearRegion(left, top, right, bottom);
	writer.setCursorPosition(left + 1, alignCursorY(top, bottom));
	writer.writeLine(timer.toString());
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
	score = (utility::Time::getSecondsBetween(utility::Time(0, 0, 0), timer))*level;
}


//Tools
int Player::alignCursorY(int top, int bottom) //align-text:center; (just in Y).
{
	int alignY;
	((top + bottom) % 2 == 0 ? alignY = (top + bottom)/2 : alignY = ((top+bottom)/2)-1); //Center cursor in Y. 
	return alignY;
}