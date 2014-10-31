#include <stdio.h>
#include <math.h>

main()
{
	double a, b, c;
	double x[2];
	int flag;
	
	do {
		printf("Input a, b, c: ");
		scanf("%lf%lf%lf", &a, &b, &c);
		
		flag = function(a, b, c, x);
		if( flag == 1 )
		{
			printf("Root : %lf, %lf\n", x[0], x[1]);
		}
		else if( flag == 0 )
		{
			printf("Equal root : %lf\n", x[0]);
		}
		else {
			puts("retry");
		}
	} while( flag < 0 );
}

int function(double a, double b, double c, double x[2])
{
	double D;
	int ret;

	D = b*b - 4*a*c;
	if( D < 0 ) {
		ret = -1;
	}
	else if( D == 0.0 ) {
		x[0] = -b / (2*a);
		ret = 0;
	}
	else {
		x[0] = (-b - sqrt(D)) / (2*a);
		x[1] = (-b + sqrt(D)) / (2*a);
		ret = 1;
	}
	return ret;
}
