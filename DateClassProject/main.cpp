#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	try
	{
		Date date(28, 2, 2021);
		cout << endl << date.toDaysMethod_(date) << endl;
		cout << date.differenceBetween(Date(20, 9, 2024));
	}
	catch (const exception& ex)
	{
		cout << "Error: " << ex.what();
	}
	return 0;
}
