#include "Libraries\headers\Matrix.h"

int main()
{
	Matrix<Fraction> m{ {1,2,3},{2,3,4},{3,4,5} }, m2{ m };
	cout << m - m2;
	system("PAUSE");
}