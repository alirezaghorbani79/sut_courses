

/* Employee.cpp : This file contains the 'main' function. Program execution begins and ends there.
CPP_HW01_3
Created By: Hassan Rezaei Nasab
ID: 9622743
*/

#include <iostream>
#include <iomanip>
#include "Employee.h"

using namespace std;

int main()
{
	//poor normal employee!! production
	Employee NormalEmployee(" ", " ", 0, 0, 0);

	NormalEmployee.setName("Mostafa", "Kabiri");
	NormalEmployee.setId(352698);
	NormalEmployee.setSalary(2500000, 0);

	//rich abnormal employee!! production
	Employee AbnormalEmployee(" ", " ", 0, 0, 0);

	AbnormalEmployee.setName("Mojtaba", "Ahmadi");
	AbnormalEmployee.setId(303500);
	AbnormalEmployee.setSalary(20000000, 5000000);

	//printing their info
	cout << "<<Employee Information Display>>" << endl;

	NormalEmployee.print();

	cout << endl;

	AbnormalEmployee.print();

}
