#include <iostream>
#include <cstdio>
#include <cmath>
//Ŭ���� 2���� circle(center,radios(������))->setpodouble,getArea(),getCircumferemce(),������ ����
//�������غ��� -> ��, �ﰢ��, �簢�� �Ϲ����� �ٰ����϶�(���̸�����𸦶�) ��� ����
/*
Ʈ���̾ޱ۸����� 2�� ä��°�
���ʱ�2��ä��°�
��Ŭ Ŭ���������
�ٰ��� Ŭ������������
*/
struct Triangle
{
private:
 double x1, y1,
  x2, y2,
  x3, y3;
public:   //����Ʈ���ʹ¸���Ÿ���̾���,Ŭ�����̸�������
 Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
 {
  this->x1 = x1;
  this->y1 = y1;
  (*this).x2 = x2;
  (*this).y2 = y2;
  this->x3 = x3;
  this->y3 = y3;
 }
 //����Ʈ���͸������Ѱ�������Ÿ�����־���Ѵ�
 void setPoint(double x1, double y1, double x2, double y2, double x3, double y3)
 {
  this->x1 = x1;
  this->y1 = y1;
  this->x2 = x2;
  this->y2 = y2;
  this->x3 = x3;
  this->y3 = y3;
 }
 double getArea(); //���� ������2����
 double getCircumference(); //�ѷ�
};
//double getArea() { } �̷��� ���� ����
//Ŭ�����ۿ��� ���ɶ� �Ŭ������ ���function�̶��������������Ѵ�
double Triangle::getArea()
{
 double s = ((x1-x2)*y3)+((x2-x3)*y1)+((x3-x1)*y2);
 s = s*s;
 s = sqrt(s);
 s = s/2;
 return (double)s;
	double v1_x = x1 - x2;
	double v1_y = y1 - y2;
	double v2_x = x1 - x3;
	double v2_y = y1 - y3;
	double s = fabs(v1_x * v2_y - v2_x * v1_y) / 2.0;
	return s;
}
double Triangle::getCircumference()
{
 double length1=0,
   length2=0,
   length3=0;
 double temp1 = 0,temp2 = 0;
 temp1 = (x3-x2)*(x3-x2);
 temp2 = (y3-y2)*(y3-y2);
 temp1 = temp1+temp2;
 length1 = sqrt(temp1);
 
 temp1 = (x2-x1)*(x2-x1);
 temp2 = (y2-y1)*(y2-y1);
 temp1 = temp1+temp2;
 length2 = sqrt(temp1);

 temp1 = (x1-x3)*(x1-x3);
 temp2 = (y1-y3)*(y1-y3);
 temp1 = temp1+temp2;
 length3 = sqrt(temp1);
 temp1 = length1 + length2 + length3;
  
 return (double)temp1;
}
int main(void){
 Triangle A(1,2,3,4,5,6);	//  �������� 
 double area = A.getArea();
 double circumference = A.getCircumference();
 printf("area = %lf\n",area);
 printf("circumference = %lf",circumference);
 return 0;
}
 
