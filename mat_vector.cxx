#include <iostream>
using namespace std;

class Matrix
{
	static const int Size = 4;
	int elem[Size];
public:
	Matrix() { ; };
	Matrix(int a, int b, int c, int d) { elem[0]=a, elem[1]=b, elem[2]=c, elem[3]=d; };
	void operator<<(int n[]);
	void operator>>(int n[]) const;
	void show() const;
};

void Matrix::operator<<(int n[])
{
	for(int i=0;i<Size;i++) {
		elem[i] = n[i];
	}
}

void Matrix::operator>>(int n[]) const
{
	for(int i=0;i<Size;i++) {
		n[i] = elem[i];
	}
}

void Matrix::show() const
{
	cout << "Matrix = { ";
	for(int i=0;i<Size;i++) {
		cout << elem[i] << " ";
	}
	cout << "}" << endl;
}

int main()
{
	Matrix a(4,3,2,1), b;
	int x[4], y[4] = {1,2,3,4};    // 2���� ����� 4�� �����ǰ�

	a >> x;        // a �� �� ���Ҹ� �迭 x�� ����. x[]�� {4,3,2,1}
	b << y;        // �迭 y�� ���� ���� b�� �� ���ҿ� ����

	for(int i=0; i<4; i++) {
		cout << x[i] << ' ';   // x[] ���
	}
	cout << endl;
	b.show();
}

