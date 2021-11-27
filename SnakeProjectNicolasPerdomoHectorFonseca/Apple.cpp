#include "Apple.h"

using utility::Random;

Apple::Apple(char character)
	:x(setX()), y(setY()), character(character)
{
}

int Apple::getX()
{
	return x;
}

int Apple::getY()
{
	return y;
}

int Apple::setX()
{
	x = Random::getRandomInteger(10 + 1, 100 - 1);
}

int Apple::setY()
{
	y = Random::getRandomInteger(10 + 1, 100 - 1);
}
