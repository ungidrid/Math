#include "../headers/Complex.h"
using namespace std;
#include <iostream>
#include <string>
#include <sstream>

//CONSTRUCTORS
Complex::Complex(const Fraction& real, const Fraction& imaginarious):m_real{real}, m_imaginarious{imaginarious} {}

//METHODS
Fraction& Complex::Re() {
	return m_real;
}
Fraction& Complex::Im() {
	return m_imaginarious; 
}
const Fraction& Complex::Re() const {
	return m_real;
}
const Fraction& Complex::Im() const {
	return m_imaginarious;
}
Fraction Complex::squaredAbs() const {
	return m_real * m_real + m_imaginarious * m_imaginarious; 
}
Complex Complex::conjugate() const {
	return Complex(Re(), -Im()); 
}
ostream& Complex::print(ostream& out) const {
	if (Im() == 0)
		return out << Re();
	if (Re() == 0)
		return out << Im() << "*i" ;
	return out << Re() << " + " << Im() << "*i";
}

//OPERATORS
Complex Complex::operator+() const {
	return *this;
}
Complex Complex::operator-() const {
	return Complex(-Re(), -Im()); 
}
Complex& Complex::operator+=(const Complex& c2) {
	*this = *this + c2;
	return *this;
}
Complex& Complex::operator-=(const Complex& c2) {
	*this = *this - c2;
	return *this;
}
Complex& Complex::operator*=(const Complex& c2) {
	*this = *this * c2;
	return *this;
}
Complex& Complex::operator/=(const Complex& c2) {
	*this = *this / c2;
	return *this;
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
bool operator==(const Complex& left, const Complex& right) {
	return (left.Re() == right.Re() && left.Im() == right.Im());
}
bool operator!=(const Complex& left, const Complex& right) {
	return !(left == right);
}

ostream& operator<<(ostream& out, const Complex& c) {
	return c.print(out);
}
istream& operator>>(istream& in, Complex& c) {
	string temp;
	getline(in, temp);

	size_t s_index = temp.find_first_of("1234567890");
	size_t e_index = temp.find_first_of(",");
	string temp1(temp, s_index, e_index - s_index);
	stringstream s(temp1);
	s >> c.m_real;
	s.clear();

	s_index = temp.find_first_of("0123456789", e_index);
	e_index = temp.find_first_of(")", e_index);
	temp1.assign(temp, s_index, e_index - s_index);
	s.str(temp1);
	s >> c.m_imaginarious;
	return in;
}