#include <stdio.h>
#include <math.h>

float f(int x)
{
	float fx[] = { 1/8.0f, 3/8.0f, 3/8.0f, 1/8.0f };
	return fx[x];	
}

main()
{
	int x[] = { 0, 1, 2, 3 };
	int i;
	float e_x, e_x2, var_x, sd_x;
	
	e_x = 0.0f;
	e_x2 = 0.0f;
	for( i=0 ; i<4 ; i++ ) {
		e_x += x[i] * f(x[i]);
		e_x2 += x[i] * x[i] * f(x[i]);
	}
	printf("E(X)=%f, E(X^2)=%f\n", e_x, e_x2);
	
	var_x = e_x2 - e_x * e_x;
	sd_x = sqrt(var_x);
	printf("Var(X)=%f, S.Dev(X)=%f\n", var_x, sd_x);
}
