#pragma once
#include"Coordinate.h"
class Rectangle
{
private:
	utility::Coordinate topLeft;
	utility::Coordinate bottomRight;

public:
	Rectangle(utility::Coordinate topLeft, utility::Coordinate bottomRight);

	utility::Coordinate getTopRigth();
	utility::Coordinate getBottomLeft();
	int getSize();
	int getWidth();
	int getHeight();
};