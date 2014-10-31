#include <iostream>
#include <cmath>
using namespace std;

class CPoint
{
	double m_x, m_y;
public:
	CPoint() : m_x(0.0), m_y(0.0) { ; };
	void GetInput();
	void Show() { cout << "(" << m_x << "," << m_y << ")"; };
	void MoveX(double x) { m_x += x; };
	void MoveY(double y) { m_y += y; };
	double Distance(CPoint *other);
 friend ostream& operator <<(ostream& os, const CPoint& pt);
};

void CPoint::GetInput()
{
	double x, y;
	cout << "Input x & y : ";
	cin >> x >> y;
	m_x = x;
	m_y = y;
}

double CPoint::Distance(CPoint *other)
{
	double dx = this->m_x - other->m_x;
	double dy = this->m_y - other->m_y;
	return sqrt(dx*dx + dy*dy);
}

ostream& operator <<(ostream& os, const CPoint& pt)
{
	os << "(" << pt.m_x << "," << pt.m_y << ")";
	return os;
}

int main()
{
	CPoint *p1, p2;
	p1 = new CPoint();

	p1->GetInput();
	cout << "P1 : " << *p1 << endl;
	
	p2.GetInput();
	cout << "P2 : " << p2 << endl;

	p2.MoveX(1.0);
	cout << "Moved P2 : " << p2 << endl;
	
	p1->MoveY(-0.5);
	cout << "Moved P1 : " << *p1 << endl;

	cout << "Distance: " << p1->Distance(&p2) << endl;
}
