#pragma once

#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator; 
	
	static int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a%b); }//great common divisor
	void reduce()
	{
		int cd = gcd(m_numerator, m_denominator);
		m_numerator /= cd;
		m_denominator /= cd;
	}
public:
	Fraction(int numerator = 0, int denominator = 1) : m_numerator{numerator},m_denominator{denominator}
	{ 
		assert(m_denominator != 0 && "Fraction's denominator cannot be assigned to 0");
		reduce(); 
	}
	double toDouble() { return static_cast<double>(m_numerator) / m_denominator; }
	friend ostream& operator<<(ostream& out, const Fraction& f)
	{
		if (f.m_denominator != 1)
		{
			out << f.m_numerator << "/" << f.m_denominator;
			return out;
		}
		else { out << f.m_numerator; return out; }
	}
	friend istream& operator>>(istream& in, Fraction& f)
	{
		in >> f.m_numerator;
		char c = in.get();
		if (c == '\n') { f.m_denominator = 1; return in; }
		assert(c == '/' && "Unhandled input");
		in >> f.m_denominator;
		assert(f.m_denominator != 0 && "Fraction's denominator cannot be assigned to 0");
		f.reduce();
		return in;
	}
	friend Fraction operator+(const Fraction& f1,const Fraction& f2)
	{
		return Fraction(f1.m_numerator*f2.m_denominator + f1.m_denominator*f2.m_numerator, f1.m_denominator*f2.m_denominator);
	}
	friend Fraction operator-(const Fraction& f1, const Fraction& f2)
	{
		return Fraction(f1.m_numerator*f2.m_denominator - f1.m_denominator*f2.m_numerator, f1.m_denominator*f2.m_denominator);
	}
	Fraction operator-() { return Fraction(-m_numerator, m_denominator); }
	Fraction operator+() { return *this; }
	friend Fraction operator*(const Fraction& f1, const Fraction& f2)
	{
		return Fraction(f1.m_numerator*f2.m_numerator, f1.m_denominator*f2.m_denominator);
	}
	friend Fraction operator/(const Fraction& f1, const Fraction& f2)
	{
		assert(f2.m_numerator != 0 && "Division by 0");
		return Fraction(f1.m_numerator*f2.m_denominator, f1.m_denominator*f2.m_numerator);
	}
	friend bool operator==(const Fraction& f1, const Fraction& f2)
	{ 
		return (f1.m_numerator*f2.m_denominator == f1.m_denominator*f2.m_numerator); 
	}
	friend bool operator!=(const Fraction& f1, const Fraction& f2)
	{ 
		return (f1.m_numerator*f2.m_denominator != f1.m_denominator*f2.m_numerator); 
	}
	friend void operator+=(Fraction& f1,const Fraction& f2) { f1 = f1 + f2; }
	friend void operator-=(Fraction& f1,const Fraction& f2) { f1 = f1 - f2; }
	friend void operator*=(Fraction& f1,const Fraction& f2) { f1 = f1 * f2; }
	friend void operator/=(Fraction& f1,const Fraction& f2) { f1 = f1 / f2; }
};
