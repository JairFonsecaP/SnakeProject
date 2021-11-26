#pragma once
#include <string>
#include <ctime>
#include "Date.h"
#include "Time.hh"
#include "Strings.h"
#include "Math.hh"

namespace utility
{
	class DateTime : public Date, Time
	{
	public:
		DateTime(int year, int month, int day, int hour, int minute, int second);
		DateTime(int year, int month, int day);
		DateTime(Date date, Time time);
		DateTime(Date date);
		
		bool operator ==(const DateTime& other) const;
		bool operator !=(const DateTime& other) const;
		bool operator <(const DateTime& other) const;
		bool operator <=(const DateTime& other) const;
		bool operator >(const DateTime& other) const;
		bool operator >=(const DateTime& other) const;

		int getHoursUntil(const DateTime& other) const;
		int getMinutesUntil(const DateTime& other) const;
		int getSecondsUntil(const DateTime& other) const;

		DateTime addYears(int years) const;
		DateTime addMonths(int months) const;
		DateTime addDays(int days) const;
		DateTime addHours(int hours) const;
		DateTime addMinutes(int minutes) const;
		DateTime addSeconds(int seconds) const;

		virtual std::string toString() const override;
		
		static int getHoursBetween(const DateTime& first, const DateTime& second);
		static int getMinutesBetween(const DateTime& first, const DateTime& second);
		static int getSecondsBetween(const DateTime& first, const DateTime& second);
		static DateTime normalize(const Date& initial, int hours, int minutes, int seconds);
		static DateTime addYears(const DateTime& initial, int years);
		static DateTime addMonths(const DateTime& initial, int months);
		static DateTime addDays(const DateTime& initial, int days);
		static DateTime addHours(const DateTime& initial, int hours);
		static DateTime addMinutes(const DateTime& initial, int minutes);
		static DateTime addSeconds(const DateTime& initial, int seconds);
		static DateTime getNow();
	};
}
