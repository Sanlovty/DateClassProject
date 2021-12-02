#ifndef DATE_H
#define DATE_H

/**
 * ��� ����������� ����������, � ������� ����� ������������ ���������
 * ������ ��� ����� ��������, ���������� � ���� ��� ������ ( ����� ������, ������ ���������)
 * ��������� ����� ��� ��� ����� ������, ���� ���������.
 * ��������� ��� ���: tuple<���1, ���2,...., ���N>  name - ��� �� ������ ������ �� N ��������� ������(�������� ����������)
 * �����.
 * ����� ����� �������� �������� ������� �� ������ ������ get<N>(name), ��� N- ����� �������� � �������, � name - �������� �������
 */
#include <tuple>
#include <string>

/**
 * ����� �� ������ using namespace std; � �� ������ � ������� ������ ���� ������� std::
 * �� ����������� ���������� ������
 */
using std::string;
using std::tuple;
using std::isdigit;
using std::to_string;
using std::exception;
using std::stoul;
using std::get;
using std::abs;
/*
 *  �� �� ����� ������ ��� ����� ������ tuple<size_t, size_t, size_t>, ������� ����� using
 *	using � ������ ������ ��������� �������� typedef. ���, �� ������ ������� ���. ����� �� ����� - ��������, ������ - ������������ ���
 *	using triple = tuple<size_t, size_t, size_t>; ����������� ��������� typedef tuple<size_t, size_t, size_t> triple;
 */
using triple = tuple<size_t, size_t, size_t>;

/**
 * ���������� ��� ����� Date
 */
