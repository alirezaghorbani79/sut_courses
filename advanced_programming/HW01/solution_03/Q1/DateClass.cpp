/* DateClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
CPP_HW01_1
Created By: Hassan Rezaei Nasab
ID: 9622743
*/

#include <iostream>
#include <iomanip>

using namespace std;


class Date {
public:

	int year = 0;
	int month = 0;
	int day = 0;

	Date(int y, int m, int d) {//Default Constructor

		set_day(d);
		set_month(m);
		set_year(y);
	};

	void set_day(int d) 
	{
		try
		{
			if (d <= 0 || d >= 32)
				throw "Day is out of range! try again: "; // throw exception of type const char*

			// Otherwise
			day = d;
		}
		catch (const char* exception) // catch exceptions of type const char*
		{
			std::cerr << "Error: " << exception << '\n';

		}
	}

	void set_month(int m) 
	{
		try
		{
			if (m <= 0 || m >= 13)
				throw "Month is out of range! try again: "; // throw exception of type const char*

			// Otherwise
			month = m;
		}
		catch (const char* exception) // catch exceptions of type const char*
		{
			std::cerr << "Error: " << exception << '\n';

		}
	}

	void set_year(int y)
	{
		try
		{
			if (y <= 0 || y >= 1500)
				throw "Year is out of range! try again: "; // throw exception of type const char*

			// Otherwise
			year = y;
		}
		catch (const char* exception) // catch exceptions of type const char*
		{
			std::cerr << "Error: " << exception << '\n';

		}
	}
	void print1() {

		cout << setw(2) << setfill('0') << year << "-" << setw(2) << setfill('0')
			<< month << "-" << setw(2) << setfill('0') << day << endl;
	}

	void print2() {

		switch (month)
		{
		case 1:
			cout << year << "-" << "Farvardin" << "-" << day << endl;
			break;
		case 2:
			cout << year << "-" << "Ordibehesht" << "-" << day << endl;
			break;
		case 3:
			cout << year << "-" << "Khordad" << "-" << day << endl;
			break;
		case 4:
			cout << year << "-" << "Tir" << "-" << day << endl;
			break;
		case 5:
			cout << year << "-" << "Mordad" << "-" << day << endl;
			break;
		case 6:
			cout << year << "-" << "Shahrivar" << "-" << day << endl;
			break;
		case 7:
			cout << year << "-" << "Mehr" << "-" << day << endl;
			break;
		case 8:
			cout << year << "-" << "Aban" << "-" << day << endl;
			break;
		case 9:
			cout << year << "-" << "Azar" << "-" << day << endl;
			break;
		case 10:
			cout << year << "-" << "Day" << "-" << day << endl;
			break;
		case 11:
			cout << year << "-" << "Bahman" << "-" << day << endl;
			break;
		case 12:
			cout << year << "-" << "Esfand" << "-" << day << endl;
			break;
		}


	}

};

int main()
{
	Date d1(1400, 12, 12);//Object #1 & Stack
	Date* d2 = new Date(1400, 12, 29);//Object #2 & Dynamic

	cout << "First Date was :";
	d1.print1();//print1 for Object #1
	cout << "Or" << endl;
	d1.print2();//print2 for Object #1

	cout << endl << "And Second Date will be:";
	d2->print1();//print1 for Object #2
	cout << "Or" << endl;
	d2->print2();//print2 for Object #2

	delete[] d2;//deleting Object #2
}


