#include <stdio.h>
#include <stdlib.h>

main(int argc, char **argv)
{
	int i;
	float r, m;
	
	if( argc == 1 ){
		printf("ratio=");
		scanf("%f", &r);
	}
	else {
		r = strtod(argv[1], NULL);
	}
	
	printf("r=%f\n", r);
	
	m = 0.0f;
	i=0;
	while( m < 0.99999f ){
		m += (1.0f - m) * r;
		printf("i=%d, m=%f\n", ++i, m);
	}
}

