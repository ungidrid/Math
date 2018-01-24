#pragma once
#include "Fraction.h";

class Complex{
	Fraction m_real;
	Fraction m_imaginarious;
public:
	Complex(Fraction, Fraction);
	Fraction& Re();
	Fraction& Im();
	Fraction squaredAbs();
	Complex conjugate();
	Complex operator+();
	Complex operator-();
	friend Complex operator+(Complex, Complex);
	friend Complex operator-(Complex, Complex);
	friend Complex operator*(Complex, Complex);
	friend Complex operator/(Complex, Complex);


	friend ostream& operator<<(ostream&, Complex);
	friend istream& operator>>(istream&, Complex&);
};