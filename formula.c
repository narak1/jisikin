#include <stdio.h>
#include <math.h>

main()
{
	double a, b, c, D, d;
	double x1, x2;
	
	printf("Input coefficient : ");
	scanf("%lf%lf%lf", &a, &b, &c);
	D = b*b - 4.0*a*c;
	if( D > 0.0 ) {
		d = sqrt(D);
		x1 = (-b - d) / (2.0 * a);
		x2 = (-b + d) / (2.0 * a);
		printf("two real roots : %lf , %lf\n", x1, x2);
	}
	else if( D == 0.0 ) {
		printf("a multiple root : %lf\n", -b/(2.0*a));
	}
	else {
		d = sqrt(-D);
		puts("has not real root");
		
		x1 = -b / (2.0 * a);
		x2 = d / (2.0 * a);
		if( b == 0.0 ) {
			printf("two imaginary roots : -%lfi , %lfi\n", x2, x2);			
		}
		else {
			printf("two complex roots : %lf-%lfi , %lf+%lfi\n", x1, x2, x1, x2);
		}
	}
}
