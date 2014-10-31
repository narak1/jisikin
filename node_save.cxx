#include <cstdio>
#include <ctime>
#include <cstdlib>

const int nodenum = 100;

int main(void)
{
 int i,x,y;
 int arr1[nodenum][2];    //�迭  ���� * ����
 
 srand((int)time(NULL)); // ���� �ð��� �̿��ؼ� ���� ����
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
 
 //printf("i�� ����: %d \n", arr1[99][0]);
 //printf("x�� ����: %d \n", arr1[99][1]);
 //printf("y�� ����: %d \n", arr1[99][2]);
 getchar();
}
