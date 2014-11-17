#include <iostream>
#include <iomanip>

using namespace std;

main()
{
	cout.precision(3);
	cout.width(10);
	cout << fixed << 1.043 << setw(10) << -5.497 << setw(10) << 21.700 << std::endl;
	cout << setw(10) << 11.043 << setw(10) << -15.497 << setw(10) << 1.712 << std::endl;
}
