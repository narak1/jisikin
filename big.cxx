#include <iostream>
#include <iomanip>
using namespace std;

class MyBig
{
	char *digit;
	int len;
	static const int Base = 100;	// 00 ~ 99, Packed BCD
public:
	MyBig() : len(1) { digit = new char[1]; digit[0] = 0; };
	MyBig(int num);
	MyBig(const MyBig& big);
	MyBig(const string str);
	~MyBig() { delete [] digit;	};
	
	MyBig& operator=(MyBig& b);

	void operator+=(const MyBig& b);			// a += b;
	void operator-=(const MyBig& b);
	void operator*=(const MyBig& b);
	void operator/=(const MyBig& b);
	void operator%=(const MyBig& b);
	
friend MyBig operator+(const MyBig& a, const MyBig& b);	// a + b

friend void big_add(const MyBig& a, const MyBig& b, MyBig& c);	// a + b => c

friend ostream& operator<<(ostream& os, MyBig& b);
//friend istream& operator>>(istrema& is, MyBig& b);
};

//------

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

MyBig operator+(const MyBig& a, const MyBig& b)
{
	MyBig c;
	big_add(a, b, c);
	return c;
}

void MyBig::operator+=(const MyBig& b)
{
	MyBig c(*this);
	big_add(c, b, *this);
}

ostream& operator<<(ostream& os, MyBig& b)
{
	os << int(b.digit[b.len-1]);
	for( int i=b.len-2 ; i>=0 ; i-- ) {
		os << setw(2) << setfill('0') << (int)b.digit[i];
	}
	
	return os;
}

//====== EOF MyBig Class Library ========

//====== Main Program ======
//#include "MyBig.h"

main()
{
	void test();
	
	//test();
	int num;
	cout << "Input num : ";
	cin >> num;
	
	MyBig a;
	string str;
	for( int i=1 ; i<=num ; i++ ) {
		cout << "Input big number " << i << " : ";
		cin >> str;
		MyBig b(str);
		a += b;
		cout << "Sum = " << a << endl;
	}
}

void test()
{
	int num1;
	cout << "Input a numbers : ";
	cin >> num1;
	
	MyBig a(num1);
	cout << "Big : " << a << endl;
	
	string str1;
	cout << "Input big number : ";
	cin >> str1;
	MyBig b(str1);
	cout << "Big : " << b << endl;
	
	MyBig c = a + b;
	cout << "a + b = " << c << endl;

	c += c;
	cout << "c + c = " << c << endl;
}
