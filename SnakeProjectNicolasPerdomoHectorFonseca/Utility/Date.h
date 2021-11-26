#pragma once
#include <string>
#include <ctime>
#include "Strings.h"
#include "Math.hh"

namespace utility
{
	class Date
	{
	private:
		int year;
		int month;
		int day;

	public:
		Date(int year, int month, int day);

		bool operator ==(const Date& other) const;
		bool operator !=(const Date& other) const;
		bool operator <(const Date& other) const;
		bool operator <=(const Date& other) const;
		bool operator >(const Date& other) const;
		bool operator >=(const Date& other) const;

		int getYear() const;
		int getMonth() const;
		int getDay() const;

		bool isLeapYear() const;
		std::string getMonthString() const;
		int getDaysInMonth() const;
		int getYearsUntil(const Date& other) const;
		int getMonthsUntil(const Date& other) const;
		int getDaysUntil(const Date& other) const;
		Date addYears(int years) const;
		Date addMonths(int months) const;
		Date addDays(int days) const;

		virtual std::string toString() const;
		std::string getInfo() const;

		// Static members
		static bool isLeapYear(int year);
		static std::string getMonthString(int month);
		static int getDaysInMonth(int month, int year);
		static int getYearsBetween(const Date& first, const Date& second);
		static int getMonthsBetween(const Date& first, const Date& second);
		static int getDaysBetween(const Date& first, const Date& second);
		static Date addYears(const Date& initial, int years);
		static Date addMonths(const Date& initial, int months);
		static Date addDays(const Date& initial, int days);
		static Date normalize(int year, int month, int day);
		static Date getToday();

	private:
		static void normalizeDays(int& year, int& month, int& day);
	};
}
