#include <stdio.h>
#include <math.h>

double f(double x)
{
	return x*x*x + 2.0*x - 3.0;
}

main()
{
	double xl, xr, x;
	double yl, yr, y;
	double eps = 1.0e-10;
	
	xl = 0.0;
	xr = 7.0 / 5.0;
	
	yl = f(xl);
	yr = f(xr);
	
	if( yl * yr > 0.0 ) {
		puts("cannot solve");
		return;
	}
	
	while(1) {
		x = (xl + xr) / 2.0;
		y = f(x);
		
		printf("x=%lf, y=%lg\n", x, y);
		
		if( fabs(y) < eps ) {
			printf("Solution : %lf\n", x);
			break;
		}
		
		if( yl * y > 0.0 ) {
			xl = x;
		}
		else {
			xr = x;
		}
	}
}
