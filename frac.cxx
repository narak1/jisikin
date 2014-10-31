#include <iostream>
using namespace std;

// start of Fraction.h
class CFraction
{
	int m_num, m_denom;
public:
	CFraction() : m_num(0), m_denom(1) { ; };
	
	friend void store(int nNumer, int nDenom, CFraction &fr);
	friend void print(const CFraction& fr);
};
// end of Fraction.h

//#include "Fraction.h"

int GreatestComDev(int m, int n)
{
	int r = 1;
	if( m==0 || n==0 ) {
		return 1;
	}
	else {
		while(1)
		{
			r = n % m;
			if( r == 0 )
				break;
				
			n = m;
			m = r;
		}
		return m;
	}
}

void store(int nNumer, int nDenom, CFraction &fr)
{
	if( nDenom == 0 )
		return;
		
	int gcd = GreatestComDev(nNumer, nDenom);
	fr.m_num = nNumer / gcd;
	fr.m_denom = nDenom / gcd;
}

void print(const CFraction& fr)
{
	cout << fr.m_num << "/" << fr.m_denom;
}

void getData(int &n, int &m)
{
	cin >> n >> m;
}

int main()
{
	cout << "This program create a fraction." << endl;
	int nNumer=0, nDenom=0;
	
	cout << "Input numerator & denominator : ";
	getData(nNumer, nDenom);
	
	CFraction fr1;
	store(nNumer, nDenom, fr1);	// 저장
	cout << "fr1 contains: ";
	print(fr1);		// 화면출력
	
	cout << "\nThanks you for using fractions." << endl; 
}
