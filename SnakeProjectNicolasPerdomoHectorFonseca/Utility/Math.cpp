#include "Math.hh"

namespace utility
{
	int Math::absolute(int value)
	{
		return (value >= 0) ? value : -value;
	}

	int Math::minimum(int a, int b)
	{
		return (a < b) ? a : b;
	}

	int Math::maximum(int a, int b)
	{
		return (a > b) ? a : b;
	}

	int Math::clamp(int value, int min, int max)
	{
		if (value < min)
			value = min;
		else if (value > max)
			value = max;
		return value;
	}

	double Math::absolute(double value)
	{
		return (value >= 0) ? value : -value;
	}

	double Math::minimum(double a, double b)
	{
		return (a < b) ? a : b;
	}

	double Math::maximum(double a, double b)
	{
		return (a > b) ? a : b;
	}

	double Math::clamp(double value, double min, double max)
	{
		if (value < min)
			value = min;
		else if (value > max)
			value = max;
		return value;
	}

	double Math::squareRoot(double value)
	{
		value = Math::absolute(value);
		return sqrt(value);
	}

	double Math::getDistance(const Position& first, const Position& second)
	{
		Position deltaVector = second - first;
		double distanceSquared = (deltaVector.X * deltaVector.X) + (deltaVector.Y * deltaVector.Y);
		double distance = Math::squareRoot(distanceSquared);
		return distance;
	}

	double Math::getMagnitude(const Position& position)
	{
		return Math::getDistance(Position(0, 0), position);
	}

	Position Math::normalize(const Position& position)
	{
		double magnitude = Math::getMagnitude(position);
		if (magnitude <= 0)
			return Position(1, 0);
		return position / magnitude;
	}

	void Math::normalize(int& subUnit, int& superUnit, unsigned int subUnitsPerSuper, bool oneBased)
	{
		if (subUnitsPerSuper < 1)
			return;

		int min = (oneBased) ? 1 : 0;
		int max = (oneBased) ? (int)subUnitsPerSuper : (int)subUnitsPerSuper - 1;

		int superUnitOffset = 0;
		if (subUnit < min)
			superUnitOffset = ((subUnit - min + 1) / (int)subUnitsPerSuper) - 1;
		else if (subUnit > max)
			superUnitOffset = ((subUnit - min) / (int)subUnitsPerSuper);
		else
			return; // Return because subUnit is already in normal range

		superUnit += superUnitOffset;
		subUnit -= ((int)subUnitsPerSuper * superUnitOffset);
	}
}
