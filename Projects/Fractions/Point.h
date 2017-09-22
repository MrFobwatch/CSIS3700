//
// Created by Kevin on 9/1/2017.
//

#ifndef FRACTIONS_POINT_H
#define FRACTIONS_POINT_H

#include <iostream>
#include "Fraction.h"

class Point {
public:
    Point();
    Point(Fraction x, Fraction y);
    Point operator+(const Point &point);
    Point operator-(const Point &point);
    Fraction operator*(const Point &point);
    Point operator*(const Fraction &fraction);
    friend std::istream& operator>>(std::istream &ins, Point &point);
    friend std::ostream& operator<<(std::ostream &out, const Point &point);

private:
    Fraction x,y;
};



#endif //FRACTIONS_POINT_H
