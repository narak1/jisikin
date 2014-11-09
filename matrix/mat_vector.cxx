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
	int x[4], y[4] = {1,2,3,4};    // 2차원 행렬의 4개 원소의값

	a >> x;        // a 의 각 원소를 배열 x에 복사. x[]는 {4,3,2,1}
	b << y;        // 배열 y의 원소 값을 b의 각 원소에 설정

	for(int i=0; i<4; i++) {
		cout << x[i] << ' ';   // x[] 출력
	}
	cout << endl;
	b.show();
}

