#pragma once
#include <vector>
#include "Complex.h"

class LinearEquation{
protected:
	vector<Fraction> valArray;
public:
	LinearEquation(size_t);
	LinearEquation(const vector<Fraction>&);
	LinearEquation(const initializer_list<Fraction>&);

	vector<Fraction>& getEquation();
	const vector<Fraction>& getEquation() const;
	void printEquation() const;	//REDO

	const LinearEquation& operator+() const;
	LinearEquation& operator+();
	LinearEquation& operator-();//Ѕлет, в тебе в FRACTION унарний м≥нус створюЇ новий об'Їкт ≥ повертаЇ його, а тут той же унарний м≥нус в тому ж контекст≥ м≥н€Ї сам об'Їкт. ќприд≥лис€, блет. якщо в≥н м≥н€тиме об'Їкт, то його не можна зробити const 
	Fraction& operator[](size_t index); 
	const Fraction& operator[](size_t index) const; 

	friend LinearEquation operator-(const LinearEquation&,const LinearEquation&);
	friend LinearEquation operator+(const LinearEquation&,const LinearEquation&);
	friend bool operator==(const LinearEquation&, const LinearEquation&);
	friend bool operator!=(const LinearEquation&, const LinearEquation&);
	friend LinearEquation operator*(const Fraction&,const LinearEquation&);
	//operator<< could be overloaded too by use of "printEquation" method
};
