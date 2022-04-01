#include <iostream>
#include "Date.h"

using namespace std;

int main() {
    Date date1(1400, 7, 20);
    Date *date2 = new Date(1400, 7,20);

    date1.print1();
    date2->print2();

    delete date2;
    return 0;
}
