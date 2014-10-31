#include <cstdio>
#include <ctime>
#include <cstdlib>

const int nodenum = 100;

int main(void)
{
 int i,x,y;
 int arr1[nodenum][2];    //배열  세로 * 가로
 
 srand((int)time(NULL)); // 현재 시간을 이용해서 씨드 설정
 for (i=0;i<nodenum;i++)
 {
  x= rand()%101;
  y= rand()%101;

  arr1[i][0]=x;
  arr1[i][1]=y;
 }
 
 char fname[32];
 sprintf(fname, "node%03d.dat", nodenum);
 FILE *fp = fopen(fname, "w");
 if( fp == NULL ) {
 	perror(fname);
 	return 0;
 }
 
 for( i=0 ; i<nodenum ; i++ )
 {
 	fprintf(fp, "%2d %2d %2d\n", i+1, arr1[i][0], arr1[i][1]);
 }
 
 fclose(fp);
 
 //printf("i의 값은: %d \n", arr1[99][0]);
 //printf("x의 값은: %d \n", arr1[99][1]);
 //printf("y의 값은: %d \n", arr1[99][2]);
 getchar();
}
