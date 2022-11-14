#ifndef FRACTION_H
#define FRACTION_H

#include<iostream>
#include<string>

class Fraction{
private:
    int numerator;
    int denominator;
public:
    Fraction();
    Fraction(int n);
    Fraction(int n, int d);
    int getNumerator();
    int getDenominator();
    void setNumerator(int numerator);
    void setDenominator(int denominator);
    int gcd(int a, int b);    
    int lcm(int a, int b);
    std::string DisplayFraction();
    double DisplayFractionAsDouble();
    Fraction operator!();
    Fraction operator+(Fraction frac2);
    Fraction operator-(Fraction frac2);
    Fraction operator*(Fraction frac2);
    Fraction operator/(Fraction frac2);
};

std::ostream& operator<< (std::ostream &ostr, Fraction& f);

#endif