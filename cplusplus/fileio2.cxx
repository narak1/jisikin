#include <iostream>
#include <fstream>
using namespace std;

void getFirstLast(string &str1, int& length);
void writeRecordToFile(string str1, int length);

int main(int argc, char **argv)
{
	string recordName;
	string enterRecord;
	int length;
	string answer;

	cout << "Hello to my program " << argv[0] << "." << endl;

	do {
		getFirstLast(recordName, length);
		writeRecordToFile(recordName, length);
		cout << "Would you like to add another record?" << endl;
		cin >> answer;
	} while( answer == "Yes" );
	
	cout << "Thank you, Good Bye!" << endl;
}

//
// c.
//
void getFirstLast(string& str1, int& length)
{
	string firstName;
	string lastName;
	
	cout << "Please enter your first name: ";
	cin >> firstName;
	cout << "Please enter your last name: ";
	cin >> lastName;
	str1 = firstName + " " + lastName;
	length = firstName.length() + lastName.length();
	cout << "Your Record Name is: " << str1
		 << " and the total number of characters in your first and last names is: "
		 << length << "." << endl;
}

//
// d.
//
void writeRecordToFile(string str1, int length)
{
	ofstream ofs;
	const char* fname = "record.txt";
	ofs.open(fname, fstream::out | fstream::app);
	if( ! ofs ) {
		cerr << fname << " open error!" << endl;
		return;
	}

	ofs << str1 << '\t' << length << endl;
	ofs.close();
}
