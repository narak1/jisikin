/* Write a program that models the Littleton City Lotto.
Allow to user to first select their lotto numbers.
randomly generate the winning lotto numbers for the week and then check the winning numbers against
the random ticket the user played in the Lotto to see how many numbers the user guessed correctly. */

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <cctype>
#include <cstdlib>
using namespace std;

const int NUMELS = 7;

void selectionSort(int[], int);
void getLottoPicks(int number[]);
bool NoDuplicates(int nums[], int count, int newnum);
void GenWinNums(int WinningNums[]);
void Matches(int[], int[]);

int main()
{
int i;
int number[NUMELS];
char selection;
string name;
int UserTicket[NUMELS];
int WinningNums[NUMELS];

do{
cout << "LITTLETON CITY LOTTO MODEL:" << endl;
cout << "----------------------------" << endl;
cout << "1) Play lotto" << endl;
cout << "Q) Quit Program" << endl;
cout << "Please make a selection:" << endl;
cin >> selection;
cin.ignore();
selection = toupper(selection);

switch (selection)
{
case '1':
cout << "Please enter your name:" << endl;
getline(cin, name);

getLottoPicks(number);

GenWinNums(WinningNums);

selectionSort(WinningNums, 7);
selectionSort(number, 7);

cout << endl ;
cout << "JOHNNY's LOTTO RESULTS" << endl;
cout << "----------------------" << endl;
cout << "WINNING TICKET NUMBERS: ";
for (int i = 0; i < 7; i++){
cout << setw(3) << WinningNums[i];
}
cout << endl;
cout << "       JOHNNY's TICKET: ";
for (int i = 0; i < NUMELS; i++){
cout << setw(3) << number[i];
}
cout << endl;

cout << "RESULTS:" << endl;
cout << "--------" << endl;
Matches(number, WinningNums);
break;

case'Q':
break;

default:
cout << "Invalid selection.\n";
}
} while (selection != 'Q');

system("pause");
return 0;
}

void Matches(int getLottoPicks[], int GenWinNums[])
{
	int count = 0;
	for (int a = 0; a < NUMELS; a++)
	{
		for (int b = 0; b < NUMELS; b++)
		{
			if (getLottoPicks[a] == GenWinNums[b])
			{
				count++;
			}
		}
	}
	cout << "Number Matches: " << count;
	cout << "\nWinnings      : ";
	
	if (count == 2 || count == 1 || count == 0)
	{
		cout << "SORRY NOTHING\n\n";
	}
	else if (count == 3)
	{
		cout << "FREE TICKET\n\n";
	}
	else if (count == 4)
	{
		cout << "NOT BAD - $100\n\n";
	}
	else if (count == 5)
	{
		cout << "LUCKY YOU! - $5,000\n\n";
	}
	else if (count == 6)
	{
		cout << "GREAT! - $100,000\n\n";
	}
	else if (count == 7)
	{
		cout << "JACKPOT! - 1 MILLION\n\n";
	}
}


void getLottoPicks(int UserTicket[])
{
	cout << "Please enter number 1:";
	for (int i = 0; i < NUMELS; i++)
	{
		cin >> UserTicket[i];
		if (UserTicket[i] > 40 || UserTicket[i] < 1)
		{
			cout << "The number must be between 1 and 40. Please enter another number:" << endl;
			--i;
		}
		else if( NoDuplicates(UserTicket, i, UserTicket[i]) == false ) {
			cout << "No duplicate numbers are accepted. Please enter another number:" << endl;
			--i;
		}
		else if( i < NUMELS-1 ) {
			cout << "Please enter number " << (i+2) << ":";
		}
	}
}


void GenWinNums(int WinningNums[])
{
	srand(time(NULL));
	for (int i = 0; i < NUMELS; i++)
	{
		WinningNums[i] = rand() % 40 + 1;
		if( NoDuplicates(WinningNums, i-1, WinningNums[i]) == false ) {
			--i;
		}
	}
}


void selectionSort(int list[], int length)
{
int min, temp;

for (int index = 0; index < length - 1; index++)
{
min = index;
for (int scan = index + 1; scan < length; scan++)
if (list[scan]< list[min])
min = scan;

temp = list[min];
list[min] = list[index];
list[index] = temp;
}
}

bool NoDuplicates(int nums[], int count, int newnum)
{
for (int i = 0; i < count; i++)
{
if (nums[i] == newnum)
return false;
}
return true;
}

