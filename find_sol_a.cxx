#include <cstdio>
#include <cmath>

double g = 9.81;	// m/s^2
double L = 5.0;		// m

double func_v(double t, double h)
{
	double t1 = sqrt(2.0 * g * h);
	double t2 = t / (2.0 * L);
	return t1 * tanh(t2 * t1);
}

int main()
{
	double t = 3.0, v = 5.0;
	double h = 0.0, dh = 0.01;
	double h_max = 100.0;

	double pre_dv = v - func_v(t, h);
	h += dh;
	while( h < h_max ) {
		double cur_dv = v - func_v(t, h);
		
		if( cur_dv == 0.0 ) {
			printf("is solution at %.2lf\n", h);
		}
		else if( pre_dv * cur_dv < 0.0 ) {
			printf("has solution in (%.2lf ~ %.2lf)\n", h-dh, h);
		}

		pre_dv = cur_dv;
		h += dh;
	}
}

