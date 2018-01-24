#pragma once
#include "FractionClassC++.h";

class Complex{
	Fraction real;
	Fraction imaginarious;
public:
	Complex(Fraction real = 0, Fraction imaginarious = 0)
	{
		this->real = real;
		this->imaginarious = imaginarious;
	}
	Fraction& Re() { return real; }
	Fraction& Im() { return imaginarious; }
	Fraction squaredAbs() { return real*real + imaginarious*imaginarious; }
	Complex conjugate() { return Complex(Re(), -Im()); }
	friend ostream& operator<<(ostream& out, Complex c)
	{
		if (c.Im() == 0) { out << c.Re(); return out; }
		if (c.Re() == 0) { out << c.Im() << "*i"; return out; }
		out << c.Re() << " + " << c.Im() << "*i ";
		return out;
	}
	friend istream& operator>>(istream& in, Complex& c)
	{
		in >> c.Re();
		//char s = in.get();
		//if (s == '\n') { c.Im() = 0; return in; }
		in >> c.Im();
		return in;
	}
	Complex operator+() { return *this; }
	Complex operator-() { return Complex(-Re(), -Im()); }
	friend Complex operator+(Complex left, Complex right) { return Complex(left.Re() + right.Re(), left.Im() + right.Im()); }
	friend Complex operator-(Complex left, Complex right) { return left + -right; }
	friend Complex operator*(Complex left, Complex right) { return Complex(left.Re()*right.Re() - left.Im()*right.Im(), left.Re()*right.Im() + left.Im()*right.Re()); }
	friend Complex operator/(Complex left, Complex right)
	{
		Complex c(left*right.conjugate());
		c.Re() /= right.squaredAbs();
		c.Im() /= right.squaredAbs();
		return c;
	}
};