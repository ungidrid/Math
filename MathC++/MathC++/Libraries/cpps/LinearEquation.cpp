#include "..\headers\LinearEquation.h"

//CONSTRUCTORS
LinearEquation::LinearEquation(int length) { 
	valArray.resize(length); 
}
LinearEquation::LinearEquation(const vector<Fraction>& vect) { 
	valArray = vect; 
}
LinearEquation::LinearEquation(const initializer_list<Fraction>& list) { 
	valArray = list; 
}

//METHODS
vector<Fraction>& LinearEquation::getEquation() {
	return valArray;
}
vector<Fraction> LinearEquation::getEquation() const{
	return valArray;
}
void LinearEquation::printEquation() const{
	for (const auto &elem : valArray)
		cout << elem << " ";
}

//OPERATORS
LinearEquation operator+(const LinearEquation& left,const LinearEquation& right){
	LinearEquation eq(left.getEquation().size());
	for (int i = 0; i < left.getEquation().size(); i++)
		eq[i] = left[i] + right[i];
	return eq;
}
LinearEquation operator-(const LinearEquation& left, const LinearEquation& right) {
	return left + (-right); 
}
Fraction& LinearEquation::operator[](int index) {
	return valArray[index];
}

Fraction LinearEquation::operator[](int index) const {
	return valArray[index];
}

LinearEquation LinearEquation::operator+() const{ 
	return *this; 
}
LinearEquation LinearEquation::operator-() const{ 
	for (auto elem : valArray) elem = -elem;
	return *this; 
}

LinearEquation operator*(const Fraction& left, const LinearEquation& right){
	LinearEquation eq(right.getEquation().size());
	for (int i = 0; i < right.getEquation().size(); i++) { eq[i] = left * right[i]; }
	return eq;
}
bool operator==(const LinearEquation& left, const LinearEquation& right) {
	return left.valArray == right.valArray; 
}
bool operator!=(const LinearEquation& left, const LinearEquation& right) {
	return left.valArray != right.valArray; 
}