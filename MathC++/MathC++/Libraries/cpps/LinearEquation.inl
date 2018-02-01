//CONSTRUCTORS
template<class T>
LinearEquation<T>::LinearEquation(size_t length) { valArray.resize(length); }
template<class T>
LinearEquation<T>::LinearEquation(const vector<T>& vect) :valArray{ vect } { }
template<class T>
LinearEquation<T>::LinearEquation(const initializer_list<T>& list) : valArray{ list } { }

//METHODS
template<class T>
size_t LinearEquation<T>::size() const{
	return valArray.size();
}
template<class T>
ostream& LinearEquation<T>::print(ostream& out) const {
	for (const auto &elem : valArray)
		out << elem << " ";
	return out;
}

//OPERATORS
template<class T>
LinearEquation<T> operator+(const LinearEquation<T>& left, const LinearEquation<T>& right) {
	if (left.size() != right.size())
		throw runtime_error ("Linear combinations with different lengths could not be added!");
	LinearEquation<T> eq(left.size());
	for (size_t i = 0; i < left.size(); ++i)
		eq[i] = left[i] + right[i];
	return eq;
}
template<class T>
LinearEquation<T> operator-(const LinearEquation<T>& left, const LinearEquation<T>& right) {
	return left + (-right);
}
template<class T>
T& LinearEquation<T>::operator[](size_t index) {
	if (!(index >= 0 && index < size()))
		throw runtime_error ("Index out of range!");
	return valArray[index];
}
template<class T>
const T& LinearEquation<T>::operator[](size_t index) const {
	if (!(index >= 0 && index < size()))
		throw runtime_error ("Index out of range!");
	return valArray[index];
}
template<class T>
LinearEquation<T> LinearEquation<T>::operator+() const {
	return *this;
}
template<class T>
LinearEquation<T> LinearEquation<T>::operator-() const {
	vector<T> temp{ valArray };
	for (auto& elem : temp)
		elem = -elem;
	return temp;
}
template<class S, class F>
LinearEquation<F> operator*(const S& left, const LinearEquation<F>& right) {
	LinearEquation<F> eq(right.size());
	for (size_t i = 0; i < right.size(); ++i)
		eq[i] = left * right[i];
	return eq;
}
template<class S, class F>
LinearEquation<F> operator*(const LinearEquation<F>& left, const S& right)
{
	return right * left;
}
template<class T>
bool operator==(const LinearEquation<T>& left, const LinearEquation<T>& right) {
	return left.valArray == right.valArray;
}
template<class T>
bool operator!=(const LinearEquation<T>& left, const LinearEquation<T>& right) {
	return !(left == right);
}
template<class T>
ostream& operator<<(ostream& out, const LinearEquation<T>& le) {
	return le.print(out);
}