#include <stdio.h>
#include <math.h>

struct point { double x, y; };

double calc_distance(struct point *p1, struct point *p2)
{
	double dx, dy;
	dx = p1->x - p2->x;
	dy = p1->y - p2->y;
	return sqrt(dx*dx + dy*dy);
}

void calc_ratio_point(struct point *p1, struct point *p2, double ratio, struct point *p3)
{
	p3->x = p1->x + (p2->x - p1->x) * ratio;
	p3->y = p1->y + (p2->y - p1->y) * ratio;
}

int main()
{
	struct point p1, p2, p3, p4, q;
	double a, b, c, x, y, m, n;
	double aa, bb, cc;

	printf("Input Point 1's Coord: ");
	scanf("%lf%lf", &p1.x, &p1.y);
	printf("Input Point 2's Coord: ");
	scanf("%lf%lf", &p2.x, &p2.y);

	a = calc_distance(&p1, &p2);

	printf("Input Distance from P1 & P2: ");
	scanf("%lf%lf", &b, &c);

	printf("a=%.3lf, b=%.3lf, c=%.3lf\n", a, b, c);

	if( a > b + c ) {
		fprintf(stderr, "Impossible\n");
		return 1;
	}
	else if( a == b + c ) {
		/* one point of contact */
		calc_ratio_point(&p1, &p2, b/a, &p3);
		printf("3rd point=(%.3lf, %.3lf)\n", p3.x, p3.y);
		return 0;
	}

	x = (a*a + b*b - c*c) / (2*a);
	calc_ratio_point(&p1, &p2, x/a, &q);

	if( p1.x == p2.x ) {	/* vertical. m=∞ */
		y = sqrt(c*c - x*x);
		p3.x = q.x - y;
		p4.x = q.x + y;
		p3.y = p4.y = q.y;
	}
	else if( p1.y == p2.y ) {	/* horizontal. m'=∞ */
		p3.x = p4.x = q.x;
		y = sqrt(c*c - x*x);
		p3.y = q.y - y;
		p4.y = q.y + y;
	}
	else {
		m = (p1.y - p2.y) / (p1.x - p2.x);
		m = -1.0 / m;						/* 두점을 지나는 직선의 기울기 */
		n = q.y - m * q.x;					/* 직선의 y절편 */

		/* calc points of intersection */
		aa = 1.0 + m * m;
		bb = (m*n - m*p1.y - p1.x);			/* using b' in formula */
		cc = p1.x*p1.x + (n - p1.y)*(n - p1.y) - b*b;

		/* quadratic formula */
		p3.x = (-bb - sqrt(bb*bb - aa*cc)) / aa;
		p3.y = m * p3.x + n;

		p4.x = (-bb + sqrt(bb*bb - aa*cc)) / aa;
		p4.y = m * p4.x + n;
	}

	printf("P3=(%.3lf, %.3lf) ; P4=(%.3lf, %.3lf)\n", p3.x, p3.y, p4.x, p4.y);
}

