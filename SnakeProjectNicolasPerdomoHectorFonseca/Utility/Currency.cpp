#include "Currency.h"
using std::string;
using std::stringstream;

namespace utility
{
	Currency::Currency(bool sign, unsigned long long totalCents)
		: sign(sign), totalCents(totalCents)
	{
		if (totalCents == 0)
			sign = true;
	}

	Currency::Currency(bool sign, unsigned int dollarValue, unsigned short centValue)
		: Currency(sign, dollarValue * 100ULL + (centValue % 100))
	{ }

	Currency::Currency(double dollars)
		: Currency((dollars >= 0),
			(unsigned long long)std::abs(dollars) * 100ULL +
			(unsigned long long)std::round(std::abs(dollars - (long long)dollars) * 100))
	{ }

	bool Currency::getSign()
	{
		return sign;
	}

	unsigned long long Currency::getTotalCents()
	{
		return totalCents;
	}

	double Currency::getDollars()
	{
		return (double)totalCents / 100 * ((sign) ? 1 : -1);
	}

	unsigned long long Currency::getDollarValue()
	{
		return totalCents / 100ULL;
	}

	unsigned short Currency::getCentValue()
	{
		return (unsigned short)(totalCents - (getDollarValue() * 100ULL));
	}

	string Currency::toString()
	{
		string prefix = (getSign()) ? "$" : "-$";

		stringstream centsStream;
		centsStream.fill('0');
		centsStream.width(2);
		centsStream << getCentValue();
		centsStream.flush();

		return prefix + std::to_string(getDollarValue()) + "." + centsStream.str();
	}
}
