#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int Width = 20;
const int Height = 10;

int miro(int arr[Height][Width], int x, int y);
int find_path(int arr[Height][Width], int x, int y, int *x2, int *y2);

void main(int argc, char **argv)
{
	int arr[Height][Width];
	int i, j, x, y, x2, y2;
	double len;
	int cnt;
	int flag;
	FILE *fp;
	char *fname = "matrix.txt";

	if( argc > 1 ) {
		fname = argv[1];
	}

	fp = fopen(fname, "r");
	if( fp == NULL ) {
		perror(fname);
		return;
	}

	for(i = 0; i < Height; i++){
		for(j = 0; j < Width; j++){
			fscanf(fp, "%d", &arr[i][j]);
		}
	}
	fclose(fp);

	x = y = 1;	// start position
	len = 0.0;	// path length
	cnt = 0;	// point num
	while(1) {
		printf("Count=%d, Position = %d,%d ; len=%lf\n", cnt, x, y, len);
		flag = find_path(arr, x, y, &x2, &y2);
		if( flag == 0 ) {
			break;
		}

		arr[x][y] = 2;	// already passed

		len += sqrt( (x2-x)*(x2-x) + (y2-y)*(y2-y) );
		++cnt;
		
		x = x2;
		y = y2;
	}

	printf("Count=%d, 이동 거리 : %lf\n", cnt, len);

	for (x = 0; x < 10; x++) {
		for (y = 0; y <20; y++) {
			printf("%d", arr[x][y]);
		}
		puts("");
	}
	putchar('\n');
}

int find_path(int arr[Height][Width], int x, int y, int *x2, int *y2)
{
	int i, j;
	for( i=-1 ; i<=1 ; i++ ) {
		for( j=-1 ; j<=1 ; j++ ) {
			if( (i == 0 ) && (j == 0) ) {	// this position
				;
			}
			else if( arr[x+i][y+j] == 1 ) {
				*x2 = x+i;
				*y2 = y+j;
				return 1;
			}
		}
	}
	return 0;
}
