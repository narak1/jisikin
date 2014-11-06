#include <stdio.h>

#define ROWS 5
#define COLS 10

double get_row_avg(int m[][COLS], int r);
double get_row_avg2(int m[][COLS], int r);

int main()
{
	int array1[ROWS][COLS];
	int i, j;
	double avg;
	
	srand(time(NULL));		// set random seed
	
	// data set random
	//
	for( i=0 ; i<ROWS ; i++ ) {
		for( j=0 ; j<COLS ; j++ ) {
			array1[i][j] = rand() % 101;	// value is 0 ~ 100
		}
	}

	// print data
	//
	for( i=0 ; i<ROWS ; i++ ) {
		for( j=0 ; j<COLS ; j++ ) {
			printf("%2d ", array1[i][j]);
		}
		puts("");	// new line
	}

	// print row average
	//
	for( i=0 ; i<ROWS ; i++ ) {
		avg = get_row_avg2(array1, i);
		printf("%d rows average = %.2lf\n", i+1, avg);
	}
}

double get_row_avg(int m[][COLS], int r)
{
 int *p, *endp;
 double sum=0.0;
 p = &m[r][0];
 endp = &m[r][COLS];
 
 while(p < endp)
 sum += *p++;
 
 sum /= COLS;
 return sum;
}

double get_row_avg2(int m[][COLS], int r)
{
	double sum = 0.0;
	int i;
	for( i=0 ; i<COLS ; i++ ) {
		sum += m[r][i];
	}
	sum /= COLS;
	return sum;
}
