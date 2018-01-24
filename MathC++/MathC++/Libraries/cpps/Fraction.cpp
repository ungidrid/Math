#include "../headers/Fraction.h"





//CONSTRUCTORS
Fraction::Fraction(int numerator = 0, int denominator = 1) : m_numerator{ numerator }, m_denominator{ denominator } {
	assert(m_denominator != 0 && "Fraction's denominator cannot be assigned to 0");
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

double Fraction::toDouble() {
	return static_cast<double>(m_numerator) / m_denominator; 
}

//OPERATORS
Fraction Fraction::operator-() {
	return Fraction(-m_numerator, m_denominator); 
}
Fraction Fraction::operator+() {
	return *this; 
}
Fraction Fraction::operator+(const Fraction& f2) {
	return Fraction(m_numerator*f2.m_denominator + m_denominator * f2.m_numerator, m_denominator*f2.m_denominator);
}
Fraction Fraction::operator-(const Fraction& f2) {
	return Fraction(m_numerator*f2.m_denominator - m_denominator * f2.m_numerator, m_denominator*f2.m_denominator);
}
Fraction Fraction::operator*(const Fraction& f2){
	return Fraction(m_numerator*f2.m_numerator, m_denominator*f2.m_denominator);
}
Fraction Fraction::operator/(const Fraction& f2){
	assert(f2.m_numerator != 0 && "Division by 0");
	return Fraction(m_numerator*f2.m_denominator, m_denominator*f2.m_numerator);
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
bool Fraction::operator==(const Fraction& f2) {
	return (m_numerator*f2.m_denominator == m_denominator * f2.m_numerator);
}
bool Fraction::operator!=(const Fraction& f2) {
	return !Fraction::operator==(f2);
}

ostream& operator<<(ostream& out, const Fraction& f) {
	if (f.m_denominator != 1) {
		out << f.m_numerator << "/" << f.m_denominator;
		return out;
	}
	else
		out << f.m_numerator; return out;
}
istream& operator>>(istream& in, Fraction& f) {
	in >> f.m_numerator;
	char c = in.get();
	if (c == '\n') { f.m_denominator = 1; return in; }
	assert(c == '/' && "Unhandled input");
	in >> f.m_denominator;
	assert(f.m_denominator != 0 && "Fraction's denominator cannot be assigned to 0");
	f.reduce();
	return in;
}