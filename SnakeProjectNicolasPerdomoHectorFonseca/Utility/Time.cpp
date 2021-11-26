#include "Time.hh"
using std::string;
using std::to_string;

namespace utility
{
	// Instance methods

	Time::Time(int hour, int minute, int second)
	{
		if (hour < 0)
			hour = 0;
		else if (hour > 23)
			hour = 23;
		this->hour = hour;

		if (minute < 0)
			minute = 0;
		else if (minute > 59)
			minute = 59;
		this->minute = minute;

		if (second < 0)
			second = 0;
		else if (second > 59)
			second = 59;
		this->second = second;
	}

	bool Time::operator ==(const Time& other) const
	{
		return (this->hour == other.hour
			&& this->minute == other.minute
			&& this->second == other.second);
	}

	bool Time::operator !=(const Time& other) const
	{
		return !(*this == other);
	}

	bool Time::operator <(const Time& other) const
	{
		if (this->hour < other.hour)
			return true;
		else if (this->hour > other.hour)
			return false;
		else if (this->minute < other.minute)
			return true;
		else if (this->minute > other.minute)
			return false;
		else if (this->second < other.second)
			return true;
		else
			return false;
	}

	bool Time::operator <=(const Time& other) const
	{
		return (*this == other || *this < other);
	}

	bool Time::operator >(const Time& other) const
	{
		return !(*this <= other);
	}

	bool Time::operator >=(const Time& other) const
	{
		return !(*this < other);
	}

	int Time::getHour() const
	{
		return hour;
	}

	int Time::getMinute() const
	{
		return minute;
	}

	int Time::getSecond() const
	{
		return second;
	}

	int Time::getHoursUntil(const Time& other) const
	{
		return Time::getHoursBetween(*this, other);
	}

	int Time::getMinutesUntil(const Time& other) const
	{
		return Time::getMinutesBetween(*this, other);
	}

	int Time::getSecondsUntil(const Time& other) const
	{
		return Time::getSecondsBetween(*this, other);
	}

	Time Time::addHours(int hours) const
	{
		return Time::addHours(*this, hours);
	}

	Time Time::addMinutes(int minutes) const
	{
		return Time::addMinutes(*this, minutes);
	}

	Time Time::addSeconds(int seconds) const
	{
		return Time::addSeconds(*this, seconds);
	}

	string Time::toString() const
	{
		return Strings::integerToString(hour, 2)
			+ ":" + Strings::integerToString(minute, 2)
			+ ":" + Strings::integerToString(second, 2);
	}


	// Static methods

	int Time::getHoursBetween(const Time& first, const Time& second)
	{
		return Time::getMinutesBetween(first, second) / 60;
	}

	int Time::getMinutesBetween(const Time& first, const Time& second)
	{
		return Time::getSecondsBetween(first, second) / 60;
	}

	int Time::getSecondsBetween(const Time& first, const Time& second)
	{
		int hoursDifference = second.hour - first.hour;
		int minutesDifference = second.minute - first.minute;
		int secondsBetween =
			(hoursDifference * 60 * 60)
			+ (minutesDifference * 60)
			+ (second.second - first.second);
		return secondsBetween;
	}

	Time Time::normalize(int hours, int minutes, int seconds)
	{
		int days;
		return Time::normalize(hours, minutes, seconds, days);
	}
	
	Time Time::normalize(int hours, int minutes, int seconds, int& days)
	{
		days = 0;

		Math::normalize(seconds, minutes, 60, false);
		Math::normalize(minutes, hours, 60, false);
		Math::normalize(hours, days, 24, false);

		return Time(hours, minutes, seconds);
	}
	
	Time Time::addHours(const Time& initial, int hours)
	{
		return Time::normalize(initial.getHour() + hours, initial.getMinute(), initial.getSecond());
	}

	Time Time::addMinutes(const Time& initial, int minutes)
	{
		return Time::normalize(initial.getHour(), initial.getMinute() + minutes, initial.getSecond());
	}

	Time Time::addSeconds(const Time& initial, int seconds)
	{
		return Time::normalize(initial.getHour(), initial.getMinute(), initial.getSecond() + seconds);
	}

	Time Time::getNow()
	{
		struct tm now;
		time_t nowTime = time(0);
		localtime_s(&now, &nowTime);
		return Time(now.tm_hour, now.tm_min, now.tm_sec);
	}
}
