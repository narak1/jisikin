//====== MyBig Class Header ========

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

class MyBig
{
public:
	enum SignValue { Plus, Minus };

protected:

	SignValue sign;
	char *digit;
	int len;
	static const int Base = 100;	// 00 ~ 99, Packed BCD

friend int abs_cmp(const MyBig& a, const MyBig& b);				// - / 0 / +
friend void big_add(const MyBig& a, const MyBig& b, MyBig& c);	// a + b => c
friend void big_sub(const MyBig& a, const MyBig& b, MyBig& c);	// a - b => c

public:
	MyBig() : sign(Plus), len(1) { digit = new char[1]; digit[0] = 0; };
	MyBig(int num);
	MyBig(const MyBig& big);
	MyBig(const string str);
	~MyBig() { delete [] digit;	};
	
	MyBig& operator=(MyBig& b);

	void make_random_value(int len);

	void make_plus() { this->sign = Plus; };
	void make_minus() { this->sign = Minus; };

	SignValue get_sign() const { return this->sign; };
	MyBig abs() const { MyBig t(*this); t.make_plus(); return t; };
	
	void operator+=(const MyBig& b);			// a += b;
	void operator-=(const MyBig& b);
	void operator*=(const MyBig& b);
	void operator/=(const MyBig& b);
	void operator%=(const MyBig& b);
	
//friend MyBig operator+(const MyBig& a, const MyBig& b);	// a + b
//friend MyBig operator-(const MyBig& a, const MyBig& b);	// a - b

friend ostream& operator<<(ostream& os, MyBig& b);
//friend istream& operator>>(istrema& is, MyBig& b);
};

//====== Main Program ======
//#include "MyBig.h"

main()
{
	void test();
	srand(time(NULL));
	test();
}

void test()
{
	int r = rand() % 3 + 35;
	MyBig a, b, c, d;

	a.make_random_value(r);
	cout << "a = " << a << endl;

	r = rand() % 3 + 35;
	b.make_random_value(r);
	cout << "b = " << b << endl;

	// c = a + b;
	c = a;
	c += b;
	cout << "c = " << c << endl;

	d = a;
	d -= b;
	cout << "d = " << d << endl;
}

//====== SOF MyBig Class Library ========

inline int get_sign(int n) { return n >= 0 ? MyBig::Plus : MyBig::Minus; }

MyBig::MyBig(int num)
{
	if( num == 0 ) {
		this->len = 1;
		this->digit = new char[1];
		this->digit[0] = 0;
		return;
	}

	this->len = 5;
	this->digit = new char[5];	// int max is 10 digits
	for( int i=0 ; i<5 ; i++ ) {
		this->digit[i] = num % Base;
		num /= Base;
		if( num == 0 ) {
			this->len = i + 1;
			break;
		}
	}
}

MyBig::MyBig(const MyBig& b)
{
	this->len = b.len;
	this->digit = new char[b.len];
	for( int i=0 ; i<b.len ; i++ ) {
		this->digit[i] = b.digit[i];
	}
}

MyBig::MyBig(const string str)
{
	int len = str.length();
	if( len == 0 ) {
		this->len = 1;
		this->digit = new char[1];
		this->digit[0] = 0;
		return;
	}

	const char *ptr = str.c_str();
	while( ! isdigit(*ptr) ) {
		++ptr;
		--len;
	}

	if( len == 0 ) {
		this->len = 1;
		this->digit = new char[1];
		this->digit[0] = 0;
		return;
	}

	this->len = (len + 1) / 2;
	char *tmp = new char[this->len];

	int i = 0;
	int j = len % 2;
	if( j ) {		// odd string lenght
		tmp[0] = *ptr - '0';
		++i;
	}
	for( ; i<this->len ; i++,j+=2 ) {
		tmp[i] = (ptr[j] - '0') * 10 + (ptr[j+1] - '0');		
	}
	
	// make little endian
	this->digit = new char[this->len];
	for( i=0 ; i<this->len ; i++ ) {
		this->digit[i] = tmp[this->len-1-i];
	}
	
	delete [] tmp;
}

