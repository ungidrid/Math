#include "stdafx.h"
#include "Libraries\headers\LinearEquation.h"

int main()
{
	Complex c(3, 5), q(4,4);
	cout << "c + q == " << c + q << '\n';
	cout << "c * q == " << c * q << '\n';
	cout << "c - q == " << c - q << '\n';
	cout << "c / q == " << c / q << '\n';
	cout << "~c == " << c.conjugate() << '\n';
	cout << "|c|^2 == " << c.squaredAbs() << '\n';
	cout << ""
}