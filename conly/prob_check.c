#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int i, j, len, n;
	char *p;
	
	if( argc == 1 ) {
		fprintf(stderr, "Usage: %s a   (a:integer)\n", argv[0]);
		return 0;
	}
	
	if( argv[1][0] == '-' ) {
		p = argv[1] + 1;
		while( *p ) {
			*p = (10 - (*p - '0')) % 10 + '0';	// 0->0, 1->9, ...
			++p;
		}
		p = argv[1] + 1;
	}
	else {
		p = argv[1];
	}
	len = strlen(p);
	
	for( i=0 ; i<10 ; i++ ) {
		n = 0;
		for( j=0 ; j<len ; j++ ) {
			if( p[j] == i+'0' ) {
				++n;
			}
		}
		
		if( n != 0 ) {
			printf("Prob(A=%d)=%d/%d,", i, n, len);
		}
	}
	puts("");
}

