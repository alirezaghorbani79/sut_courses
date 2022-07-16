#pragma once


class Date
{

public:

	Date(int year = 1400, int month = 12, int day = 12);

	void setDate(int year, int month, int day);
	Date& setDay(int day);
	Date& setMonth(int month);
	Date& setYear(int year);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	Date& fromMiladi(void);
	Date& toMiladi(void);
	Date& syncDate(void);

	Date& print2(void);
	Date& print1(void);

private:
	int day, month, year;

};
