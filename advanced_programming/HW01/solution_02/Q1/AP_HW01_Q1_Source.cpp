#include <iostream>
#include <exception>
#include <iomanip>

#include "OOP_HW01_Q1_Header.h"

using namespace std;



Date::Date(int year, int month, int day)
{
	setDate(year, month, day);
}


// ================================ Set Function ================================
void Date::setDate(int year, int month, int day)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}
Date& Date::setDay(int day)
{
	if ((day >= 1) && (day <= 30))
		this->day = day;
	else
		throw invalid_argument("Ops. Invalid Day! Must be 1-30");

	return *this;
}
Date& Date::setMonth(int month)
{
	if ((month >= 1) && (month <= 12))
		this->month = month;
	else
		throw invalid_argument("Ops. Invalid Month! Must be 1-12");

	return *this;
}
Date& Date::setYear(int year)
{
	if ((year >= 1300) && (year < 1500))
		this->year = year;
	else
		throw invalid_argument("Ops. Invalid Year! Must be 1300-1499");
	return *this;
}


// ================================ Get Function ================================
int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}


// ================================ Print Function ================================
void Date::print1(void) const
{
	cout << day << '-' << month << '-' << year << endl;
}
void Date::print2(void) const
{
	if (month == 1)
		cout << day << '-' << "Farvardin" << '-' << year << endl;
	if (month == 2)
		cout << day << '-' << "Ordibehesht" << '-' << year << endl;
	if (month == 3)
		cout << day << '-' << "Khordad" << '-' << year << endl;
	if (month == 4)
		cout << day << '-' << "Tir" << '-' << year << endl;
	if (month == 5)
		cout << day << '-' << "Mordad" << '-' << year << endl;
	if (month == 6)
		cout << day << '-' << "Shahrivar" << '-' << year << endl;
	if (month == 7)
		cout << day << '-' << "Mehr" << '-' << year << endl;
	if (month == 8)
		cout << day << '-' << "Aban" << '-' << year << endl;
	if (month == 9)
		cout << day << '-' << "Azar" << '-' << year << endl;
	if (month == 10)
		cout << day << '-' << "Dey" << '-' << year << endl;
	if (month == 11)
		cout << day << '-' << "Bahmen" << '-' << year << endl;
	if (month == 12)
		cout << day << '-' << "Esfand" << '-' << year << endl;
}




int main() try
{
	
	Date d1(1379, 12, 20);
	Date* d2 = new Date(1401, 1, 1);

	d1.print1();
	d1.print2();
	cout << "-------------------------" << endl;
	d2->print1();
	d2->print2();


	delete d2;

}

catch (invalid_argument & e)
{
	cout << e.what() << endl;
}

catch (exception & e)
{
	cout << e.what() << endl;
}
