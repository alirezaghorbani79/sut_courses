#include <iostream>
#include "Employee.h"

using namespace std;

int main() {
    Employee employee1(1, "Silver", 2500000, 0);
    Employee employee2(2, "Lead", 20000000, 5000000);

    employee1.print();
    employee2.print();


    return 0;
}
