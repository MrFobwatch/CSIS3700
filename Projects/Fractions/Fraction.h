//
// Created by Kevin on 9/1/2017.
//

#ifndef FRACTIONS_FRACTION_H
#define FRACTIONS_FRACTION_H

#include <iostream>

class Fraction {
public:
    Fraction();
    void setFractionValue();
    void FractionEquals();
    Fraction operator+(const Fraction &a);
    Fraction operator-(const Fraction &a);
    Fraction operator*(const Fraction &a);
    Fraction operator/(const Fraction &a);
    Fraction operator<(const Fraction &a);
    Fraction operator>(const Fraction &a);
    Fraction operator<=(const Fraction &a);
    Fraction operator>=(const Fraction &a);
    Fraction operator==(const Fraction &a);
    Fraction operator!=(const Fraction &a);
    Fraction operator<(const int &a);
    Fraction operator>(const int &a);
    Fraction operator<=(const int &a);
    Fraction operator>=(const int &a);
    Fraction operator==(const int &a);
    Fraction operator!=(const int &a);
    friend std::ostream& operator«(std::ostream &,const Fraction &);
    friend std::istream& operator»(std::istream &,Fraction &);

private:
    int numer;
    int denom;
};


#endif //FRACTIONS_FRACTION_H
