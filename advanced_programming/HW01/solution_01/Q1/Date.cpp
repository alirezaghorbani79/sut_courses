//
// Created by Alireza Ghorbani on 2/19/2022.
//

#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int year, int month, int day) {
    setDate(year, month, day);
}

Date &Date::setDate(int year, int month, int day) {
    setYear(year);
    setMonth(month);
    setDay(day);

    return *this;
}

Date &Date::setYear(int year) {
    this->year = year;

    return *this;
}

Date &Date::setMonth(int month) {
    this->month = month;

    return *this;
}

Date &Date::setDay(int day) {
    this->day = day;
}

int Date::getYear() const {
    return this->year;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getDay() const {
    return this->day;
}

std::string Date::getStrMonth(int month) const {
    return this->months[month];
}

void Date::print1() const {
    cout << getYear() << "-" << getMonth() << "-" << getDay() << endl;
}

void Date::print2() const {
    cout << getYear() << "-" << getStrMonth(getMonth()) << "-" << getDay() << endl;
}
