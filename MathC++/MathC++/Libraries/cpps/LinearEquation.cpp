#include "..\headers\LinearEquation.h"

//CONSTRUCTORS
LinearEquation::LinearEquation(size_t length) { valArray.resize(length); }
LinearEquation::LinearEquation(const vector<Fraction>& vect):valArray{vect} { }
LinearEquation::LinearEquation(const initializer_list<Fraction>& list):valArray{list} { }

//METHODS
vector<Fraction>& LinearEquation::getEquation() {
	return valArray;
}
const vector<Fraction>& LinearEquation::getEquation() const{
	return valArray;
}
ostream& LinearEquation::print(ostream& out) const{
	for (const auto &elem : valArray)
		out << elem <<" ";
	return out;
}

//OPERATORS
LinearEquation operator+(const LinearEquation& left,const LinearEquation& right){
	LinearEquation eq(left.valArray.size());
	for (size_t i = 0; i < left.valArray.size(); ++i)
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
LinearEquation LinearEquation::operator+() const {
	return *this;
}
LinearEquation LinearEquation::operator-() const {
	vector<Fraction> temp(valArray);
	for (auto& elem : temp) 
		elem = -elem;
	return temp; 
}
LinearEquation operator*(const Fraction& left, const LinearEquation& right){
	LinearEquation eq(right.getEquation().size());
	for (size_t i = 0; i < right.getEquation().size(); ++i)
		eq[i] = left * right[i]; 
	return eq;
}

LinearEquation operator*(const LinearEquation& right, const Fraction& left) {
	LinearEquation eq(right.getEquation().size());
	for (size_t i = 0; i < right.getEquation().size(); ++i)
		eq[i] = left * right[i];
	return eq;
}
bool operator==(const LinearEquation& left, const LinearEquation& right) {
	return left.valArray == right.valArray; 
}
bool operator==(const LinearEquation& l, int a) {
	for (size_t i = 0; i < l.getEquation().size(); ++i) {
		if (l[i] != a)
			return false;
	}
	return true;
}
bool operator!=(const LinearEquation& left, const LinearEquation& right) {
	return !(left.valArray == right.valArray); 
}
ostream& operator<<(ostream& out, const LinearEquation& le){
	return le.print(out);
}