#include <stdio.h>
#include <math.h>

struct Point
{
	double x, y;
};

double calc_area(struct Point *p1, struct Point *p2, struct Point *p3);

main(int argc, char **argv)
{
	char* filename = "input.txt";
	FILE *fp;
	int i, ret;
	struct Point pts[5];
	struct Point *p1, *p2, *p3;
	double area, sum;
	
	fp = fopen(filename, "r");
	if( fp == NULL ) {
		perror(filename);
		return 1;
	}
	
	for( i=0 ; i<5 ; i++ )
	{
		ret = fscanf(fp, "%lf%lf", &pts[i].x, &pts[i].y);
	//	if( ret == EOF ) {
	//		printf("Data too small: %d\n", i);
	//		return 1;
	//	}
	}
	
	fclose(fp);

	sum = 0.0;
	p3 = &pts[4];
	for( i=0 ; i<4 ; i++ ) {
		p1 = &pts[i];
		p2 = &pts[i+1];
		if( p2 == p3 )
			p2 = &pts[0];
			
		area = calc_area(p1, p2, p3);
		sum += area;
		printf("Area of triangle %d = %lf\n", i+1, area);
	}
	printf("Total area = %lf\n", sum);
}

double calc_area(struct Point *p1, struct Point *p2, struct Point *p3)
{
	return fabs(0.5 * ( (p2->x-p1->x) * (p3->y-p1->y) - (p2->y-p1->y) * (p3->x-p1->x)));	
}
