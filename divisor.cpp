
main(int argc, char **argv)
{
	int i, n;
	
	if( argc == 1 ) {
		printf("n=");
		scanf("%d", n);
	}
	else {
		n = strtol(argv[1], NULL, 10);
	}
	
	for( i=3 ; i*i<=n ; i+=2 ) {
		if( n % i == 0 ) {
			printf("n = %d x %d\n", i, n/i);
			break;
		}
	}
}
