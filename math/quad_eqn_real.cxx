#include<iostream>
#include <cmath>
using namespace std;
class  Complex
{
private:
   double real;
   double imag;
public:

  Complex();
  Complex(double a,double b);
  ~Complex();

  double getReal();
  double getimag();
  Complex add(const Complex&c);
  void print() const;
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
double Complex::getReal()
{
 return (real);
}
double Complex::getimag()
{
 return (imag);
}
void Complex::print() const
{
 cout<<real<<"+"<<imag<<"i"<<endl;
}
ostream& operator<<(ostream& os, const Complex& c)
{
	c.print();
	return os;
}
//========== Equation ========

class Equation
{
	double coef[3];
	Complex root[2];
public:
	void inputCoef();
	double getCoef(int idx=0) const { return coef[idx]; };
	int solve();
	Complex& getRoot(int idx=0) { return root[idx]; };
};

void Equation::inputCoef()
{
	cout << "2차항의 계수: ";
	cin >> coef[2];
	cout << "1차항의 계수: ";
	cin >> coef[1];
	cout << "상수항의 계수: ";
	cin >> coef[0];
}

int Equation::solve()
{
	double d = coef[1] * coef[1] - 4 * coef[2] * coef[0];	// 판별식 
	if( d >= 0 ) {
		double t = (-coef[1] - std::sqrt(d)) / (2*coef[2]);	// 작은 근 
		root[0] = Complex(t, 0);
		t = (-coef[1] + std::sqrt(d)) / (2*coef[2]);		// 큰 근 
		root[1] = Complex(t, 0);
	}
	else {
		double p = -coef[1] / (2*coef[2]);		// -b/2a
		double q = sqrt(-d) / (2*coef[2]);		// sqrt(D)/2a
		root[0] = Complex(p, -q);				// -b-sqrt(D) / 2a
		root[1] = Complex(p, q);				// -b+sqrt(D) / 2a
	}
	return (int)d;		// d>0 : two real roots, d=0 : a multiple root, d<0 : two complex root
}

//====== main ==========

int main()
{
	Equation eqn;

	eqn.inputCoef();
	cout << "Equation: " << eqn.getCoef(2) << "x^2 + " << eqn.getCoef(1) << "x + " << eqn.getCoef() << endl;

	int flag = eqn.solve();
	if( flag > 0 ) {
		cout << "two real roots : " << eqn.getRoot().getReal() << ", " << eqn.getRoot(1).getReal() << endl;
	}
	else if( flag == 0 ) {
		cout << "a multiple root : " << eqn.getRoot().getReal() << endl;
	}
	else {
		cout << "two complex roots : " << endl;
		cout << eqn.getRoot() << eqn.getRoot(1) << endl;
	}
}

