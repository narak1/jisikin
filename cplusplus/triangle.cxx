#include <iostream>
#include <cstdio>
#include <cmath>
//클래스 2개더 circle(center,radios(반지름))->setpodouble,getArea(),getCircumferemce(),생성자 만듦
//생각만해보기 -> 원, 삼각형, 사각형 일반적인 다각형일때(선이몇개일지모를때) 어떻게 할지
/*
트라이앵글멤버펑션 2개 채우는것
랙탱글2개채우는것
서클 클래스만들고
다각형 클래스만들기생각
*/
struct Triangle
{
private:
 double x1, y1,
  x2, y2,
  x3, y3;
public:   //컨스트럭터는리턴타입이없다,클래스이름과같다
 Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
 {
  this->x1 = x1;
  this->y1 = y1;
  (*this).x2 = x2;
  (*this).y2 = y2;
  this->x3 = x3;
  this->y3 = y3;
 }
 //컨스트럭터를제외한것은리턴타입이있어야한다
 void setPoint(double x1, double y1, double x2, double y2, double x3, double y3)
 {
  this->x1 = x1;
  this->y1 = y1;
  this->x2 = x2;
  this->y2 = y2;
  this->x3 = x3;
  this->y3 = y3;
 }
 double getArea(); //면적 꼭짓점2개로
 double getCircumference(); //둘레
};
//double getArea() { } 이렇게 쓰면 오류
//클래스밖에서 사용될때 어떤클래스의 멤버function이란것을명시해줘야한다
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
 Triangle A(1,2,3,4,5,6);	//  일직선임 
 double area = A.getArea();
 double circumference = A.getCircumference();
 printf("area = %lf\n",area);
 printf("circumference = %lf",circumference);
 return 0;
}
 
