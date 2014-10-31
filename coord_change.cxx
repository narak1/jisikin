#define _USE_MATH_DEFINES


#include <iostream> 
#include <iomanip> 
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std; 
class Point 
{ 
private: 
   double x, y;
public: 
   Point() : x(0.0), y(0.0) { count++; } 
   Point(double xx, double yy) : x(xx), y(yy) { count++; } 
   Point(const Point& p) : x(p.x), y(p.y) { count++; } 
   ~Point() { --count; }

   double getX() const { return x; } 
   double getY() const { return y; }
   void setX(double xx) { x = xx; } 
   void setY(double yy) { y = yy; }

private: 
   double r, a; 
   static int count;
public:
	static int getCount() { return count; } 
   void setXY(double xx, double yy) { x = xx; y = yy; } 
   void setR(double rr) { r = rr; }
   void setA(double aa)  { a = aa; }

   double getR() const { return r; }
   double getradA() const { return a;  }
   double getdegA() const { return a*180.0/M_PI; }
	Point& operator=(Point& p)
	{
		this->x = p.x, this->y = p.y, this->r = p.r, this->a = p.a;
		return p;
	}
   
   void change()
   {
	  this->r = sqrt((x*x)+(y*y));
	  this->a = atan2(y, x);
   }

   void rechange()
   {
	  x = r * cos(a);
	  y = r * sin(a);
   }

   void print(const char* s) const
   { 
      cout << fixed << setprecision(4); 
      cout << s << setw(10) << x << setw(10) << y; 
   } 

   void printRA(const char* s) const
   { 
      cout << fixed << setprecision(4); 
      cout << s << setw(10) << r << setw(10) << a; 
   } 
}; 

int Point::count = 0;


int main()  
{
	const int max_pts = 10;
	Point *pts;
	double x, y;
	
	Point p1, p2;
	cout << "count = " << Point::getCount() << endl;
 	
	srand(time(NULL));
	
	pts = new Point[max_pts];
	for( int i=0 ; i<max_pts ; i++ )
	{
		x = (rand() % 20001) / 100.0 - 100.0;
		y = (rand() % 20001) / 100.0 - 100.0;
		pts[i].setXY(x, y);
		pts[i].change();
	}
	
	cout << "count after allocation = " << Point::getCount() << endl;	
	cout << "no        x         y    length    radian    degree" << endl;
	for( int i=0 ; i<max_pts ; i++ ) {
		Point *p = &pts[i];
		cout << i;
		p->print("");
		p->printRA("");
		cout << fixed << setprecision(4) << setw(10) << p->getdegA() << endl;
	}

	// find max length point
	double max_len = 0.0;
	for( int i=0 ; i<max_pts ; i++ ) {
		if( max_len < pts[i].getR() ) {
			max_len = pts[i].getR();
			p1 = pts[i];
		}
	}
	
	delete [] pts;
	
	cout << "count after release = " << Point::getCount() << endl;
	cout << "longest point" << endl;
	cout << " ";
	p1.print("");
	p1.printRA("");
	cout << fixed << setprecision(4) << setw(10) << p1.getdegA() << endl;	
}

