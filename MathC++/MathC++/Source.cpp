#include "Libraries\headers\Matrix.h"

int main()
{
	Matrix<Fraction> m{ {0,2,3},{1,2,1},{0,3,2} };
	cout << m.rank() << m.determinant();
	system("PAUSE");
}