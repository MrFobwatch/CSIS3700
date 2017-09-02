//
// Created by Kevin on 9/1/2017.
//

#include "Point.h"

Point::Point(Fraction x, Fraction y) {
    setX(x);
    setY(y);
}

const Fraction &Point::getX() const {
    return x;
}

void Point::setX(const Fraction &x) {
    Point::x = x;
}

const Fraction &Point::getY() const {
    return y;
}

void Point::setY(const Fraction &y) {
    Point::y = y;
}

Point operator+(const Point& point1, const Point& point2) {
    Fraction xRes,yRes;
    xRes = point1.getX() + point2.getX();
    yRes = point1.getY() + point2.getY();
    return Point(xRes, yRes);
}

Point operator-(const Point& point1, const Point& point2) {
    Fraction xRes,yRes;
    xRes = point1.getX() - point2.getX();
    yRes = point1.getY() - point2.getY();
    return Point(xRes, yRes);
}

Fraction operator*(const Point& point1, const Point& point2) {    //Performs the cross product
    Fraction cross;
    cross = (point1.getX() * point2.getY()) - (point1.getY() * point2.getX());
    return cross;
}

Point operator*(const Point& point, const Fraction& fraction) {
    Fraction xRes,yRes;
    xRes = point.getX() * fraction;
    yRes = point.getY() * fraction;
    return Point(xRes, yRes);
}

std::istream &operator>>(std::istream &ins, Point &point) {
    ins >> point.x >>point.y;
    return ins;
}

std::ostream &operator<<(std::ostream& out, const Point& point) {
    out << point.x << "," << point.y;
    return out;
}
