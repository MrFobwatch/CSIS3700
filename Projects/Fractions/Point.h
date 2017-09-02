//
// Created by Kevin on 9/1/2017.
//

#ifndef FRACTIONS_POINT_H
#define FRACTIONS_POINT_H

#include <iostream>
#include "Fraction.h"

class Point {
public:
    Point(Fraction x, Fraction y);
    //friend std::istream &operator>>(std::istream &, Point &);
    //friend std::ostream &operator<<(std::ostream& out, const Point& point);
    Fraction x;
    Fraction y;
private:

};

Point operator+(const Point &point1, const Point &point2);
Point operator-(const Point &point1, const Point &point2);
Fraction operator*(const Point &point1, const Point &point2);
Point operator*(const Point &point, const Fraction &fraction);

#endif //FRACTIONS_POINT_H
