#include <stdio.h>

#define BASE 5

int full_add(int n1, int n2, int *c)
{
	int m;
	m = n1 + n2 + c[0];		// c[0] e.q. (*c)
	*c = m / BASE;
	return m % BASE;
}

int half_add(int n1, int n2)
{
	return (n1 + n2) % BASE;
}

int full_sub(int n1, int n2, int *b)
{
	int m;
	m = n1 - n2 - (*b);
	if( m < 0 ) {
		*b = 1;
		m += BASE;
	}
	else {
		*b = 0;
	}
	return m;
}

int half_sub(int n1, int n2)
{
	return (n1 - n2 + BASE) % BASE;
}

int main()
{
	int m[4], n[1], r[5];	// 4 x 1 MUX  => max 5 digit
	int i, j;
	int carry;

	puts("4 X 1 MUX Test");
	printf("Input 4 digit with space (base %d) : ", BASE);
	for( i=3 ; i>=0 ; i-- ) {
		scanf("%d", &m[i]);		// Input Little Endian
	}
	printf("Input 1 digit (base %d) : ", BASE);
	scanf("%d", &n[0]);

	for( i=0 ; i<5 ; i++ ) {	// initialize
		r[i] = 0;
	}
	while( n[0] ) {
		carry = 0;	// initial
		for( i=0 ; i<4 ; i++ ) {
			r[i] = full_add(r[i], m[i], &carry);
		}
		r[i] = half_add(r[i], carry);	// half_add()
		
		n[0] = half_sub(n[0], 1);		// half_sub()
	}
	printf("Result: ");
	for( i=4 ; i>=0 ; i-- ) {	// Print Little Endian
		printf("%d ", r[i]);
	}
	puts("");
}
