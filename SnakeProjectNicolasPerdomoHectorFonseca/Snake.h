#pragma once
#include "Coordinate.h"
#include <vector>

class Snake
{
public:
	static short const goUp = 0;
	static short const goRight = 1;
	static short const goDown = 2;
	static short const goLeft = 3;

private:
	static const short initialLength = 10;

	int length;
	short headDirection;
	short tailDirection;

	utility::Coordinate head;
	utility::Coordinate tail;
	std::vector <utility::Coordinate> bodyPoints;

	
public:
	Snake();

	utility::Coordinate getHead();
	utility::Coordinate getTail();
	short getDirection();
	int getLength();
	std::vector <utility::Coordinate> getBodyPoints();
	void update();
	void updateEating();
	void setDirection(short direction);

private:
	void stepHead();
	void stepTail();
	void step(utility::Coordinate* coordinate, short direction);
	void subtractOneToX(utility::Coordinate* x);
	void subtractOneToY(utility::Coordinate* y);
	void addOneToX(utility::Coordinate* x);
	void addOneToY(utility::Coordinate* y);

	static std::vector <utility::Coordinate> getInitialSnake();
};

