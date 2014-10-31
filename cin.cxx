#include <iostream>

using namespace std;

int main()
{
	string s1, str;
	
	while( !cin.eof() )
	{
		s1.clear();
		cin >> s1;
		str = s1 + str;
	}
	cout << str << endl;
}
