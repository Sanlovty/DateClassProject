#ifndef DATE_H
#define DATE_H
#include <tuple>
#include <string>

using std::string;
using std::tuple;
using std::isdigit;
using std::to_string;
using std::exception;
using std::stoul;
using std::get;

class Date
{
	const char stringSeparator_ = '.';
	static const size_t defaultDay_ = 1;
	static const size_t defaultMonth_ = 1;
	static const size_t defaultYear_ = 1970;

	using triple = tuple<size_t, size_t, size_t>;

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
	};


	date_t date_;

	triple splitString_(const string& date) const;
	size_t parseStringValue_(const string& value) const;
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

	Date& operator =(const Date& other);
	string toString() const;
};

#endif
