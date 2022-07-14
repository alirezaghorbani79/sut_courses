#pragma once


class Date
{

public:

	Date(int year = 0, int month = 0, int day = 0);
	void setDate(int year, int month, int day);
	Date& setDay(int day);
	Date& setMonth(int month);
	Date& setYear(int year);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void print2(void) const;
	void print1(void) const;

private:
	int day, month, year;

};
