/*Ex09_01.c */

#include<stdio.h>

#include<string.h>

struct student {
	 char name[20];
	 int korean ,english ,math;
	 double average;
};


int main (void)
{

struct student s1;
struct student s2= {"�ڳ���",90,78,86};

s1.korean=100;
s1.english=100;
s1.math= 100;
strcpy(s1.name,"����");
s1.average = (double)(s1.korean+s1.english+s1.math) / 3;


s2.average = (double)(s2.korean+s2.english+s2.math) / 3;


printf ("%s: 5%.2f\n",s1.name,s1.average);
printf ("%s: 5%.2f\n",s2.name,s2.average);
return 0;

}
