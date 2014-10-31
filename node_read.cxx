#include <cstdio>

const int nodenum = 100;

int main(void)
{
 int i,x,y;
 int arr1[nodenum][2];    //배열  세로 * 가로
 
 char fname[32];
 sprintf(fname, "node%03d.dat", nodenum);
 FILE *fp = fopen(fname, "r");
 if( fp == NULL ) {
 	perror(fname);
 	return 0;
 }
 
 for( i=0 ; i<nodenum ; i++ )
 {
 	fscanf(fp, "%*d%d%d", &arr1[i][0], &arr1[i][1]);
 }
 
 fclose(fp);

	for( i=0 ; i<nodenum ; i++ )
	{
		printf("%2d : %2d %2d\n", i+1, arr1[i][0], arr1[i][1]);
	}

 getchar();
}
