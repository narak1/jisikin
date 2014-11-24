#include <stdio.h>
#include <time.h>

int mod_fibo(int n, int m)
{
	int i, f[3], d;

	if( n==0 ) return 0;
	if( n == 1 ) return 1;

	d = 1 << m;
	printf("div=%d\n", d);

	f[1] = 0;
	f[2] = 1;
	for( i=2 ; i<=n ; i++ ) {
		f[0] = f[1];
		f[1] = f[2];
		f[2] = (f[1] + f[0]) % d;
	//	printf("f%02d = %d\n", i, f[2]);
	}
	return f[2];
}

int main(int argc, char **argv)
{
	int n, m;
	time_t t1, t2;

	n = 10;
	m = 3;

	if( argc > 1 ) n = strtol(argv[1], NULL, 10);
	if( argc > 2 ) m = strtol(argv[2], NULL, 10);

	t1 = time(NULL);
	printf("mof_fibo(%d,%d)=%d\n", n, m, mod_fibo(n, m));
	t2 = time(NULL);
	printf("spent time=%d sec\n", t2-t1);
}
