#include <iostream>
#include <cmath>
using namespace std;

class  Complex
{
   double real;
   double imag;
public:
	Complex();
	Complex(double a,double b);
	~Complex();

	double getReal() const { return real; };
	double getimag() const { return imag; };
	bool is_zero() const { return real==0 && imag==0; };
	bool is_one() const { return real==1 && imag==0; };

	Complex operator-() const;	// negative

	Complex add(const Complex&c);
	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;

	friend Complex operator*(const double a, const Complex& c);

	double abs() const { return std::sqrt(real*real + imag*imag); };
	double amp() const { return atan2(imag, real); };
	Complex sqrt(Complex* r2=NULL) const;

	void pirnt();
	friend ostream& operator<<(ostream& os, const Complex& c);
};

Complex::Complex()
{
 real=0;
 imag=0;
}
Complex::Complex(double a,double b)
{
 real=a;
 imag=b;
}
Complex::~Complex()
{
}
void Complex::pirnt()
{
 cout<<real<<"+"<<imag<<"i"<<endl;
}

Complex operator*(double a, const Complex& c)
{
	Complex t(c);
	t.real *= a;
	t.imag *= a;
	return t;
}

Complex Complex::operator*(const Complex& c) const
{
	Complex t;
	t.real = this->real * c.real - this->imag * c.imag;
	t.imag = this->real * c.imag + this->imag * c.real;
	return t;
}

Complex Complex::operator+(const Complex& c) const
{
	Complex t(*this);
	t.real += c.real;
	t.imag += c.imag;
	return t;
}

Complex Complex::operator-(const Complex& c) const
{
	Complex t(*this);
	t.real -= c.real;
	t.imag -= c.imag;
	return t;
}

Complex Complex::operator-() const
{
	Complex t;
	t.real = -this->real;
	t.imag = -this->imag;
	return t;
}

Complex Complex::operator/(const Complex& c) const
{
	Complex t;
	double tmp = c.real * c.real + c.imag * c.imag;
	t.real = (this->real * c.real + this->imag * c.imag) / tmp;
	t.imag = (-this->real * c.imag + this->imag * c.real) / tmp;
	return t;
}

Complex Complex::sqrt(Complex* r2) const
{
	double r = this->abs();
	double a = this->amp();
	Complex t(std::sqrt(r) * cos(a/2), std::sqrt(r) * sin(a/2));
	if( r2 != NULL ) *r2 = -t;
	return t;
}

ostream& operator<<(ostream& os, const Complex& c)
{
	if( c.real != 0 ) os << c.real;
	else if( c.imag == 0 ) os << "0";

	if( c.imag != 0 ) {
		if( c.imag > 0 ) os << "+";
		if( c.imag == 1 )	;
		else if( c.imag == -1 ) os << "-";
		else os << c.imag;
		os << "i";
	}
	return os;
}

//========== Equation ========

class QuadEqn
{
	Complex a,b,c;
	Complex r[2];
public:
	void Set(const Complex& a, const Complex& b, const Complex& c);
	void Solve(Complex* r1=NULL, Complex* r2=NULL);
	Complex& Get(int idx=0) { return r[idx]; };
	bool Verify(int idx=0);
	friend ostream& operator<<(ostream& os, const QuadEqn& eqn);
};

void QuadEqn::Set(const Complex& a, const Complex& b, const Complex& c)
{
	this->a = a, this->b = b, this->c = c;
}

void QuadEqn::Solve(Complex* r1, Complex* r2)
{
	Complex d = this->b * this->b - 4 * this->a * this->c;
	Complex t = d.sqrt();

	r[0] = (-this->b - t) / (2*a);
	r[1] = (-this->b + t) / (2*a);

	if( r1 != NULL ) *r1 = r[0];
	if( r2 != NULL ) *r2 = r[1];
}

bool QuadEqn::Verify(int idx)
{
	Complex t = a * r[idx] * r[idx] + b * r[idx] + c;
	return (fabs(t.getReal()) < 1e-10) && (fabs(t.getimag()) < 1e-10);
}

ostream& operator<<(ostream& os, const QuadEqn& eqn)
{
	if( ! eqn.a.is_zero() ) {
		if( ! eqn.a.is_one() )
			os << "(" << eqn.a << ") ";
		os << "z^2 + ";
	}
	if( ! eqn.b.is_zero() ) {
		if( ! eqn.b.is_one() ) {
			os << "(" << eqn.b << ") ";
		}
		os << "z + ";
	}
	if( ! eqn.c.is_zero() ) {
		os << "(" << eqn.c << ") ";
	}
	os << "= 0";
	return os;
}

//====== main ==========

int main()
{
	double real, img;
	cout << "Input 2nd order term's complex coefficient : ";
	cin >> real >> img;
	Complex a(real, img);
	cout << "Input 1st order term's complex coefficient : ";
	cin >> real >> img;
	Complex b(real, img);
	cout << "Input constant term's complex value : ";
	cin >> real >> img;
	Complex c(real, img);

	QuadEqn eq1;
	eq1.Set(a, b, c);
	cout << "Equation: " << eq1 << endl;

	eq1.Solve();
	cout << "Solution: z1=" << eq1.Get() << ", z2=" << eq1.Get(1) << endl;
	cout << "Verify: " << eq1.Verify() << ", " << eq1.Verify(1) << endl;
}
