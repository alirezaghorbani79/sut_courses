//
// Created by Alireza Ghorbani on 2/19/2022.
//

#include <iostream>
#include "math.h"
#include "Circle.h"

using namespace std;

Circle::Circle(std::string name ,int x, int y, float r) {
    setPoint(x, y);
    setRadius(r);
    setName(name);
}

Circle &Circle::setPoint(int x, int y) {
    this->x = x;
    this->y = y;

    return *this;
}

Circle &Circle::setRadius(float r) {
    if (r < 0) {
        throw invalid_argument("The minimum value for radius is 0");
    }

    this->r = r;

    return *this;
}

Circle &Circle::setName(std::string name) {
    this->name = name;
}

int Circle::getX() {
    return this->x;
}

int Circle::getY() {
    return this->y;
}

int Circle::getRadius() {
    return this->r;
}

std::string Circle::getName() {
    return this->name;
}

float Circle::perimeter() {
    return 2 * 3.14 * getRadius();
}

float Circle::area() {
    return pow(getRadius(), 2) * 3.14;
}

void Circle::shift(int x, int y) {
    setPoint(getX() + x, getY() + y);
}

void Circle::print() {
    cout << "====================================" << endl;
    cout << "Radius: " << getRadius() << endl;
    cout << "X: " << getX() << endl;
    cout << "Y: " << getY() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter:" << perimeter() << endl;
    cout << "Name: " << getName() << endl;
    cout << "====================================" << endl;

}

