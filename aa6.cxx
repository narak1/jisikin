#include <iostream>
#include <cmath>
using namespace std;
class point
{
private:
 int x;
 int y;
public:
 point(int a,int b):x(a),y(b){};
 point(point &p) { x=p.x, y=p.y; };
 void setpoint(int x1,int y1) { x=x1, y=y1; };
 void setpoint(point &p) { x=p.x, y=p.y; };
 int getx() { return x; };
 int gety() { return y; };
 void print() { }
};

class circle
{
private:
 point xy;
 int radius;
public:
 circle(point a, int r) : xy(a), radius(r) { ; };
 void setcircle(point p, int r) { xy.setpoint(p); radius = r; };
 double area() { return M_PI * radius * radius; };
 double diameter() { return 2.0 * radius; };
 int getradius() { return radius; };
 bool intersection(circle*, circle*);
 double distancebetweencenter(circle*,circle*);
};

bool circle::intersection(circle *c1, circle *c2)
{
	return c1->radius + c2->radius >= c1->distancebetweencenter(c1, c2);
}
double circle::distancebetweencenter(circle *a, circle *b)
{
 int x0 = a->xy.getx(); int y0 = a->xy.gety();
 int x1 = b->xy.getx(); int y1 = b->xy.gety();
 return sqrt((double)((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1)));
}
int main()
{
 point a(9,7);
 point b(8,8);
 
 circle cc(b,0);
 circle *c1=new circle(a,3);
 circle *c2=new circle(b,2);
 cout<<"Point 1 X Y : "<<a.getx()<<","<<a.gety()<<endl;
 cout<<"Point 2 X Y : "<<b.gety()<<","<<b.gety()<<endl<<endl;
 cout<<"Radius Circle 1 : "<<c1->getradius()<<endl;
 cout<<"Radius Circle 2 : "<<c2->getradius()<<endl;
 cout<<"The area of circle 1 : "<<c1->area()<<endl;
 cout<<"The area of circle 2 : "<<c2->area()<<endl<<endl;
 cout<<"Distance between centers of two circles : "<<cc.distancebetweencenter(c1,c2)<<endl;
 cout<<"Does two circles intersect yes or no? " << cc.intersection(c1,c2) << endl;
}
