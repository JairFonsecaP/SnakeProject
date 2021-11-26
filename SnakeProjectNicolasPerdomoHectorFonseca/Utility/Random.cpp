#include "Random.h"

namespace utility
{
	int Random::getRandomInteger(int min, int max) // min and max both inclusive
	{
		std::random_device rd;
		std::mt19937 mtEngine = std::mt19937(rd());
		std::uniform_int_distribution<int> randomIntGenerator =
			std::uniform_int_distribution<int>(min, max);
		return randomIntGenerator(mtEngine);
	}

	double Random::getRandomDouble(double min, double max) // min and max both inclusive
	{
		std::random_device rd;
		std::mt19937 mtEngine = std::mt19937(rd());
		std::uniform_real_distribution<double> randomDoubleGenerator =
			std::uniform_real_distribution<double>(min, max);
		return randomDoubleGenerator(mtEngine);
	}
}
