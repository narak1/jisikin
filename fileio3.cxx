#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	const char *in_fname = "HW6Prob2In.dat";
	const char *out_fname = "HW6Prob2Out.dat";
	
	const int MaxData = 10;
	double data[MaxData];

	ifstream ifs(in_fname);
	if( !ifs.is_open() ) {
		cerr << in_fname << " open error!" << endl;
		return 0;
	}

	for( int i=0 ; i<MaxData ; i++ )
	{
		ifs >> data[i];
	}

	ifs.close();
	
	// find min, max, avg
	double min = data[0];
	double max = data[0];
	double sum = data[0];
	for( int i=1 ; i<MaxData ; i++ ) {
		min = min < data[i] ? min : data[i];
		max = max > data[i] ? max : data[i];
		sum += data[i];
	}

	ofstream ofs(out_fname);
	if( !ofs.is_open() ) {
		cerr << out_fname << " open error!" << endl;
		return 0;
	}

	cout << "Max Value = " << max << endl;
	ofs << "Max Value = " << max << endl;
	
	cout << "Min Value = " << min << endl;
	ofs << "Min Value = " << min << endl;

	double average = sum / MaxData;
	cout << "Average   = " << average << endl;
	ofs << "Average   = " << average << endl;
	
	ofs.close();
}
