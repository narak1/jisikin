#include<stdio.h>

//�Լ������� ����ü
struct complex
{
 double real;//�Ǽ�
 double img;//���
};
typedef struct complex complex;
complex paircomplex1(complex com);
void printcomplex(complex com);//com����ü����
void paircomplex2(complex *com);//com ����ü�����ͺ���
int main(void)
{
 complex comp = { 3.4, 4.8 };
 complex pcomp;//����ü ��������pcomp
 printcomplex(comp);//�Լ�ȣ��
 pcomp = paircomplex1(comp);
 printcomplex(pcomp);
 paircomplex2(&pcomp);
 printcomplex(pcomp);
return 0;
}
void printcomplex(complex com)
{
 printf("���Ҽ�=%lf+%lfi \n", com.real, com.img);
}
complex paircomplex1(complex com)
{
 com.img = -com.img;
 return com;
}
void printcomplex2(complex *com)
{
 printf("���Ҽ�=%lf+%lfi \n", com->real, com->img);
}
void paircomplex2(complex *com)
{
 com->img = -com->img;
}
