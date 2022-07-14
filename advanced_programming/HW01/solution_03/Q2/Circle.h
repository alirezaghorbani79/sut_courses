#pragma once
#include <iostream>
#include <string>

using namespace std;

class Circle 
{
public:

	Circle(float x, float y, float r, string n);
	void setname(string s1);
	void setCordinates(float x, float y);
	void setRadius(float r); //with exception handling
	void getinfo();
	float getx_c();
	float gety_c();
	float getr();
	string getname();
	float perimeter();
	float area();
	void shiftCordinates(float x, float y);
	void print();

private:

	float x_c;
	float y_c;
	float r;
	string name;

};
