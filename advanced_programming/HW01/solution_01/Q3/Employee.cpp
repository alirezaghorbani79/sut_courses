//
// Created by Alireza Ghorbani on 2/19/2022.
//

#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee(int id, string name, float salary, float managementFee) {
    setData(id, name, salary, managementFee);
}

Employee &Employee::setData(int id, string name, float salary, float managementFee) {
    setId(id);
    setName(name);
    setSalary(salary);
    setManagementFee(managementFee);
}

Employee &Employee::setId(int id) {
    this->id = id;

    return *this;
}

Employee &Employee::setSalary(float salary) {
    if (salary < 0) this->salary = 0;
    else this->salary = salary;

    return *this;
}

Employee &Employee::setManagementFee(float fee) {
    if (fee < 0) this->managementFee = 0;
    else this->managementFee = fee;

    return *this;
}

Employee &Employee::setName(string name) {
    this->name = name;

    return *this;
}

int Employee::getId() const {
    return this->id;
}

float Employee::getSalary() const {
    return this->salary;
}

float Employee::getManagementSalary() const {
    return this->managementFee;
}

string Employee::getName() const {
    return this->name;
}

void Employee::print() {
    cout.precision(20);

    cout << "===================================" << endl;
    cout << "ID:" << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Payment: " << getSalary() + getManagementSalary() << endl;
    cout << "===================================" << endl;

}

