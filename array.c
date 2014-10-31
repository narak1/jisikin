#include <stdio.h>

void print_array(int arr[][4], int r, int c);
int sum_array(int arr[][4], int r, int c);

main()
{
	int arr1[2][4] = { 1,2,3,4,5,6,7,8};
	int arr2[3][4] = { 1,1,1,1,3,3,3,3,5,5,5,5 };
	
	int a[3][2]={{1,2},{3,4},{5,6}};

	puts("arr1");
	print_array(arr1, 2, 4);
	puts("arr2");
	print_array(arr2, 3, 4);
	
	printf("sum of arr1 = %d\n", sum_array(arr1, 2, 4));
	printf("sum of arr2 = %d\n", sum_array(arr2, 3, 4));
	
	puts("-------");
	puts("1)");
	printf("address of 1st row : %p\n", a);
	printf("address of 1st row : %p\n", a[0]);
	printf("address of 1st row : %p\n", *a);
	puts("2)");
	printf("value of 3rd row and 2nd column : %d\n", a[2][1]);
	printf("value of 3rd row and 2nd column : %d\n", *(a[2]+1));
	printf("value of 3rd row and 2nd column : %d\n", *(*(a+2)+1));
	printf("value of 3rd row and 2nd column : %d\n", (*a)[2*2+1]);	// 1차 배열로 가정하고 위치를 계산 
}

void print_array(int arr[][4], int r, int c)
{
	int i, j;
	
	if( c > 4 )
		c = 4;
		
	for( i=0 ; i<r ; i++ ) {
		for( j=0 ; j<c ; j++ ) {
			printf("%d ", arr[i][j]);
		}
		putchar('\n');
	}
}

int sum_array(int arr[][4], int r, int c)
{
	int i, j, sum;
	
	if( c > 4 )
		c = 4;

	sum = 0;
	for( i=0 ; i<r ; i++ ) {
		for( j=0 ; j<c ; j++ ) {
			sum += arr[i][j];
		}
	}
	
	return sum;
}

