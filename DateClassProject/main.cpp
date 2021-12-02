#include <iostream>
#include "Date.h"
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	try
	{
		Date date1(3, 12, 2021);
		Date date2(25, 8, 2021);

		cout << endl << "���������� ���� ����� " << date1.toString() << " � " << date2.toString() << " = " << date1.
			differenceBetween(date2) << endl;
		cout << endl << "����� 745 ���� �� " << date1.toString() << " ����� " << date1.dateBeforeByDays(745).toString()
			<< endl;
		cout << endl << "745 ���� ����� �� " << date1.toString() << " ����� " << date1.dateAfterByDays(745).toString()
			<< endl;
		cout << endl << "��������� ���� " << date1.toString() << " ���� 15 ";
		date1.setDay(15);
		cout << "� ������� " << date1.toString() << endl;
		cout << endl << "��������� ���� " << date1.toString() << " ���� 32 ";
		date1.setDay(32);
		cout << "� ������� " << date1.toString() << endl;
		cout << endl << "��������� ���� " << date1.toString() << " ����� 15 ";
		date1.setMonth(15);
		cout << "� ������� " << date1.toString() << endl;
		cout << endl << "��������� ���� " << date1.toString() << " ����� 2 ";
		date1.setMonth(2);
		cout << "� ������� " << date1.toString() << endl;
		cout << endl << "��������� ���� " << date1.toString() << " ��� 2004 ";
		date1.setYear(2004);
		cout << "� ������� " << date1.toString() << endl;
	}
	catch (const exception& ex)
	{
		cout << "Error: " << ex.what();
	}
	return 0;
}
