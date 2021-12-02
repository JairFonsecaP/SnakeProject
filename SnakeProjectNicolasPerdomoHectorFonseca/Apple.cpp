#include "Apple.h"
#include "Game.h"

using utility::Random;
using utility::Coordinate;

Apple::Apple(char character)
	:coordinate({ getPointRandom(Game::BorderLeft + 1, Game::BorderRight - 1) ,getPointRandom(Game::BorderTop + 1, Game::BorderBottom - 1) }), character(character)
	//:x(getPointRandom(1, 50)), y(getPointRandom(4, 30)), character(character)
{ }

Coordinate Apple::getCoordinate()
{
	return coordinate;
}

char Apple::getCharacter()
{
	return character;
}

void Apple::update()
{
	setX();
	setY();
}

void Apple::setX()
{
	coordinate = { getPointRandom(Game::BorderLeft + 1, Game::BorderRight - 1), coordinate.Y };
	
}

void Apple::setY()
{
	coordinate = { coordinate.X, getPointRandom(Game::BorderTop + 1, Game::BorderBottom - 1) };
}

int Apple::getPointRandom(int min, int max)
{
	return Random::getRandomInteger(min, max);
}