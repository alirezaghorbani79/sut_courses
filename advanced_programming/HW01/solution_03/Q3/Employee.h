

/* Employee.h
CPP_HW01_3
Created By: Hassan Rezaei Nasab
ID: 9622743
*/

#pragma once
#include <iostream>
#include <string>
#include <locale>

using namespace std;

class Employee
{
public:
	//class parameters
	string FirstName;
	string LastName;
	int Id;

	Employee() {// Default Constructor
		setName("", "");
		setId(0);
		setSalary(0, 0);
	}
	Employee(string s1, string s2, int x, float s, float ms) {// Constructor Function

		setName(s1, s2);
		setId(x);
		setSalary(s, ms);

	}

	void setName(string s1, string s2) {
		FirstName = s1;
		LastName = s2;
	}

	void setId(int id) {
		Id = id;
	}

	void setSalary(float x, float y) {
		if (x <= 0) {
			x = 0;
		}
		if (y <= 0) {
			y = 0;
		}
		Salary = x;
		ManagementSalary = y;
	}

	void getInfo() {//gets all information about an employee

		getFirstName();
		getLastName();
		getId();
		getSalary();
		getManagementSalary();

	}

	//get functions
	string getFirstName() { return FirstName; }
	string getLastName() { return LastName; }
	int getId() { return Id; }
	float getSalary() { return Salary; }
	float getManagementSalary() { return ManagementSalary; }

	//prints employee informations
	void print() {

		cout << "First Name :\t" << FirstName << endl << "Last Name :\t"
			<< LastName << endl << "Personnel ID :\t" << Id << endl;
		
		cout << fixed << setprecision(0);
		cout <<"Total Salary :\t" << Salary + ManagementSalary << endl;


	}
private:
	//class parameters ( but very PRIVATE!!!!)
	float Salary;
	float ManagementSalary;

};

