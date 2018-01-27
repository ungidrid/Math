#pragma once
#include <vector>
#include "Complex.h"

template<class T>
class LinearEquation{
protected:
	vector<T> valArray;
public:
	LinearEquation(size_t);
	LinearEquation(const vector<T>&);
	LinearEquation(const initializer_list<T>&);

	vector<T>& getEquation();
	const vector<T>& getEquation() const;
	ostream& print(ostream&) const;

	LinearEquation<T> operator+() const;
	LinearEquation<T> operator-() const;
	T& operator[](size_t index); 
	const T& operator[](size_t index) const;

	template<class F>
	friend LinearEquation<F> operator-(const LinearEquation<F>&,const LinearEquation<F>&);
	template<class F>
	friend LinearEquation<F> operator+(const LinearEquation<F>&,const LinearEquation<F>&);
	template<class F>
	friend bool operator==(const LinearEquation<F>&, const LinearEquation<F>&);
	template<class F>
	friend bool operator!=(const LinearEquation<F>&, const LinearEquation<F>&);
	//friend bool operator==(const LinearEquation&, int a);
	template<class T, class F>
	friend LinearEquation<F> operator*(const T&,const LinearEquation<F>&);
	
	template<class F>
	friend ostream& operator<<(ostream& out, const LinearEquation<F>& le);
};

#include "../cpps/LinearEquation.inl"