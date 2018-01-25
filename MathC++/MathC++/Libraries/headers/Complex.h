#pragma once
#include "Fraction.h"

class Complex{
	Fraction m_real;
	Fraction m_imaginarious;
public:
	Complex(const Fraction& = 0, const Fraction& = 0);

	ostream& print(ostream&) const;
	Fraction& Re();
	Fraction& Im();
	const Fraction& Re() const;
	const Fraction& Im() const;
	Fraction squaredAbs() const;
	Complex conjugate() const;
	Complex operator+() const;	//TODESTORY
	Complex operator-() const;
	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);

	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
};