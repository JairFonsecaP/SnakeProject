#pragma once
#include <string>
#include "Strings.h"

namespace utility
{
	struct Position
	{
	public:
		double X;
		double Y;

		Position(double x, double y);

		bool operator==(const Position& other) const;
		bool operator!=(const Position& other) const;

		Position operator+(const Position& other) const;
		Position operator-(const Position& other) const;

		Position operator+(double value) const;
		Position operator-(double value) const;
		Position operator*(double value) const;
		Position operator/(double value) const;

		std::string toString() const;

		static Position absolute(const Position& position);
		static Position minimum(const Position& a, const Position& b);
		static Position maximum(const Position& a, const Position& b);
		static Position clamp(const Position& position, const Position& min, const Position& max);
	};
}
