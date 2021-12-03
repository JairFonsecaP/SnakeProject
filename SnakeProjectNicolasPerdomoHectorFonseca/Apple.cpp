#include "Apple.h"
#include "Game.h"

using utility::Random;
using utility::Coordinate;

Apple::Apple(char character)
	:coordinate(createCoordinate()),
	character(character)
{ }

Coordinate Apple::getCoordinate()
{
	return coordinate;
}

char Apple::getCharacter()
{
	return character;
}

void Apple::randomizePosition()
{
	short x = getPointRandom(Game::BorderLeft + 1, Game::BorderRight - 1);
	short y = getPointRandom(Game::BorderTop + 1, Game::BorderBottom - 1);
	coordinate = { x, y };
}

int Apple::getPointRandom(int min, int max)
{
	return Random::getRandomInteger(min, max);
}

utility::Coordinate Apple::createCoordinate()
{
	return
	{
		getPointRandom(Game::BorderLeft + 1, Game::BorderRight - 1),
		getPointRandom(Game::BorderTop + 1, Game::BorderBottom - 1)
	};
}
