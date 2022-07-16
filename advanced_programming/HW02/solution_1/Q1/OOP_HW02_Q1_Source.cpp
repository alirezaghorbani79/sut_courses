#include <iostream>
#include <exception>
#include <ctime>

#include "OOP_HW02_Q1_Header.h"

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
	if ((day >= 1) && (day <= 31))
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
	if ((year >= 1200) && (year < 3000))
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

// ================================ Date Convert ================================
//reference: https://b2n.ir/s13782
Date& Date::fromMiladi(void)
{
	int miladiDayInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int shamsiDayInMinth[12] = { 31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29 };
	int miladiYear, miladiMonth, miladiDay, shamsiYear, shamsiMonth, shamsiDay;
	long miladiDayNum, shamsiDayNum;
	int j_np;
	int i;

	miladiYear = year - 1600;
	miladiMonth = month - 1;
	miladiDay = day - 1;

	miladiDayNum = 365 * miladiYear + (miladiYear + 3) / 4 - (miladiYear + 99) / 100 + (miladiYear + 399) / 400;
	for (i = 0; i < miladiMonth; ++i)
		miladiDayNum += miladiDayInMonth[i];
	if (miladiMonth > 1 && ((miladiYear % 4 == 0 && miladiYear % 100 != 0) || (miladiYear % 400 == 0)))
		++miladiDayNum;
	miladiDayNum += miladiDay;

	shamsiDayNum = miladiDayNum - 79;

	j_np = shamsiDayNum / 12053;
	shamsiDayNum %= 12053;

	shamsiYear = 979 + 33 * j_np + 4 * (shamsiDayNum / 1461);
	shamsiDayNum %= 1461;

	if (shamsiDayNum >= 366) 
	{
		shamsiYear += (shamsiDayNum - 1) / 365;
		shamsiDayNum = (shamsiDayNum - 1) % 365;
	}

	for (i = 0; i < 11 && shamsiDayNum >= shamsiDayInMinth[i]; ++i) 
		shamsiDayNum -= shamsiDayInMinth[i];
	shamsiMonth = i + 1;
	shamsiDay = shamsiDayNum + 1;


	setYear(shamsiYear);
	setMonth(shamsiMonth);
	setDay(shamsiDay);

	return *this;
}

Date& Date::toMiladi(void)
{
	int miladiDayInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int shamsiDayInMonth[12] = { 31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29 };
	int miladiYear, miladiMonth, miladiDay, shamsiYear, shamsiMonth, shamsiDay;
	long miladiDayNum, shamsiDayNum;
	int leap;
	int i;

	shamsiYear = year - 979;
	shamsiMonth = month - 1;
	shamsiDay = day - 1;

	shamsiDayNum = 365 * shamsiYear + (shamsiYear / 33) * 8 + (shamsiYear % 33 + 3) / 4;

	for (i = 0; i < shamsiMonth; ++i)
		shamsiDayNum += shamsiDayInMonth[i];

	shamsiDayNum += shamsiDay;
	miladiDayNum = shamsiDayNum + 79;
	miladiYear = 1600 + 400 * (miladiDayNum / 146097);
	miladiDayNum = miladiDayNum % 146097;

	leap = 1;
	if (miladiDayNum >= 36525)
	{
		miladiDayNum--;
		miladiYear += 100 * (miladiDayNum / 36524);
		miladiDayNum = miladiDayNum % 36524;

		if (miladiDayNum >= 365)
			miladiDayNum++;
		else
			leap = 0;
	}

	miladiYear += 4 * (miladiDayNum / 1461);
	miladiDayNum %= 1461;

	if (miladiDayNum >= 366) 
	{
		leap = 0;

		miladiDayNum--;
		miladiYear += miladiDayNum / 365;
		miladiDayNum = miladiDayNum % 365;
	}

	for (i = 0; miladiDayNum >= miladiDayInMonth[i] + (i == 1 && leap); i++)
		miladiDayNum -= miladiDayInMonth[i] + (i == 1 && leap);

	miladiMonth = i + 1;
	miladiDay = miladiDayNum + 1;


	setYear(miladiYear);
	setMonth(miladiMonth);
	setDay(miladiDay);

	return *this;
}

Date& Date::syncDate(void)
{
	// current date/time based on current system
	time_t now = time(NULL);
	tm currentTime;
	localtime_s(&currentTime, &now);

	setYear(currentTime.tm_year + 1900);
	setMonth(currentTime.tm_mon + 1);
	setDay(currentTime.tm_mday);

	return *this;
}


// ================================ Print Function ================================
Date& Date::print1(void) 
{
	cout << day << '-' << month << '-' << year << endl;
	return *this;
}
Date& Date::print2(void)
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

	return *this;
}




int main() try
{
	Date* d1 = new Date;
	d1->print1().toMiladi().print1();
	cout << endl;
	d1->syncDate().print1().fromMiladi().print1();

	cout << endl;

	Date* d2 = new Date(1357, 11, 22);
	d2->print1();
	d2->toMiladi().print1();

	cout << endl;

	Date d3(1200, 13, 14);
	d3.print1();

}

catch (invalid_argument& e)
{
	cout << e.what() << endl;
}

catch (exception& e)
{
	cout << e.what() << endl;
}