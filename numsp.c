#include <stdio.h>
int main()
{
int array[100];                     
int count;                             
int div_number = 0;
int temp;
int temp_num;

int i = 0;
int j = 0;
int k = 0;

scanf("%d", &div_number);
count = div_number / 2;
for (i = 1; i <= count; i++)
{
printf("= %d + %d\n", i, div_number - i);

array[0] = i;
array[1] = div_number - i;
temp_num = array[1];
for (j = 2; j<array[1] + j - 1; j++)
{
temp = array[1] - 1;
array[j] = 1;
array[1] = temp;
if (array[0] <= array[1])
{
printf("= ");
}
for (k = 0; k <= j; k++)
{
if (array[0] > array[1])
{
continue;
}
if (k < j)
printf("%d + ", array[k]);
if (k == j)
{
printf("%d \n", array[k]);
}
}

}
}
return 0;
}

