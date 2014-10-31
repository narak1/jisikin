#include <stdio.h>

int is_prime(int num)
{
	int i, flag;
	
	if( num == 1)		// 1 is Not prime
		return 0;
	else if( num == 2 )	// 2 is prime
		return 1;
	else if( num%2 == 0 )	// even is Not prime
		return 0;
		
	flag = 1;
	for( i=3 ; i*i<=num ; i+=2 ) {	// check only odd number
		if( num % i == 0 ) {		// multiple of i, so not prime
			flag = 0;
			break;
		}
	}
	
	return flag;
}

main()
{
	int i, num;
	
	num = 0;
	for( i=1 ; i<=10000 ; i++ ) {
		if( is_prime(i) ) {
			++num;
			printf("%4d ", i);
			if( num % 20 == 0 )
				putchar('\n');
		}
	}
	printf("\nnumber of prime : %d\n", num);
}
