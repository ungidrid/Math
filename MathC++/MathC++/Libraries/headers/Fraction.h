#pragma once
#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;

class Fraction{
	int m_numerator;
	int m_denominator; 
	
	//GREAT COMMON DIVISOR
	static int gcd(int a, int b);
	void reduce();
public:
	Fraction(int = 0, int = 1);

	ostream& print(ostream&) const;
	double toDouble() const;
	Fraction operator-() const;
	Fraction operator+() const;
	Fraction& operator+=(const Fraction&);
	Fraction& operator-=(const Fraction&);
	Fraction& operator*=(const Fraction&);
	Fraction& operator/=(const Fraction&);

	friend Fraction operator+(const Fraction&, const Fraction&);
	friend Fraction operator-(const Fraction&, const Fraction&);
	friend Fraction operator*(const Fraction&, const Fraction&);
	friend Fraction operator/(const Fraction&, const Fraction&);
	friend bool operator==(const Fraction&, const Fraction&);
	friend bool operator!=(const Fraction&, const Fraction&);

	friend ostream& operator<<(ostream&, const Fraction&);
	friend istream& operator>>(istream&, Fraction&);
};