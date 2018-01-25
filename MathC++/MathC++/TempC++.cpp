#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{

}

/*class Fruit
{
private:
	string c_name;
	string c_color;
public:
	Fruit(string name, string color) :c_name{ name }, c_color{ color } {}
	string getName() const { return c_name; }
	string getColor() const { return c_color; }
};

class Apple:public Fruit
{
private:
	double c_fiber;
public:
	Apple(string name, string color, double fiber) :Fruit(name, color), c_fiber{ fiber } {}
	double getFiber() const { return c_fiber; }
	friend ostream& operator<<(ostream& out,const Apple& f)
	{
		out << "Apple(" << f.getName() << ", " << f.getColor() << ", " << f.getFiber()<<")";
		return out;
	}
};

class Banana :public Fruit
{
public:
	Banana(string name, string color) :Fruit(name, color) {}
	friend ostream& operator<<(ostream& out,const Banana& f)
	{
		out << "Apple(" << f.getName() << ", " << f.getColor() << ")";
		return out;
	}
};

int main()
{
	const Apple a("Red delicious", "red", 4.2);
	cout << a;

	const Banana b("Cavendish", "yellow");
	cout << b;

	return 0;
}*/