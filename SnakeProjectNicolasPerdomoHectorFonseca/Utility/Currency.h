#pragma once
#include <cmath>
#include <string>
#include <sstream>

namespace utility
{
	class Currency
	{
	private:
		bool sign;
		unsigned long long totalCents;

	public:
		Currency(bool sign, unsigned long long totalCents);
		Currency(bool sign, unsigned int dollarValue, unsigned short centValue);
		Currency(double dollars);

		bool getSign();
		unsigned long long getTotalCents();

		double getDollars();
		unsigned long long getDollarValue();
		unsigned short getCentValue();

		std::string toString();
	};
}
