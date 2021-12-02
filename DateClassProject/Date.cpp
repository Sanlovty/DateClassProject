#include "Date.h"
#include "Date.h"

triple Date::splitString_(const string& date) const
{
	string day, month, year;
	const char* const exceptionMessage = "Wrong string-date format. Must be XX.XX.XX";

	for (size_t i = 0, type = 0, pos = 0; i < date.length(); i++)
	{
		if (i + 1 == date.length())
		{
			if (type != 2)
			{
				throw exception(exceptionMessage);
			}
			year = date.substr(pos);
			if (year.empty())
			{
				throw exception(exceptionMessage);
			}
		}
		if (date[i] == stringSeparator_)
		{
			if (type == 0)
			{
				day = date.substr(pos, i);
				if (day.empty())
				{
					throw exception(exceptionMessage);
				}
				pos = i + 1;
			}
			else if (type == 1)
			{
				month = date.substr(pos, i - pos);
				if (month.empty())
				{
					throw exception(exceptionMessage);
				}
				pos = i + 1;
			}
			else
			{
				throw exception(exceptionMessage);
			}
			type++;
		}
		else if (!isdigit(date[i]))
		{
			throw exception(exceptionMessage);
		}
	}
	return triple(stoul(day), stoul(month), stoul(year));
}

size_t Date::roundBy_(const size_t& value, const size_t& bound) const
{
	return value % bound;
}

void Date::roundDays_()
{
	if (date_.day > monthDays_[date_.month - 1])
	{
		if (date_.month == 2 && isLeapYear())
		{
			date_.day = monthDays_[date_.month - 1] + 1;
			return;
		}
		date_.day = monthDays_[date_.month - 1];
	}
}

size_t Date::toDaysMethod_(const Date& date) const
{
	size_t days = 0;
	for (size_t y = 1; y <= date.getYear(); y++)
	{
		if (isLeapYearMethod_(y))
		{
			days += 366;
		}
		else
		{
			days += 365;
		}
	}
	for (size_t m = 1; m < date.getMonth(); m++)
	{
		if (m == 2 && isLeapYearMethod_(date.getYear()))
		{
			days += monthDays_[m - 1] + 1;
		}
		else
		{
			days += monthDays_[m - 1];
		}
	}
	for (size_t d = 1; d <= date.getDay(); d++)
	{
		days++;
	}
	return days;
}

Date Date::daysToDate_(const size_t& days) const
{
	size_t daysCopy = days;
	size_t years = 0;
	size_t months = 1;
	bool yearsEnough = false;
	bool monthsEnough = false;

	while (!yearsEnough && daysCopy >= 365)
	{
		if (isLeapYearMethod_(years))
		{
			if (daysCopy > 366)
			{
				years++;
				daysCopy -= 366;
			}
			else
			{
				yearsEnough = true;
			}
		}
		else
		{
			if (daysCopy > 365)
			{
				years++;
				daysCopy -= 365;
			}
			else
			{
				yearsEnough = true;
			}
		}
	}
	while (!monthsEnough)
	{
		if (months == 2 && isLeapYearMethod_(years))
		{
			if (daysCopy > monthDays_[months - 1] + 1)
			{
				months++;
				daysCopy -= monthDays_[months - 1] + 1;
			}
			else
			{
				monthsEnough = true;
			}
		}
		else
		{
			if (daysCopy > monthDays_[months - 1])
			{
				daysCopy -= monthDays_[months - 1];
				months++;
			}
			else
			{
				monthsEnough = true;
			}
		}
	}
	if (daysCopy == 0)
	{
		daysCopy = 1;
	}
	if (months == 0)
	{
		months = 1;
	}
	if (years == 0)
	{
		years = 1;
	}
	return Date(daysCopy, months, years);
}

size_t Date::parseStringValue_(const string& value) const
{
	const char* const exceptionMessage = "Incorrect string value. Allowed symbols: [0-9]";
	for (size_t i = 0; i < value.length(); i++)
	{
		if (!isdigit(value[i]))
		{
			throw exception(exceptionMessage);
		}
	}
	return stoul(value);
}

Date::Date() : date_(date_t())
{
}

Date::Date(const string& date)
{
	const triple response = splitString_(date);
	*this = Date(get<0>(response), get<1>(response), get<2>(response));
}

Date::Date(const size_t& day, const size_t& month, const size_t& year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

Date::Date(const string& day, const string& month, const string& year)
{
	*this = Date(parseStringValue_(day), parseStringValue_(month), parseStringValue_(year));
}

size_t Date::getDay() const
{
	return date_.day;
}

size_t Date::getMonth() const
{
	return date_.month;
}

size_t Date::getYear() const
{
	return date_.year;
}

triple Date::getDate() const
{
	return triple(date_.day, date_.month, date_.year);
}

void Date::setDay(const size_t& day)
{
	if (date_.day == 0)
	{
		date_.day = defaultDay_;
	}
	else
	{
		date_.day = day;
	}

	roundDays_();
}

void Date::setDay(const string& day)
{
	setDay(parseStringValue_(day));
}

void Date::setMonth(const size_t& month)
{
	date_.month = roundBy_(month, 13);
	if (month == 0)
	{
		date_.month = defaultMonth_;
	}
	else
	{
		date_.month = month;
	}
	roundDays_();
}

void Date::setMonth(const string& month)
{
	setMonth(parseStringValue_(month));
}

void Date::setYear(const size_t& year)
{
	if (year == 0)
	{
		date_.year = defaultYear_;
	}
	else
	{
		date_.year = year;
	}
	roundDays_();
}

void Date::setYear(const string& year)
{
	setYear(parseStringValue_(year));
}

void Date::setDate(const size_t& day, const size_t& month, const size_t& year)
{
	*this = Date(day, month, year);
}

void Date::setDate(const string& day, const string& month, const string& year)
{
	*this = Date(day, month, year);
}

void Date::setDate(const string& date)
{
	*this = Date(date);
}

/**
 * Алгоритм определения високостного года https://docs.microsoft.com/ru-ru/office/troubleshoot/excel/determine-a-leap-year
 */
bool Date::isLeapYearMethod_(const size_t& year) const
{
	return (year % 100 == 0) ? (year % 400 == 0) : (year % 4 == 0);
}

size_t Date::toDays() const
{
	return toDaysMethod_(*this);
}

bool Date::isLeapYear() const
{
	return isLeapYearMethod_(date_.year);
}

size_t Date::differenceBetween(Date date) const
{
	return static_cast<size_t>(abs(
		static_cast<int64_t>(toDaysMethod_(*this)) - static_cast<int64_t>(toDaysMethod_(date))));
}

Date Date::dateBeforeByDays(const size_t& days) const
{
	const size_t dateDays = toDays() + 1;
	if (days > dateDays)
	{
		throw exception("The date is less than days from parameter");
	}
	return daysToDate_(dateDays - days);
}

Date Date::dateAfterByDays(const size_t& days) const
{
	return daysToDate_(toDays() + 1 + days);
}

Date& Date::operator=(const Date& other)
{
	if (this == &other)
	{
		return *this;
	}
	date_ = other.date_;
	return *this;
}

string Date::toString() const
{
	return string(to_string(date_.day)
		+ '.' + to_string(date_.month)
		+ '.' + to_string(date_.year));
}
