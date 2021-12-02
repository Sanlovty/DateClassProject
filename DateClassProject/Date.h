#ifndef DATE_H
#define DATE_H

/**
 * Это стандартная библиотека, в которой можно пользоваться картежами
 * Кортеж это набор значений, пакующихся в один тип данных ( грубо говоря, массив элементов)
 * Прочитать можно про них любую статью, если интересно.
 * Создаются они так: tuple<тип1, тип2,...., типN>  name - так мы создаём картеж на N элементов разных(возможно одинаковых)
 * типов.
 * Чтобы потом получать элементы кортежа мы должны писать get<N>(name), где N- номер элемента в кортеже, а name - название кортежа
 */
#include <tuple>
#include <string>

/**
 * чтобы не тянуть using namespace std; и не писать у каждого вызова этиъ функций std::
 * по отдельности используем нужные
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
 *  мы не хотим каждый раз везде писать tuple<size_t, size_t, size_t>, поэтому пишем using
 *	using в данном случае выступает аналогом typedef. Так, мы просто именуем тип. Слева от равно - название, справа - существующий тип
 *	using triple = tuple<size_t, size_t, size_t>; равносильно написанию typedef tuple<size_t, size_t, size_t> triple;
 */
using triple = tuple<size_t, size_t, size_t>;

/**
 * Собственно наш класс Date
 */
class Date
{
	// Возможно мы захотим поменять когда-либо разделитель даты, поэтому делаем символ константым
	const char stringSeparator_ = '.';
	// Константа дня по умолчанию
	static const size_t defaultDay_ = 1;
	// Константа месяца по умолчанию
	static const size_t defaultMonth_ = 1;
	// Константа года по умолчанию
	static const size_t defaultYear_ = 1970;
	// Константый массив кол-ва дней в месяце, так для 12 месяца его кол-вом дней будет monthDays_[12-1]. -1 т.к. нумерация с нуля
	// Нюанс: Февраль([2-1]) в обычный год - 28, високостный - 29
	const size_t monthDays_[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// По заданию мы должны были хранить всё в структуре. Я объвляю структуру и сразу же создаю переменную date_ этого типа
	struct date_t
	{
		// год
		size_t year;
		// месяц
		size_t month;
		// день
		size_t day;

		/*
		 * Стандартный (дефолтный) конструктор без параметров. На случай, если мы захотим написать date_t name; *не укажем значения по умолчанию*
		 */
		date_t() : year(defaultYear_), month(defaultMonth_), day(defaultDay_)
		{
		}

		/*
		 * Конструктор с параметрами, для случая date_t name(1,2,3);
		 */
		date_t(const size_t& year, const size_t& month, const size_t& day) : year(year), month(month), day(day)
		{
		}
	} date_;

	/*
	 * Приватный метод, которому на вход подаётся строка. (случаи, когда мы пытаемся инциализировать Date с помощью string)
	 * Эта строка должна быть формата число(разделитель)число(разделитель)число *10.10.2001*. Если такого нет - вылетает ошибка
	 * Иначе создаётся кортеж, в который помещаются 3 числа (день, месяц, год)
	 */
	triple splitString_(const string& date) const;
	/*
	 * Приватный метод, который принимает число(value) и границу(bound), по которой он будет округлён(остаток от деления). Так roundBy_(10,8) вернёт 8
	 */
	size_t roundBy_(const size_t& value, const size_t& bound) const;
	/*
	 * Приватный метод, который принимает строку, содержающую только число(предположительно). Если находится другой символ - кидает
	 * ошибку, иначе возвращает число, которое было записано в строке
	 */
	size_t parseStringValue_(const string& value) const;
	/*
	 * Приватный метод, который принимает год и определяет, является ли год високостный
	 * true - если да, иначе - false
	 */
	bool isLeapYearMethod_(const size_t& year) const;

	/*
	 * Приватный метод, который вызывается когда каким-либо образом изменяется наша дата, будь то setDay, setMonth, setYear, setData.
	 * Он не даёт дню быть больше, чем в месяце есть.
	 */
	void roundDays_();
	/*
	 * Приватный метод, который принимает Дату и преобразует её в количество дней с 01.01.1
	 */
	size_t toDaysMethod_(const Date& date) const;
	/*
	 * Приватный метод, который принимает количество дней с 01.01.1 и превращает их в Дату
	 */
	Date daysToDate_(const size_t& days) const;

public:
	/*
	 * Конструктор по умолчанию
	 */
	Date();
	/*
	 * Конструктор, инициализирующий с помощью строки вида "01.09.2001" или "1.9.2001"
	 */
	Date(const string& date);
	/*
	 * Конструктор, инициализирующий с помощью трёх числовых значений (день, месяц, год)
	 */
	Date(const size_t& day, const size_t& month, const size_t& year);
	/*
	 * Конструктор, инициализирующий с помощью трёх строковых значений (день, месяц, год). Пример: Date("01","10","2021")
	 */
	Date(const string& day, const string& month, const string& year);

	/*
	 * Публичный метод, возвращающий день(day) нашей даты(date_)
	 */
	size_t getDay() const;
	/*
	 * Публичный метод, возвращающий месяц(month) нашей даты(date_)
	 */
	size_t getMonth() const;
	/*
	 * Публичный метод, возвращающий год(year) нашей даты(date_)
	 */
	size_t getYear() const;
	/*
	 * Публичный метод, возвращающий кортеж из трёх значений сразу: <день,месяц,год> (date_.day,date_.month,date_.year)
	 */
	triple getDate() const;

	/*
	 * Публичный метод, позволяющий установить день с помощью числового значения
	 */
	void setDay(const size_t& day);
	/*
	 * Публичный метод, позволяющий установить день с помощью строкового значения
	 */
	void setDay(const string& day);
	/*
	 * Публичный метод, позволяющий установить месяц с помощью числового значения
	 */
	void setMonth(const size_t& month);
	/*
	 * Публичный метод, позволяющий установить месяц с помощью строкового значения
	 */
	void setMonth(const string& month);
	/*
	 * Публичный метод, позволяющий установить год с помощью числового значения
	 */
	void setYear(const size_t& year);
	/*
	 * Публичный метод, позволяющий установить год с помощью строкового значения
	 */
	void setYear(const string& year);
	/*
	 * Публичный метод, позволяющий установить дату целиком с помощью 3 числовых значений
	 */
	void setDate(const size_t& day, const size_t& month, const size_t& year);
	/*
	 * Публичный метод, позволяющий установить дату целиком с помощью 3 строковых значений
	 */
	void setDate(const string& day, const string& month, const string& year);
	/*
	 * Публичный метод, позволяющий установить дату целиком с помощью строки
	 */
	void setDate(const string& date);

	/*
	 * Публичный метод, возвращающий количество дней с момента 01.01.1 до date_
	 */
	size_t toDays() const;
	/*
	 * Публичный метод, возвращающий true, если год високостный, иначе false
	 */
	bool isLeapYear() const;
	/*
	 * Публичный метод, возвращающий количество дней между date_ и параметром date
	 */
	size_t differenceBetween(Date date) const;
	/*
	 * Публичный метод, возвращающий Дату за days дней
	 */
	Date dateBeforeByDays(const size_t& days) const;
	/*
	 * Публичный метод, возвращающий Дату через days дней
	 */
	Date dateAfterByDays(const size_t& days) const;

	/*
	 * Переопределение оператора =, для того, чтобы возможно было писать так: Date date; date = Date();
	 */
	Date& operator =(const Date& other);
	/*
	 * Публичный метод, возвращающий Дату в виде строки
	 */
	string toString() const;
};

#endif
