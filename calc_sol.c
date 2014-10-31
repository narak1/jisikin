#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fx(double x, double A)
{
	return tan(x) - x - A;
}

main(int argc, char **argv)
{
	int i;
	double A, epsilon;
	double xl, xr, yl, yr, x, y;

	if( argc == 1 ) {
		epsilon = 1e-14;
	}
	else {
		epsilon = strtod(argv[1], NULL);
	}
	printf("Input A : ");
	scanf("%lf", &A);
	
	// fx(-pi/2) -> -INF
	// fx(pi/2) -> INF
	// fx is continuous function so has a solution in [-pi/2 pi/2]

	xl = -M_PI_2;
	yl = fx(xl, A);
	xr = M_PI_2;
	yr = fx(xr, A);
	x = 0.0;
	y = fx(x, A);
	printf("x=%lf, y=%g\n", x, y);
	while( fabs(y) > epsilon ) {
		if( y < 0.0 ) {
			xl = x;
			yl = y;
		}
		else {
			xr = x;
			yr = y;
		}
		x = (xl + xr) / 2.0;
		y = fx(x, A);
		printf("x=%lf, y=%g\n", x, y);
	}
	
	printf("A=%lf, Solution is x=%.14lf\n", A, x);
}
