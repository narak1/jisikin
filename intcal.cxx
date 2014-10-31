#include <iostream>
using namespace std;

int main()
{
	double origin = 100000;
	double mr_kim_int = 0.1;
	double mr_kim_sum = 100000;
	double wife_int = 0.05;
	double wife_sum = 100000;
	int year = 0;
	do {
		++year;
		mr_kim_sum += origin * mr_kim_int;
		wife_sum += wife_sum * wife_int;
		cout << "year:" << year << ", mr.kim: " << mr_kim_sum << ", wife: " << wife_sum << endl;
	} while( mr_kim_sum > wife_sum );
}
