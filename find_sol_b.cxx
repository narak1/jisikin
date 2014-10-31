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
	double lh = 1.48, rh = 1.49;
	double h = (lh + rh) / 2.0;

	double left_dv = v - func_v(t, lh);
	double right_dv = v - func_v(t, rh);
	while( (rh - lh) < 1.0e-4 ) {
		double cur_dv = v - func_v(t, h);

		if( cur_dv == 0.0 ) {
			break;
		}
		else if( left_dv * cur_dv < 0.0 ) {
			// printf("has solution in (%.2lf ~ %.2lf)\n", lh, h);
			rh = h;
		}
		else {
			lh = h;
		}

		h = (lh + rh) / 2.0;
	}
	printf("solution is %.4lf\n", h);
}

