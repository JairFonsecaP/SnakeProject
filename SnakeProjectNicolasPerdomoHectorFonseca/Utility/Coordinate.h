#pragma once
#include <string>
#include <Windows.h>
#include "Math.hh"
#include "Position.h"
#include "Strings.h"

namespace utility
{
	struct Coordinate
	{
	public:
		int X;
		int Y;

		Coordinate(int x, int y);
		Coordinate(const Position& position);
		Coordinate(const COORD& coord);

		bool operator==(const Coordinate& other) const;
		bool operator!=(const Coordinate& other) const;

		Coordinate operator+(const Coordinate& other) const;
		Coordinate operator-(const Coordinate& other) const;

		Coordinate operator+(int value) const;
		Coordinate operator-(int value) const;
		Coordinate operator*(int value) const;
		Coordinate operator/(int value) const;

		operator Position() const;	// Cast Coordinate to Position
		operator COORD() const;		// Cast Coordinate to COORD

		std::string toString() const;

		static Coordinate absolute(const Coordinate& coordinate);
		static Coordinate minimum(const Coordinate& a, const Coordinate& b);
		static Coordinate maximum(const Coordinate& a, const Coordinate& b);
		static Coordinate clamp(const Coordinate& coordinate, const Coordinate& min, const Coordinate& max);
	};
}
