#pragma once
#include "Random.h"
class Apple
{
private:
	int x;
	int y;
	char character;

public:
	Apple(char character);
	int getX();
	int getY();

private:
	static int setX();
	static int setY();
};

