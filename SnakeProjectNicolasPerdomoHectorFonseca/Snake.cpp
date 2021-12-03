#include "Snake.h"

using std::vector;
using utility::Coordinate;

Snake::Snake()
	:
	length(initialLength),
	bodyPoints(getInitialSnake()),
	head({ 12,18 }),
	tail({ 0,0 }),
	headDirection(goRight),
	tailDirection(1),
	speed(1)
{
	 head = bodyPoints[bodyPoints.size() - 1];
	 tail = bodyPoints[0];
}

Coordinate Snake::getHead()
{
	return head;
}

Coordinate Snake::getTail()
{
	return tail;
}
short Snake::getDirection()
{
	return headDirection;
}

int Snake::getLength()
{
	return length;
}

vector<Coordinate> Snake::getBodyPoints()
{
	return bodyPoints;
}

void Snake::move()
{
	stepHead();
	stepTail();
}

void Snake::moveAndGrow()
{
	stepHead();
	length++;
}

void Snake::setDirection(short direction)
{
	this->headDirection = direction;
}

int Snake::getSpeed()
{
	return speed;
}

void Snake::setSpeed(int speed)
{
	this->speed = speed;
}

void Snake::stepHead()
{
	step(&head, headDirection);
	bodyPoints.push_back(head);
}
void Snake::stepTail()
{
	tail = bodyPoints[0];
	bodyPoints.erase(bodyPoints.begin() + 0);
}


void Snake::step(Coordinate* coordinate, short direction)
{
	switch (direction)
	{
	case goUp:
	{
		subtractOneToY(coordinate);
		break;
	}
	case goRight:
	{
		addOneToX(coordinate);
		break;
	}
	case goDown:
	{
		addOneToY(coordinate);
		break;
	}
	case goLeft:
	{
		subtractOneToX(coordinate);
		break;
	}
	}
}

void Snake::subtractOneToX(Coordinate* x)
{
	*x = x->operator-({ 1,0 });
}

void Snake::subtractOneToY(utility::Coordinate* y)
{
	*y = y->operator-({ 0,1 });
}

void Snake::addOneToX(utility::Coordinate* x)
{
	*x = x->operator+({ 1,0 });
}

void Snake::addOneToY(utility::Coordinate* y)
{
	*y = y->operator+({ 0,1 });
}


vector<Coordinate> Snake::getInitialSnake()
{
	vector<Coordinate> toReturn;
	for (int i = 0; i < initialLength; i++)
	{
		COORD coord = { short(i + 2),18 };
		toReturn.push_back(coord);
	}
	return toReturn;
}

