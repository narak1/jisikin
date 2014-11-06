#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Point
{
	double x, y;
public:
	Point(double x1=0, double y1=0) : x(x1), y(y1) { ; };
	Point(const Point& p) : x(p.x), y(p.y) { ; };
	double getX() const { return x; };
	double getY() const { return y; };
	double cal_distance(const Point& t) const
	{
		return sqrt( (x-t.x)*(x-t.x) + (y-t.y)*(y-t.y) );
	};
	friend ostream& operator<<(ostream& os, const Point& pt);
};

ostream& operator<<(ostream& os, const Point& pt)
{
	os << "( " << pt.x << ", " << pt.y << " )";
	return os;
}

class Rectangle
{
	Point c;	// center
	double w, h;	// width, height, non-negative
public:
	Rectangle(double cx=0, double cy=0, double w1=0, double h1=0)
		: c(cx, cy)
	{
		setW(w1);
		setH(h1);
	};
	Rectangle(Point& c1, double w1=0, double h1=0) : c(c1), w(w1), h(h1)
	{
		setW(w1);
		setH(h1);
	};

	void setW(double w) { this->w = w > 0 ? w : 0; };
	void setH(double h) { this->h = h > 0 ? h : 0; };
	double getW() const { return w; };
	double getH() const { return h; };
	Point& getC() { return c; };
	
	double calc_area() const { return w*h; };
	double calc_perimeter() const { return 2*(h+w); };
	friend ostream& operator<<(ostream& os, const Rectangle& rect);
};

ostream& operator<<(ostream& os, const Rectangle& rect)
{
	os << rect.c << ", w = " << rect.w << ", h = " << rect.h;
	return os;
}

class Circle
{
	Point c;
	double r;	// radius
public:
	Circle(double cx=0, double cy=0, double r1=0) : c(cx, cy), r(r1) { ; };
	Circle(const Point& p1, double r1=0) : c(p1), r(r1) { ; };
	
	void setR(double R) { this->r = r > 0 ? r : 0; };
	Point& getC() { return c; };
	
	double calc_area() const { return M_PI*r*r; };
	double calc_perimeter() const { return 2*M_PI*r; };
	friend ostream& operator<<(ostream& os, const Circle& cc);
};

ostream& operator<<(ostream& os, const Circle& cc)
{
	os << cc.c << ", r = " << cc.r;
	return os;
}

//======================

void print_info(const char* mesg, const Rectangle& rect)
{
	cout << mesg << rect << endl;
	if( rect.getW() == rect.getH() ) {
		cout << "This is a square." << endl;
	}
	else {
		cout << "This is NOT a square." << endl;
	}
	cout << "Area = " << rect.calc_area() << endl;
	cout << "Perimeter = " << rect.calc_perimeter() << endl;
}

int main()
{
	Rectangle rec0(-2, -1.5, -1.5, -1.5);
	cout << "RECTANGLE 0 " << rec0 << endl;
	cout << endl;
	
	Rectangle rec1(2.5, 0, 2.5, 2);
	print_info("RECTANGLE 1 ", rec1);
	cout << endl;
	
	double distance = rec1.getC().cal_distance(rec0.getC());
	cout << "distance between centers of rectangles : " << distance << endl;
	
	Circle c1(rec1.getC(), distance);
	cout << "CIRCLE " << c1 << endl;
	cout << "Area = " << c1.calc_area() << endl;
	cout << "Perimeter = " << c1.calc_perimeter() << endl;
	cout << endl;
	
	Rectangle rec2(c1.getC(), distance, distance);
	print_info("RECTANGLE 2 ", rec2);
	system("pause");
}
