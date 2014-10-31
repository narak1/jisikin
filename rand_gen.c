#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int ary[4][6]={0};
	int chk[4*6]={0,};
	int i,j,k;
	int v;

	srand(time(NULL));

	for(i=0;i<4;i++)
	{
		for(j=0;j<6;j++)
		{
			v = rand() % 24;
			if( chk[v] < 2 )
				ary[i][j] = v + 1;
			else
				--j;	// retry
			++chk[v];	// check value increase
		}
	}

	puts("random :");
	for(i=0;i<4;i++){
		for(j=0;j<6;j++){
			printf("%5d",ary[i][j]);
		}
		puts("");
	}

	puts("check:");
	for( i=0 ; i<24 ; i++ ) {
		if( chk[i] )
			printf("%5d: %d\n", i+1, chk[i]);
	}

	system("PAUSE"); 
	return 0;
}
