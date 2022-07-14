#include <iostream>
#include <string>
#include <exception>
#include <iomanip>

#include "OOP_HW01_Q2_Header.h"

using namespace std;




Circule::Circule(int x, int y, float r, string cirName)
{
	setCircle(x, y, r, cirName);
}

// ================================ Set Function ================================
void Circule::setCircle(int x, int y, float r, string cirName)
{
	setX(x);
	setY(y);
	setRadius(r);
	setCirName(cirName);
}
Circule& Circule::setX(int x)
{
	this->x = x;
	return *this;
}
Circule& Circule::setY(int y)
{
	this->y = y;
	return *this;
}
Circule& Circule::setRadius(float r)
{
	if (r >= 0)
		this->r = r;
	else
		throw invalid_argument("Radius Cannot be negative");
	return *this;
}
Circule& Circule::setCirName(string cirName)
{
	this->cirName = cirName;
	return *this;
}


// ================================ Get Function ================================
int Circule::getX(void) const
{
	return x;
}
int Circule::getY(void) const
{
	return y;
}
float Circule::getRadius(void) const
{
	return r;
}
string Circule::getCirName(void) const
{
	return cirName;
}


float Circule::perimeter(float r)
{
	return (2 * 3.14 * r);
}
float Circule::area(float r)
{
	return (3.14 * r * r);
}
void Circule::shift(int xShift, int yShift)
{
	this->x += xShift;
	this->y += yShift;
}


void Circule::print(void)
{
	cout << "Circule Name=" << cirName << endl;
	cout << "(x=" << x << "," << "y=" << y << ")" << endl;
	cout << "Radius=" << r << endl;
	cout << "Perimeter=" << perimeter(r) << endl;
	cout << "Area=" << area(r) << endl;

}





int main() try
{
	Circule c1(2, 4, 3, "cir-1");
	c1.print();
	cout << "----------------" << endl;


	int x, y;
	float r;
	string cirName;
	cout << "Enter X: ";
	cin >> x;

	cout << "Enter Y: ";
	cin >> y;	

	cout << "Enter r: ";
	cin >> r;

	cout << "Enter Name of Circle: ";
	cin >> cirName;

	Circule c2(x, y, r, cirName);
	cout << endl;
	c2.print();

	cout << "----------------" << endl;
	c2.shift(10, 20);
	c2.print();



}

catch (invalid_argument & e)
{
	cout << e.what() << endl;
}

catch (exception & e)
{
	cout << e.what() << endl;
}
