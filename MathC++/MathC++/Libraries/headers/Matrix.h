#pragma once
#include <vector>
#include "LinearEquation.h"

template<class T>
class Matrix {
protected:
	vector<LinearEquation<T>> vect;
public:
	Matrix();
	Matrix(const vector<LinearEquation<T>>&);
	Matrix(const initializer_list<LinearEquation<T>>&);
	//IDENTITY MATRIX
	static Matrix<T> E(size_t);

	size_t size() const;
	virtual ostream& print(ostream&) const;
	T determinant() const;
	Matrix<T> transposed() const;
	Matrix<T> inversed() const;
	Matrix<T> power(int) const;
	Matrix<T> operator+() const;
	Matrix<T> operator-() const;

	LinearEquation<T>& operator[](size_t);
	const LinearEquation<T>& operator[](size_t)const;
	template<class F>
	friend Matrix<F> operator*(const Matrix<F>&, const F&);
	template<class F>
	friend Matrix<F> operator*(const F&, const Matrix<F>&);
	template<class F>
	friend Matrix<F> operator+(const Matrix<F>&, const Matrix<F>&);
	template<class F>
	friend Matrix<F> operator-(const Matrix<F>&, const Matrix<F>&);
	template<class F>
	friend Matrix<F> operator*(const Matrix<F>&, const Matrix<F>&);
	template<class F>
	friend bool operator==(const Matrix<F>&, const Matrix<F>&);
	template<class F>
	friend bool operator!=(const Matrix<F>&, const Matrix<F>&);

	template<class F>
	friend ostream& operator<<(ostream&, const Matrix<F>&);
};

#include "../cpps/Matrix.inl"