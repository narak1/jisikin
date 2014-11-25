#include <stdio.h>
#include <math.h>
struct complex
{
 double real;//실수
 double img;//허수
};
typedef struct complex complex;//자료형 재정의
enum check{plus=10, minus=20, multi=30, absolute=40}ch;//사칙연산 열거형 정의
complex _plus(complex complex_input1, complex complex_input2);//더하기
complex _minus(complex complex_input1, complex complex_input2);//빼기
complex _multi(complex complex_input1, complex complex_input2);//곱하기
double _absolute(complex complex_input1);//절대값
void print_c(complex c);//출력
/* 메인함수 선언 */
int main(void)
{

 complex complex_input1, complex_input2;//두 복소수
 complex complex_result;//사칙연산 결과값
 double c;

 printf("첫번째 복소수(a+bi)를 입력하세요.\na=");
 scanf("%lf", &complex_input1.real);
 printf("b=");
 scanf("%lf", &complex_input1.img);
 printf("두번째 복소수(a+bi)를 입력하세요.\na=");
 scanf("%lf", &complex_input2.real);
 printf("b=");
 scanf("%lf", &complex_input2.img);
// print_c(c);
 printf("계산할 연산을 입력하시오.(plus=10,minus=20,multi=30,absolute=40)\n");
 scanf("%d", &ch);

 switch(ch)
 {
  case plus:
   complex_result = _plus(complex_input1, complex_input2);
   printf("결과: %.1lf + %.1lfi\n", complex_result.real, complex_result.img);
   break;
  case minus:
   complex_result = _minus(complex_input1, complex_input2);
   printf("결과: %.1lf + %.1lfi\n", complex_result.real, complex_result.img);
   break;
  case multi:
   complex_result = _multi(complex_input1, complex_input2);
   printf("결과: %.1lf + %.1lfi\n", complex_result.real, complex_result.img);
   break;
  case absolute:
   c = _absolute(complex_input1);
   printf("결과 : |%.1lf + %.1lf| = %.1lf\n", complex_input1.real, complex_input1.img, c);
   break;
 }
 return 0;

}
complex _plus(complex complex_input1, complex complex_input2)//더하기
{
 complex complex_result;
 complex_result.real = complex_input1.real + complex_input2.real;
 complex_result.img = complex_input1.img + complex_input2.img;
 return complex_result;
}
complex _minus(complex complex_input1, complex complex_input2)//빼기
{
 complex complex_result;
 complex_result.real = complex_input1.real - complex_input2.real;
 complex_result.img = complex_input1.img - complex_input2.img;
 return complex_result;
}
complex _multi(complex complex_input1, complex complex_input2)//곱하기
{
 complex complex_result;
 complex_result.real = (complex_input1.real * complex_input2.real) - (complex_input1.img * complex_input2.img);
 complex_result.img = (complex_input1.real * complex_input2.img) + (complex_input1.img * complex_input2.real);
 return complex_result;
}
double _absolute(complex complex_input1)//절대값
{

 return sqrt(complex_input1.real * complex_input1.real + complex_input1.img * complex_input1.img);
}
void print_c(complex c) //출력
{
    printf("(%.1lf, %.1lf)", c.real, c.img);
}
