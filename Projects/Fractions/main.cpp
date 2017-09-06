#include <iostream>
#include "Point.h"



int main() {
    Fraction x,y;
    //Inputs of line segments
    std::cout << "Enter a point P1: " << std::endl;
//    std::cin >> x;
//    std::cin >> y;
    x = Fraction(4);
    y = Fraction(15);
    Point p1(x,y);
    std::cout << "Enter a point P2: " << std::endl;
//    std::cin >> x;
//    std::cin >> y;
    x = Fraction(8);
    y = Fraction(25);
    Point p2(x,y);
    std::cout << "Enter a point Q1: " << std::endl;
//    std::cin >> x;
//    std::cin >> y;
    x = Fraction(1);
    y = Fraction(3);
    Point q1(x,y);
    std::cout << "Enter a point Q2: " << std::endl;
//    std::cin >> x;
//    std::cin >> y;
    x = Fraction(7);
    y = Fraction(9);
    Point q2(x,y);
    //Parametrize points
    Point r;
    r = p2 - p1;
    Point s;
    s = q2 - q1;
    Point z;
    z = q1 - p1;

    Fraction x_t;
    x_t = z * s;
    Fraction x_u;
    x_u = z * r;
    Fraction y_ans;
    y_ans = r * s;

    if ((y_ans == 0) && (x_t == 0)) {
        std::cout <<  "The line segments are collinear." << std::endl;
    }
    else if ((y_ans == 0) && (x_t != Fraction(0))) {
        std::cout << "The line segments are parallel." << std::endl;
    }
    else if (y_ans != Fraction(0)) {
        Fraction t,u;
        t = x_t / y_ans;
        u = x_u / y_ans;
        if (((Fraction (0) <= t) &&  (t <= Fraction(1))) && ((Fraction (0) <= u) && (u <= Fraction(1)))) {
            Point intersect;
            intersect = p1 + (t * r);
            std::cout << "The intersection is " << intersect << std::endl;
        }
        else {
            std::cout << "The line segments do not intersect" << std::endl;
        }
    }
    return 0;
}