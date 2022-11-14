#include "fraction.h"
#include<iostream>
#include<cmath>
#include<string>
#include <stdexcept>

Fraction::Fraction(): numerator(0), denominator(1) {};
Fraction::Fraction(int n) : numerator(n), denominator(1) {};
Fraction::Fraction(int n, int d=1): numerator(n), denominator(d){
    if(d==0){
        throw std::invalid_argument("Division by zero is not allowed");
    }
};

int Fraction::getNumerator(){
    return numerator;
};

int Fraction::getDenominator(){
    return denominator;
};

void Fraction::setNumerator(int numerator){
    this->numerator = numerator;
};

void Fraction::setDenominator(int denominator){
    this->denominator = denominator;
};

int Fraction::gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);     
};
    
int Fraction::lcm(int a, int b){
    return (abs(a*b))/gcd(a,b);
};

std::string Fraction::DisplayFraction(){
    std::string snumerator = std::to_string(numerator);
    std::string sDenominator = std::to_string(denominator);
    std::string sFraction = "[" + snumerator + "/" + sDenominator + "]";
    return sFraction;
};

double Fraction::DisplayFractionAsDouble(){
    double res = (static_cast<double>(numerator)) / denominator;
    return res;
};

Fraction Fraction::operator!(){
    int ingcd = gcd(numerator, denominator);
    return Fraction(numerator/ ingcd, denominator/ ingcd);
};

Fraction Fraction::operator+(Fraction frac2){
    Fraction frac_res;
    int res_numerator, res_denominator;
    res_numerator = (numerator * frac2.getDenominator()) + (denominator*frac2.getNumerator());
    res_denominator = denominator * frac2.getDenominator(); 
    frac_res.setNumerator(res_numerator);
    frac_res.setDenominator(res_denominator);
    return !frac_res;
};
Fraction Fraction::operator-(Fraction frac2){
    Fraction frac_res;
    int res_numerator, res_denominator;
    res_numerator = (numerator * frac2.getDenominator()) - (denominator*frac2.getNumerator());
    res_denominator = denominator * frac2.getDenominator(); 
    frac_res.setNumerator(res_numerator);
    frac_res.setDenominator(res_denominator);
    return !frac_res;
};

Fraction Fraction::operator*(Fraction frac2){
    Fraction frac_res;
    int res_numerator, res_denominator;
    res_numerator = numerator * frac2.getNumerator();
    res_denominator = denominator * frac2.getDenominator(); 
    frac_res.setNumerator(res_numerator);
    frac_res.setDenominator(res_denominator);
    return !frac_res;
};
Fraction Fraction::operator/(Fraction frac2){
    Fraction frac_res;
    int res_numerator, res_denominator;
    res_numerator = numerator * frac2.getDenominator();
    res_denominator = denominator * frac2.getNumerator(); 
    frac_res.setNumerator(res_numerator);
    frac_res.setDenominator(res_denominator);
    return !frac_res;
};

std::ostream& operator<< (std::ostream &ostr, Fraction& f){
    return ostr << f.DisplayFraction();
};