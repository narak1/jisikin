#ifndef employee_Header
#define employee_Header
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


class employee
{
private:
	string Name;
	string IDNumber;
	string Department;
	string Position;
	int YearsWorked;
public:
	employee(string a, string b, string c, string d, int e)
	{
		Name = a;
		IDNumber = b;
		Department = c;
		Position = d;
		YearsWorked = e;
	};
	employee(string a, string b){
		Name = a;
		IDNumber = b;
		YearsWorked = 0;
	};
	employee(){		YearsWorked = 0;	};

	void setName(string a)		{	Name = a; 			};
	string getName()			{	return Name;		};
	void setIDNumber(string b)	{	IDNumber = b;		};
	string getIDNumber()		{	return IDNumber;	};
	void setDepartment(string c){	Department = c;		};
	string getDepartment()		{	return Department;	};
	void setPosition(string d)	{	Position = d;		};
	string getPosition()		{	return Position;	};
	bool setYearsWorked(int e);
	int getYearsWorked()		{	return YearsWorked;	};
};

#endif

bool employee::setYearsWorked(int e)
{
	if( e < 0 ) {
		cout << "Attempt to set yearsWorded for " << Name << " was invalid."
				" It was set to 0." << endl;
		YearsWorked = 0;
		return false;
	}
	YearsWorked = e;
	return true;
}

//---------------------------------------

#include <iostream>
#include <string>
//#include "employee.h"
#include <iomanip>
using namespace std;

int main()
{
	// 1. Declare 3 Employee
	//
	const int numofpersons = 3;
	employee information[numofpersons] = {
		employee("Jenny Jocobs", "JJ8990", "Accounting", "President", 15),
		employee("Myron Smith", "MS7571"),
		employee()
	};

	// 2. Use set functions
	//
	employee *e = &information[1];
	e->setDepartment("IT");
	e->setPosition("Programmer");
	if( e->setYearsWorked(-1) == false ) {
		e->setYearsWorked(5);
	}

	e = &information[2];
	e->setName("Chris Raines");
	e->setIDNumber("CR6873");
	e->setDepartment("Manufacturing");
	e->setPosition("Engineer");
	if( e->setYearsWorked(30) == false ) {
		e->setYearsWorked(5);
	}

	// Print information
	//
	cout << "\n\n";
	cout << "Name          ID Number   Department      Position      Years Worked\n";
	cout << "----          ---------   ----------      --------      ------------\n";
	for (int i = 0; i < numofpersons; i++)
	{
		cout << setw(14) << left << information[i].getName();
		cout << setw(12) << information[i].getIDNumber();
		cout << setw(16) << information[i].getDepartment();
		cout << setw(14) << information[i].getPosition();
		cout << setw(3) << right << information[i].getYearsWorked() << endl;
	}

	cout << "\n\n";
	system("pause");
	return 0;
}
