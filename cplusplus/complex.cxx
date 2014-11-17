#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class Complex
{
	double real, image;
public:
	Complex(double r=0, double i=0) : real(r), image(i) { ; };
	Complex(const Complex& c) : real(c.real), image(c.image) { ; };
	double get_real() { return this->real; };
	double get_image() { return this->image; };
	void set_value(double r, double i=0) { this->real = r; this->image = i; };
	void Print();
	
	Complex& operator=(const Complex& c) { real=c.real; image=c.image; return *this; }
	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
};

void Complex::Print()
{
	if( this->real != 0.0 ) {
		cout << fixed << setprecision(1) << this->real;
		if( this->image != 0.0 ) {
			cout << (this->image > 0.0 ? " + " : " - ");
			cout << fixed << setprecision(1) << fabs(this->image) << "i";
		}
	}
	else {
		cout << fixed << setprecision(1) << this->image;
		if( this->image != 0.0 ) {
			cout << "i";
		}
	}
}

Complex Complex::operator+(const Complex& c) const
{
	Complex z;
	z.real = this->real + c.real;
	z.image = this->image + c.image;
	return z;
}

Complex Complex::operator-(const Complex& c) const
{
	Complex z;
	z.real = this->real - c.real;
	z.image = this->image - c.image;
	return z;
}

//========== Main ======

main()
{
	srand(time(NULL));
	double a = (rand() % 2001 - 1000) / 100.0;
	double b = (rand() % 2001 - 1000) / 100.0;
	Complex c1(a, b);
	Complex c2(a, -b);
	Complex c3 = c1 + c2;
	Complex c4;
	c4 = c1 - c2;
	
	cout << "C1   = "; c1.Print(); cout << endl;
	cout << "C2   = "; c2.Print(); cout << endl;
	cout << "C1+C2= "; c3.Print(); cout << endl;
	cout << "C1-C2= "; c4.Print(); cout << endl;
}
