#include<stdio.h>

//함수에서의 구조체
struct complex
{
 double real;//실수
 double img;//허수
};
typedef struct complex complex;
complex paircomplex1(complex com);
void printcomplex(complex com);//com구조체변수
void paircomplex2(complex *com);//com 구조체포인터변수
int main(void)
{
 complex comp = { 3.4, 4.8 };
 complex pcomp;//구조체 변수설정pcomp
 printcomplex(comp);//함수호출
 pcomp = paircomplex1(comp);
 printcomplex(pcomp);
 paircomplex2(&pcomp);
 printcomplex(pcomp);
return 0;
}
void printcomplex(complex com)
{
 printf("복소수=%lf+%lfi \n", com.real, com.img);
}
complex paircomplex1(complex com)
{
 com.img = -com.img;
 return com;
}
void printcomplex2(complex *com)
{
 printf("복소수=%lf+%lfi \n", com->real, com->img);
}
void paircomplex2(complex *com)
{
 com->img = -com->img;
}
