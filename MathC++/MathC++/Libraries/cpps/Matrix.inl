//CONSTRUCTORS
template<class T>
Matrix<T>::Matrix() {}
template<class T>
Matrix<T>::Matrix(const vector<LinearEquation<T>>& vect) :vect{ vect } { }
template<class T>
Matrix<T>::Matrix(const initializer_list<LinearEquation<T>>& list) : vect{ list } {}

//METHODS
template<class T>
Matrix<T> Matrix<T>::E(size_t size) {
	Matrix e(vector<LinearEquation<T>>(size, LinearEquation<T>(size)));
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			if (i == j)e[i][j] = static_cast<T>(1);
	return e;
}
template<class T>
ostream& Matrix<T>::print(ostream& out) const {
	out << '\n';
	for (const auto &elem : vect)
		out << elem << '\n';
	out << '\n';
	return out;
}
template<class T>
T Matrix<T>::determinant() const {
	assert(rows() == cols() && "Matrix has no determinant since it is not squared!"); 
	if (rows() == 1)
		return vect[0][0];
	T det = static_cast<T>(0);
	for (size_t i = 0; i < rows(); ++i) {
		Matrix<T> newmatrix(vector<LinearEquation<T>>(rows() - 1, rows() - 1));
		for (size_t j = 0; j < rows(); ++j) {
			if (i == j)
				continue;
			for (size_t k = 0; k < rows() - 1; ++k)
				newmatrix[k][j - (j > i)] = vect[k + 1][j];
		}
		if (i % 2 == 0)
			det += vect[0][i] * newmatrix.determinant();
		else
			det -= vect[0][i] * newmatrix.determinant(); 
	}
	return det;
}
template<class T>
Matrix<T> Matrix<T>::transposed() const {
	assert(cols() != 0 && rows() != 0 && "Matrix could not be transposed!"); 
	Matrix<T> m(vector<LinearEquation<T>>(cols(), LinearEquation<T>(rows())));
	for (size_t i = 0; i < rows(); ++i)
		for (size_t j = 0; j < cols(); ++j)
			m[j][i] = vect[i][j];
	return m;
}
template<class T>
Matrix<T> Matrix<T>::inversed() const {
	assert(determinant() != static_cast<T>(0) && "Inversed matrix does not exist!");
	Matrix<T> m_inversed(vector<LinearEquation<T>>(rows(), LinearEquation<T>(rows())));
	for (size_t row = 0; row < rows(); ++row)
		for (size_t col = 0; col < cols(); ++col) {
			Matrix<T> minor(vector<LinearEquation<T>>(rows() - 1, LinearEquation<T>(rows() - 1)));
			for (size_t i = 0; i < rows(); ++i)
				for (size_t j = 0; j < rows(); ++j) {
					if (i == row || j == col)
						continue;
					minor[i - (i > row)][j - (j > col)] = vect[i][j];
				}
			m_inversed[row][col] = T(static_cast<int>(pow(-1, row + col)))*minor.determinant();
		}
	return m_inversed.transposed() * (static_cast<T>(1) / determinant());
}
template<class T>
Matrix<T> Matrix<T>::power(int deg) const {
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
size_t Matrix<T>::rows() const {
	return vect.size();
}
template<class T>
size_t Matrix<T>::cols() const {
	return vect[0].getEquation().size();
}
template<class T>
size_t Matrix<T>::rank() const {
	Matrix<T> mat{ ((cols() > rows()) ? transposed() : *this) };
	for (size_t i = 0; i < mat.cols(); ++i)
		for (size_t j = 0; j < mat.rows(); ++j) {
			if (i >= j)
				continue;
			mat[j] = mat[i] * mat[j][i] - mat[j] * mat[i][i];
		}

	size_t rank = 0;
	for (size_t i = 0; i < mat.rows(); ++i) {
		if (mat[i] == LinearEquation<T>(vector<T>(mat[i].size(), static_cast<T>(0))))
			continue;
		else
			++rank;
	}
	return rank;
}

//OPERATORS
template<class T>
LinearEquation<T>& Matrix<T>::operator[](size_t index) {
	return vect[index];
}
template<class T>
const LinearEquation<T>& Matrix<T>::operator[](size_t index) const {
	return vect[index];
}
template<class S, class F>
Matrix<F> operator*(const Matrix<F>& left, const S& right) {
	Matrix<F> m{ left };
	for (size_t i = 0; i < left.rows(); ++i)
		for (size_t j = 0; j < left.cols(); ++j)
			m[i][j] *= right;
	return m;
}
template<class S, class F>
Matrix<F> operator*(const S& left, const Matrix<F>& right){
	return right * left;
}
template<class T>
Matrix<T> operator+(const Matrix<T>& left, const Matrix<T>& right) {
	assert(left.rows() == right.rows() && left.cols() == right.cols() && "Matrices could not be added!"); 
	Matrix<T> m(vector<LinearEquation<T>>(left.rows(), LinearEquation<T>(left.rows())));
	for (size_t i = 0; i < left.rows(); ++i)
		m[i] = left[i] + right[i];
	return m;
}
template<class T>
Matrix<T> operator-(const Matrix<T>& left, const Matrix<T>& right) {
	return left + -right;
}
template<class T>
Matrix<T> operator*(const Matrix<T>& left, const Matrix<T>& right) {
	assert(left.cols() == right.rows() && "Matrices could not be multiplicated!");
	Matrix<T> m(vector<LinearEquation<T>>(left.rows(), LinearEquation<T>(right.cols())));
	for (size_t i = 0; i < left.rows(); ++i)
		for (size_t j = 0; j < right.cols(); ++j)
			for (size_t k = 0; k < right.rows(); ++k)
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
	for (size_t i = 0; i < temp.rows(); ++i)
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
ostream& operator<<(ostream& out, const Matrix<T>& m) {
	return m.print(out);
}