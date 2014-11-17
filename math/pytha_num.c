#include <stdio.h>

main()
{
	int a, b, c;
	int num, flag;
	
	num = 0;
	flag = 1;
	for( a=1 ; flag ; a++ ) {
		for( b=1 ; b<a ; b++ ) {
			for( c=a-b+1 ; c<b ; c++ ) {
				if( a*a == b*b + c*c ) {
					++num;
					printf("%2d - %2d : %2d : %2d\n", num, a, b, c);
					if( num >= 10 ) {
						flag = 0;
						break;
					}
				}
			}
			
			if( flag == 0 ) break;
		}
	}
}

