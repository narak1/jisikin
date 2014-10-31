#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int NUM_MONKEYS = 3;
const int NUM_DAYS = 7;

void input_data(string monkey_name[], int amount_foods[][NUM_DAYS]);
void read_data(string monkey_name[], int amount_foods[][NUM_DAYS]);
void save_data(string monkey_name[], int amount_foods[][NUM_DAYS]);
void print_data(string monkey_name[], int amount_foods[][NUM_DAYS]);

main()
{
	// 2) Fill the arrays
	
	// option 1
	string monkey_name[NUM_MONKEYS];
	int amount_foods[NUM_MONKEYS][NUM_DAYS];

	// option 2
	monkey_name[0] = "none";
	monkey_name[1] = "none";
	monkey_name[2] = "none";

	for( int i=0 ; i<NUM_MONKEYS ; i++ ) {
		for( int j=0 ; j<NUM_DAYS ; j++ ) {
			amount_foods[i][j] = 0;
		}
	}
	
	input_data(monkey_name, amount_foods);
	
	// option 3
	read_data(monkey_name, amount_foods);
	save_data(monkey_name, amount_foods);
	
	// 3) Printing
	print_data(monkey_name, amount_foods);
}

// option 2

void input_data(string monkey_name[], int amount_foods[][NUM_DAYS])
{
	for( int i=0 ; i<NUM_MONKEYS ; i++ ) {
		cout << "Enter monkey's name : ";
		cin >> monkey_name[i];
		for( int j=0 ; j<NUM_DAYS ; j++ ) {
			cout << "Enter the pounds eaten by monkey #"
				 << (i+1) << " on day #" << (j+1) << ": ";
			cin >> amount_foods[i][j];
			if( amount_foods[i][j] < 0 ) {
				cout << "Enter non negative value!" << endl;
				--j;
			}
		}
	}
}

// option 3

void read_data(string monkey_name[], int amount_foods[][NUM_DAYS])
{
	string file_name;
	
	cout << "Enter data file name : ";
	cin >> file_name;

	ifstream ifs(file_name.c_str());
	if( ! ifs.is_open() ) {
		cout << "Cannot open file " << file_name << endl;
		return;
	}
	
	for( int i=0 ; i<NUM_MONKEYS ; i++ ) {
		ifs >> monkey_name[i];
		for( int j=0 ; j<NUM_DAYS ; j++ ) {
			ifs >> amount_foods[i][j];
		}
	}
	
	ifs.close();
}

void save_data(string monkey_name[], int amount_foods[][NUM_DAYS])
{
	string file_name;
	
	cout << "Enter save file name : ";
	cin >> file_name;

	ofstream ofs(file_name.c_str());
	if( ! ofs.is_open() ) {
		cout << "Cannot open file " << file_name << endl;
		return;
	}
	
	for( int i=0 ; i<NUM_MONKEYS ; i++ ) {
		ofs << monkey_name[i] << endl;
		for( int j=0 ; j<NUM_DAYS ; j++ ) {
			ofs << amount_foods[i][j] << " ";
		}
		ofs << endl;
	}
	
	ofs.close();
}

// 3) Printing

void print_data(string monkey_name[], int amount_foods[][NUM_DAYS])
{
	cout << "Name    ";
	for( int i=0 ; i<NUM_DAYS ; i++ ) {
		cout << "Day " << (i+1) << "  ";
	}
	cout << endl;
	
	for( int i=0 ; i<NUM_MONKEYS ; i++ ) {
		cout << setw(10) << left << monkey_name[i];
		for( int j=0 ; j<NUM_DAYS ; j++ ) {
			cout << setw(4) << amount_foods[i][j] << "   ";
		}
		cout << endl;
	}
}

