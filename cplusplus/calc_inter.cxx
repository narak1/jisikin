#include <iostream>
using namespace std;

int main()
{
	int amount, total;
	double ratio;
	int y;
	
	amount = 10000000;
	ratio = 0.035;
	cout << "원금 : " << amount << endl; 
	cout << "이율 : " << ratio << endl; 

	total = amount;
	for( y=1 ; ; y++ ) {
		total *= 1.0 + ratio;
		if( total > 3*amount ) {
			break;
		}
	}
	cout << "합계 : " << total << endl; 
	cout << "햇수 : " << y << endl; 
}
