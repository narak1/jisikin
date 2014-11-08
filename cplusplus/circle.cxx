#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius=0) { this->radius = radius; };
	void show() const { cout << "radius = " << radius << " 인 원" << endl; };
	friend Circle& operator++( Circle& );		// Prefix increment
	friend Circle operator++( Circle&, int );	// Postfix increment
};

Circle& operator++(Circle& c)
{
	c.radius++;
	return c;
}

Circle operator++(Circle& c, int)
{
	Circle t;	// for return
	t = c;
	c.radius++;
	return t;
}

int main()
{
	cout << "Date : 2014/11/03\n학번 : ______ , 이름 : ______\n";
	
	Circle a(5), b(4);
	++a;	// increase radius
	b = a++;	// increase radius
	a.show();
	b.show(); 
}
