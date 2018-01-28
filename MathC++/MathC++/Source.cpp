#include "Libraries\headers\Matrix.h"

int main()
{
	Matrix<Fraction> m{ {0,1,2},{1,3,0},{0,3,2} };
	cout << "m: " << m.rows() << "x" << m.cols() << '\n' << m << "Rank: " << m.rank() << '\n';
	system("PAUSE");
}