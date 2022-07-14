#pragma once

#include <iostream>
#include <string>

using namespace std;

class Circule
{
public:
	Circule(int x = 0, int y = 0, float r = 0, string cirName = "cir0");
	void setCircle(int x, int y, float r, string cirName);
	Circule& setX(int x);
	Circule& setY(int y);
	Circule& setRadius(float r);
	Circule& setCirName(string cirName);

	int getX(void) const;
	int getY(void) const;
	float getRadius(void) const;
	string getCirName(void) const;

	float perimeter(float r);
	float area(float r);

	void shift(int xShift, int yShift);

	void print(void);

private:
	int x, y;
	float r;
	string cirName;

};

