#include <iostream>
using namespace std;
class Date { // 기본 클래스
 int m, d, y;
public:
 Date() { m = d = y = 0; }
 Date(int month, int day, int year);
 Date(const Date& d1);
 friend int operator <(const Date& d1, const Date& d2);
 friend int operator >(const Date& d1, const Date& d2);
 friend int operator ==(const Date& d1, const Date& d2);
 friend ostream& operator <<(ostream& os, const Date& d);
 friend Date operator+(const Date& d1, const Date& d2);
};
Date::Date(int month, int day, int year)
{
 m = month; d = day; y = year;
}
Date::Date(const Date& d1)
{
 *this = d1;
}
int operator <(const Date& d1, const Date& d2)
{
 if (d1.y < d2.y)
  return 1;
 if (d1.y == d2.y && d1.m < d2.m)
  return 1;
 if (d1.y == d2.y && d1.m == d2.m && d1.d <d2.d)
  return 1;
 return 0;
}
int operator >(const Date& d1, const Date& d2)
{
 if (d1.y > d2.y)
  return 1;
 if (d1.y == d2.y && d1.m > d2.m)
  return 1;
 if (d1.y == d2.y && d1.m == d2.m && d1.d > d2.d)
  return 1;
 return 0;
}
int operator ==(const Date& d1, const Date& d2)
{
 return (d1.y == d2.y && d1.m == d2.m && d1.d == d2.d);
}

ostream& operator <<(ostream& os, const Date& d)
{
 cout << d.m << "-" << d.d << "-" << d.y;
 return os;
}
Date operator+(const Date& d1, const Date& d2)
{
 Date d;
 d.y=d1.y+d2.y;
 d.m=d1.m+d2.m;
 d.d=d1.d+d2.d;
 return d;
}
class TimeDate : public Date { // 파생 클래스
 int hr, min, sec;
public:
 TimeDate() { hr = min = sec = 0; }
 TimeDate(int month, int day, int year,
  int hour, int minute, int second);
 friend int operator ==(TimeDate& d1, TimeDate& d2);
 friend int operator <(TimeDate& d1, TimeDate& d2);
 friend ostream& operator <<(ostream& os, TimeDate& d);
};
TimeDate::TimeDate(int month, int day, int year, int hour, int minute,
      int second) : Date(month, day, year)
{
 hr =hour; min = minute; sec =second;
}

int operator ==(TimeDate& t1, TimeDate& t2)
{
	if (Date(t1) == Date(t2))
		return (t1.hr == t2.hr && t1.min == t2.min && t1.sec == t2.sec);
	else
		return 0;
}

int operator <(TimeDate& t1, TimeDate& t2)
{
 if (Date(t1) < Date(t2))
  return 1;
 else if (Date(t2) < Date(t1))
  return 0;
 if (t1.hr < t2.hr)
  return 1;
 if (t1.hr == t2.hr && t1.min < t2.min)
  return 1;
 if (t1.hr == t2.hr && t1.min == t2.min && t1.sec < t2.sec)
  return 1;
 return 0;
}

ostream& operator <<(ostream& os, TimeDate& t)
{
 cout << Date(t) << " ";
 cout << t.hr << ":" << t.min << ":" << t.sec << endl;
 return os;
}

class CPreciseTimeDate : public TimeDate
{
	double under_sec;
public:
	CPreciseTimeDate() : under_sec(0.0) { ; };
	CPreciseTimeDate(int month, int day, int year,
					  int hour, int minute, int second,
					  double under_second)
	 : TimeDate(month, day, year, hour, minute, second), under_sec(under_second) { ; };
	 
int operator ==(const CPreciseTimeDate& d2) const;
int operator >(const CPreciseTimeDate& d2) const;

 friend ostream& operator <<(ostream& os, CPreciseTimeDate& d);
};

int CPreciseTimeDate::operator==(const CPreciseTimeDate& d2) const
{
	if( TimeDate(*this) == TimeDate(d2) )
		return this->under_sec == d2.under_sec;
	else
		return 0;
}

int CPreciseTimeDate::operator>(const CPreciseTimeDate& d2) const
{
	if( TimeDate(*this) == TimeDate(d2) )
		return this->under_sec > d2.under_sec;
	else
		return TimeDate(*this) > TimeDate(d2);
}

ostream& operator <<(ostream& os, CPreciseTimeDate& t)
{
 cout << TimeDate(t) << "." << t.under_sec << endl;
 return os;
}

int main()
{
 Date today(5, 5, 2001), yesterday(5, 4, 2001);
 TimeDate one(5, 6, 2001, 12, 11, 11), two(7, 8, 2001, 10, 10, 36);
 if (today < yesterday) cout << today;
 else cout << yesterday;
 cout << endl;
 if (one < two) cout << one;
 else cout << two;
}
