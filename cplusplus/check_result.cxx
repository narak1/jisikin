#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int ARRAY_SIZE = 20;

const char* trim(string& str)
{
	const char* ptr = str.c_str();
	while( *ptr ) {
		if( ! isspace(*ptr) ) break;
		++ptr;
	}
	return ptr;
}

int main(int argc, char **argv)
{
	const char *fname = "Lab9data.txt";
	fstream input;
	string jungdap, tmp;

	string name;
	string answer;
	int total;
	double maxScore = 0.4;
	double actualScore;
	char grade;

	if( argc > 1 ) {
		fname = argv[1];
	}

	input.open(fname);
	if( !input ) {
		cerr << fname << " file open error!" << endl;
		return 0;
	}

	input >> jungdap;
	getline(input, tmp);

	while( ! input.eof() ) {
		name.clear();
		input >> name;
		if( name.empty() ) break;
		getline(input, tmp);
		answer = trim(tmp);

		cout << name << " [" << answer << "] ";

		total = 0;
		for( int i=0 ; i<answer.length() ; i++ ) {
			if( answer.at(i) ==  ' ' )	; // no count
			else if( answer[i] == jungdap[i] ) total += 2;
			else --total;
		}
		cout << setw(4) << total;

		actualScore = total / maxScore;
		if( actualScore >= 90 ) grade = 'A';
		else if( actualScore >= 80 ) grade = 'B';
		else if( actualScore >= 70 ) grade = 'C';
		else if( actualScore >= 60 ) grade = 'D';
		else grade = 'F';

		cout << " " <<  grade << endl;
	}
	
	input.close();
}

