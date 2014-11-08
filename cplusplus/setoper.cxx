#include <iostream>
using namespace std;

class MySet {
	int* m_Set;
	int m_Size;
	int m_MaxSize;
public:
	MySet();
	MySet(int agSize);
	MySet(int* agSet, int agSize);
	MySet(const MySet& ag);		// for MySet object return
	~MySet();
	int GetSize();
	int GetItem(int agIndex);
	void AddItem(int agValue);
	void Print() const;
	
	MySet operator^(const MySet& right) const;
	MySet operator*(const MySet& right) const;
	MySet& operator=(const MySet& right);	// for copy
};

MySet::MySet()
{
	m_MaxSize = 100;
	m_Set = new int [m_MaxSize];
	m_Size = 0;
}

MySet::MySet(int* agSet, int agSize)
{
	m_MaxSize = 100;
	m_Set = new int [m_MaxSize];
	for( int i=0 ; i<agSize ; i++ ) {
		m_Set[i] = agSet[i];
	}
	m_Size = agSize;
}

MySet::MySet(const MySet& ag)
{
	m_MaxSize = ag.m_MaxSize;
	m_Size = ag.m_Size;
	m_Set = new int [m_MaxSize];
	for( int i=0 ; i<m_Size ; i++ ) {
		m_Set[i] = ag.m_Set[i];
	}
}

MySet::~MySet()
{
	delete [] m_Set;
}

MySet MySet::operator^(const MySet& right) const
{
	MySet r;
	for( int i=0 ; i<this->m_Size ; i++ ) {
		for( int j=0 ; j<right.m_Size ; j++ ) {
			if( this->m_Set[i]  == right.m_Set[j] ) {
				r.m_Set[r.m_Size] = this->m_Set[i];
				++r.m_Size;
				break;
			}
		}
	}
	return r;
}

MySet MySet::operator*(const MySet& right) const
{
	MySet r;
	for( int i=0 ; i<this->m_Size ; i++ ) {
		r.m_Set[i] = this->m_Set[i];
	}
	r.m_Size = this->m_Size;

	for( int j=0 ; j<right.m_Size ; j++ ) {
		bool flag = 0;
		for( int i=0 ; i<this->m_Size ; i++ ) {
			if( this->m_Set[i]  == right.m_Set[j] ) {
				flag = 1;
				break;
			}
		}
		if( flag == 0 ) {
			r.m_Set[r.m_Size] = right.m_Set[j];
			++r.m_Size;
		}
	}
	return r;
}

MySet& MySet::operator=(const MySet& right)
{
	this->m_Size = right.m_Size;
	for( int i=0 ; i<right.m_Size ; i++ ) {
		this->m_Set[i] = right.m_Set[i];
	}
	return *this;
}

void MySet::Print() const
{
	cout << "{";
	for( int i=0 ; i<m_Size ; i++ ) {
		if( i != 0 ) {
			cout << ",";
		}
		cout << " " << m_Set[i];
	}
	cout << " }" << endl;	
}

int main()
{
	cout << "Date : 2014/10/27\n학번 : ______ , 이름 : ______\n\n";
	int s1[] = { 1, 3, 5, 7, 9, 11};
	int s2[] = { 11, 13, 7, 9, 20};
	MySet set1(s1, 6);
	MySet set2(s2, 5);
	cout << "SET1 = ";
	set1.Print();
	cout << "SET2 = ";
	set2.Print();

	MySet Inter;
	Inter = set1^set2;
	cout << "\nSET1 ^ SET2 = ";
	Inter.Print();
	
	MySet Uni;
	Uni = set1*set2;
	cout << "\nSET1 * SET2 = ";
	Uni.Print();
}
