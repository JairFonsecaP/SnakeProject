#include "Apple.h"
#include "Game.h"

using utility::Random;
using utility::Coordinate;

Apple::Apple(char character)
	:coordinate(createCoordinate()),
	character(character)
{ }
void Apple::restart()
{
	coordinate = createCoordinate();
}

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
	short x = Random::getRandomInteger(Game::BorderLeft + 1, Game::BorderRight - 1);
	short y = Random::getRandomInteger(Game::BorderTop + 1, Game::BorderBottom - 1);
	coordinate = { x, y };
}


utility::Coordinate Apple::createCoordinate()
{
	return
	{
		Random::getRandomInteger(Game::BorderLeft + 1, Game::BorderRight - 1),
		Random::getRandomInteger(Game::BorderTop + 1, Game::BorderBottom - 1)
	};
}
