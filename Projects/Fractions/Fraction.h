//
// Created by Kevin on 9/1/2017.
//

#ifndef FRACTIONS_FRACTION_H
#define FRACTIONS_FRACTION_H

#include <iostream>

class Fraction {
public:
    Fraction();
    Fraction(int numer);
    Fraction(int numer, int denom);
    void setFrac(int numer, int denom);
    void FractionEquals();
    Fraction operator+(const Fraction &fraction);
    Fraction operator-(const Fraction &fraction);
    Fraction operator*(const Fraction &fraction);
    Fraction operator/(const Fraction &fraction);
    Fraction operator<(const Fraction &fraction);
    Fraction operator>(const Fraction &fraction);
    Fraction operator<=(const Fraction &fraction);
    Fraction operator>=(const Fraction &fraction);
    Fraction operator==(const Fraction &fraction);
    Fraction operator!=(const Fraction &fraction);
    Fraction operator<(const int &n);
    Fraction operator>(const int &n);
    Fraction operator<=(const int &n);
    Fraction operator>=(const int &n);
    Fraction operator==(const int &n);
    Fraction operator!=(const int &n);
    friend std::istream& operator»(std::istream &, Fraction &);
    friend std::ostream& operator«(std::ostream &, const Fraction &);

private:
    int numer;
    int denom;
};


#endif //FRACTIONS_FRACTION_H
