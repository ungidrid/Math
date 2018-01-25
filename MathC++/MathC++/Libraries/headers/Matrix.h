#pragma once
#include <vector>
#include "LinearEquation.h"

/*class Matrix
{
protected:
	vector<LinearEquation> vect;
public:
	Matrix();
	Matrix(const vector<LinearEquation>& vect);
	Matrix(const initializer_list<LinearEquation>& list);
	static Matrix E(int size);
	LinearEquation& operator[](int index) { return vect[index]; }
	int size();
	virtual void printMatrix() const;
	friend ostream& operator<<(ostream& out, Matrix m)
	{
		m.printMatrix();
		return out;
	}
	Fraction determinant();
	Matrix transposed();
	Matrix inversed();
	Matrix power(int deg);
	friend Matrix operator*(Matrix left, Fraction right)
	{
		for (int i = 0; i < left.size(); i++)
			for (int j = 0; j < left.vect[0].getEquation().size(); j++)
				left[i][j] *= right;
		return left;
	}
	friend Matrix operator*(Fraction left, Matrix right) { return right*left; }
	friend Matrix operator+(Matrix left, Matrix right)
	{
		if (left.size() != right.size() || left.vect[0].getEquation().size() != right.vect[0].getEquation().size())
		{
			cout << "Matrices could not be added!\n";
			return Matrix();
		}
		Matrix m(vector<LinearEquation>(left.size(), LinearEquation(left.size())));
		for (int i = 0; i < left.size(); i++)
			m[i] = left[i] + right[i];
		return m;
	}
	friend Matrix operator-(Matrix left, Matrix right) { return left + -right; }
	friend Matrix operator*(Matrix left, Matrix right)
	{
		if (left.vect[0].getEquation().size() != right.size())
		{
			cout << "Matrices could not be multiplicated!\n";
			return Matrix();
		}
		Matrix m(vector<LinearEquation>(left.size(), LinearEquation(right.vect[0].getEquation().size())));
		for(int i = 0; i < left.size(); i++)
			for (int j = 0; j < right.vect[0].getEquation().size(); j++)
				for (int k = 0; k < right.size(); k++)
					m[i][j] += left[i][k] * right[k][j];
		return m;
	}
	Matrix operator+() { return *this; }
	Matrix operator-() { for (auto &elem : vect) { elem = -elem; } return *this; }
	friend bool operator==(Matrix left, Matrix right) { return left.vect == right.vect; }
	friend bool operator!=(Matrix left, Matrix right) { return left.vect != right.vect; }
};*/