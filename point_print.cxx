#include <iostream>
using namespace std;

class CPoint
{
	double m_x, m_y;
public:
	CPoint() : m_x(0.0), m_y(0.0) {	};
	CPoint(double x, double y) : m_x(x), m_y(y) { };
	CPoint delta(CPoint *p) const;
friend ostream& operator<<(ostream &os, const CPoint &p);
};

CPoint CPoint::delta(CPoint *p) const
{
	CPoint p2;
	p2.m_x = this->m_x - p->m_x;
	p2.m_y = this->m_y - p->m_y;
	return p2;
}

ostream& operator<<(ostream &os, const CPoint &p)
{
	os << p.m_x << "  " << p.m_y;
	return os;
}

main()
{
	double x, y;
	CPoint *p1, *p2;

	cout << "Input one point : ";
	cin >> x >> y;
	p1 = new CPoint(x, y);

	cout << "Input another point : ";
	cin >> x >> y;
	p2 = new CPoint(x, y);
	
	cout << "P: " << p1->delta(p2) << endl;
}
