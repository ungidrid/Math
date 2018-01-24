#pragma once
#include <vector>
#include "Complex.h"

class LinearEquation{
protected:
	vector<Fraction> valArray;
public:
	LinearEquation(int length);
	LinearEquation(const vector<Fraction> &vect);
	LinearEquation(const initializer_list<Fraction>& list);

	vector<Fraction>& getEquation();
	void printEquation() const;

	LinearEquation& operator+() { return *this; }
	LinearEquation& operator-() { for (auto &elem : valArray) { elem = -elem; } return *this; }
	Fraction& operator[](int index);

	friend LinearEquation operator-(LinearEquation left, LinearEquation right);
	friend LinearEquation operator+(LinearEquation left, LinearEquation right);
	friend bool operator==(LinearEquation left, LinearEquation right);
	friend bool operator!=(LinearEquation left, LinearEquation right);
	friend LinearEquation operator*(Fraction left, LinearEquation right);
};
