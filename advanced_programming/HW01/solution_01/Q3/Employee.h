//
// Created by Alireza Ghorbani on 2/19/2022.
//

#ifndef Q3_EMPLOYEE_H
#define Q3_EMPLOYEE_H

using namespace std;

class Employee {
public:
    int id;
    string name;

    Employee();
    Employee(int, string, float, float);

    Employee &setData(int, string , float, float);
    Employee &setId(int);
    Employee &setSalary(float);
    Employee &setManagementFee(float);
    Employee &setName(string);

    int getId() const;
    float getSalary() const;
    float getManagementSalary() const;
    string getName() const;

    void print();


private:
    float salary;
    float managementFee;
};


#endif //Q3_EMPLOYEE_H
