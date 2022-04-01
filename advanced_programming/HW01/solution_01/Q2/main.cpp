#include <iostream>
#include "Circle.h"

using namespace std;

int main() {
    Circle circle1("C1", 2, 2, 9);
    circle1.print();

    string c2Name;
    int c2x, c2y;
    float c2r;

    cout << "Please enter name of circle:";
    getline(cin, c2Name);

    cout << "Please enter x, y and radius:";
    cin >> c2x >> c2y >> c2r;

    Circle circle2(c2Name, c2x, c2y, c2r);
    circle2.print();

    circle2.shift(20, 10);
    circle2.print();

    return 0;
}
