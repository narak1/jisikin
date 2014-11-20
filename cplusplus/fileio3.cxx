#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char **argv)
{
	const char *in_fname = "format1.txt";
	const char *out_fname = "foramt2.txt";
	if( argc > 1 ) {
		in_fname = argv[1];
	}
	if( argc > 2 ) {
		out_fname = argv[2];
	}
	
	ifstream ifs(in_fname);
	if( !ifs ) {
		cerr << in_fname << " open error!" << endl;
		return 1;
	}
	ofstream ofs(out_fname);
	if( !ofs ) {
		cerr << out_fname << " create error!" << endl;
		ifs.close();
		return 2;
	}
	
	int num;
	ifs >> num;
	for( int i=0 ; i<num ; i++ ) {
		string name;
		int num2;
		ifs >> name >> num2;

		ofs << "ÀÌ¸§: " << name << endl;
		ofs << "-------------------------" << endl;
		for( int j=0 ; j<num2 ; j++ ) {
			string val;
			ifs >> name >> val;
			ofs << setw(20) << left << name << setw(5) << right << val << endl;
		}
		ofs << "-------------------------" << endl;
		ofs << endl;
	}
	
	ifs.close();
	ofs.close();
}

