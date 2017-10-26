#include <iostream>
#include "Point.h"



int main() {
    Fraction x,y;
    //Inputs of line segments
    std::cout << "Enter a point P1: " << std::endl;
    std::cin >> x;
    std::cin >> y;
    Point p1(x,y);
    std::cout << "Enter a point P2: " << std::endl;
    std::cin >> x;
    std::cin >> y;
    Point p2(x,y);
    std::cout << "Enter a point Q1: " << std::endl;
    std::cin >> x;
    std::cin >> y;
    Point q1(x,y);
    std::cout << "Enter a point Q2: " << std::endl;
    std::cin >> x;
    std::cin >> y;
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
    else if ((y_ans == 0) && (x_t != 0)) {
        std::cout << "The line segments are parallel." << std::endl;
    }
    else if (y_ans != 0) {
        Fraction t,u;
        t = x_t / y_ans;
        u = x_u / y_ans;
        if (((t >= 0) &&  (t <= 1)) && ((u >= 0) && (u <= 1))) {
            Point intersect;
            intersect = p1 + (r * t); //Must be in the order of point * fraction for code to work
            std::cout << "The intersection is: " << intersect << std::endl;
        }
        else {
            std::cout << "The line segments do not intersect." << std::endl;
        }
    }
    return 0;
}
