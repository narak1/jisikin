#include <stdio.h> 
#include <math.h>

double f(double x) 
{ 
   return exp(x) + x - 2.0; 
} 
double fp(double x) 
{ 
   return exp(x) + 1.0; 
} 
main() 
{ 
   double x, y, eps; 

	eps = 1e-10;   
   x = 1.0;
   y = f(x);
   printf("x=%.5lf, y=%.5lg\n", x, y);
   while( y > eps )
   {
		x -= y / fp(x);
		y = f(x);
	   printf("x=%.5lf, y=%.5lg\n", x, y);
   }
   
   printf("\n Solution = %lf\n", x);
} 
