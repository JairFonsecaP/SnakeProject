#include "DateTime.h"
using std::string;
using std::to_string;

namespace utility
{
	// Instance methods

	DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
		: Date(year, month, day), Time(hour, minute, second)
	{ }

	DateTime::DateTime(int year, int month, int day)
		: Date(year, month, day), Time(0, 0, 0)
	{ }

	DateTime::DateTime(Date date, Time time)
		: Date(date), Time(time)
	{ }

	DateTime::DateTime(Date date)
		: Date(date), Time(0, 0, 0)
	{ }

	bool DateTime::operator ==(const DateTime& other) const
	{
		return Date::operator==(other)
			&& Time::operator==(other);
	}

	bool DateTime::operator !=(const DateTime& other) const
	{
		return !(*this == other);
	}

	bool DateTime::operator <(const DateTime& other) const
	{
		if (Date::operator<(other))
			return true;
		else if (Date::operator>(other))
			return false;
		else if (Time::operator<(other))
			return true;
		else
			return false;
	}

	bool DateTime::operator <=(const DateTime& other) const
	{
		return (*this == other || *this < other);
	}

	bool DateTime::operator >(const DateTime& other) const
	{
		return !(*this <= other);
	}

	bool DateTime::operator >=(const DateTime& other) const
	{
		return !(*this < other);
	}

	int DateTime::getHoursUntil(const DateTime& other) const
	{
		return DateTime::getHoursBetween(*this, other);
	}

	int DateTime::getMinutesUntil(const DateTime& other) const
	{
		return DateTime::getMinutesBetween(*this, other);
	}

	int DateTime::getSecondsUntil(const DateTime& other) const
	{
		return DateTime::getSecondsBetween(*this, other);
	}

	DateTime DateTime::addYears(int years) const
	{
		return DateTime::addYears(*this, years);
	}

	DateTime DateTime::addMonths(int months) const
	{
		return DateTime::addMonths(*this, months);
	}

	DateTime DateTime::addDays(int days) const
	{
		return DateTime::addDays(*this, days);
	}

	DateTime DateTime::addHours(int hours) const
	{
		return DateTime::addHours(*this, hours);
	}

	DateTime DateTime::addMinutes(int minutes) const
	{
		return DateTime::addMinutes(*this, minutes);
	}

	DateTime DateTime::addSeconds(int seconds) const
	{
		return DateTime::addSeconds(*this, seconds);
	}
	
	string DateTime::toString() const
	{
		return Date::toString() + ", " + Time::toString();
	}


	// Static methods

	int DateTime::getHoursBetween(const DateTime& first, const DateTime& second)
	{
		return DateTime::getMinutesBetween(first, second) / 60;
	}

	int DateTime::getMinutesBetween(const DateTime& first, const DateTime& second)
	{
		return DateTime::getSecondsBetween(first, second) / 60;
	}

	int DateTime::getSecondsBetween(const DateTime& first, const DateTime& second)
	{
		int daysBetween = Date::getDaysBetween(first, second);
		int secondsBetween = (daysBetween * 24 * 60 * 60) + Time::getSecondsBetween(first, second);
		return secondsBetween;
	}
	
	DateTime DateTime::normalize(const Date& initial, int hours, int minutes, int seconds)
	{
		int days;
		Time time = Time::normalize(hours, minutes, seconds, days);
		return DateTime(initial.addDays(days), time);
	}

	DateTime DateTime::addYears(const DateTime& initial, int years)
	{
		return DateTime(initial.getYear() + years, initial.getMonth(), initial.getDay(),
						initial.getHour(), initial.getMinute(), initial.getSecond());
	}

	DateTime DateTime::addMonths(const DateTime& initial, int months)
	{
		return DateTime(Date::addMonths(initial, months), initial);
	}

	DateTime DateTime::addDays(const DateTime& initial, int days)
	{
		return DateTime(Date::addDays(initial, days), initial);
	}

	DateTime DateTime::addHours(const DateTime& initial, int hours)
	{
		return DateTime::normalize(initial, initial.getHour() + hours, initial.getMinute(), initial.getSecond());
	}

	DateTime DateTime::addMinutes(const DateTime& initial, int minutes)
	{
		return DateTime::normalize(initial, initial.getHour(), initial.getMinute() + minutes, initial.getSecond());
	}

	DateTime DateTime::addSeconds(const DateTime& initial, int seconds)
	{
		return DateTime::normalize(initial, initial.getHour(), initial.getMinute(), initial.getSecond() + seconds);
	}

	DateTime DateTime::getNow()
	{
		struct tm now;
		time_t nowTime = time(0);
		localtime_s(&now, &nowTime);
		return DateTime(now.tm_year + 1900, now.tm_mon + 1, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec);
	}
}
