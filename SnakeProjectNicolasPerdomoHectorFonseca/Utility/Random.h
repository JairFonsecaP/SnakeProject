#pragma once
#include <random>

namespace utility
{
	class Random
	{
	public:
		static int getRandomInteger(int min, int max);
		static double getRandomDouble(double min, double max);
	};
}
