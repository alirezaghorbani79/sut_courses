#pragma once

#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
	Employee(string name = "Employee-0", int ID = 1111, float salary = 5000000, float manageCost = 2000000)
	{
		setEmployee(name, ID, salary, manageCost);
	}
	// ================================ Set Function ================================
	void setEmployee(string name, int ID, float salary, float manageCost)
	{
		setName(name);
		setID(ID);
		setSalary(salary);
		setManageCost(manageCost);

	}
	Employee& setName(string name)
	{
		this->name = name;
		return *this;
	}
	Employee& setID(int ID)
	{
		if (ID > 0)
			this->ID = ID;
		else
			this->ID = 0;
		return *this;
	}
	Employee& setSalary(float salary)
	{
		if (salary >= 0)
			this->salary = salary;
		else
			this->salary = 0;
		return *this;
	}
	Employee& setManageCost(float manageCost)
	{
		if (manageCost >= 0)
			this->manageCost = manageCost;
		else
			this->manageCost = 0;
		return *this;
	}
	// ================================ Get Function ================================
	string getName() const
	{
		return name;
	}
	int getID() const
	{
		return ID;
	}
	float getSalary() const
	{
		return salary;
	}
	float getManageCost() const
	{
		return manageCost;
	}

	void print(void) const
	{
		cout << "Name: " << name << endl << "Personnel ID: " << ID << endl;
		cout << "Total Salary: " << salary + manageCost << endl;
	}


	string name;
	int ID;

private:
	float salary, manageCost;

};