class Date
{
	// �������� �� ������� �������� �����-���� ����������� ����, ������� ������ ������ ����������
	const char stringSeparator_ = '.';
	// ��������� ��� �� ���������
	static const size_t defaultDay_ = 1;
	// ��������� ������ �� ���������
	static const size_t defaultMonth_ = 1;
	// ��������� ���� �� ���������
	static const size_t defaultYear_ = 1970;
	// ���������� ������ ���-�� ���� � ������, ��� ��� 12 ������ ��� ���-��� ���� ����� monthDays_[12-1]. -1 �.�. ��������� � ����
	// �����: �������([2-1]) � ������� ��� - 28, ����������� - 29
	const size_t monthDays_[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// �� ������� �� ������ ���� ������� �� � ���������. � ������� ��������� � ����� �� ������ ���������� date_ ����� ����
	struct date_t
	{
		// ���
		size_t year;
		// �����
		size_t month;
		// ����
		size_t day;

		/*
		 * ����������� (���������) ����������� ��� ����������. �� ������, ���� �� ������� �������� date_t name; *�� ������ �������� �� ���������*
		 */
		date_t() : year(defaultYear_), month(defaultMonth_), day(defaultDay_)
		{
		}

		/*
		 * ����������� � �����������, ��� ������ date_t name(1,2,3);
		 */
		date_t(const size_t& year, const size_t& month, const size_t& day) : year(year), month(month), day(day)
		{
		}
	} date_;

	/*
	 * ��������� �����, �������� �� ���� ������� ������. (������, ����� �� �������� ��������������� Date � ������� string)
	 * ��� ������ ������ ���� ������� �����(�����������)�����(�����������)����� *10.10.2001*. ���� ������ ��� - �������� ������
	 * ����� �������� ������, � ������� ���������� 3 ����� (����, �����, ���)
	 */
	triple splitString_(const string& date) const;
	/*
	 * ��������� �����, ������� ��������� �����(value) � �������(bound), �� ������� �� ����� �������(������� �� �������). ��� roundBy_(10,8) ����� 8
	 */
	size_t roundBy_(const size_t& value, const size_t& bound) const;
	/*
	 * ��������� �����, ������� ��������� ������, ����������� ������ �����(����������������). ���� ��������� ������ ������ - ������
	 * ������, ����� ���������� �����, ������� ���� �������� � ������
	 */
	size_t parseStringValue_(const string& value) const;
	/*
	 * ��������� �����, ������� ��������� ��� � ����������, �������� �� ��� �����������
	 * true - ���� ��, ����� - false
	 */
	bool isLeapYearMethod_(const size_t& year) const;

	/*
	 * ��������� �����, ������� ���������� ����� �����-���� ������� ���������� ���� ����, ���� �� setDay, setMonth, setYear, setData.
	 * �� �� ��� ��� ���� ������, ��� � ������ ����.
	 */
	void roundDays_();
	/*
	 * ��������� �����, ������� ��������� ���� � ����������� � � ���������� ���� � 01.01.1
	 */
	size_t toDaysMethod_(const Date& date) const;
	/*
	 * ��������� �����, ������� ��������� ���������� ���� � 01.01.1 � ���������� �� � ����
	 */
	Date daysToDate_(const size_t& days) const;

public:
	/*
	 * ����������� �� ���������
	 */
	Date();
	/*
	 * �����������, ���������������� � ������� ������ ���� "01.09.2001" ��� "1.9.2001"
	 */
	Date(const string& date);
	/*
	 * �����������, ���������������� � ������� ��� �������� �������� (����, �����, ���)
	 */
	Date(const size_t& day, const size_t& month, const size_t& year);
	/*
	 * �����������, ���������������� � ������� ��� ��������� �������� (����, �����, ���). ������: Date("01","10","2021")
	 */
	Date(const string& day, const string& month, const string& year);

	/*
	 * ��������� �����, ������������ ����(day) ����� ����(date_)
	 */
	size_t getDay() const;
	/*
	 * ��������� �����, ������������ �����(month) ����� ����(date_)
	 */
	size_t getMonth() const;
	/*
	 * ��������� �����, ������������ ���(year) ����� ����(date_)
	 */
	size_t getYear() const;
	/*
	 * ��������� �����, ������������ ������ �� ��� �������� �����: <����,�����,���> (date_.day,date_.month,date_.year)
	 */
	triple getDate() const;

	/*
	 * ��������� �����, ����������� ���������� ���� � ������� ��������� ��������
	 */
	void setDay(const size_t& day);
	/*
	 * ��������� �����, ����������� ���������� ���� � ������� ���������� ��������
	 */
	void setDay(const string& day);
	/*
	 * ��������� �����, ����������� ���������� ����� � ������� ��������� ��������
	 */
	void setMonth(const size_t& month);
	/*
	 * ��������� �����, ����������� ���������� ����� � ������� ���������� ��������
	 */
	void setMonth(const string& month);
	/*
	 * ��������� �����, ����������� ���������� ��� � ������� ��������� ��������
	 */
	void setYear(const size_t& year);
	/*
	 * ��������� �����, ����������� ���������� ��� � ������� ���������� ��������
	 */
	void setYear(const string& year);
	/*
	 * ��������� �����, ����������� ���������� ���� ������� � ������� 3 �������� ��������
	 */
	void setDate(const size_t& day, const size_t& month, const size_t& year);
	/*
	 * ��������� �����, ����������� ���������� ���� ������� � ������� 3 ��������� ��������
	 */
	void setDate(const string& day, const string& month, const string& year);
	/*
	 * ��������� �����, ����������� ���������� ���� ������� � ������� ������
	 */
	void setDate(const string& date);

	/*
	 * ��������� �����, ������������ ���������� ���� � ������� 01.01.1 �� date_
	 */
	size_t toDays() const;
	/*
	 * ��������� �����, ������������ true, ���� ��� �����������, ����� false
	 */
	bool isLeapYear() const;
	/*
	 * ��������� �����, ������������ ���������� ���� ����� date_ � ���������� date
	 */
	size_t differenceBetween(Date date) const;
	/*
	 * ��������� �����, ������������ ���� �� days ����
	 */
	Date dateBeforeByDays(const size_t& days) const;
	/*
	 * ��������� �����, ������������ ���� ����� days ����
	 */
	Date dateAfterByDays(const size_t& days) const;

	/*
	 * ��������������� ��������� =, ��� ����, ����� �������� ���� ������ ���: Date date; date = Date();
	 */
	Date& operator =(const Date& other);
	/*
	 * ��������� �����, ������������ ���� � ���� ������
	 */
	string toString() const;
};

#endif
