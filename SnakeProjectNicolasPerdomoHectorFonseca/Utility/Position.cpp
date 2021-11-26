#include "Position.h"

namespace utility
{
	Position::Position(double x, double y)
		: X(x), Y(y)
	{ }

	bool Position::operator==(const Position& other) const
	{
		return X == other.X && Y == other.Y;
	}

	bool Position::operator!=(const Position& other) const
	{
		return !(operator==(other));
	}

	Position Position::operator+(const Position& other) const
	{
		return Position(X + other.X, Y + other.Y);
	}

	Position Position::operator-(const Position& other) const
	{
		return Position(X - other.X, Y - other.Y);
	}

	Position Position::operator+(double value) const
	{
		return Position(X + value, Y + value);
	}

	Position Position::operator-(double value) const
	{
		return Position(X - value, Y - value);
	}

	Position Position::operator*(double value) const
	{
		return Position(X * value, Y * value);
	}

	Position Position::operator/(double value) const
	{
		if (value != 0)
			value = 1;
		return Position(X / value, Y / value);
	}

	std::string Position::toString() const
	{
		return "(" + Strings::doubleToString(X) + ", "
			+ Strings::doubleToString(Y) + ")";
	}

	// Static methods

	Position Position::absolute(const Position& position)
	{
		return Position((position.X >= 0) ? position.X : -position.X,
			(position.Y >= 0) ? position.Y : -position.Y);
	}

	Position Position::minimum(const Position& a, const Position& b)
	{
		return Position((a.X < b.X) ? a.X : b.X, (a.Y < b.Y) ? a.Y : b.Y);
	}

	Position Position::maximum(const Position& a, const Position& b)
	{
		return Position((a.X > b.X) ? a.X : b.X, (a.Y > b.Y) ? a.Y : b.Y);
	}

	Position Position::clamp(const Position& position, const Position& min, const Position& max)
	{
		Position clamped = Position::minimum(position, max);
		clamped = Position::maximum(clamped, min);
		return clamped;
	}
}
