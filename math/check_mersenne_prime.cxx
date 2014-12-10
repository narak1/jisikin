#include <stdio.h>
#include <stdlib.h>
char llt(int p)
{
long long s = 4;
int m = (1<<p)-1;
printf("%10d",m);
for(int i=1; i<=p-2; i++) s=(s*s-2)%m;
if(s==0) return 'P';
else return ' ';
}
int main()
{
int x[10] = {3,5,7,11,13,17,19,23,31};
for(int i=0; i<10; i++) printf("p=%2d %c\n", x[i], llt(x[i]));
system("pause");
return 0;
}
