#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* medal_type[] = { "Gold", "Silver", "Bronze" };
const int medal_num = sizeof(medal_type) / sizeof(const char*);

#define MAX_ATH 10

void swap_int(int *n, int *m)
{
	int i;
	i = *n, *n = *m, *m = i;
}

void swap_double(double *d, double *e)
{
	double f;
	f = *d, *d = *e, *e = f;
}

main()
{
	double athlete[MAX_ATH];
	int ranking[MAX_ATH];
	int num_ath;
	int i, j;

	srand(time(NULL));

	num_ath = 8;

	for( i=0 ; i<num_ath ; i++ ) {
		athlete[i] = (rand() % 101) / 100.0 + 9.50;
	}
	for( i=0 ; i<num_ath ; i++ ) {
		printf("Athlete %d: %.2lfsec\n", i+1, athlete[i]);
	}
	putchar('\n');
	/* find ranking */
	// initialize
	for( i=0 ; i<num_ath ; i++ ) {
		ranking[i] = i+1;
	}
	// sorting
	for( i=0 ; i<num_ath-1 ; i++ ) {
		for( j=i+1 ; j<num_ath ; j++ ) {
			if( athlete[i] > athlete[j] ) {
				swap_double(&athlete[i], &athlete[j]);
				swap_int(&ranking[i], &ranking[j]);
			}
		}
	}
	// print
	for( i=0 ; i<medal_num ; i++ ) {
		printf("Place #%d (%s medal): Athlete %d\n",
			i+1, medal_type[i], ranking[i]);
	}
}

