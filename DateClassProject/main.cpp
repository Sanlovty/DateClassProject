#include <iostream>
#include "Date.h"
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(65001); // если с этим не будет русских символов, то вставь 65001, вместо 1251
	try
	{
		Date date1(3, 12, 2021);
		Date date2(25, 8, 2021);

		cout << endl << "Количество дней между " << date1.toString() << " и " << date2.toString() << " = " << date1.
			differenceBetween(date2) << endl;
		cout << endl << "Через 745 дней от " << date1.toString() << " будет " << date1.dateBeforeByDays(745).toString()
			<< endl;
		cout << endl << "745 дней назад от " << date1.toString() << " будет " << date1.dateAfterByDays(745).toString()
			<< endl;
		cout << endl << "Установим дате " << date1.toString() << " день 15 ";
		date1.setDay(15);
		cout << "и получим " << date1.toString() << endl;
		cout << endl << "Установим дате " << date1.toString() << " день 32 ";
		date1.setDay(32);
		cout << "и получим " << date1.toString() << endl;
		cout << endl << "Установим дате " << date1.toString() << " месяц 15 ";
		date1.setMonth(15);
		cout << "и получим " << date1.toString() << endl;
		cout << endl << "Установим дате " << date1.toString() << " месяц 2 ";
		date1.setMonth(2);
		cout << "и получим " << date1.toString() << endl;
		cout << endl << "Установим дате " << date1.toString() << " год 2004 ";
		date1.setYear(2004);
		cout << "и получим " << date1.toString() << endl;
	}
	catch (const exception& ex)
	{
		cout << "Error: " << ex.what();
	}
	return 0;
}
