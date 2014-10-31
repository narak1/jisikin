#include <stdio.h>

main()
{
	int i;
	int A[5]={5,-8,0,2,9};
	int degree=4;
	int idx;

	for( i=0 ; i<=degree ; i++ )
	{
		//....  i 는 다항식의 차수가 되는게 맞음. 
	}
	
	for( i=degree ; i>=0 ; i-- )
	{
		idx = degree - i;
		if( A[idx] ) {
		//	if( A[idx] > 0 )
		//		if( idx > 0 )
		//			printf("+");
				
			if( i>1 ) {
				printf("%+dx^%d", A[idx], i);
			}
			else if( i==1 ) {
				printf("%+dx", A[idx]);
			}
			else {
				printf("%+d", A[idx]);
			}
		}
	}
}
