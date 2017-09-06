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
    const Fraction &getX() const;
    void setX(const Fraction &x);
    const Fraction &getY() const;
    void setY(const Fraction &y);
    Point& operator=(const Point &point);
    friend std::istream& operator>>(std::istream &ins, Point &point);
    friend std::ostream& operator<<(std::ostream &out, const Point &point);
private:
    Fraction x,y;
};

Point operator+(const Point &point1, const Point &point2);
Point operator-(const Point &point1, const Point &point2);
Fraction operator*(const Point &point1, const Point &point2);
Point operator*(const Fraction &fraction, const Point &point);

#endif //FRACTIONS_POINT_H
