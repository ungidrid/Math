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

	size_t size()const;
	virtual void printMatrix() const;	//REDO
	Fraction determinant()const;
	Matrix transposed()const;
	Matrix inversed()const;
	Matrix power(int)const;

	LinearEquation& operator[](size_t);
	const LinearEquation& operator[](size_t)const;
	//�� ����� �� ���������� ����� ���������. ����� ���� ��������� ����� ��'���, ����� ���� �������. ��� ������ ������������, ������
	friend Matrix operator*(const Matrix&, const Fraction&);
	friend Matrix operator*(const Fraction&, const Matrix&);
	//� ��� ����
	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator-(const Matrix&, const Matrix&);
	friend Matrix operator*(const Matrix&, const Matrix&);
	
	Matrix& operator+();
	const Matrix& operator+()const;

	//� ��� � ���� ������� ���� ���� ��'���. � ����� �� ��� �� �����
	Matrix operator-();
	friend bool operator==(const Matrix&, const Matrix&);
	friend bool operator!=(const Matrix&, const Matrix&);

	//REDO
	friend ostream& operator<<(ostream&, Matrix);
};