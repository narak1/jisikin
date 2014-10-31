#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSEC 10000

double a = 1.0;		// coefficient
double b = -5.0 * M_SQRT2;
double c = 8.0;

double func_2order(double x)
{
	double y;
	y = a*x*x + b*x + c;
	return y;
}

main(int argc, char **argv)
{
	int i;
	double lx, rx, dx;
	double x[MAXSEC+1], y[MAXSEC+1];

	if( argc == 4 )
	{
		a = strtod(argv[1], NULL);
		b = strtod(argv[2], NULL);
		c = strtod(argv[3], NULL);
	}
	printf("Func: %.3lf*x^2 + %.3lf*x + %.3lf\n", a, b, c);
	
	printf("Input Domain (two value): ");
	scanf("%lf%lf", &lx, &rx);
	if( lx > rx) {
		dx = lx, lx = rx, rx = dx;	// exchange left and right
	}
	dx = (rx - lx) / MAXSEC;
	printf("lx=%.3lf, rx=%.3lf, dx=%g\n", lx, rx, dx);
	
	for( i=0 ; i<=MAXSEC ; i++ )
	{
		x[i] = i * dx + lx;
		y[i] = func_2order(x[i]);
	}
		
	for( i=0 ; i<MAXSEC ; i++ )
	{
		if( y[i] == 0.0f ) {	// solution
			printf("x=%g, y=%g\n", x[i], y[i]);
		}
		else if( y[i] * y[i+1] < 0.0f ) {	// changed sign, so has solution
			printf("x=%.6lf, y=%.6lf ~ x=%.6lf, y=%.6lf\n",
				x[i], y[i], x[i+1], y[i+1]);
		}
	}
}
