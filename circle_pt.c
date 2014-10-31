#include <stdio.h>
#include <math.h>

#define MAXPT	16

typedef struct
{
	double x, y;
} point;

point circle[MAXPT];
double angle[MAXPT] =
{
	M_PI/2,
	M_PI/2+M_PI/6, M_PI/2-M_PI/6,
	M_PI/2+M_PI/4, M_PI/2-M_PI/4,
	M_PI/2+M_PI/3, M_PI/2-M_PI/3,
	M_PI, 0,
	M_PI+M_PI/6, -M_PI/6,
	M_PI+M_PI/4, -M_PI/4,
	M_PI+M_PI/3, -M_PI/3,
	M_PI+M_PI/2,
};

void calc_point();
void move_point(double dx, double dy);
void print_point();

main()
{
	char cmd[4];

	calc_point();
	while(1)
	{
		print_point();
		printf("input command: ");
		scanf("%s", cmd);
		if( cmd[0] == 'x' )
			move_point(-1.0, 0.0);
		else if( cmd[0] == 'X' )
			move_point(1.0, 0.0);
		else if( cmd[0] == 'y' )
			move_point(0.0, -1.0);
		else if( cmd[0] == 'Y' )
			move_point(0.0, 1.0);
	}
}

void calc_point()
{
	int i;
	for( i=0 ; i<MAXPT ; i++ ) {
		circle[i].x = cos(angle[i]);
		circle[i].y = sin(angle[i]);
	}
}

void print_point()
{
	int i;
	printf("(%lf, %lf)\n", circle[0].x, circle[0].y);
	for( i=1 ; i<MAXPT-1 ; i++ ) {
		printf("(%lf, %lf)", circle[i].x, circle[i].y);
		if( i%2 )
			putchar('\t');
		else
			putchar('\n');
	}
	printf("(%lf, %lf)\n", circle[i].x, circle[i].y);
}

void move_point(double dx, double dy)
{
	int i;
	for( i=0 ; i<MAXPT ; i++ ) {
		circle[i].x += dx;
		circle[i].y += dy;
	}
}
