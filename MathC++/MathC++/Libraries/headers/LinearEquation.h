#pragma once
#include <vector>
#include "Complex.h"

template<class T>
class LinearEquation{
protected:
	vector<T> valArray;
public:
	LinearEquation(size_t);//1
	LinearEquation(const vector<T>&);//1
	LinearEquation(const initializer_list<T>&);//1

	vector<T>& getEquation();//1
	const vector<T>& getEquation() const;//1
	ostream& print(ostream&) const;//1

	LinearEquation<T> operator+() const;//1
	LinearEquation<T> operator-() const;//1
	T& operator[](size_t index); //1
	const T& operator[](size_t index) const;//1 

	template<class F>
	friend LinearEquation<F> operator-(const LinearEquation<F>&,const LinearEquation<F>&);//1
	template<class F>
	friend LinearEquation<F> operator+(const LinearEquation<F>&,const LinearEquation<F>&);//1
	template<class F>
	friend bool operator==(const LinearEquation<F>&, const LinearEquation<F>&);//1
	template<class F>
	friend bool operator!=(const LinearEquation<F>&, const LinearEquation<F>&);//1
	template<class F>
	friend LinearEquation<F> operator*(const F&,const LinearEquation<F>&);
	
	template<class F>
	friend ostream& operator<<(ostream& out, const LinearEquation<F>& le);//1
};


//CONSTRUCTORS
template<class T>
LinearEquation<T>::LinearEquation(size_t length) { valArray.resize(length); }
template<class T>
LinearEquation<T>::LinearEquation(const vector<T>& vect) :valArray{ vect } { }
template<class T>
LinearEquation<T>::LinearEquation(const initializer_list<T>& list) : valArray{ list } { }

//METHODS
template<class T>
vector<T>& LinearEquation<T>::getEquation() {
	return valArray;
}
template<class T>
const vector<T>& LinearEquation<T>::getEquation() const {
	return valArray;
}
template<class T>
ostream& LinearEquation<T>::print(ostream& out) const {
	for (const auto &elem : valArray)
		out << elem << " ";
	return out;
}

//OPERATORS
template<class T>
LinearEquation<T> operator+(const LinearEquation<T>& left, const LinearEquation<T>& right) {
	LinearEquation<T> eq(left.valArray.size());
	for (size_t i = 0; i < left.valArray.size(); ++i)
		eq[i] = left[i] + right[i];
	return eq;
}
template<class T>
LinearEquation<T> operator-(const LinearEquation<T>& left, const LinearEquation<T>& right) {
	return left + (-right);
}
template<class T>
T& LinearEquation<T>::operator[](size_t index) {
	return valArray[index];
}
template<class T>
const T& LinearEquation<T>::operator[](size_t index) const {
	return valArray[index];
}
template<class T>
LinearEquation<T> LinearEquation<T>::operator+() const {
	return *this;
}
template<class T>
LinearEquation<T> LinearEquation<T>::operator-() const {
	vector<T> temp{ valArray };
	for (auto& elem : temp)
		elem = -elem;
	return temp;
}
template<class T>
LinearEquation<T> operator*(const T& left, const LinearEquation<T>& right) {
	LinearEquation<T> eq(right.getEquation().size());
	for (size_t i = 0; i < right.getEquation().size(); ++i)
		eq[i] = left * right[i];
	return eq;
}
template<class T>
bool operator==(const LinearEquation<T>& left, const LinearEquation<T>& right) {
	return left.valArray == right.valArray;
}
template<class T>
bool operator!=(const LinearEquation<T>& left, const LinearEquation<T>& right) {
	return !(left.valArray == right.valArray);
}
template<class T>
ostream& operator<<(ostream& out, const LinearEquation<T>& le) {
	return le.print(out);
}