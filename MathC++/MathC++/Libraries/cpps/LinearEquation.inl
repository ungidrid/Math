//CONSTRUCTORS
template<class T>
LinearEquation<T>::LinearEquation(size_t length) { valArray.resize(length); }
template<class T>
LinearEquation<T>::LinearEquation(const vector<T>& vect) :valArray{ vect } { }
template<class T>
LinearEquation<T>::LinearEquation(const initializer_list<T>& list) : valArray{ list } { }

//METHODS
template<class T>
vector<T>& LinearEquation<T>::getEquation() {
return valArray;
}
template<class T>
const vector<T>& LinearEquation<T>::getEquation() const {
return valArray;
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
LinearEquation<T> eq(left.valArray.size());
for (size_t i = 0; i < left.valArray.size(); ++i)
eq[i] = left[i] + right[i];
return eq;
}
template<class T>
LinearEquation<T> operator-(const LinearEquation<T>& left, const LinearEquation<T>& right) {
return left + (-right);
}
template<class T>
T& LinearEquation<T>::operator[](size_t index) {
return valArray[index];
}
template<class T>
const T& LinearEquation<T>::operator[](size_t index) const {
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
template<class F>
//redefinition from T to F makes no sense, but it isn't working in other way
LinearEquation<F> operator*(const F& left, const LinearEquation<F>& right) {
LinearEquation<T> eq(right.getEquation().size());
for (size_t i = 0; i < right.getEquation().size(); ++i)
eq[i] = left * right[i];
return eq;
}
template<class T>
bool operator==(const LinearEquation<T>& left, const LinearEquation<T>& right) {
return left.valArray == right.valArray;
}
template<class T>
bool operator!=(const LinearEquation<T>& left, const LinearEquation<T>& right) {
return !(left.valArray == right.valArray);
}
template<class T>
ostream& operator<<(ostream& out, const LinearEquation<T>& le) {
return le.print(out);
}