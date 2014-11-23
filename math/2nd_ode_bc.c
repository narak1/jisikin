/*
	D.E. boubdary value problem
		f(y, y', y", ...) = g(x) ; y(x0)=A, y(xN)=B

	-y" + y' = -1 ; y(0)=0 , y(1)=1

	y' = ツy / ツx = (yn - y(n-1)) / h
	y" = ツy' / ツx = (y(n+1) - 2yn + y(n-1) / h^2
	y' = (y(n+1) - yn) / h 
	y' = (y(n+1) - y(n-1)) / 2h

	(-1/h^2 + 1/2h) y(n+1) + 2/h^2 yn + (-1/h^2 - 1/2h) y(n-1) = -1
	y0 = 0
	yN = 1
*/

#define MAXSTEP 1000

#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	double m[3][MAXSTEP], y[MAXSTEP], f[MAXSTEP];
	doubel x0, xN;
	double h, a, b, c;

	