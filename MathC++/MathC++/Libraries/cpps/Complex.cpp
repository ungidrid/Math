#include "../headers/Complex.h"

//CONSTRUCTORS
Complex::Complex(Fraction real = 0, Fraction imaginarious = 0) {
	this->m_real = real;
	this->m_imaginarious = imaginarious;
}

Fraction& Complex::Re() {
	return m_real;
}
Fraction& Complex::Im() {
	return m_imaginarious; 
}
Fraction Complex::squaredAbs() {
	return m_real * m_real + m_imaginarious * m_imaginarious; 
}
Complex Complex::conjugate() {
	return Complex(Re(), -Im()); 
}

//OPERATORS
Complex Complex::operator+() {
	return *this; 
}
Complex Complex::operator-() {
	return Complex(-Re(), -Im()); 
}
Complex operator+(Complex left, Complex right) { 
	return Complex(left.Re() + right.Re(), left.Im() + right.Im()); 
}
Complex operator-(Complex left, Complex right) { 
	return left + -right; 
}
Complex operator*(Complex left, Complex right) { 
	return Complex(left.Re()*right.Re() - left.Im()*right.Im(), left.Re()*right.Im() + left.Im()*right.Re()); 
}
Complex operator/(Complex left, Complex right){
	Complex c(left*right.conjugate());
	c.Re() /= right.squaredAbs();
	c.Im() /= right.squaredAbs();
	return c;
}

ostream& operator<<(ostream& out, Complex c) {
	if (c.Im() == 0) { out << c.Re(); return out; }
	if (c.Re() == 0) { out << c.Im() << "*i"; return out; }
	out << c.Re() << " + " << c.Im() << "*i ";
	return out;
}
istream& operator>>(istream& in, Complex& c) {
	in >> c.Re();
	//char s = in.get();
	//if (s == '\n') { c.Im() = 0; return in; }
	in >> c.Im();
	return in;
}