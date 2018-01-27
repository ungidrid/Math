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

	virtual ostream& print(ostream&) const;
	T determinant() const;
	Matrix<T> transposed() const;
	Matrix<T> inversed() const;
	Matrix<T> power(int) const;
	Matrix<T> operator+() const;
	Matrix<T> operator-() const;
	size_t rows() const; 
	size_t cols() const;
	size_t rank() const;

	LinearEquation<T>& operator[](size_t);
	const LinearEquation<T>& operator[](size_t)const;
	template<class T,class F>
	friend Matrix<F> operator*(const Matrix<F>&, const T&);
	template<class T, class F>
	friend Matrix<F> operator*(const T&, const Matrix<F>&);
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