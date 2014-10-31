#include <iostream>
#include <cmath>
using namespace std;

const double mile_to_meter = 1609.34;
const double centi = 0.01;

class Distance
{
private:
 int miles;
 int meter;			// 1 mile = about 1609.34 metres
 double centimeter;	// 1 meter = 100 centimeter
public:
	Distance() : miles(0), meter(0), centimeter(0.0) { ; };
 Distance(int mi,int m, double cm) : miles(mi), meter(m), centimeter(cm) { ; };

 void setDist(int mi,int m, double cm) { miles=mi, meter=m, centimeter=cm; };
 void setMiles(int mi) { miles=mi; };
 void setMeter(int m) { meter=m; };
 void setCentimeter(double cm) { centimeter=cm; };
 int getMiles() { return miles; };
 int getMeter() { return meter; };
 double getCentimeter() { return centimeter; };
 
 double sum_centimeter() const { return ((miles * 1609) + meter) * 100 + centimeter; };

friend Distance operator+(const Distance& a, const Distance& b);
friend Distance operator-(const Distance& a, const Distance& b);

	bool operator==(const Distance& b) const;
	bool operator>(const Distance& b) const;
	bool operator<(const Distance& b) const { return ! (*this > b); };

friend ostream& operator <<(ostream& os, const Distance& d);

	int tomile() const;
	int tometer() const;
	int tocentimeter() const;
friend Distance tomile(const Distance& a);
friend Distance tometer(const Distance& a);
friend Distance tocentimeter(const Distance& a);
};

Distance operator+(const Distance& a, const Distance& b)
{
	Distance c;
	c.miles = a.miles + b.miles;
	c.meter = a.meter + b.meter;
	c.centimeter = a.centimeter + b.centimeter;
	if( c.centimeter >= 100.0 ) {
		c.centimeter -= 100.0;
		++c.meter;
	}
	return c;
}

Distance operator-(const Distance& a, const Distance& b)
{
	Distance c;
	c.miles = a.miles - b.miles;
	c.meter = a.meter - b.meter;
	c.centimeter = a.centimeter - b.centimeter;
	return c;
}

bool Distance::operator==(const Distance& b) const
{
	return (this->miles==b.miles && this->meter==b.meter && this->centimeter==b.centimeter);
}

bool Distance::operator>(const Distance& b) const
{
	return (this->sum_centimeter() > b.sum_centimeter());
}

ostream& operator <<(ostream& os, const Distance& d)
{
 cout << d.miles << " miles " << d.meter << " meters " << d.centimeter << " centimeters";
 return os;
}

int Distance::tomile() const
{
	return this->miles + round((this->meter + this->centimeter * centi) / mile_to_meter);
}

int Distance::tometer() const
{
	return round(this->miles * mile_to_meter) + this->meter + round(this->centimeter * centi);
}

int Distance::tocentimeter() const
{
	return round((this->miles * mile_to_meter + this->meter) / centi) + this->centimeter;
}

Distance tomile(const Distance& a)
{
	Distance c;
	c.miles = a.tomile();
	return c;
}

Distance tometer(const Distance& a)
{
	Distance c;
	c.meter = a.tometer();
	return c;
}
Distance tocentimeter(const Distance& a)
{
	Distance c;
	c.centimeter = a.tocentimeter();
	return c;
}

int main()
{
	Distance a(1,2,4);
	Distance b(1,1,4);
	string boolstr[] = { "FALSE", "TURE" };
	
	cout << "DISTANCE CALCULATOR" << endl << endl;
	cout << "Given :" << endl;
	cout << "  Distance a(1,2,4)" << endl;
	cout << "  Distance b(1,1,4)" << endl;
	cout << endl;
	cout << "The sum of distance is        : " << a+b << endl;
	cout << "The difference of distance is : " << a-b << endl;
	cout << endl;
	cout << "CONTITIONAL OPERATORS" << endl;
	cout << endl;
	cout << "The statement distance a==b is : " << boolstr[a==b] << endl;
	cout << "The statement distance a>b is  : " << boolstr[a>b] << endl;
	cout << "The statement distance a<b is  : " << boolstr[a<b] << endl;
	cout << endl;
	
	cout << "to miles       : " << a.tomile() << endl;
	cout << "to meters      : " << a.tometer() << endl;
	cout << "to centimeters : " << a.tocentimeter() << endl;
	cout << "tocentimeters  : " << tocentimeter(a) << endl;
}
