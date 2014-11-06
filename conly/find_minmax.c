#include <stdio.h>

int findMaxIndex(int a[],int size);
int findMinIndex(int a[],int size);

void main()
{
	int i, j, n, m[100][100];
	
	printf("enter a integer:");
	scanf("%d",&n);

	printf("enter %dx%d matrix:", n, n);
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&m[j][i]);
		}
	}

	// print original
	//
	puts("original maxtrix");
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			printf("%2d ",m[j][i]);
		}
		puts("");
	}

	// find min/max
	//
	for(j=0;j<n;j++)
	{
		if( j%2 == 0 ) {
			i = findMinIndex(m[j], n);
		}
		else {
			i = findMaxIndex(m[j], n);
		}
		m[j][i] = 0;
	}

	// print result
	//
	puts("result maxtrix");
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			printf("%2d ",m[j][i]);
		}
		puts("");
	}
}

int findMaxIndex(int a[],int size)
{
	int i, idx, val;
	idx = 0;
	val = a[0];
	for( i=1 ; i<size ; i++ ) {
		if( a[i] > val ) {
			idx = i;
			val = a[i];
		}
	}
	return idx;
}

int findMinIndex(int a[],int size)
{
	int i, idx, val;
	idx = 0;
	val = a[0];
	for( i=1 ; i<size ; i++ ) {
		if( a[i] < val ) {
			idx = i;
			val = a[i];
		}
	}
	return idx;
}

