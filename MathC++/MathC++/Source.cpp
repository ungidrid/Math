#include "Libraries\headers\Matrix.h"

int main()
{
	Matrix<Complex> m{ {Complex(2,1),Complex(1)},{Complex(2,0), Complex(2)} } , m2{ m };
	cout << m << " " << m.determinant();
	system("PAUSE");
}