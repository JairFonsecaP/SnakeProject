#pragma once
#include <string>
#include <ctime>
#include "Strings.h"
#include "Math.hh"

namespace utility
{
	class Time 
	{
	private:
		int hour;
		int minute;
		int second;

	public:
		Time(int hour, int minute, int second);

		bool operator ==(const Time& other) const;
		bool operator !=(const Time& other) const;
		bool operator <(const Time& other) const;
		bool operator <=(const Time& other) const;
		bool operator >(const Time& other) const;
		bool operator >=(const Time& other) const;

		int getHour() const;
		int getMinute() const;
		int getSecond() const;

		int getHoursUntil(const Time& other) const;
		int getMinutesUntil(const Time& other) const;
		int getSecondsUntil(const Time& other) const;
		
		Time addHours(int hours) const;
		Time addMinutes(int minutes) const;
		Time addSeconds(int seconds) const;

		std::string toString() const;

		static int getHoursBetween(const Time& first, const Time& second);
		static int getMinutesBetween(const Time& first, const Time& second);
		static int getSecondsBetween(const Time& first, const Time& second);
		static Time normalize(int hours, int minutes, int seconds);
		static Time normalize(int hours, int minutes, int seconds, int& days);
		static Time addHours(const Time& initial, int hours);
		static Time addMinutes(const Time& initial, int minutes);
		static Time addSeconds(const Time& initial, int seconds);
		static Time getNow();
	};
}
