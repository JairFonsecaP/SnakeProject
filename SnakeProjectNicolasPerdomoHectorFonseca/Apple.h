#pragma once
#include "Random.h"
#include "Coordinate.h"


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
	void restart();

private:
	static utility::Coordinate createCoordinate();
};

