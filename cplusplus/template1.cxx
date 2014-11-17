#include <iostream>
#include <cstdlib>
using namespace std;

//Class definition
template<class T>
class Generic
{
private:
	T *marray;
	int size;
public:
	Generic(int b) { size=b; };
	void setsize(int a) { size = a; };
	void setmarray(T* a) { marray = a; };
	void mySort();
	void swap( T * element1Ptr, T * element2Ptr );
	void output();
};
 
//Template
//Functions

template<class T>
void Generic<T>::output()
{
	for( int i=0 ; i<this->size ; i++ ) {
		cout << this->marray[i] << "   ";
	}
	cout << endl;
}

template<class T>
void Generic<T>::mySort()
{
	for( int i=this->size-1 ; i>0 ; i-- ) {
		for( int j=0 ; j<i ; j++ ) {
			if( this->marray[j] > this->marray[j+1] ) {
				this->swap( &this->marray[j] , &this->marray[j+1] );
			}
		}
	}
	cout << endl;
}

template<class T>
void Generic<T>::swap( T * element1Ptr, T * element2Ptr )
{
	T tmp;
	tmp = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = tmp;
}

void stringData(); //to pass string array for sorting function
void intData();//to pass int array for sorting function
void doubleData();//to pass double array for sorting function
char enterChoice(void); //for the menu

int main ()
{
	char choice;
	while ( ( choice = enterChoice() ) != 'q' ) {
		system("cls");
		switch (choice) {
			case 's': stringData(); break;
			case 'i': intData(); break;
			case 'd': doubleData(); break;
			default: cerr << "Incorrect choice" << endl; break;
		}
	}
	system("pause");
	return 0;
}

char enterChoice(void)
{
	char input;
	cout << "\t+----------------Main Menu---------------+" << endl;
	cout << "\t|                                        |" << endl;
	cout << "\t|        Sort array of (i)nteger         |" << endl;
	cout << "\t|        Sort array of (d)ouble          |" << endl;
	cout << "\t|        Sort array of (s)tring          |" << endl;
	cout << "\t|        (Q)uit                          |" << endl;
	cout << "\t|                                        |" << endl;
	cout << "\t+----------------------------------------+" << endl;
	cin >> input;
	return tolower(input);
}

void stringData()
{
	string data[] = { "fff", "ss", "aa", "ss", "bb", "h" };
	Generic<string> ia(6);
	ia.setmarray(data);

	cout << "---------------------Unsorted ----------------------" << endl;
	ia.output();

	cout << "---------------------Sorted ----------------------" << endl;
	ia.mySort();
	ia.output();
}

void intData()
{
	int data[] = { 5, 4, 3, 3, 2, 1 };
	Generic<int> ia(6);
	ia.setmarray(data);

	cout << "---------------------Unsorted ----------------------" << endl;
	ia.output();

	cout << "---------------------Sorted ----------------------" << endl;
	ia.mySort();
	ia.output();
}

void doubleData()
{
	double data[] = { 5.5, 4.25, 10.1, 3.6, 2, 1 };
	Generic<double> da(6);
	da.setmarray(data);

	cout << "---------------------Unsorted ----------------------" << endl;
	da.output();

	cout << "---------------------Sorted ----------------------" << endl;
	da.mySort();
	da.output();
}
