//
// Created by Alireza Ghorbani on 2/19/2022.
//

#ifndef Q2_CIRCLE_H
#define Q2_CIRCLE_H


class Circle {
public:
    Circle(std::string, int, int, float);

    Circle &setPoint(int, int);
    Circle &setRadius(float);
    Circle &setName(std::string);

    int getX();
    int getY();
    int getRadius();
    std::string getName();

    float perimeter();
    float area();

    void shift(int, int);
    void print();

private:
    float r;
    int x, y;
    std::string name;
};


#endif //Q2_CIRCLE_H
