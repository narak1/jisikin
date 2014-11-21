#include <stdio.h>

int cubic_sum(int n)
{
	if( n == 0 )
		return 0;
	else
		return n*n*n + cubic_sum(n-1);
}

int main()
{
	int n, sum;
	printf("Input number: ");
	scanf("%d", &n);
	sum = cubic_sum(n);
	printf("Sum = %d\n", sum);
}

