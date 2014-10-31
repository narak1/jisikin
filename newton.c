#include <stdio.h> 
double f(double x, int n) 
{ 
   return x*x - n; 
} 
double fp(double x) 
{ 
   return 2.0*x; 
} 
main() 
{ 
   int i; 
   double x, xn; 
   for( i=1 ; i<=30 ; i++ ) { 
      xn = i; 
      do { 
         x = xn; 
         xn = x - f(x, i) / fp(x); 
      } while( xn != x ); 
      printf("%3d: %20.18lf\n", i, x); 
   } 
} 
