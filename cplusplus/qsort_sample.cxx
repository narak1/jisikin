#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

class Datas
{
	string name;
	int age;
	double point;
	char sex;
public:
	friend ostream& operator<<(ostream& os, const Datas& dt);
	void set_name(const char *n) { name = n; };
	void set_age(int a) { age = a; };
	void set_point(double p) { point = p; };
	void set_sex(char s) { sex = s; };
	
	int compare(const Datas& d2) const;
	double operator-(const Datas& d2) const { return this->point - d2.point; };
};

ostream& operator<<(ostream& os, const Datas& dt)
{
	os << dt.sex << ", "
		<< setw(5) << left << dt.name.c_str() << ", "
		<< setw(2) << right << dt.age << ", "
		<< setw(6) << right << fixed << setprecision(3) << dt.point;
	return os;
}

int Datas::compare(const Datas& d2) const
{
	if( this->name == d2.name ) {
		return d2.age - this->age;
	}
	else {
		return strcmp(this->name.c_str(), d2.name.c_str());
	}
}
void print_data(const char* mesg, const Datas dt[], int num);

int main()
{
	const int MaxData = 10;
	Datas mdata[MaxData];
	char buf[16];
	int cmp_name(const void *p1, const void* p2);
	int cmp_point(const void* p1, const void *p2);

	srand(time(NULL));
	for( int i=0 ; i<MaxData ; i++ ) {
		int l = rand() % 3 + 3;
		for( int j=0 ; j<l ; j++ ) {
			buf[j] = rand() % 26 + 'a';		// a ~ z
		}
		buf[l] = 0;		// null terminated string
		mdata[i].set_name(buf);
		
		int age = rand() % 21 + 5;			// 5 ~ 25
		mdata[i].set_age(age);
		
		double pt = (rand() % 10001) / 100.0;	// 0.0 ~ 10.0
		mdata[i].set_point(pt);
		
		char sex = (rand() % 2) == 0 ? 'F' : 'M';
		mdata[i].set_sex(sex);
	}	
	print_data("Origin:", mdata, MaxData);
	
	qsort(mdata, MaxData, sizeof(Datas), cmp_name);
	print_data("Sort Name:", mdata, MaxData);
	
	qsort(mdata, MaxData, sizeof(Datas), cmp_point);
	print_data("Sort Point:", mdata, MaxData);
}

int cmp_name(const void *p1, const void* p2)
{
	Datas *d1 = (Datas *)p1;
	Datas *d2 = (Datas *)p2;
	return d1->compare(*d2);
}

int cmp_point(const void* p1, const void *p2)
{
	Datas *d1 = (Datas *)p1;
	Datas *d2 = (Datas *)p2;
	return *d2 - *d1;	// descending
	//return *d1 - *d2;	// ascending
}

void print_data(const char* mesg, const Datas dt[], int num)
{
	cout << mesg << endl;
	for( int i=0 ; i<num ; i++ ) {
		cout << setw(2) << (i+1) << ": " << dt[i] << endl;
	}
}

