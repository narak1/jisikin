#include <stdio.h>

#define MAXNUM 100

void split_num(int num, int arr[], int idx);
void print_arr(int arr[], int idx);

main()
{
	int num;
	int arr[MAXNUM] = { 0, };
	
	printf("Input number (MAX %d) : ", MAXNUM);
	scanf("%d", &num);
	if( num > MAXNUM )
		return 1;

	split_num(num, arr, 0);
}

void split_num(int num, int arr[], int idx)
{
	int i, min;
	
	if( num == 1 )
		return;

	min = 1;
	for( i=0 ; i<idx ; i++ ) {
		if( arr[i] > min )
			min = arr[i];
	}
	
	for( i=min ; i<=num/2 ; i++ ) {
		arr[idx] = i;
		arr[idx+1] = num - i;
		print_arr(arr, idx+1);
		
		split_num(num-i, arr, idx+1);
	}
}

void print_arr(int arr[], int idx)
{
	int i;
	for( i=0 ; i<idx ; i++ )
		printf("%d + ", arr[i]);
	printf("%d\n", arr[i]);
}
