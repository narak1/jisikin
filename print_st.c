#include <stdio.h>

void print_state(int idx, char usage[], int size);
int next_state(char usage[], int size);

main()
{
	char usage[6] = { 0, 1, 0, 1, 0, 1 };
	int idx;
	
	idx = 0;
	do {
		++idx;
		print_state(idx, usage, 6);
		
	} while( next_state(usage, 6) );
}

void print_state(int idx, char usage[], int size)
{
	int i;
	char *dir[] = { "", "¾Õ", "¹Ø" };
	char *kind[] = { "ÁÖ¸Ô", "¹ß" };
	
	printf("%3d: ", idx);
	for( i=0 ; i<size ; i++ ) {
		printf("%s%s ", dir[ usage[i] ], kind[ i%2 ] );
	}
	puts("");
}

int next_state(char usage[], int size)
{
	int i;
	
	i = 5;
	do {
		usage[i]++;		// set next kind
		if( usage[i] == usage[i-1] ) {	// same previous
			usage[i]++;
		}
		
		if( usage[i] > 2 ) {	// over -> prev change
			usage[i] = 0;
			--i;
		}
		else {					// fixed
			break;
		}
	} while( i );

	if( i == 0 ) {
		++usage[0];
		if( usage[0] > 2 )
			return 0;
	}

	++i;
	for( ; i<6 ; i++ ) {
		if( usage[i-1] > 0 )
			usage[i] = 0;
		else
			usage[i] = 1;
	}

	return 1;
}
