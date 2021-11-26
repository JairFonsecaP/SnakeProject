#pragma once
#include <math.h>
#include "Position.h"

namespace utility
{
	class Math
	{
	public:
		static int absolute(int value);
		static int minimum(int a, int b);
		static int maximum(int a, int b);
		static int clamp(int value, int min, int max);
		
		static double absolute(double value);
		static double minimum(double a, double b);
		static double maximum(double a, double b);
		static double clamp(double value, double min, double max);

		static double squareRoot(double value);
		static double getDistance(const Position& first, const Position& second);
		static double getMagnitude(const Position& position);
		static Position normalize(const Position& position);

		static void normalize(int& subUnit, int& superUnit, unsigned int subUnitsPerSuper, bool oneBased);
	};
}
