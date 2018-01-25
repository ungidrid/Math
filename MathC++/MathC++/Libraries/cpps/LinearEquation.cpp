#include "..\headers\LinearEquation.h"

//CONSTRUCTORS
LinearEquation::LinearEquation(size_t length):valArray(length) { }
LinearEquation::LinearEquation(const vector<Fraction>& vect):valArray(vect) { }
LinearEquation::LinearEquation(const initializer_list<Fraction>& list):valArray(list) { }

//METHODS
vector<Fraction>& LinearEquation::getEquation() {
	return valArray;
}
const vector<Fraction>& LinearEquation::getEquation() const{
	return valArray;
}
void LinearEquation::printEquation() const{
	for (const auto &elem : valArray)
		cout << elem << " ";
}

//OPERATORS
LinearEquation operator+(const LinearEquation& left,const LinearEquation& right){
	LinearEquation eq(left.getEquation().size());
	for (size_t i = 0; i < left.getEquation().size(); ++i)
		eq[i] = left[i] + right[i];
	return eq;
}
LinearEquation operator-(const LinearEquation& left, const LinearEquation& right) {
	return left + (-right); 
}

Fraction& LinearEquation::operator[](size_t index) {
	return valArray[index];
}
const Fraction& LinearEquation::operator[](size_t index) const {
	return valArray[index];
}

LinearEquation& LinearEquation::operator+(){ 
	return *this; 
}
const LinearEquation& LinearEquation::operator+() const {
	return *this;
}
LinearEquation& LinearEquation::operator-(){ 
	for (auto elem : valArray) 
		elem = -elem;
	return *this; 
}

LinearEquation operator*(const Fraction& left, const LinearEquation& right){
	LinearEquation eq(right.getEquation().size());

	for (size_t i = 0; i < right.getEquation().size(); ++i)
		eq[i] = left * right[i]; 
	return eq;
}
bool operator==(const LinearEquation& left, const LinearEquation& right) {
	return left.valArray == right.valArray; 
}
bool operator!=(const LinearEquation& left, const LinearEquation& right) {
	return !(left.valArray == right.valArray); 
}