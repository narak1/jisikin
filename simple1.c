#include<stdio.h>
#include<stdlib.h>
   
#include<stdio.h>
#include<stdlib.h>
 
int main(void)
{
double arr[5][5],ary[5][5],hap,gop,cha;
int i,k;
double ten=10.00;
 
for(i=0;i<5;i++)
{
for(k=0;k<5;k++)
{
arr[i][k]=(double)(rand()%10000)/1000;
	printf("%6.3lf ", arr[i][k]);
}
puts("");
}

}

