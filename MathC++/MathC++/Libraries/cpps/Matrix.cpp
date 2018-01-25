#include "..\headers\Matrix.h"


//CONSTRUCTORS
Matrix::Matrix() {}
Matrix::Matrix(const vector<LinearEquation>& vect):vect(vect) { }
Matrix::Matrix(const initializer_list<LinearEquation>& list):vect(list) {}
Matrix Matrix::E(size_t size){
	Matrix e(vector<LinearEquation>(size, LinearEquation(size)));
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			if (i == j)e[i][j] = 1;
	return e;
}

size_t Matrix::size()const { 
	return vect.size();
}
//TEST IT
string Matrix::print() const{
	string temp;
	temp+= '\n';
	for (const auto &elem : vect){
		temp+=elem.print() + '\n';
	}
	temp += '\n';
	return temp;
}
Fraction Matrix::determinant()const{
	if (vect.size() != vect[0].getEquation().size()) { 
		cout << "Matrix has no determinant since it is not squared!\n"; 
		return Fraction(); 
	}
	if (vect.size() == 1) 
		return vect[0][0];
	Fraction det = 0;
	for (size_t i = 0; i < vect.size(); ++i){
		Matrix newmatrix(vector<LinearEquation>(vect.size() - 1, vect.size() - 1));
		for (size_t j = 0; j < vect.size(); ++j){
			if (i == j) 
				continue;
			for (size_t k = 0; k < vect.size() - 1; ++k)
				newmatrix[k][j - (j > i)] = vect[k + 1][j];
		}
		if (i % 2 == 0)
			det += vect[0][i] * newmatrix.determinant();
		else 
			if (i % 2 == 1)
				det -= vect[0][i] * newmatrix.determinant();
	}
	return det;
}
Matrix Matrix::transposed()const{
	if (vect[0].getEquation().size() == 0 || vect.size() == 0){
		cout << "Matrix could not be transposed!\n";
		return Matrix();
	}
	Matrix m(vector<LinearEquation>(vect[0].getEquation().size(), LinearEquation(vect.size())));
	for (size_t i = 0; i < vect.size(); ++i)
		for (size_t j = 0; j < vect[0].getEquation().size(); ++j)
			m[j][i] = vect[i][j];
	return m;
}
Matrix Matrix::inversed()const{
	if (this->determinant() == 0) { cout << "Inversed matrix does not exist!\n"; return Matrix(); }
	Matrix m_inversed(vector<LinearEquation>(this->size(), LinearEquation(this->size())));
	for (size_t row = 0; row < this->size(); row++)
		for (size_t col = 0; col < this->size(); col++){
			Matrix minor(vector<LinearEquation>(this->size() - 1, LinearEquation(this->size() - 1)));
			for (size_t i = 0; i < this->size(); i++)
				for (size_t j = 0; j < this->size(); j++){
					if (i == row || j == col)
						continue;
					minor[i - (i > row)][j - (j > col)] = this->vect[i][j];
				}
			m_inversed[row][col] = Fraction(static_cast<int>(pow(-1, row + col)))*minor.determinant();
		}
	return m_inversed.transposed() * (Fraction(1) / this->determinant());
}
Matrix Matrix::power(int deg)const{
	Matrix m = *this, result = m;
	if (deg <= 0) {
		m = m.inversed();
		deg = -deg;
		for (; deg >= 0; deg--)
			result = result * m;
	}
	for (; deg > 1; deg--)
		result = result * m;
	return result;
}

LinearEquation& Matrix::operator[](size_t index) {
	return vect[index];
}
const LinearEquation& Matrix::operator[](size_t index)const {
	return vect[index];
}
//Ось тут. Стандарт.
Matrix operator*(const Matrix& left, const Fraction& right) {
	for (size_t i = 0; i < left.size(); ++i)
		for (size_t j = 0; j < left.vect[0].getEquation().size(); ++j)
			left[i][j] *= right;
	return left;
}
Matrix operator*(const Fraction& left, const Matrix& right) {
	return right * left;
}
//А тут норм
Matrix operator+(const Matrix& left, const Matrix& right) {
	if (left.size() != right.size() || left.vect[0].getEquation().size() != right.vect[0].getEquation().size()) {
		cout << "Matrices could not be added!\n";
		return Matrix();
	}
	Matrix m(vector<LinearEquation>(left.size(), LinearEquation(left.size())));
	for (size_t i = 0; i < left.size(); ++i)
		m[i] = left[i] + right[i];
	return m;
}
Matrix operator-(const Matrix& left, const Matrix& right) {
	return left + -right;
}
Matrix operator*(const Matrix& left, const Matrix& right) {
	if (left.vect[0].getEquation().size() != right.size()) {
		cout << "Matrices could not be multiplicated!\n";
		return Matrix();
	}
	Matrix m(vector<LinearEquation>(left.size(), LinearEquation(right.vect[0].getEquation().size())));
	for (size_t i = 0; i < left.size(); ++i)
		for (size_t j = 0; j < right.vect[0].getEquation().size(); ++j)
			for (size_t k = 0; k < right.size(); ++k)
				m[i][j] += left[i][k] * right[k][j];
	return m;
}

Matrix& Matrix::operator+() {
	return *this;
}
const Matrix& Matrix::operator+()const {
	return *this;
}
//ТУТ
Matrix Matrix::operator-() {
	for (auto &elem : vect)
		elem = -elem;
	return *this;
}
bool operator==(const Matrix& left, const Matrix& right) {
	return left.vect == right.vect;
}
bool operator!=(const Matrix& left, const Matrix& right) {
	return !(left.vect == right.vect);
}

ostream& operator<<(ostream& out, Matrix m) {
	out << m.print();
	return out;
}