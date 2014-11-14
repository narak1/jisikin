#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

const int numberofrows = 15;
const int numberofcolumns = 20;

void chart(char table[numberofrows][numberofcolumns]);
void pricesdata(double prices[15]);

int main()
{
	char choice;
	int row, seat;
	char table[numberofrows][numberofcolumns];
	int ticket = 0;
	double prices[15];
	double total;

	for (int x = 0; x < numberofrows; x++)
		for (int y = 0; y < numberofcolumns; y++)
			table[x][y] = '*';

	do{
		cout << "\n* Seats available";
		cout << "\n# Reserved Seats\n";
		chart(table);
		cout << "\nMenu:\n";
		cout << "1) Buy ticket\n";
		cout << "2) Total sell and exit\n\n";
		cout << "Enter your choice : ";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
			case '1':
				cout << "Enter row: ";
				cin >> row;
				cout << "Enter seat: ";
				cin >> seat;
				if (table[row][seat] == '*')
				{
					table[row][seat] = '#';
					ticket++;
				}
				else if (table[row][seat] == '#')
				{
					cout << "Invalid choice";
				}
				break;

			case '2':
				pricesdata(prices);
				cout << "UPDATED SEATING CHART AND SALES INFO:\n\n";
				chart(table);
				cout << "TOTAL TICKETS SOLD: " << ticket;
				total = 0;
				for (int i = 0; i < numberofrows; ++i)
				{
					int num = 0;
					for( int j=0 ; j<numberofcolumns ; j++ ) {
						if( table[i][j] == '#' ) {
							++num;
						}
					}
					total += prices[i] * num;
				}
				cout << "\nTOTAL REVENUE: $ " << fixed << setprecision(2) << total;
				cout << "\n";
				system("pause");
				break;

			default:
				cout << "Invalid choice";
		}
	} while (choice != '2');
}

void chart(char table[numberofrows][numberofcolumns])
{
	cout << "Seats:  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19" << endl;
	for (int b = 0; b < numberofrows; b++)
	{
		cout << "Row" << setw(3) << b;
		for (int c = 0; c < numberofcolumns; c++)
		{
			cout << setw(3) << table[b][c];
		}
		cout << "\n";
	}
}

void pricesdata(double prices[15])
{
	const char *fname = "Prices.txt";
	ifstream infile;
	infile.open(fname);
	if( !infile ) {
		cerr << "File open error: " << fname << endl;
		return;
	}
	for (int i = 0; i < 15; ++i)
	{
		infile >> prices[i];
	}
	infile.close();
}
