#pragma once
#include "Random.h"
#include "Coordinate.h"
//#include "Game.h"

class Apple
{
private:
	utility::Coordinate coordinate;
	char character;

public:
	Apple(char character);

	utility::Coordinate getCoordinate();
	char getCharacter();

	void randomizePosition();

private:
	static int getPointRandom(int min, int max);
	static utility::Coordinate createCoordinate();
};

