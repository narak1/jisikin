#include <stdio.h>
#include <math.h>
double quad_eqn(double a,double b,double c);
int main()
{ 
 double a,b,c,d;
  printf("2차방정식의 계수를 입력하시오\n");
  printf("a: ");
  scanf("%lf", &a);
  printf("b: ");
  scanf("%lf", &b);
  printf("c: ");
  scanf("%lf", &c);
  d = quad_eqn(a,b,c) ;
  if(d==0) { //판별식이 0이면 근이 하나이므로
  printf("x= %lf\n", (-b)/(2*a) ); //한개 출력
 }
  if( d>0 ) { // 이 경우에는  근이 두개
  printf("근은 %lf, %lf입니다.\n", ((-b)+sqrt(d))/(2*a), ((-b)-sqrt(d))/(2*a)); // 두개 각각 출력
   }
  if( d<0 ) { // 근이 없을땐 이렇게
  printf("실근이 없습니다.\n");
 }
  return 0;
}
double quad_eqn(double a, double b, double c)
{
  double result;
  result =b*b-4*a*c;
  if(a==0) {
    printf("ERROR!!\n"); // 만약 a가 0이라면 이차방정식이 아님, 에러출력
    return(-1);
   }
 return result;
}
 
