#include <stdio.h>

#define MAXDEPTH 5
#define MAXTYPES 5

void find_path(int path[], int n, int depth);

main()
{
	int path[MAXDEPTH];
	for( int i=1 ; i<=MAXTYPES ; i++ ) {
		find_path(path, i, 1);
	}
}

void find_path(int path[], int n, int depth)
{
	if( depth == MAXDEPTH ) {
		for( int i=0 ; i<MAXDEPTH-1 ; i++ ) {
			printf("%d -> ", path[i]);
		}
		printf("%d\n", n);
	}
	else {
		path[depth-1] = n;

		int tt[MAXTYPES] = { 0, };
		for( int i=0 ; i<depth ; i++ ) {	// find used
			tt[ path[i]-1 ] = 1;
		}
		for( int i=1 ; i<=MAXTYPES ; i++ ) {
			if( tt[i-1] == 0 ) {
				find_path(path, i, depth+1);
			}
		}
	}
}
