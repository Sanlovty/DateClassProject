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
	setDay(get<0>(response));
	setMonth(get<1>(response));
	setYear(get<2>(response));
}

Date::Date(const size_t& day, const size_t& month, const size_t& year) : date_(day, month, year)
{
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
	date_.day = day % 32;
	if (date_.day == 0)
	{
		date_.day = defaultDay_;
	}
}

void Date::setDay(const string& day)
{
	setDay(parseStringValue_(day));
}

void Date::setMonth(const size_t& month)
{
	date_.month = month % 13;
	if (date_.month == 0)
	{
		date_.month = defaultMonth_;
	}
}

void Date::setMonth(const string& month)
{
	setMonth(parseStringValue_(month));
}

void Date::setYear(const size_t& year)
{
	date_.year = year == 0 ? defaultYear_ : year;
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

bool Date::isLeapYear() const
{
	if (date_.year % 4 == 0)
	{
		if (date_.year % 100 == 0)
		{
			return true;
		}
		if (date_.year % 400 == 0)
		{
			return true;
		}
		return false;
	}
	return false;
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
