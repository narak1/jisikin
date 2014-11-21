#include <stdio.h>

main()
{
	int a[10000];
	unsigned long long b;
	int i, len;
	
	unsigned long long r;
	
	len = 5000;
	
	srand(time(NULL));
	for( i=0 ; i<len ; i++ ) {
		a[i] = rand() % 10;
	}
	b = rand();
	b *= rand();
	b *= rand();
	b = 10000000000000000UL;
	
	// print
	printf("a=");
	for( i=0 ; i<len ; i++ ) {
		printf("%d", a[i]);
	}
	putchar('\n');
	printf("b=%llu\n", b);
	
	// calc mod
	r = a[0];
	for( i=1 ; i<len ; i++ ) {
		r *= 10;
		r += a[i];
		r %= b;
	}
	printf("a%%b=%llu\n", r);
}
