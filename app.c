#include <stdio.h>
#include <string.h>

main()
{
	char input_str[5][10];
	char *sort_str[5], *tmp;
	int i, j;
	void array_prn(char **app);

	puts("Input five strings less than 10 chars.");
	for( i=0 ; i<5 ; i++ ) {
		printf("%d: ", i+1);
		scanf("%s", input_str[i]);
	}

	// initialize pointer array
	for( i=0 ; i<5 ; i++ ) {
		sort_str[i] = input_str[i];
	}

	// bubble sort
	for( i=1 ; i<5 ; i++ ) {
		for( j=0 ; j<5-i ; j++ ) {
			if( sort_str[j][0] > sort_str[j+1][0] ) {
				tmp = sort_str[j];
				sort_str[j] = sort_str[j+1];
				sort_str[j+1] = tmp;
			}
		}
	}

	// print
	puts("Sorted result")
	array_prn(sort_str);
}

void array_prn(char **app)
{
	int i;
	for( i=0 ; i<5 ; i++ ) {
		printf("%d: %s\n", i+1, app[i]);
	}
}
