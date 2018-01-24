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

vector<Fraction>& LinearEquation::getEquation() { 
	return valArray; 
}
void LinearEquation::printEquation() const{
	for (const auto &elem : valArray)
		cout << elem << " ";
}

LinearEquation operator-(LinearEquation left, LinearEquation right){
	LinearEquation eq(left.getEquation().size());
	for (int i = 0; i < left.getEquation().size(); i++)
		eq[i] = left[i] - right[i];
	return eq;
}
LinearEquation operator+(LinearEquation left, LinearEquation right) { 
	return left - (-right); 
}
Fraction& LinearEquation::operator[](int index) {
	return valArray[index];
}

LinearEquation& LinearEquation::operator+() { 
	return *this; 
}
LinearEquation& LinearEquation::operator-() { 
	for (auto &elem : valArray) elem = -elem;
	return *this; 
}

LinearEquation operator*(Fraction left, LinearEquation right){
	LinearEquation eq(right.getEquation().size());
	for (int i = 0; i < right.getEquation().size(); i++) { eq[i] = left * right[i]; }
	return eq;
}
bool operator==(LinearEquation left, LinearEquation right) { 
	return left.valArray == right.valArray; 
}
bool operator!=(LinearEquation left, LinearEquation right) { 
	return left.valArray != right.valArray; 
}