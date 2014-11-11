#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITERATION 50000
#define SEED 23
#define MAX_RV 4.0
#define INTERVAL 100

float Uniform2();

void main()
{
	int i, j;
	float random_variable;
	float base, delta, tmp, pdf;
	int pd[INTERVAL];
	
	srand(time(NULL));

	base = -MAX_RV / 2;
	delta = MAX_RV / INTERVAL;
	for( i=0 ; i<INTERVAL ; i++ ) {
		pd[i] = 0;
	}

	for(i=0;i<ITERATION;i++){
		random_variable = MAX_RV*Uniform2();
	//	printf("%f \n",random_variable);
		for( j=0 ; j<INTERVAL ; j++ ) {
			if( random_variable < ((j+1)*delta + base) ) {
				pd[j]++;
				break;
			}
		}
	}
	
	for( i=0 ; i<INTERVAL ; i++ ) {
		tmp = i * delta + base;
		pdf = pd[i] / (float)ITERATION;
		printf("%5.2f ~ %5.2f : %8.6f\n", tmp, tmp+delta, pdf);
	}
}

float Uniform2()
{
	float rv;
	rv = rand() /(float)RAND_MAX - 0.5;
	return rv;
}

