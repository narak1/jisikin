#include <stdio.h>

#define MAXDEPTH 5

void chain_sum(int arr[][MAXDEPTH], int sum, int idx, int depth, int max_depth);
void print_max();

int result[2*2*2*2];
int r_idx;

main()
{
	int arr[MAXDEPTH][MAXDEPTH] = {
		{0	},
		{10,11},
		{20,21,22},
		{30,31,32,33},
		{40,41,42,43,44} };
	int i, j;
	
	srand(time(NULL));
	for( i=0 ; i<MAXDEPTH ; i++ ) {
		for( j=0 ; j<=i ; j++ ) {
			//arr[i][j] = rand() % 30 + 1;	// 1 ~ 30
		}
	}
	
	chain_sum(arr, 0, 0, 0, MAXDEPTH-1);
	
	print_max();	
}

void chain_sum(int arr[][MAXDEPTH], int sum, int idx, int depth, int max_depth)
{
	sum += arr[depth][idx];

	if( depth == max_depth ) {	
		printf("idx=%d, depth=%d, sum=%d\n", idx, depth, sum);
		result[r_idx++] = sum;
		return;
	}
		
	chain_sum(arr, sum, idx, depth+1, max_depth);
	chain_sum(arr, sum, idx+1, depth+1, max_depth);
}

void print_max()
{
	int i, n = 0;
	for( i=0 ; i<r_idx ; i++ ) {
		if( result[i] > n ) {
			n = result[i];
		}
	}
	
	printf("total result=%d, max=%d\n", r_idx, n);
}
