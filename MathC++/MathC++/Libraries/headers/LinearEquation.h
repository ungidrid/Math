#pragma once
#include <vector>
#include "ComplexClassC++.h"

class LinearEquation
{
protected:
	vector<Fraction> valArray;
public:
	LinearEquation(int length) { valArray.resize(length); }
	LinearEquation(const vector<Fraction> &vect) { valArray = vect; }
	LinearEquation(const initializer_list<Fraction>& list) { valArray = list; }
	friend LinearEquation operator-(LinearEquation left, LinearEquation right)
	{
		LinearEquation eq(left.getEquation().size());
		for (int i = 0; i < left.getEquation().size(); i++)
			eq[i] = left[i] - right[i];
		return eq;
	}
	friend LinearEquation operator+(LinearEquation left, LinearEquation right) { return left - (-right); }
	LinearEquation operator+() { return *this; }
	LinearEquation operator-() { for (auto &elem : valArray) { elem = -elem; } return *this; }
	friend bool operator==(LinearEquation left, LinearEquation right) { return left.valArray == right.valArray; }
	friend bool operator!=(LinearEquation left, LinearEquation right) { return left.valArray != right.valArray; }
	friend LinearEquation operator*(Fraction left, LinearEquation right)
	{
		LinearEquation eq(right.getEquation().size());
		for (int i = 0; i < right.getEquation().size(); i++) { eq[i] = left*right[i]; }
		return eq;
	}
	Fraction& operator[](int index) { return valArray[index]; }
	vector<Fraction>& getEquation() { return valArray; }
	void printEquation() const
	{
		for (const auto &elem : valArray)
			cout << elem << " ";
	}
};
