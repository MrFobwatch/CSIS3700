//
// Created by Kevin on 9/1/2017.
//

#include "Fraction.h"

Fraction::Fraction() {
    this->numer=0;
    this->denom=1;
}
Fraction::Fraction(int numer){
    this->numer=numer;
    this->denom=1;
}

Fraction::Fraction(int numer, int denom){
    this->numer=numer;
    this->denom=denom;
}

int Fraction::getNumer() const {
    return numer;
}

void Fraction::setNumer(int numer) {
    Fraction::numer = numer;
}

int Fraction::getDenom() const {
    return denom;
}

void Fraction::setDenom(int denom) {
    Fraction::denom = denom;
}

void Fraction::FractionEquals() {

}

void Fraction::setFrac(int numer, int denom) {

}

Fraction operator+(const Fraction &fraction1, const Fraction &fraction2) {
    int numerResult,denomResult;
    numerResult = fraction1.numer + fraction2.numer;
    denomResult = fraction1.denom + fraction2.denom;
    return Fraction(numerResult, denomResult);
}

Fraction operator-(const Fraction &fraction1, const Fraction &fraction2) {
    int numerResult,denomResult;
    numerResult = fraction1.numer - fraction2.numer;
    denomResult = fraction1.denom - fraction2.denom;
    return Fraction(numerResult, denomResult);
}

Fraction operator*(const Fraction &fraction1, const Fraction &fraction2) {
    int numerResult,denomResult;
    numerResult = fraction1.numer * fraction2.numer;
    denomResult = fraction1.denom * fraction2.denom;
    return Fraction(numerResult, denomResult);
}

Fraction operator/(const Fraction &fraction1, const Fraction &fraction2) {
    int numerResult,denomResult;
    numerResult = fraction1.numer * fraction2.denom;
    denomResult = fraction1.denom * fraction2.numer;
    return Fraction(numerResult, denomResult);
}

Fraction operator<(const Fraction &fraction1, const Fraction &fraction2) {
    return Fraction();
}

Fraction operator>(const Fraction &fraction1, const Fraction &fraction2) {
    return Fraction();
}

Fraction operator<=(const Fraction &fraction1, const Fraction &fraction2) {
    return Fraction();
}

Fraction operator>=(const Fraction &fraction1, const Fraction &fraction2) {
    return Fraction();
}

Fraction operator==(const Fraction &fraction1, const Fraction &fraction2) {
    return Fraction();
}

Fraction operator!=(const Fraction &fraction1, const Fraction &fraction2) {
    return Fraction();
}

Fraction operator<(const Fraction &fraction, const int n) {
    return Fraction();
}

Fraction operator>(const Fraction &fraction, const int n) {
    return Fraction();
}

Fraction operator<=(const Fraction &fraction, const int n) {
    return Fraction();
}

Fraction operator>=(const Fraction &fraction, const int n) {
    return Fraction();
}

Fraction operator==(const Fraction &fraction, const int n) {
    return Fraction();
}

Fraction operator!=(const Fraction &fraction, const int n) {
    return Fraction();
}

std::istream &operator>>(std::istream &, Fraction &){

}

std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
    out << fraction.getNumer() << "/" << fraction.getDenom();
    return out;
}


