#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>


#define PI 3.14159265
using namespace std;


class shape
{
public:
	shape() : width(1) {};
	shape(float width) : width(width) {};
	~shape();
	void setWidth(int width)
	{
		this->width = width;
	}
	float getWidth() const
	{
		return width;
	}
	virtual string getName() const
	{
		return "shape";
	}
	virtual float getArea() const
	{
		return width * width;
	}
	virtual void print() const
	{
		cout << "My Name is: " << getName() << endl;
		cout << "My Area is: " << getArea() << endl;
		cout << "My Width is: " << getWidth() << endl;
	}
protected:
	float width;

};

class twoDimentialShape : public shape
{
public:
	twoDimentialShape() : shape(width = 1), length(1) {};
	twoDimentialShape(float width, float length) : shape(width), length(length) {};
	void setLength(float length)
	{
		this->length = length;
	}
	float getLength() const
	{
		return length;
	}
	string getName() const
	{
		return "twoDimentialShape";
	}
	float getArea() const
	{
		return width * length;
	}
	void print() const
	{
		shape::print();
		cout << "My Length is: " << getLength() << endl;
	}

protected:
	float length;
};

class threeDimentialShape : public shape
{
public:
	threeDimentialShape() : shape(width = 1), length(1), height(1) {};
	threeDimentialShape(float width, float length, float height) : shape(width), length(length), height(height) {};
	void setLength(float length)
	{
		this->length = length;
	}
	void setHeight(float height)
	{
		this->height = height;
	}
	float getLength() const
	{
		return length;
	}
	float getHeight() const
	{
		return height;
	}
	virtual float getVolume() const
	{
		return width * length * height;
	}
	string getName() const
	{
		return "threeDimentialShape";
	}
	void print() const
	{
		cout << "My Name is: " << getName() << endl;
		cout << "My volume is: " << getVolume() << endl;
		cout << "My Width is: " << getWidth() << endl;
		cout << "My Length is: " << getLength() << endl;
		cout << "My Height is: " << getHeight() << endl;
	}

protected:
	float length, height;
};

class circle : public twoDimentialShape
{
public:
	circle() : twoDimentialShape(radius = 1, radius = 1) {};
	circle(float radius) : twoDimentialShape(radius, radius) {};
	~circle();
	void setRadius(float radius)
	{
		this->radius = radius;
	}
	float getRadius() const
	{
		return radius;
	}
	float getArea() const
	{
		return PI * twoDimentialShape::getArea();
	}
	string getName() const
	{
		return "Circle";
	}
	void print() const
	{
		cout << "My Name is: " << getName() << endl;
		cout << "My Areea is: " << getArea() << endl;
		cout << "My Radius is: " << getRadius() << endl;
	}
protected:
	float radius = width;

};

class triangle : public twoDimentialShape
{
public:
	triangle() : twoDimentialShape(width = 1, length = 1), thirdSide(1) {};
	triangle(float width, float length, float thirdSide) : twoDimentialShape(width, length), thirdSide(thirdSide) {};
	~triangle();
	void setRectangle(float firstSide, float secondSide, float thirdSide)
	{
		setFirstSide(firstSide);
		setSecondSide(secondSide);
		setThirdSide(thirdSide);
	}
	void setFirstSide(float firstSide)
	{
		this->firstSide = firstSide;
	}
	void setSecondSide(float secondSide)
	{
		this->secondSide = secondSide;
	}
	void setThirdSide(float thirdSide)
	{
		this->thirdSide = thirdSide;
	}
	float getThirdSide() const
	{
		return thirdSide;
	}
	string getName() const
	{
		return "Triangle";
	}
	float getArea() const
	{
		if ((getWidth() + getLength() > getThirdSide()) && (getWidth() + getThirdSide() > getLength()) && (getLength() + getThirdSide() > getWidth()))
		{
			float s = (getWidth() + getLength() + getThirdSide()) / 2;
			return sqrt(s * (s - getWidth()) * (s - getLength()) * (s - getThirdSide()));
		}
		else
		{
			return 0;
		}
	}
	void print() const
	{
		cout << "My Name is: " << getName() << endl;
		cout << "My Area is: " << getArea() << endl;
		cout << "My First Side is: " << getWidth() << endl;
		cout << "My Second Side is: " << getLength() << endl;
		cout << "My Third Side is: " << getThirdSide() << endl;
	}

protected:
	float firstSide, secondSide, thirdSide;

};

class sphere : public threeDimentialShape
{
public:
	sphere() : threeDimentialShape(radius = 1, radius = 1, radius = 1) {};
	sphere(float radius) : threeDimentialShape(radius, radius, radius), radius(radius) {};
	~sphere();
	void setRadius(float radius)
	{
		threeDimentialShape::setHeight(radius);
	}
	float getRadius() const
	{
		return threeDimentialShape::getHeight();
	}
	float getVolume() const
	{
		return 1.3333 * PI * threeDimentialShape::getVolume();
	}
	string getName() const
	{
		return "Sphere";
	}
	void print() const
	{
		cout << "My Name is: " << getName() << endl;
		cout << "My volume is: " << getVolume() << endl;
		cout << "My Radius is: " << getRadius() << endl;
	}

protected:
	float radius;

};

class tetrahedron : public threeDimentialShape
{
public:
	tetrahedron() : threeDimentialShape(side = 1, side = 1, side = 1) {};
	tetrahedron(float side) : threeDimentialShape(side, side, side), side(side) {};
	~tetrahedron();
	void setSide(float side)
	{
		this->side = side;
	}
	float getSide() const
	{
		return threeDimentialShape::getHeight();
	}
	float getVolume() const
	{
		return threeDimentialShape::getVolume() / (6 * sqrt(2));
	}
	string getName() const
	{
		return "Tetrahedron";
	}
	void print() const
	{
		cout << "My Name is: " << getName() << endl;
		cout << "My volume is: " << getVolume() << endl;
		cout << "My All Side is: " << getSide() << endl;
	}
protected:
	float side;

};


int main()
{
	vector<shape*> shapes
	{
		new triangle(4, 5, 3),
		new circle(5),
		new sphere(10),
		new tetrahedron(2)
	};

	for (auto i : shapes)
	{
		i->print();
		cout << endl;
	}
}