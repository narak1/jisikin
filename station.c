#include <stdio.h>
#include <stdlib.h>

#define TOTAL	60
#define ST_A	5
#define ST_B	4
#define ST_C	3
#define NUM		(TOTAL/ST_A)

main()
{
	int total, num;

	total = 1080;
	num = total / ST_A;

	calc_distance(total, 0, num, 0, num);
}

calc_distance(int total, int lb, int rb, int lc, int rc)
{
	int a[10], b[10], c[10], t[30];
	/*int d[NUM][NUM];*/
	int **d;
	int num;
	int i, j, k, n;

	printf("total=%d, lb=%d, rb=%d, lc=%d, rc=%d\n", total, lb, rb, lc, rc);

	num = rb - lb + 1;
	d = (int **) malloc(sizeof(int *) * num);
	for( i=0 ; i<num ; i++ ) {
		d[i] = (int *) malloc(sizeof(int) * num);
	}

	for( i=0 ; i<6 ; i++ ) {
		a[i] = i * total / ST_A;
	}

	n = total / ST_A;		// max long
	for( j=0 ; j<num ; j++ )
	{
		for( i=0 ; ; i++ ) {
			b[i] = i * total / ST_B + j + lb;		// b station position
			if( b[i] > total ) {
				break;
			}
		}

		for( k=0 ; k<num ; k++ )
		{
			for( i=0 ; ; i++ ) {
				c[i] = i * total / ST_C + k + lc;		// c station position
				if( c[i] > total ) {
					break;
				}
			}

			d[j][k] = find_near_long(a, b, c, t, total);	// find most log distance
			if( n > d[j][k] ) {
				n = d[j][k];
				printf("j=%d, k=%d, d=%d\n", j+lb, k+lc, n);
			}
		}
	}

	for( j=0 ; j<num ; j++ ) {
		for( k=0 ; k<num ; k++ ) {
			if( d[j][k] == n ) {
				printf("MAX Distance: a=%d, b=%d, Distancd=%d\n", j+lb, k+lc, n);
			}
		}
	}

	for( j=lb ; j<=rb ; j++ ) {
		for( k=lc ; k<=rc ; k++ ) {
			if( d[j-lb][k-lc] == n ) {
				calc_distance(total*10, (j-1)*10, (j+1)*10, (k-1)*10, (k+1)*10);
			}
		}
	}
}

int find_near_long(int a[], int b[], int c[], int t[], int total)
{
	int i, j, k, n;
	int d, r;

	i = j = k = n = 0;
	for( d=0 ; d<=total ; d++ )
	{
		if( a[i] == d ) {
			t[n] = a[i];
			i++;
			n++;
		}
		else if( b[j] == d ) {
			t[n] = b[j];
			j++;
			n++;
		}
		else if( c[k] == d ) {
			t[n] = c[k];
			k++;
			n++;
		}
	}

	r = 0;
	for( i=0 ; i<n-1 ; i++ ) {
		d = t[i+1] - t[i];
		if( r < d )
			r = d;
	}

/*
	printf("Stations: ");
	for( i=0 ; i<n ; i++ ) {
		printf("%2d ", t[i]);
	}
	printf("Most=%d\n", r);
*/

	return r;
}

