#include "Libraries\headers\Matrix.h"

int main()
{
	Matrix<double> m1{ {1,2,4},{2,3,4},{3,4,5} }, m2{ {1,2,5},{2,2,1},{1,5,3} };
	LinearEquation<Fraction> le1{ Fraction(1,2),2,3 }, le2{2,5,Fraction(1,4)};
	cout << 2 * m1 << m1 * 2 << m1.inversed() << m1.transposed() << m1.power(0) << m1.rank();
	system("PAUSE");
}