#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <tuple>
#include <string>

using std::string;
using std::tuple;
using std::cout;
using std::endl;
using std::isdigit;
using std::to_string;
using std::exception;
using std::stoul;
using std::get;
using std::abs;
using triple = tuple<size_t, size_t, size_t>;

class Date
{
	const char stringSeparator_ = '.';
	static const size_t defaultDay_ = 1;
	static const size_t defaultMonth_ = 1;
	static const size_t defaultYear_ = 1970;
	const size_t monthDays_[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	struct date_t
	{
		size_t year;
		size_t month;
		size_t day;

		date_t() : year(defaultYear_), month(defaultMonth_), day(defaultDay_)
		{
		}

		date_t(const size_t& year, const size_t& month, const size_t& day) : year(year), month(month), day(day)
		{
		}
	} date_;

	triple splitString_(const string& date) const;
	size_t roundBy_(const size_t& value, const size_t& bound) const;
	size_t parseStringValue_(const string& value) const;
	bool isLeapYearMethod_(const size_t& year) const;

	void roundDays_();
	size_t toDaysMethod_(const Date& date) const;
	Date daysToDate_(const size_t& days) const;

public:
	Date();
	Date(const string& date);
	Date(const size_t& day, const size_t& month, const size_t& year);
	Date(const string& day, const string& month, const string& year);

	size_t getDay() const;
	size_t getMonth() const;
	size_t getYear() const;
	triple getDate() const;

	void setDay(const size_t& day);
	void setDay(const string& day);
	void setMonth(const size_t& month);
	void setMonth(const string& month);
	void setYear(const size_t& year);
	void setYear(const string& year);
	void setDate(const size_t& day, const size_t& month, const size_t& year);
	void setDate(const string& day, const string& month, const string& year);
	void setDate(const string& date);

	size_t toDays() const;
	bool isLeapYear() const;
	size_t differenceBetween(Date date) const;
	Date dateBeforeByDays(const size_t& days) const;
	Date dateAfterByDays(const size_t& days) const;

	Date& operator =(const Date& other);
	string toString() const;
};

#endif
