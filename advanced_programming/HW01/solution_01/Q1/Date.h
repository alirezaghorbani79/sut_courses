//
// Created by Alireza Ghorbani on 2/19/2022.
//

#ifndef Q1_DATE_H
#define Q1_DATE_H


class Date {
public:
    //Constructor
    Date(int year = 0, int month = 0, int day = 0);

    //Setter methods
    Date &setDate(int , int, int);
    Date &setYear(int);
    Date &setMonth(int);
    Date &setDay(int);

    //Getter methods
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    std::string getStrMonth(int) const;

    //Print methods
    void print1() const;
    void print2() const;

private:
    //Fields
    int year, month, day;
    std::string months[12] = {"Farvardin", "Ordibehesht", "Khordad",
                              "Tir", "Mordad", "Shahrivar",
                              "Mehr","Aban", "Azar",
                              "Dey", "Bahman", "Esfand"};
};


#endif //Q1_DATE_H
