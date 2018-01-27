#include "..\headers\Matrix.h"


//CONSTRUCTORS
Matrix::Matrix() {}
Matrix::Matrix(const vector<LinearEquation>& vect):vect{vect} { }
Matrix::Matrix(const initializer_list<LinearEquation>& list):vect{list} {}
Matrix Matrix::E(size_t size){
	Matrix e(vector<LinearEquation>(size, LinearEquation(size)));
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			if (i == j)e[i][j] = 1;
	return e;
}

size_t Matrix::size() const{ 
	return vect.size();
}
ostream& Matrix::print(ostream& out) const{
	out << '\n';
	for (const auto &elem : vect)
		out << elem << '\n';
	out << '\n';
	return out;
}
Fraction Matrix::determinant() const{
	assert(vect.size() == vect[0].getEquation().size() && "Matrix has no determinant since it is not squared!"); //assertation added
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
			det -= vect[0][i] * newmatrix.determinant(); // else if -> else
	}
	return det;
}
Matrix Matrix::transposed() const{
	assert(vect[0].getEquation().size() != 0 && vect.size() != 0 && "Matrix could not be transposed!"); //assertation added
	Matrix m(vector<LinearEquation>(vect[0].getEquation().size(), LinearEquation(vect.size())));
	for (size_t i = 0; i < vect.size(); ++i)
		for (size_t j = 0; j < vect[0].getEquation().size(); ++j)
			m[j][i] = vect[i][j];
	return m;
}
Matrix Matrix::inversed() const{
	assert(determinant() != 0 && "Inversed matrix does not exist!");//assertation added
	Matrix m_inversed(vector<LinearEquation>(this->size(), LinearEquation(this->size())));
	for (size_t row = 0; row < this->size(); ++row)
		for (size_t col = 0; col < this->size(); ++col){
			Matrix minor(vector<LinearEquation>(this->size() - 1, LinearEquation(this->size() - 1)));
			for (size_t i = 0; i < this->size(); ++i)
				for (size_t j = 0; j < this->size(); ++j){
					if (i == row || j == col)
						continue;
					minor[i - (i > row)][j - (j > col)] = this->vect[i][j];
				}
			m_inversed[row][col] = Fraction(static_cast<int>(pow(-1, row + col)))*minor.determinant();
		}
	return m_inversed.transposed() * (Fraction(1) / this->determinant());
}
Matrix Matrix::power(int deg) const{
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
size_t Matrix::rows()const {
	return vect.size();
}
size_t  Matrix::cols()const {
	return vect[0].getEquation().size();
}
size_t  Matrix::rank()const {
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

LinearEquation& Matrix::operator[](size_t index) {
	return vect[index];
}
const LinearEquation& Matrix::operator[](size_t index) const {
	return vect[index];
}
Matrix operator*(const Matrix& left, const Fraction& right) {
	Matrix m{ left };
	for (size_t i = 0; i < left.size(); ++i)
		for (size_t j = 0; j < left.vect[0].getEquation().size(); ++j)
			m[i][j] *= right;
	return left;
}
Matrix operator*(const Fraction& left, const Matrix& right) {
	return right * left;
}
Matrix operator+(const Matrix& left, const Matrix& right) {
	assert(left.size() == right.size() && left.vect[0].getEquation().size() == right.vect[0].getEquation().size() && "Matrices could not be added!"); // assertation added
	Matrix m(vector<LinearEquation>(left.size(), LinearEquation(left.size())));
	for (size_t i = 0; i < left.size(); ++i)
		m[i] = left[i] + right[i];
	return m;
}
Matrix operator-(const Matrix& left, const Matrix& right) {
	return left + -right;
}
Matrix operator*(const Matrix& left, const Matrix& right) {
	assert(left.vect[0].getEquation().size() == right.size() && "Matrices could not be multiplicated!");//assertation added
	Matrix m(vector<LinearEquation>(left.size(), LinearEquation(right.vect[0].getEquation().size())));
	for (size_t i = 0; i < left.size(); ++i)
		for (size_t j = 0; j < right.vect[0].getEquation().size(); ++j)
			for (size_t k = 0; k < right.size(); ++k)
				m[i][j] += left[i][k] * right[k][j];
	return m;
}

Matrix Matrix::operator+()const {
	return *this;
}
Matrix Matrix::operator-() const {
	Matrix temp{ *this };
	for (size_t i = 0; i < temp.size(); ++i)
		temp[i] = -temp[i];
	return temp;
}
bool operator==(const Matrix& left, const Matrix& right) {
	return left.vect == right.vect;
}
bool operator!=(const Matrix& left, const Matrix& right) {
	return !(left.vect == right.vect);
}

ostream& operator<<(ostream& out,const Matrix& m) {
	return m.print(out);
}