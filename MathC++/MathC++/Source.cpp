#include "stdafx.h"
#include "Libraries\headers\LinearEquation.h"
#include "Libraries\cpps\LinearEquation.cpp"

int main()
{
	LinearEquation<Fraction> LE{ Fraction(1,2),Fraction(2,3),3 };
	(3*LE).printEquation();
	system("PAUSE");
}