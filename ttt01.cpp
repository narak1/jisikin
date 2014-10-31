#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>     // std::ostream_iterator
using namespace std;
int main ()
{
ifstream inFile1("C:\\Desktop\\word.txt", ios::in);
vector<string> v;
string tmp;
while ( getline(inFile1, tmp) )
v.push_back(tmp);
inFile1.close();
copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
sort(v.begin(), v.end());
cout << endl << "Sorted..." << endl << endl;
copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
ofstream outFile("C:\\Desktop\\word.txt", ios::out);
vector<string>::iterator it;
for ( it = v.begin(); it != v.end(); it++ )
outFile << *it << endl;
outFile.close();
return 0;
}
