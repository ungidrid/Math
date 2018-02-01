#include "Libraries\headers\Matrix.h"

int main()
{
	Matrix<Fraction> m{ {1,2},{3,6} };
	try 
	{
		cout << m.inversed();
	}
	catch (exception& exception)
	{
		cout << "Error occured: " << exception.what() << '\n';
	}
	system("PAUSE");
}