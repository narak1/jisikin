#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int main()
{
	int i, n;
	float val[MAX];
	float sum, mean, var, stdev;
	
	srand(time(NULL));
	
	n = 1000;
	for( i=0 ; i<n ; i++ ) {
		val[i] = (rand() % 101) / 10.0f + 10.0f;	// make 20.0 ~ 30.0
	}
	
	// calc mean
	sum = 0.0f;
	for( i=0 ; i<n ; i++ ) {
		sum += val[i];
	}
	mean = sum / n;
	printf("평균 : %.5f\n", mean);
	
	// calc stdev
	var = 0.0f;
	for( i=0 ; i<n ; i++ ) {
		var += (val[i] - mean) * (val[i] - mean);
	}
	var /= n;
	printf("분산 : %.5f\n", var);
//	stdev = sqrt(var);
//	printf("표준편차 : %.5f\n", mean);	
}
