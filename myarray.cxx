#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class MyArray
{
	int size;
	int *ptr;
	static const int Block = 1024;
public:
	MyArray() : size(0), ptr(NULL) { ; };
	~MyArray() { delete [] ptr; };
	int append(int num);
	int deleteTail();		// delete is keyword
	void print() const;
};

int MyArray::append(int num)
{
	if( size % Block == 0 ) {
		int *old = this->ptr;
		this->ptr = new int [size + Block];
		for( int i=0 ; i<size ; i++ ) {
			this->ptr[i] = old[i];
		}
		if( old != NULL ) {
			delete [] old;
		}
	}
	this->ptr[this->size] = num;
	++this->size;

	return this->size;
}

int MyArray::deleteTail()
{
	if( this->size > 0 ) {
		--this->size;
	}
	return this->size;
}

void MyArray::print() const
{
	for( int i=0 ; i<this->size ; i++ ) {
		cout << this->ptr[i] << ", ";
	}
	cout << endl;
}

main()
{
	MyArray arr1;
	
	srand(time(NULL));
	int n1 = rand() % 20;
	for( int i=0 ; i<n1 ; i++ ) {
		arr1.append(rand() % 1000);
	}
	cout << "List of arr1 append " << n1 << endl;
	arr1.print();
	
	int n2 = rand() % n1;
	for( int i=0 ; i<n2 ; i++ ) {
		arr1.deleteTail();
	}
	cout << "List of arr1 delete " << n2 << endl;
	arr1.print();
}

