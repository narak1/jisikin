/*
	Runge-Kutta methods
		First order O.D.E. initial value problem
		y' = f(x,y) ; y(x0)=y0

		k1 = hf(xn, yn)
		k2 = hf(xn+h/2, yn+k1/2)
		k3 = hf(xn+h/2, yn+k2/2)
		k4 = hf(xn+h, yn+k3)
		y(n+1) = yn + (k1 + 2k2 + 2k3 + k4) / 6

	High order O.D.E changed to system of 1st order O.D.E
		Let y'" = f(x, y, y', y") ; y(x0)=y0, y'(x0)=y0', y"(x0)=y0"

		Set, y1 = y
		y2 = y'
		y3 = y"

		y1' = y' = y2
		y2' = y" = y3
		y3' = y'" = f(x, y, y', y") = f(x, y1, y2, y3)

	Apply Runge-Kutta methods to system of O.D.E
		k1 = hf1(xn, y1n, y2n, y3n) = hy2n
		l1 = hf2(xn, y1n, y2n, y3n) = hy3n
		m1 = hf3(xn, y1n, y2n, y3n) = hf(xn, y1n, y2n, y3n)

		k2 = hf1(xn+h/2, y1n+k1/2, y2n+l1/2, y3n+m1/2) = h(y2n+l1/2)
		l2 = hf2(xn+h/2, y1n+k1/2, y2n+l1/2, y3n+m1/2) = h(y3n+m1/2)
		m3 = hf(xn+h/2, y1n+k1/2, y2n+l1/2, y3n+m1/2)

		...

		y1(n+1) = y1n + (k1 + 2k2 + 2k3 + k4) / 6
		y2(n+1) = y2n + (l1 + 2l2 + 2l3 + l4) / 6
		y3(n+1) = y3n + (m1 + 2m2 + 2m3 + m4) / 6

	This Problem
		-y" + y' = -1 ; y(0)=0 , y'(0)=1
		y" = f(x, y, y') = y' + 1

		y1' = y' = y2
		y2' = y" = y2 + 1

		Mathmatical solution: y(x) = 2exp(x) - x - 2
*/

#include <stdio.h>
#include <math.h>

double math_sol(double x)
{
	return 2.0 * exp(x) - x - 2.0;
}

double fxyyp(double x, double y, double yp)
{
	return yp + 1.0;
}

int main(int argc, char **argv)
{
	int i;
	double x0, y0, yp0;
	double h;
	double k1, k2, k3, k4;
	double m1, m2, m3, m4;
	double xn, yn, ypn;
	
	x0 = 0;
	y0 = 0;
	yp0 = 1;
}
