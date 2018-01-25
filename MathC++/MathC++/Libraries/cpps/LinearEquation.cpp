#include "..\headers\LinearEquation.h"

//CONSTRUCTORS
template<class T>
LinearEquation<T>::LinearEquation(int length) { 
	valArray.resize(length); 
}
template<class T>
LinearEquation<T>::LinearEquation(const vector<T>& vect) { 
	valArray = vect; 
}
template<class T>
LinearEquation<T>::LinearEquation(const initializer_list<T>& list) { 
	valArray = list; 
}

//METHODS
template<class T>
vector<T>& LinearEquation<T>::getEquation() {
	return valArray;
}
template<class T>
vector<T> LinearEquation<T>::getEquation() const{
	return valArray;
}
template<class T>
void LinearEquation<T>::printEquation() const{
	for (const auto &elem : valArray)
		cout << elem << " ";
}

//OPERATORS
template<class T>
LinearEquation<T> operator+(const LinearEquation<T>& left,const LinearEquation<T>& right){
	LinearEquation eq(left.getEquation().size());
	for (int i = 0; i < left.getEquation().size(); i++)
		eq[i] = left[i] + right[i];
	return eq;
}
template<class T>
LinearEquation<T> operator-(const LinearEquation<T>& left, const LinearEquation<T>& right) {
	return left + (-right); 
}
template<class T>
T& LinearEquation<T>::operator[](int index) {
	return valArray[index];
}
template<class T>
T LinearEquation<T>::operator[](int index) const {
	return valArray[index];
}
template<class T>
LinearEquation<T> LinearEquation<T>::operator+() const{ 
	return *this; 
}
template<class T>
LinearEquation<T> LinearEquation<T>::operator-() const{ 
	for (auto elem : valArray) elem = -elem;
	return *this; 
}
template<class T>
LinearEquation<T> operator*(const T& left, const LinearEquation<T>& right){
	LinearEquation<T> eq(right.getEquation().size());
	for (int i = 0; i < right.getEquation().size(); i++) { eq[i] = left * right[i]; }
	return eq;
}
template<class T>
bool operator==(const LinearEquation<T>& left, const LinearEquation<T>& right) {
	return left.valArray == right.valArray; 
}
template<class T>
bool operator!=(const LinearEquation<T>& left, const LinearEquation<T>& right) {
	return left.valArray != right.valArray; 
}