//
// Created by Kevin on 9/1/2017.
//

#include "Point.h"

Point::Point() {
    x = Fraction();
    y = Fraction();
}

Point::Point(Fraction xcoord, Fraction ycoord) {
    x = xcoord;
    y = ycoord;
}

//Point::operator=(const Point &point) {
//    x = point.x;
//    y = point.y;
//}

Point Point::operator+(const Point &point) {
    Fraction xRes,yRes;
    xRes = x + point.x;
    yRes = y + point.y;
    return Point(xRes, yRes);
}

Point Point::operator-(const Point &point) {
    Fraction xRes,yRes;
    xRes = x - point.x;
    yRes = y - point.y;
    return Point(xRes, yRes);
}

Fraction Point::operator*(const Point &point) {    //Performs the cross product
    Fraction cross;
    cross = ((x * point.y) - (y * point.x));
    return cross;
}

Point Point::operator*(const Fraction &fraction) {
    Fraction xRes,yRes;
    xRes = x * fraction;
    yRes = y * fraction;
    return Point(xRes, yRes);
}

std::istream &operator>>(std::istream &ins, Point &point) {
    ins >> point.x >>point.y;
    return ins;
}

std::ostream &operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}
