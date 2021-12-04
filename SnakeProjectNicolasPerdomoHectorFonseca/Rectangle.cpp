#include "Rectangle.h"
using utility::Coordinate;

Rectangle::Rectangle(Coordinate topLeft, Coordinate bottomRight)
	:topLeft(topLeft), bottomRight(bottomRight)
{}

Coordinate Rectangle::getBottomLeft()
{
	return { topLeft.X, bottomRight.Y };
}

Coordinate Rectangle::getTopRigth()
{
	return { bottomRight.X,topLeft.Y };
}

int Rectangle::getWidth()
{
	return bottomRight.X - topLeft.X;
}

int Rectangle::getHeight()
{
	return bottomRight.Y - topLeft.Y;
}

int Rectangle::getSize()
{
	return getWidth() * getHeight();
}
