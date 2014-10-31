#include <stdio.h>

#define MAXNUM 1000000000

void put_num(int n)
{
	int q, d = MAXNUM;
	do {
		q = n / d;
		if( q > 0 ) {
			putchar(q % 10 + '0');
		}
		d /= 10;
	} while( d );
}

main()
{
	int m[2][2];
	int i, j;
	srand(time(NULL));
	for(i=0 ; i<2 ; i++ ) {
		for(j=0 ; j<2 ; j++ ) {
			m[i][j] = rand();
		}
	}
	
	for(i=0 ; i<2 ; i++ ) {
		for(j=0 ; j<2 ; j++ ) {
			put_num(m[i][j]);
			putchar('\t');
		}
		putchar('\n');
	}
	
	// 검증 
	puts("검증"); 
	for(i=0 ; i<2 ; i++ ) {
		for(j=0 ; j<2 ; j++ ) {
			printf("%d\t", m[i][j]);
		}
		putchar('\n');
	}

}
