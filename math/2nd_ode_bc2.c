/*
	D.E. boundary value problem
		f(y, y', y", ...) = g(x) ; y(x0)=A, y(xN)=B

		y" + y' = 0 ; y(0)=0 , y(pi/2)=1

		y' = ツy / ツx = (yn - y(n-1)) / h
		y" = ツy' / ツx = (y(n+1) - 2yn + y(n-1) / h^2
		y' = (y(n+1) - yn) / h
		y' = (y(n+1) - y(n-1)) / 2h

		(1/h^2) y(n+1) + (1 - 2/h^2) yn + (1/h^2) y(n-1) = 0
		y0 = 0
		yN = 1

	1D D.E. -> Tridiagonal Matrix
	2D D.E. -> Pentadiagonal Matrix
	3D D.E. -> Heptadiagonal Matrix or Septa-

	Tridiagonal Matrix
	(http://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm)
		b1 c1        0  y1   d1
		a2 b2 c2        y2   d2
		   a3 b3 c3     y3 = d3
		      a4 b4 c4  y4   d4
		 0       a5 b5  y5   d5

	c'i = ci / bi 				(i=1)
	    = ci / (bi - aic'(i-1)) (n=2,...)
	d'i = di / bi (i=1)
	    = (di - aid'(i-1)) / (bi - aic'(i-1))

	yn = d'n
	yi = d'i - c'i y(i+1)

	mathmatical solution: y(x) = sin(x)
*/

#define MAXSTEP 1000

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
	int i, j, step;
	double m[3][MAXSTEP], y[MAXSTEP], f[MAXSTEP];
	double x0, xN, x;
	double h, h2, a, b, c;
	double tmp, tmp_c[MAXSTEP], tmp_f[MAXSTEP];

	step = 10;
	if( argc > 1 ) {
		step = strtol(argv[1], NULL, 10);
	}

	x0 = 0;
	y[0] = 0;		// B.C.
	xN = M_PI/2;
	y[step] = 1;	// B.C.
	h = (xN - x0) / step;
	h2 = h * h;		// h^2

	for( i=1 ; i<step ; i++ ) {
		x = x0 + i * h;
		a = 1/h2;
		b = 1 - 2/h2;
		c = 1/h2;
		if( i == 1 ) {
			m[0][i] = 0;	// b.c
			m[1][i] = b;
			m[2][i] = c;
			f[i] = 0;
		}
		else if( i == step-1 ) {
			m[0][i] = a;
			m[1][i] = b;
			m[2][i] = 0;	// b.c
			f[i] = -c;
		}
		else {
			m[0][i] = a;
			m[1][i] = b;
			m[2][i] = c;
			f[i] = 0;
		}
	}

	// print TDM
	//
	for( i=1 ; i<step ; i++ ) {
		for( j=1 ; j<i-1 ; j++ ) {
			printf("%6s ", "");
		}
		if( i != 1 ) { ++j, printf("%6.1lf ", m[0][i]); }
		++j; printf("%6.1lf ", m[1][i]);
		if( i != step-1 ) { ++j; printf("%6.1lf ", m[2][i]); }
		for( ; j<step ; j++ ) {
			printf("%6s ", "");
		}
		printf(" y%d = %6.1lf\n", i, f[i]);
	}

	// modify coef.
	//
	tmp_c[1] = m[2][1] / m[1][1];	// c1 / b1
	tmp_f[1] = f[1] / m[1][1];		// f1 / b1
	for( i=2 ; i<step ; i++ ) {
		tmp = (m[1][i] - m[0][i] * tmp_c[i-1]);
		tmp_c[i] = m[2][i] / tmp;
		tmp_f[i] = (f[i] - m[0][i] * tmp_f[i-1]) / tmp;
	}


	// print modified coefficient
	//
	for( i=1 ; i<step ; i++ ) {
		for( j=1 ; j<i-1 ; j++ ) {
			printf("%6s ", "");
		}
		if( i != 1 ) { ++j, printf("%6.1lf ", m[0][i]); }
		++j; printf("%6.1lf ", m[1][i]);
		if( i != step-1 ) { ++j; printf("%6.1lf ", tmp_c[i]); }
		for( ; j<step ; j++ ) {
			printf("%6s ", "");
		}
		printf(" y%d = %6.1lf\n", i, tmp_f[i]);
	}

	// calc solution
	//
	y[step-1] = tmp_f[step-1];		// yn = d'n
	for( i=step-2 ; i>0 ; i-- ) {
		y[i] = tmp_f[i] - tmp_c[i] * y[i+1];
	}

	// print solution
	//
	for( i=0 ; i<=step ; i++ ) {
		x = x0+i*h;
		tmp = fabs(y[i] - sin(x));
		printf("%3d: f(%.2lf) = %8.3lf, error=%g\n", i, x, y[i], tmp);
	}
}
