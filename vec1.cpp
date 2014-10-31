#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#define PHI M_PI // 3.14159
using namespace std;
const double Deg_to_Rad=PHI/180;
const double Rad_to_Deg=180/PHI;
class Vector
{
 double x;
 double y;
 double mag;
 double ang;
 char mode;

 void set_ang();
 void set_mag();
 void set_x();
 void set_y();
public:
	Vector();
    Vector(double n1,double n2,char _mode='r');
    Vector(const Vector &v);
    ~Vector() {  };
    void set(double n1,double n2,char _mode='r');
    double get_x()const;
    double get_y()const;
    double get_mag()const;
    double get_angle()const;
    void display_r()const;
    void display_p()const;
    Vector operator +(const Vector &b);
    Vector operator -(const Vector &b);
    friend ostream &operator<<(ostream &os,const Vector &v);
};

Vector::Vector()
{
 x=0,y=0,mag=0,ang=0;
 mode='r';
}
Vector::Vector(double n1,double n2,char _mode)
{
 x=n1;
 y=n2;
 set_mag();
 set_ang();
 set(n1,n2,_mode);
 
 mode=_mode;
}
void Vector::set(double n1,double n2,char _mode)
{
 if(_mode=='p'){
 mag=n1;
 ang=n2;
 x=mag*cos(ang*Deg_to_Rad);
 y=mag*sin(ang*Deg_to_Rad);
 }
}
 
void Vector::set_ang()
{
 ang=atan2(y,x)*Rad_to_Deg;

}
void Vector::set_mag()
{
 mag=sqrt(x*x+y*y);
}
double Vector::get_x()const{
 
 return x;
}
double Vector::get_y()const{
 return y;
}
double Vector::get_mag()const{
 
 return mag;
}
double Vector::get_angle()const{
 return ang;
}
void Vector::display_r()const{
 
 cout<<"x:"<<x<<"  y:"<<y<<endl;
 
}
void Vector::display_p()const{
 
 cout<<"magnitude: "<<mag<<",angle= "<<ang<<endl;
}
ostream &operator<<(ostream &os,const Vector &v){
 if(v.mode=='r')
 os<<"<x,y>  <"<<v.x<<", "<<v.y<<">"<<endl;
 else if(v.mode=='p')
  cout<<"<magnitude,angle> = <"<<v.mag<<", "<<v.ang<<">" <<endl;
 return os;
}
Vector Vector::operator+(const Vector &b)
{
Vector temp;
temp.x=b.x+this->x;
temp.y=b.y+this->y;
return temp;
}
Vector Vector::operator-(const Vector &b)
{
Vector temp;
temp.x=this->x-b.x;
temp.y=this->y - b.y;
return temp;
}

int main()
{
 cout.setf(ios::fixed,ios::floatfield);
 Vector a1(3,4,'r');
 Vector a2(5,53.13,'p');
 
 a1.display_p();
 a2.display_r();
 cout<< "a1=" << a1 << "a2=" << a2;
Vector a3=a1+a2;
 cout << "Sum=" << a3;
}
 
