// Circle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>


#define PI 3.141592  //define pi number to use

using namespace std;


class Circle
{
public:

    Circle(float x, float y, float r, string n) //default constructor
    {
        x_c = x;
        y_c = y;
        this->r = r;
        name = n;

    }

    void setname(string s1) 
    {
        name = s1;
    }
    void setCordinates(float x, float y)
    {
        x_c = x;
        y_c = y;
    }

    void setRadius(float r) //with exception handling 
    {
        try 
        {
            // If the user entered a negative radius, this is an error condition
            if (r < 0)
                throw "Radius can not be negative number"; // throw exception of type const char*

            // Otherwise, print the answer
            this->r = r;
        }
        catch (const char* exception) // catch exceptions of type const char*
        {
            std::cerr << "Error: " << exception << '\n';

        }

    }

    
    void getinfo() 
    {
        getx_c();
        gety_c();
        getr();
        getname();

    }

    float getx_c() {
        return x_c;
    }

    float gety_c() {
        return y_c;
    }

    float getr() {
        return r;
    }

    string getname() {
        return name;
    }

    float perimeter()
    {
        return 2 * PI * r;
    }

    float area() 
    {
        return PI * r * r;
    }

    void shiftCordinates(float x, float y) 
    {
        x_c += x;
        y_c += y;
    }

    void print() 
    {
        cout << "Circle Informations are:" << endl << "Name:\t" << name << endl
            << "Coordinates of center (x, y):\t" << x_c << "," << y_c << endl
            << "Radius:\t" << r << endl
            << "Area:\t" << area() << endl << "Perimeter:\t" << perimeter() << endl;

    }
private:

    float x_c;
    float y_c;
    float r;
    string name;

};




int main()
{
    Circle c1(2, 8, 10, "C1");

    c1.print();

    float x_c = 0;
    float y_c = 0;
    float r = 0;
    string name;


    cout << "Please enter the x cordinates of center: " << endl;
    cin >> x_c;
    cout << "Please enter the y cordinates of center: " << endl;
    cin >> y_c;
    cout << "Please enter the radius of circle: " << endl;
    cin >> r;
    while (r < 0) {
        cout << "Radius must be positive! enter again: " << endl;
        cin >> r;
    }
    cout << "Please enter the name of circle: " << endl;
    cin >> name;

    Circle c2(0, 0, 0, "");
    c2.setname(name);
    c2.setCordinates(x_c, y_c);
    c2.setRadius(r);
    c2.print();

    c2.shiftCordinates(10, 20);
    c2.print();

    return 0;
}

