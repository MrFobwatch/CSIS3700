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
    Point operator+(const Point& point1, const Point& point2);
    Point operator-(const Point& point1, const Point& point2);
    Fraction operator*(const Point& point1, const Point& point2);
    Point operator*(const Point& point, const Fraction &fraction);
    friend std::istream &operator>>(std::istream &, Point &);
    friend std::ostream &operator<<(std::ostream &, const Point &);


private:
    Fraction x;
    Fraction y;
};


#endif //FRACTIONS_POINT_H
