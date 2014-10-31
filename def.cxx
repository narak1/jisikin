#include <iostream>
#include <cmath>

using namespace std;
class Polygon {
public:
Polygon (double width, double height, double radius) : m_width (width), m_height(height), m_radius(radius) { };
protected:
double m_width, m_height, m_radius ;
};
class Rectangle: public Polygon {
public:
Rectangle(double width, double height, double radius) : Polygon (width, height, radius) { };
double area () { return m_width * m_height; }
};
class Triangle: public Polygon {
public:
Triangle(double width, double height, double radius) : Polygon (width, height, radius) { };
double area () { return m_width * m_height / 2; }
};
class Circle : public Polygon {
	static const double pi = M_PI;
public:
Circle(double width, double height, double radius) : Polygon (width, height, radius) { };
double area () { return m_radius * m_radius * pi; }
};
int main ()
 {
Rectangle blueRec (10., 10., 0.);
Triangle redTri(10., 10., 0.);
Circle greenCir(0., 0., 10.);
cout << blueRec.area() << endl;
cout << redTri.area() << endl;
cout<< greenCir.area() << endl;
//system("PAUSE");
return 0;
}
