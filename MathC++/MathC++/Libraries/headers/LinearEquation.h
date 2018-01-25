#pragma once
#include <vector>
#include "Complex.h"

template<class T>
class LinearEquation{
protected:
	vector<T> valArray;
public:
	LinearEquation(int);
	LinearEquation(const vector<T>&);
	LinearEquation(const initializer_list<T>&);

	vector<T>& getEquation(); //getter hybrid must be splited into getter and setter
	vector<T> getEquation() const; //getter, non-tested
	void printEquation() const;

	LinearEquation operator+() const;//constness added, not tested
	LinearEquation operator-() const;//constness added, not tested
	T& operator[](int index); //getter hybrid must be splited into getter and setter
	T operator[](int index) const; //getter, non-tested

	friend LinearEquation operator-(const LinearEquation&,const LinearEquation&);//constness added, not tested
	friend LinearEquation operator+(const LinearEquation&,const LinearEquation&);//constness added, not tested
	friend bool operator==(const LinearEquation&, const LinearEquation&);//constness added, not tested
	friend bool operator!=(const LinearEquation&, const LinearEquation&);//constness added, not tested
	friend LinearEquation operator*(const T&,const LinearEquation&);//constness added, not tested
	//operator<< could be overloaded too by use of "printEquation" method
};
