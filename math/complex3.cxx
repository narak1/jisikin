#include <stdio.h>
#include <math.h>
struct complex
{
 double real;//�Ǽ�
 double img;//���
};
typedef struct complex complex;//�ڷ��� ������
enum check{plus=10, minus=20, multi=30, absolute=40}ch;//��Ģ���� ������ ����
complex _plus(complex complex_input1, complex complex_input2);//���ϱ�
complex _minus(complex complex_input1, complex complex_input2);//����
complex _multi(complex complex_input1, complex complex_input2);//���ϱ�
double _absolute(complex complex_input1);//���밪
void print_c(complex c);//���
/* �����Լ� ���� */
int main(void)
{

 complex complex_input1, complex_input2;//�� ���Ҽ�
 complex complex_result;//��Ģ���� �����
 double c;

 printf("ù��° ���Ҽ�(a+bi)�� �Է��ϼ���.\na=");
 scanf("%lf", &complex_input1.real);
 printf("b=");
 scanf("%lf", &complex_input1.img);
 printf("�ι�° ���Ҽ�(a+bi)�� �Է��ϼ���.\na=");
 scanf("%lf", &complex_input2.real);
 printf("b=");
 scanf("%lf", &complex_input2.img);
// print_c(c);
 printf("����� ������ �Է��Ͻÿ�.(plus=10,minus=20,multi=30,absolute=40)\n");
 scanf("%d", &ch);

 switch(ch)
 {
  case plus:
   complex_result = _plus(complex_input1, complex_input2);
   printf("���: %.1lf + %.1lfi\n", complex_result.real, complex_result.img);
   break;
  case minus:
   complex_result = _minus(complex_input1, complex_input2);
   printf("���: %.1lf + %.1lfi\n", complex_result.real, complex_result.img);
   break;
  case multi:
   complex_result = _multi(complex_input1, complex_input2);
   printf("���: %.1lf + %.1lfi\n", complex_result.real, complex_result.img);
   break;
  case absolute:
   c = _absolute(complex_input1);
   printf("��� : |%.1lf + %.1lf| = %.1lf\n", complex_input1.real, complex_input1.img, c);
   break;
 }
 return 0;

}
complex _plus(complex complex_input1, complex complex_input2)//���ϱ�
{
 complex complex_result;
 complex_result.real = complex_input1.real + complex_input2.real;
 complex_result.img = complex_input1.img + complex_input2.img;
 return complex_result;
}
complex _minus(complex complex_input1, complex complex_input2)//����
{
 complex complex_result;
 complex_result.real = complex_input1.real - complex_input2.real;
 complex_result.img = complex_input1.img - complex_input2.img;
 return complex_result;
}
complex _multi(complex complex_input1, complex complex_input2)//���ϱ�
{
 complex complex_result;
 complex_result.real = (complex_input1.real * complex_input2.real) - (complex_input1.img * complex_input2.img);
 complex_result.img = (complex_input1.real * complex_input2.img) + (complex_input1.img * complex_input2.real);
 return complex_result;
}
double _absolute(complex complex_input1)//���밪
{

 return sqrt(complex_input1.real * complex_input1.real + complex_input1.img * complex_input1.img);
}
void print_c(complex c) //���
{
    printf("(%.1lf, %.1lf)", c.real, c.img);
}
