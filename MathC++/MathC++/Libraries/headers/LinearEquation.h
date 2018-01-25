#pragma once
#include <vector>
#include "Complex.h"

class LinearEquation{
protected:
	vector<Fraction> valArray;
public:
	LinearEquation(size_t);
	LinearEquation(const vector<Fraction>&);
	LinearEquation(const initializer_list<Fraction>&);

	vector<Fraction>& getEquation();
	const vector<Fraction>& getEquation() const;
	ostream& print(ostream&) const;

	LinearEquation operator+() const;
	LinearEquation operator-() const;
	Fraction& operator[](size_t index); 
	const Fraction& operator[](size_t index) const; 

	friend LinearEquation operator-(const LinearEquation&,const LinearEquation&);
	friend LinearEquation operator+(const LinearEquation&,const LinearEquation&);
	friend bool operator==(const LinearEquation&, const LinearEquation&);
	friend bool operator!=(const LinearEquation&, const LinearEquation&);
	friend LinearEquation operator*(const Fraction&,const LinearEquation&);
	
	friend ostream& operator<<(ostream&, const LinearEquation&);
};
