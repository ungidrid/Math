#pragma once
#include <iostream>
#include <cassert>
using namespace std;

class Fraction{
	int m_numerator;
	int m_denominator; 
	
	//GREAT COMMON DIVISOR
	static int gcd(int a, int b);
	void reduce();
public:
	Fraction(int, int);
	double toDouble();
	Fraction operator-();
	Fraction operator+();
	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);
	Fraction& operator+=(const Fraction&);
	Fraction& operator-=(const Fraction&);
	Fraction& operator*=(const Fraction&);
	Fraction& operator/=(const Fraction&);
	bool operator==(const Fraction&);
	bool operator!=(const Fraction&);


	friend ostream& operator<<(ostream&, const Fraction&);
	friend istream& operator>>(istream&, Fraction&);
};