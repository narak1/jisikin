#include <stdio.h>
#include <math.h>
double quad_eqn(double a,double b,double c);
int main()
{ 
 double a,b,c,d;
  printf("2���������� ����� �Է��Ͻÿ�\n");
  printf("a: ");
  scanf("%lf", &a);
  printf("b: ");
  scanf("%lf", &b);
  printf("c: ");
  scanf("%lf", &c);
  d = quad_eqn(a,b,c) ;
  if(d==0) { //�Ǻ����� 0�̸� ���� �ϳ��̹Ƿ�
  printf("x= %lf\n", (-b)/(2*a) ); //�Ѱ� ���
 }
  if( d>0 ) { // �� ��쿡��  ���� �ΰ�
  printf("���� %lf, %lf�Դϴ�.\n", ((-b)+sqrt(d))/(2*a), ((-b)-sqrt(d))/(2*a)); // �ΰ� ���� ���
   }
  if( d<0 ) { // ���� ������ �̷���
  printf("�Ǳ��� �����ϴ�.\n");
 }
  return 0;
}
double quad_eqn(double a, double b, double c)
{
  double result;
  result =b*b-4*a*c;
  if(a==0) {
    printf("ERROR!!\n"); // ���� a�� 0�̶�� ������������ �ƴ�, �������
    return(-1);
   }
 return result;
}
 
