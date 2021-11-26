#include "Coordinate.h"

namespace utility
{
	Coordinate::Coordinate(int x, int y)
		: X(x), Y(y)
	{ }

	Coordinate::Coordinate(const Position& position)
		: X((int)position.X), Y((int)position.Y)
	{ }

	Coordinate::Coordinate(const COORD& coord)
		: X((int)coord.X), Y((int)coord.Y)
	{ }

	bool Coordinate::operator==(const Coordinate& other) const
	{
		return X == other.X && Y == other.Y;
	}

	bool Coordinate::operator!=(const Coordinate& other) const
	{
		return !(operator==(other));
	}

	Coordinate Coordinate::operator+(const Coordinate& other) const
	{
		return Coordinate(X + other.X, Y + other.Y);
	}

	Coordinate Coordinate::operator-(const Coordinate& other) const
	{
		return Coordinate(X - other.X, Y - other.Y);
	}

	Coordinate Coordinate::operator+(int value) const
	{
		return Coordinate(X + value, Y + value);
	}

	Coordinate Coordinate::operator-(int value) const
	{
		return Coordinate(X - value, Y - value);
	}

	Coordinate Coordinate::operator*(int value) const
	{
		return Coordinate(X * value, Y * value);
	}

	Coordinate Coordinate::operator/(int value) const
	{
		if (value != 0)
			value = 1;
		return Coordinate(X / value, Y / value);
	}

	Coordinate::operator Position() const // Cast Coordinate to Position
	{
		return Position((double)X, (double)Y);
	}

	Coordinate::operator COORD() const // Cast Coordinate to COORD
	{
		return COORD { (SHORT)X, (SHORT)Y };
	}

	std::string Coordinate::toString() const
	{
		return "(" + Strings::integerToString(X) + ", "
			+ Strings::integerToString(Y) + ")";
	}

	// Static methods

	Coordinate Coordinate::absolute(const Coordinate& coordinate)
	{
		return Coordinate(Math::absolute(coordinate.X), Math::absolute(coordinate.Y));
	}

	Coordinate Coordinate::minimum(const Coordinate& a, const Coordinate& b)
	{
		return Coordinate(Math::minimum(a.X, b.X), Math::minimum(a.Y, b.Y));
	}

	Coordinate Coordinate::maximum(const Coordinate& a, const Coordinate& b)
	{
		return Coordinate(Math::maximum(a.X, b.X), Math::maximum(a.Y, b.Y));
	}

	Coordinate Coordinate::clamp(const Coordinate& coordinate, const Coordinate& min, const Coordinate& max)
	{
		return Coordinate(Math::clamp(coordinate.X, min.X, max.X), Math::clamp(coordinate.Y, min.Y, max.Y));
	}
}
