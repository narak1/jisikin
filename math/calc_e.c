#include <stdio.h>

main()
{
	double e, error;
	double fact, tmp, diff;
	int i, n;

	puts("자연 로그에서 사용되는 오일러 수 e를 계산하는 프로그램");
	printf("Input error value: ");
	scanf("%lf", &error);

	e = 1.0;
	n = 0;
	tmp = 10.0;		// temporary value
	do {
		++n;
		fact = 1.0;
		for( i=2 ; i<=n ; i++ ) {
			fact *= i;
		}
		fact = 1.0 / fact;
		e += fact;
		diff = tmp - fact;
		tmp = fact;

		printf("n=%2d, e=%lf, diff=%le\n", n, e, diff);

	} while( diff >= error );

	printf("e=%.10lf, loop_num=%d\n", e, n);
}
