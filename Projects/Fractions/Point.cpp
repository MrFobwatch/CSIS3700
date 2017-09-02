//
// Created by Kevin on 9/1/2017.
//

#include "Point.h"

Point::Point(Fraction x, Fraction y) {
    this->x=x;
    this->y=y;
}

Point Point::operator+(const Point& point1, const Point& point2) {
    Fraction xsum,ysum;
    xsum = point1.x + point2.x;
    ysum = point1.y + point2.y;
    return Point(xsum, ysum);
}

Point Point::operator-(const Point& point1, const Point& point2) {
    Fraction xdiff,ydiff;
    xdiff = point1.x + point2.x;
    ydiff = point1.y + point2.y;
    return Point(xdiff, ydiff);
}

Fraction Point::operator*(const Point& point1, const Point& point2) {    //Performs the cross product
    Fraction cross;
    cross = (point1.x * point2.y) - (point1.y * point2.x);
    return cross;
}

Point Point::operator*(const Point& point, const Fraction &fraction) {
    Fraction productx;
    Fraction producty;
    Point product(productx,producty);
    product.x = point.x * fraction;
    product.y = point.y * fraction;

    return Point(Fraction(), Fraction());
}

std::istream &operator>>(std::istream &, Point &) {
    return <#initializer#>;
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << point.x << "," << point.y;
    return out;
}
