#include <iostream>
using namespace std;

int main()
{
	double light_speed = 299752458;		// m/s
	double distance_sun = 100005000;	// 1¾ï5000 km
	double distance_sun2= 150000000;	// 1¾ï5000¸¸ km 
	
	// s = vt --> t = s/v
	cout << "after sec : " << distance_sun * 1000 / light_speed << endl; 
	cout << "after sec : " << distance_sun2 * 1000 / light_speed << endl; 
}
