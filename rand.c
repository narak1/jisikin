#include <stdio.h>

main()
{
	int arr[10][10];
	int i, j;
	
	srand(time(NULL));
	for( i=0 ; i<10 ; i++ ) {
		for( j=0 ; j<10 ; j++ ) {
			arr[i][j] = rand() % 4;
		}
	}

	for( i=0 ; i<10 ; i++ ) {
		for( j=0 ; j<10 ; j++ ) {
			if( arr[i][j] == 0 )	// 또는 1,2,3 중 하나 
				putchar('*');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}
