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

void Fraction::FractionEquals() {

}

void Fraction::setFrac(int numer, int denom) {

}

Fraction Fraction::operator+(const Fraction &fraction) {
    return Fraction();
}

Fraction Fraction::operator-(const Fraction &fraction) {
    return Fraction();
}

Fraction Fraction::operator*(const Fraction &fraction) {
    return Fraction();
}

Fraction Fraction::operator/(const Fraction &fraction) {
    return Fraction();
}

Fraction Fraction::operator<(const Fraction &fraction) {
    return Fraction();
}

Fraction Fraction::operator>(const Fraction &fraction) {
    return Fraction();
}

Fraction Fraction::operator<=(const Fraction &fraction) {
    return Fraction();
}

Fraction Fraction::operator>=(const Fraction &fraction) {
    return Fraction();
}

Fraction Fraction::operator==(const Fraction &fraction) {
    return Fraction();
}

Fraction Fraction::operator!=(const Fraction &fraction) {
    return Fraction();
}

Fraction Fraction::operator<(const int &n) {
    return Fraction();
}

Fraction Fraction::operator>(const int &n) {
    return Fraction();
}

Fraction Fraction::operator<=(const int &n) {
    return Fraction();
}

Fraction Fraction::operator>=(const int &n) {
    return Fraction();
}

Fraction Fraction::operator==(const int &n) {
    return Fraction();
}

Fraction Fraction::operator!=(const int &n) {
    return Fraction();
}

std::istream &operator>>(std::istream &, Fraction &){

}

std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
    out << fraction.numer << "/" << fraction.denom;
    return out;
}


