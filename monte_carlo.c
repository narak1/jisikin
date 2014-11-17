#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double func(double a, double b, double t)
{
	double tmp;
	tmp = (b*b) / (a*a);
	tmp = 1.0 - tmp;
	tmp = 1.0 - tmp * sin(t) * sin(t);
	tmp = sqrt(tmp);
	return tmp;
}

double monte_carlo(double a, double b, int num);

int main()
{
	double a, b;
	int num;
	double val;

	srand(time(NULL));

	printf("Input ellipse major and minor axis lenght : ");
	scanf("%lf%lf", &a, &b);

	if( a < b ) {	// fix major and minor axis
		val = a;
		a = b;
		b = val;
	}

	num = 1000;
	val = 4.0 * a * monte_carlo(a, b, num);
	printf("Monte Carlo simulation (%6d) : %.15lf\n", num, val);
	num = 10000;
	val = 4.0 * a * monte_carlo(a, b, num);
	printf("Monte Carlo simulation (%6d) : %.15lf\n", num, val);
	num = 100000;
	val = 4.0 * a * monte_carlo(a, b, num);
	printf("Monte Carlo simulation (%6d) : %.15lf\n", num, val);
}

double monte_carlo(double a, double b, int num)
{
	int i, cnt;
	double rx, ry, maxx, maxy, total_area;
	double fy;
	
	maxx = M_PI / 2.0;
	maxy = 2.0;
	total_area = maxx * maxy;

	cnt = 0;
	for( i=0 ; i<num ; i++ ) {
		rx = rand() / (double)RAND_MAX * maxx;
		ry = rand() / (double)RAND_MAX * maxy;
		fy = func(a, b, rx);
		if( ry <= fy ) {
			++cnt;
		}
	}
	return (total_area * cnt) / num;
}
