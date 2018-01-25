#include "../headers/Complex.h"

//CONSTRUCTORS
Complex::Complex(const Fraction& real = 0, const Fraction& imaginarious = 0):m_real(real), m_imaginarious(imaginarious) {}

//TEST IT
string Complex::print()const {
	string out;
	if (Im() == 0) {
		out+= Re().print();
		return out;
	}
	if (Re() == 0) {
		out+= Im().print()+"*i";
		return out;
	}
	out += Re().print() + " + " + Im().print() + "*i ";
	return out;
}

Fraction& Complex::Re() {
	return m_real;
}
Fraction& Complex::Im() {
	return m_imaginarious; 
}
const Fraction& Complex::Re()const {
	return m_real;
}
const Fraction& Complex::Im()const {
	return m_imaginarious;
}
Fraction Complex::squaredAbs()const {
	return m_real * m_real + m_imaginarious * m_imaginarious; 
}
Complex Complex::conjugate()const {
	return Complex(Re(), -Im()); 
}

//OPERATORS
Complex& Complex::operator+() {
	return *this; 
}
const Complex& Complex::operator+()const {
	return *this;
}

Complex Complex::operator-()const {
	return Complex(-Re(), -Im()); 
}
Complex operator+(const Complex& left, const Complex& right) { 
	return Complex(left.Re() + right.Re(), left.Im() + right.Im()); 
}
Complex operator-(const Complex& left, const Complex& right) { 
	return left + -right; 
}
Complex operator*(const Complex& left, const Complex& right) { 
	return Complex(left.Re()*right.Re() - left.Im()*right.Im(), left.Re()*right.Im() + left.Im()*right.Re()); 
}
Complex operator/(const Complex& left, const Complex& right){
	Complex c(left*right.conjugate());
	c.Re() /= right.squaredAbs();
	c.Im() /= right.squaredAbs();
	return c;
}

//TEST IT
ostream& operator<<(ostream& out, const Complex& c) {
	out << c.print();
	return out;
}
istream& operator>>(istream& in, Complex& c) {
	in >> c.Re();
	//char s = in.get();
	//if (s == '\n') { c.Im() = 0; return in; }
	in >> c.Im();
	return in;
}