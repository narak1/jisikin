#include <iostream>
using namespace std;

int main()
{
	int amount, total;
	double ratio;
	int y;
	
	amount = 10000000;
	ratio = 0.035;
	cout << "���� : " << amount << endl; 
	cout << "���� : " << ratio << endl; 

	total = amount;
	for( y=1 ; ; y++ ) {
		total *= 1.0 + ratio;
		if( total > 3*amount ) {
			break;
		}
	}
	cout << "�հ� : " << total << endl; 
	cout << "�޼� : " << y << endl; 
}
