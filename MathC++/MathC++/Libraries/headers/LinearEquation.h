#pragma once
#include <vector>
#include "Complex.h"

class LinearEquation{
protected:
	vector<Fraction> valArray;
public:
	LinearEquation(int);
	LinearEquation(const vector<Fraction>&);
	LinearEquation(const initializer_list<Fraction>&);

	vector<Fraction>& getEquation(); //getter hybrid must be splited into getter and setter
	vector<Fraction> getEquation() const; //getter, non-tested
	void printEquation() const;

	LinearEquation operator+() const;//constness added, not tested
	LinearEquation operator-() const;//constness added, not tested
	Fraction& operator[](int index); //getter hybrid must be splited into getter and setter
	Fraction operator[](int index) const; //getter, non-tested

	friend LinearEquation operator-(const LinearEquation&,const LinearEquation&);//constness added, not tested
	friend LinearEquation operator+(const LinearEquation&,const LinearEquation&);//constness added, not tested
	friend bool operator==(const LinearEquation&, const LinearEquation&);//constness added, not tested
	friend bool operator!=(const LinearEquation&, const LinearEquation&);//constness added, not tested
	friend LinearEquation operator*(const Fraction&,const LinearEquation&);//constness added, not tested
	//operator<< could be overloaded too by use of "printEquation" method
};
