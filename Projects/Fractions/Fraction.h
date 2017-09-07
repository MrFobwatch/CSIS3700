//
// Created by Kevin on 9/1/2017.
//

#ifndef FRACTIONS_FRACTION_H
#define FRACTIONS_FRACTION_H

#include <cstdlib>
#include <iostream>

class Fraction {
public:
    Fraction();
    explicit Fraction(int numer);
    Fraction(int numer, int denom);
    int getNumer() const;
    void setNumer(int numer);
    int getDenom() const;
    void setDenom(int denom);
    void setFrac();
    void setFrac(int numer);
    void setFrac(int numer, int denom);
    void simpFrac();
    Fraction& operator=(const Fraction &fraction);
    friend std::istream& operator>>(std::istream &ins, Fraction &fraction);
    friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
//    void FractionEquals();

private:
    int numer;
    int denom;
};

Fraction operator+(const Fraction &fraction1, const Fraction &fraction2);
Fraction operator-(const Fraction &fraction1, const Fraction &fraction2);
Fraction operator*(const Fraction &fraction1, const Fraction &fraction2);
Fraction operator/(const Fraction &fraction1, const Fraction &fraction2);
bool operator<(const Fraction &fraction1, const Fraction &fraction2);
bool operator>(const Fraction &fraction1, const Fraction &fraction2);
bool operator<=(const Fraction &fraction1, const Fraction &fraction2);
bool operator>=(const Fraction &fraction1, const Fraction &fraction2);
bool operator==(const Fraction &fraction1, const Fraction &fraction2);
bool operator!=(const Fraction &fraction1, const Fraction &fraction2);
bool operator<(const Fraction &fraction, int n);
bool operator>(const Fraction &fraction, int n);
bool operator<=(const Fraction &fraction, int n);
bool operator>=(const Fraction &fraction, int n);
bool operator==(const Fraction &fraction, int n);

int gcd(int a, int b);

#endif //FRACTIONS_FRACTION_H
