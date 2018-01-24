#pragma once
#include <vector>
#include "LinearEquationClassC++.h"

class Matrix
{
protected:
	vector<LinearEquation> vect;
public:
	Matrix() {}
	Matrix(const vector<LinearEquation>& vect) { this->vect = vect; }
	Matrix(const initializer_list<LinearEquation>& list) { vect = list; }
	static Matrix E(int size)
	{
		Matrix e(vector<LinearEquation>(size, LinearEquation(size)));
		for(int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				if (i == j)e[i][j] = 1;
		return e;
	}
	LinearEquation& operator[](int index) { return vect[index]; }
	int size() { return vect.size(); }
	virtual void printMatrix() const
	{
		cout << '\n';
		for (const auto &elem : vect)
		{
			elem.printEquation(); 
			cout << '\n';
		}
		cout << '\n';
	}
	friend ostream& operator<<(ostream& out, Matrix m)
	{
		m.printMatrix();
		return out;
	}
	Fraction determinant()
	{
		if (vect.size() != vect[0].getEquation().size()) { cout << "Matrix has no determinant since it is not squared!\n"; return Fraction(); }
		if (vect.size() == 1) return vect[0][0];
		Fraction det = 0;
		for (int i = 0; i < vect.size(); i++)
		{
			Matrix newmatrix(vector<LinearEquation>(vect.size() - 1, vect.size() - 1));
			for (int j = 0; j < vect.size(); j++)
			{
				if (i == j) continue;
				for (int k = 0; k < vect.size() - 1; k++)
					newmatrix[k][j - (j > i)] = vect[k + 1][j];
			}
			if (i % 2 == 0)
				det += vect[0][i] * newmatrix.determinant();

			else if (i % 2 == 1)
				det -= vect[0][i] * newmatrix.determinant();
		}
		return det;
	}
	Matrix transposed()
	{
		if (vect[0].getEquation().size() == 0 || vect.size() == 0)
		{
			cout << "Matrix could not be transposed!\n";
			return Matrix();
		}
		Matrix m(vector<LinearEquation>(vect[0].getEquation().size(), LinearEquation(vect.size()) ) );
		for(int i = 0; i < vect.size(); i++)
			for (int j = 0; j < vect[0].getEquation().size(); j++)
				m[j][i] = vect[i][j];
		return m;
	}
	Matrix inversed()
	{
		if (this->determinant() == 0) { cout << "Inversed matrix does not exist!\n"; return Matrix(); }
		Matrix m_inversed(vector<LinearEquation>(this->size(), LinearEquation(this->size())));
		for (int row = 0; row < this->size(); row++)
			for (int col = 0; col < this->size(); col++)
			{
				Matrix minor(vector<LinearEquation>(this->size() - 1, LinearEquation(this->size() - 1)));
				for (int i = 0; i < this->size(); i++)
					for (int j = 0; j < this->size(); j++)
					{
						if (i == row || j == col)continue;
						minor[i - (i > row)][j - (j > col)] = this->vect[i][j];
					}
				m_inversed[row][col] = Fraction(static_cast<int>(pow(-1,row+col)))*minor.determinant();
			}
		return m_inversed.transposed() * ( Fraction(1) / this->determinant());
	}
	Matrix power(int deg)
	{
		Matrix m = *this, result = m;
		if (deg <= 0) { 
			m = m.inversed(); 
			deg = -deg; 
			for (; deg >= 0; deg--)
				result = result*m;
		}
		for (; deg > 1; deg--)
			result = result*m;
		return result;
	}
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
};