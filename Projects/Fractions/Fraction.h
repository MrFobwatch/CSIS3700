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
    int getNumer() const;
    void setNumer(int numer);
    int getDenom() const;
    void setDenom(int denom);
    void setFrac(int numer, int denom);
    void FractionEquals();
    friend std::istream& operator>>(std::istream &, Fraction &);
    friend std::ostream& operator<<(std::ostream &, const Fraction &);

private:
    int numer;
    int denom;
};

Fraction operator+(const Fraction &fraction, const Fraction &fraction2);
Fraction operator-(const Fraction &fraction1, const Fraction &fraction2);
Fraction operator*(const Fraction &fraction1, const Fraction &fraction2);
Fraction operator/(const Fraction &fraction1, const Fraction &fraction2);
bool operator<(const Fraction &fraction1, const Fraction &fraction2);
bool operator>(const Fraction &fraction1, const Fraction &fraction2);
bool operator<=(const Fraction &fraction1, const Fraction &fraction2);
bool operator>=(const Fraction &fraction1, const Fraction &fraction2);
bool operator==(const Fraction &fraction1, const Fraction &fraction2);
bool operator!=(const Fraction &fraction1, const Fraction &fraction2);
bool operator<(const Fraction &fraction, const int n);
bool operator>(const Fraction &fraction, const int n);
bool operator<=(const Fraction &fraction, const int n);
bool operator>=(const Fraction &fraction, const int n);
bool operator==(const Fraction &fraction, const int n);


#endif //FRACTIONS_FRACTION_H
