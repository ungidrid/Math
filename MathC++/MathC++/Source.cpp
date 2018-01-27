#include "Libraries\headers\Matrix.h"

int main()
{
	Matrix<double> m{ {1,2,4},{2,3,4},{3,4,5} }, m2{ m };
	LinearEquation<Fraction> le{ Fraction(1,2),2,3 };
	cout << 3 * le;
	cout << 2*m << m * 2 << m.inversed() << m.transposed() << m.power(0) << m.rank();
	system("PAUSE");
}