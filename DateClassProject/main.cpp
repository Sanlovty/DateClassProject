#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	try
	{
		Date date(3, 12, 2021);
		cout << endl << date.dateBeforeByDays(745).toString() << endl;
		cout << endl << date.dateAfterByDays(745).toString() << endl;
	}
	catch (const exception& ex)
	{
		cout << "Error: " << ex.what();
	}
	return 0;
}
