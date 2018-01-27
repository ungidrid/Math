#include "Libraries\headers\Matrix.h"

int main()
{
	Matrix<double> m{ {1,2,4},{2,3,4},{3,4,5} }, m2{ m };
	cout << 2*m << m.inversed() << m.transposed() << m.power(0);
	system("PAUSE");
}