#include <stdio.h>
#include <math.h>

// 1 : 8 : 23
//
char* bitstr32(float x)
{
	static char bit[32+4], *p;
	int i, *n;
	p = bit;
	n = (int *) &x;
	for( i=0 ; i<32 ; i++ ) {
		if( i==1 || i==9 ) {
			*p = ' ';
			++p;
		}
		*p = ( (*n) & 0x80000000 ) == 0 ? '0' : '1';
		*n << 1;
		++p;
	}
	*p = 0;
	return bit;
}

// 1 : 11 : 52
//
char* bitstr64(double x)
{
	static char bit[64+4], *p;
	int i, *n;
	p = bit;
	n = ((int *) &x) + 1;	// assume little endian
	for( i=0 ; i<64 ; i++ ) {
		if( i==1 || i==12 ) {
			*p = ' ';
			++p;
		}
		if( i==32 ) --n;
		*p = ( (*n) & 0x80000000 ) == 0 ? '0' : '1';
		*n <<= 1;
		++p;
	}
	*p = 0;
	return bit;
}

double mysin(double x)
{
	int i, j;
	long double val, sum = 0.0;
	for( i=1 ; ; i+=2 ) {
		val = 1.0;
		for( j=1 ; j<=i ; j++ ) {
			val *= x / j;
		}
		if( val == 0.0 ) {	//
			break;
		}
		if( i % 4 == 1 )
			sum += val;
		else
			sum -= val;
	}
	return sum;
}

int main()
{
	int i, j;
	double x, y, a;

	puts("find max x the most close 1.");
	x = 1.0;
	a = 1.0;
	for( i=0 ; i<54 ; i++ ) {
		a /= 2;
		y = x - a;
		printf("%2d: %20.18lf ; %s\n", i, y, bitstr64(y));
	}

	puts("find square over-flow close 1.");
	a = 1.0;
	for( i=0 ; i<24 ; i++ ) {
		a /= 2;
	}
	for( j=0 ; j<5 ; j++ ) {
		a /= 2;
		y = (x - a) * (x - a);
		printf("%2d: %20.18lf ; %s\n", i+j, y, bitstr64(y));
	}

	puts("find sin(x), cos(x)=+-sqrt(1-sin^2(x)).");
	a = 1.0;
	for( i=0 ; i<26 ; i++ ) {
		a /= 2;
	}
	y = x - a;
	printf(" sin(x)  = %20.18lf ; %s\n", y, bitstr64(y));
	y *= y;
	printf("sin^2(x) = %20.18lf ; %s\n", y, bitstr64(y));

	puts("find sin(x), cos(x)=sin(pi/2 - x).");
	a = 1.0;
	for( i=0 ; i<53 ; i++ ) {
		a /= 2;
	}
	y = x - a;
	printf(" sin(x)  = %20.18lf ; %s\n", y, bitstr64(y));

	puts("my_sin() function verify.");
	printf(" sin(M_PI/2)  = %20.18lf\n", sin(M_PI_2));
	printf("mysin(M_PI/2) = %20.18lf\n", mysin(M_PI_2));

	x = M_PI_2;
	for( i=0 ; i<27 ; i++ ) {
		a *= 2;
		y = x - a;
		printf("x=%20.18lf, sin(x)=%20.18lf, mysin(x)=%20.18lf\n", y, sin(y), mysin(y));
	}

	printf("truncation error x = %20.18lf ; %s\n", y, bitstr64(y));

	while( a != 0 ) {
		a /= 2;
//		printf("a = %20.18lf ; %s\n", a, bitstr64(a));
		x = y + a;
		if( mysin(x) < 1.0 ) {
			y = x;
		}
	}
	printf("  overflow error x = %20.18lf ; %s\n", x, bitstr64(x));
	printf("sin(x)=%20.18lf, mysin(x)=%20.18lf\n", sin(x), mysin(x));
}
