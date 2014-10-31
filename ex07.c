#include <stdio.h>

main()
{
	int arr[] = { 1, 5, 10, 15, 20 };
	int *ptr;
	int i;
	
	ptr = arr;
	for( i=0 ; i<sizeof(arr)/sizeof(int) ; i++ ) {
		printf("%d ", *ptr);
		++ptr;
	}
	puts("");
}
