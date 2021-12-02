#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	try
	{
		Date date(30, 2, 2024);
		cout << date.toString();
	}
	catch (const exception& ex)
	{
		cout << "Error: " << ex.what();
	}
	return 0;
}
