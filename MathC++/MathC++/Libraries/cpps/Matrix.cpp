/*#include "..\headers\Matrix.h"


//CONSTRUCTORS
template<class T>
Matrix<T>::Matrix() {}
template<class T>
Matrix<T>::Matrix(const vector<LinearEquation<T>>& vect):vect{vect} { }
template<class T>
Matrix<T>::Matrix(const initializer_list<LinearEquation<T>>& list):vect{list} {}

template<class T>
Matrix<T> Matrix<T>::E(size_t size){
	Matrix e(vector<LinearEquation<T>>(size, LinearEquation<T>(size)));
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			if (i == j)e[i][j] = static_cast<T>(1);
	return e;
}
template<class T>
size_t Matrix<T>::size() const{ 
	return vect.size();
}
template<class T>
ostream& Matrix<T>::print(ostream& out) const{
	out << '\n';
	for (const auto &elem : vect)
		out << elem << '\n';
	out << '\n';
	return out;
}
template<class T>
T Matrix<T>::determinant() const{
	assert(vect.size() == vect[0].getEquation().size() && "Matrix has no determinant since it is not squared!"); //assertation added
	if (vect.size() == 1) 
		return vect[0][0];
	T det = 0;
	for (size_t i = 0; i < vect.size(); ++i){
		Matrix<T> newmatrix(vector<LinearEquation<T>>(vect.size() - 1, vect.size() - 1));
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
template<class T>
Matrix<T> Matrix<T>::transposed() const{
	assert(vect[0].getEquation().size() != 0 && vect.size() != 0 && "Matrix could not be transposed!"); //assertation added
	Matrix<T> m(vector<LinearEquation<T>>(vect[0].getEquation().size(), LinearEquation<T>(vect.size())));
	for (size_t i = 0; i < vect.size(); ++i)
		for (size_t j = 0; j < vect[0].getEquation().size(); ++j)
			m[j][i] = vect[i][j];
	return m;
}
template<class T>
Matrix<T> Matrix<T>::inversed() const{
	assert(determinant() != static_cast<T>(0) && "Inversed matrix does not exist!");//assertation added
	Matrix<T> m_inversed(vector<LinearEquation<T>>(this->size(), LinearEquation<T>(this->size())));
	for (size_t row = 0; row < this->size(); ++row)
		for (size_t col = 0; col < this->size(); ++col){
			Matrix<T> minor(vector<LinearEquation<T>>(this->size() - 1, LinearEquation<T>(this->size() - 1)));
			for (size_t i = 0; i < this->size(); ++i)
				for (size_t j = 0; j < this->size(); ++j){
					if (i == row || j == col)
						continue;
					minor[i - (i > row)][j - (j > col)] = this->vect[i][j];
				}
			m_inversed[row][col] = T(static_cast<int>(pow(-1, row + col)))*minor.determinant();
		}
	return m_inversed.transposed() * (static_cast<T>(1) / this->determinant());
}
template<class T>
Matrix<T> Matrix<T>::power(int deg) const{
	Matrix<T> m = *this, result = m;
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
template<class T>
LinearEquation<T>& Matrix<T>::operator[](size_t index) {
	return vect[index];
}
template<class T>
const LinearEquation<T>& Matrix<T>::operator[](size_t index) const {
	return vect[index];
}
template<class T>
Matrix<T> operator*(const Matrix<T>& left, const T& right) {
	Matrix<T> m{ left };
	for (size_t i = 0; i < left.size(); ++i)
		for (size_t j = 0; j < left.vect[0].getEquation().size(); ++j)
			m[i][j] *= right;
	return left;
}
template<class T>
Matrix<T> operator*(const T& left, const Matrix<T>& right) {
	return right * left;
}
template<class T>
Matrix<T> operator+(const Matrix<T>& left, const Matrix<T>& right) {
	assert(left.size() == right.size() && left.vect[0].getEquation().size() == right.vect[0].getEquation().size() && "Matrices could not be added!"); // assertation added
	Matrix m(vector<LinearEquation<T>>(left.size(), LinearEquation<T>(left.size())));
	for (size_t i = 0; i < left.size(); ++i)
		m[i] = left[i] + right[i];
	return m;
}
template<class T>
Matrix<T> operator-(const Matrix<T>& left, const Matrix<T>& right) {
	return left + -right;
}
template<class T>
Matrix<T> operator*(const Matrix<T>& left, const Matrix<T>& right) {
	assert(left.vect[0].getEquation().size() == right.size() && "Matrices could not be multiplicated!");//assertation added
	Matrix<T> m(vector<LinearEquation<T>>(left.size(), LinearEquation<T>(right.vect[0].getEquation().size())));
	for (size_t i = 0; i < left.size(); ++i)
		for (size_t j = 0; j < right.vect[0].getEquation().size(); ++j)
			for (size_t k = 0; k < right.size(); ++k)
				m[i][j] += left[i][k] * right[k][j];
	return m;
}
template<class T>
Matrix<T> Matrix<T>::operator+() const {
	return *this;
}
template<class T>
Matrix<T> Matrix<T>::operator-() const {
	Matrix<T> temp{ *this };
	for (size_t i = 0; i < temp.size(); ++i)
		temp[i] = -temp[i];
	return temp;
}
template<class T>
bool operator==(const Matrix<T>& left, const Matrix<T>& right) {
	return left.vect == right.vect;
}
template<class T>
bool operator!=(const Matrix<T>& left, const Matrix<T>& right) {
	return !(left.vect == right.vect);
}
template<class T>
ostream& operator<<(ostream& out,const Matrix<T>& m) {
	return m.print(out);
}*/