void MyBig::make_random_value(int len)
{
	if( len <= 0 ) return;
		
	this->sign = rand() % 2 ? MyBig::Plus : MyBig::Minus;
	delete [] this->digit;
	this->digit = new char [len];
	this->len = len;
	for( int i=0 ; i<len-1 ; i++ ) {
		this->digit[i] = rand() % 100;		// 0 ~ 99
	}
	this->digit[len-1] = rand() % 99 + 1;	// 1 ~ 99
}

MyBig& MyBig::operator=(MyBig& b)
{
	delete [] this->digit;
	this->sign = b.sign;
	this->len = b.len;
	this->digit = new char [b.len];
	memcpy(this->digit, b.digit, b.len);
}

int abs_cmp(const MyBig& a, const MyBig& b)
{
	int ret;

	if( a.len == b.len ) {
		for( int i=a.len-1 ; i>=0 ; i-- ) {
			ret = a.digit[i] - b.digit[i];
			if( ret != 0 )
				break;
		}
	}
	else if( a.len > b.len ) {
		ret = 1;
	}
	else {
		ret = -1;
	}
	
	return ret;
}

void big_add(const MyBig& a, const MyBig& b, MyBig& c)
{
	delete [] c.digit;
	
	int len = a.len > b.len ? a.len : b.len;
	char *tmp = new char[len];
	
	int i, num, carry = 0;
	for( i=0 ; i<len ; i++ ) {
		num = carry;
		if( i < a.len ) {
			num += a.digit[i];
		}
		if( i < b.len ) {
			num += b.digit[i];
		}
		tmp[i] = num % MyBig::Base;
		carry = num < MyBig::Base ? 0 : 1;
	}
	
	if( carry == 0 ) {
		c.len = len;
		c.digit = tmp;
	}
	else {
		c.len = len + 1;
		c.digit = new char[c.len];
		for( int i=0 ; i<len ; i++ ) {
			c.digit[i] = tmp[i];
		}
		c.digit[len] = 1;	// carry value
		
		delete [] tmp;
	}	
}

void big_sub(const MyBig& a, const MyBig& b, MyBig& c)
{
	delete [] c.digit;
	
	int len = a.len;
	char *tmp = new char[len];
	
	int i, num, barrow = 0;
	for( i=0 ; i<len ; i++ ) {
		num = barrow;
		if( i < a.len ) {
			num += a.digit[i];
		}
		if( i < b.len ) {
			num -= b.digit[i];
		}
		if( num < 0 ) {
			barrow = -1;
			tmp[i] = num + MyBig::Base;
		}
		else {
			barrow = 0;
			tmp[i] = num;
		}
	}

	c.len = len;
	c.digit = tmp;
	
	// truncation pre zeros
	for( int i=len-1 ; i>=0 ; i-- ) {
		if( tmp[i] ) {
			c.len = i + 1;
			break;
		}
	}
}

MyBig operator+(const MyBig& a, const MyBig& b)
{
	MyBig c;
	big_add(a, b, c);
	return c;
}

void MyBig::operator+=(const MyBig& b)
{
	MyBig c(*this);

	if( this->sign == b.sign ) {
		big_add(c, b, *this);
	}
	else {
		// who is more big?
		if( abs_cmp(*this, b) >= 0 ) {
			big_sub(c, b, *this);			
		}
		else {
			this->sign = b.sign;
			big_sub(b, c, *this);						
		}
	}
}

void MyBig::operator-=(const MyBig& b)
{
	MyBig c(*this);

	if( this->sign != b.sign ) {
		big_add(c, b, *this);
	}
	else {
		// who is more big?
		if( abs_cmp(*this, b) >= 0 ) {
			big_sub(c, b, *this);			
		}
		else {
			this->sign = b.sign == MyBig::Plus ? MyBig::Minus : MyBig::Plus;
			big_sub(b, c, *this);						
		}
	}
}

ostream& operator<<(ostream& os, MyBig& b)
{
	if( b.sign == MyBig::Minus ) {
		os << "-";
	}
	os << int(b.digit[b.len-1]);
	for( int i=b.len-2 ; i>=0 ; i-- ) {
		os << setw(2) << setfill('0') << (int)b.digit[i];
	}
	
	return os;
}

//====== EOF MyBig Class Library ========

