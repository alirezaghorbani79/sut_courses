#include <iostream>
#include <string>

#include "OOP_HW01_Q3_Header.h"

using namespace std;


int main()
{ 
	Employee e1("Reza Adinepour", 9814303, 2500000, 0);
	Employee e2("Abbas Buazar", 9745320, 20000000, 5000000);
	e1.print();
	cout << "---------------------" << endl;
	e2.print();

}
