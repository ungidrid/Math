#pragma once
#include <vector>
#include "LinearEquation.h"

class Matrix{
protected:
	vector<LinearEquation> vect;
public:
	Matrix();
	Matrix(const vector<LinearEquation>&);
	Matrix(const initializer_list<LinearEquation>&);
	static Matrix E(size_t);

	size_t size() const;
	virtual ostream& print(ostream&) const;
	Fraction determinant() const;
	Matrix transposed() const;
	Matrix inversed() const;
	Matrix power(int) const;
	size_t rows()const {
		return vect.size();
	}
	size_t cols()const {
		return vect[0].getEquation().size();
	}
	size_t rank()const {
		Matrix mat;
		if (this->cols() > this->rows())
			mat = this->transposed();
		else
			mat = *this;
		for (size_t i = 0; i < mat.cols(); ++i)
			for (size_t j = 0; j < mat.rows(); ++j) {
				if (i >= j)
					continue;
				mat[j] = mat[i] * mat[j][i] - mat[j] * mat[i][i];
			}

		size_t rank = 0;
		for (size_t i = 0; i < mat.rows(); ++i) {
			if (mat[i] == 0)
				continue;
			else
				++rank;
		}
		return rank;
	}


	LinearEquation& operator[](size_t);
	const LinearEquation& operator[](size_t)const;
	friend Matrix operator*(const Matrix&, const Fraction&);
	friend Matrix operator*(const Fraction&, const Matrix&);
	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator-(const Matrix&, const Matrix&);
	friend Matrix operator*(const Matrix&, const Matrix&);
	
	Matrix operator+() const;	//YOU SHELL NOT LEAVE IT ALIVE!
	Matrix operator-() const;

	friend bool operator==(const Matrix&, const Matrix&);
	friend bool operator!=(const Matrix&, const Matrix&);

	//REDO
	friend ostream& operator<<(ostream&, const Matrix&);
};