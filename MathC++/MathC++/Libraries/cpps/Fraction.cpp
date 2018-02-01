#include "../headers/Fraction.h"

//CONSTRUCTORS
Fraction::Fraction(int numerator, int denominator) : m_numerator{ numerator }, m_denominator{ denominator } {
	if (m_denominator == 0)
		throw runtime_error("Fraction's denominator cannot be assigned to 0!");
	reduce();
}

//METHODS
int Fraction::gcd(int a, int b){
	return (b == 0) ? a : gcd(b, a%b);
}
void Fraction::reduce() {
	int cd = gcd(m_numerator, m_denominator);
	m_numerator /= cd;
	m_denominator /= cd;
}

ostream& Fraction::print(ostream& out)const{
	if (m_denominator != 1)
		out << m_numerator << "/" << m_denominator;
	else
		out << m_numerator;
	return out;
}
double Fraction::toDouble() const {
	return static_cast<double>(m_numerator) / m_denominator; 
}

//OPERATORS
Fraction Fraction::operator-() const {
	return Fraction(-m_numerator, m_denominator); 
}
Fraction Fraction::operator+() const {
	return *this;
}
Fraction& Fraction::operator+=(const Fraction& f2) {
	*this = *this + f2;
	return *this;
}
Fraction& Fraction::operator-=(const Fraction& f2) {
	*this = *this - f2;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& f2) {
	*this = *this * f2;
	return *this;
}
Fraction& Fraction::operator/=(const Fraction& f2) {
	*this = *this / f2;
	return *this;
}

Fraction operator+(const Fraction& f1, const Fraction& f2) {
	return Fraction(f1.m_numerator*f2.m_denominator + f1.m_denominator * f2.m_numerator, f1.m_denominator*f2.m_denominator);
}
Fraction operator-(const Fraction& f1, const Fraction& f2) {
	return f1 + -f2;
}
Fraction operator*(const Fraction& f1, const Fraction& f2){
	return Fraction(f1.m_numerator*f2.m_numerator, f1.m_denominator*f2.m_denominator);
}
Fraction operator/(const Fraction& f1, const Fraction& f2){
	if (f2.m_numerator == 0) 
		throw runtime_error("Division by 0");
	return Fraction(f1.m_numerator*f2.m_denominator, f1.m_denominator*f2.m_numerator);
}
bool operator==(const Fraction& f1, const Fraction& f2) {
	return (f1.m_numerator*f2.m_denominator == f1.m_denominator * f2.m_numerator);
}
bool operator!=(const Fraction& f1, const Fraction& f2) {
	return !(f1==f2);
}

ostream& operator<<(ostream& out, const Fraction& f) {
	return f.print(out);
}
istream& operator>>(istream& in, Fraction& f) {
	in >> f.m_numerator;
	char c = in.get();
	if (c == '\n') { 
		f.m_denominator = 1; 
		return in; 
	}
	if (c != '/') 
		throw runtime_error("Unhandled input");
	in >> f.m_denominator;
	if (f.m_denominator == 0) 
		throw runtime_error("Fraction's denominator cannot be assigned to 0");
	f.reduce();
	return in;
}