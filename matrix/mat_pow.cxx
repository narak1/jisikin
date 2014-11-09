#include <stdio.h>

void printMat(int a[][3], int n);
void addMat(int a[][3], int b[][3], int c[][3], int n);
void multiMat(int a[][3], int b[][3], int c[][3], int n);
void powMat(int a[][3], int c[][3], int n);

int main()
{
	int A[3][3]={{1,1,0},
				{1,0,1},
				{1,1,1}};
	int B[3][3]={{1,0,0},
				{0,1,1},
				{0,0,1}};
	int q[3][3];
	int i,j,k;
	int p,m,r;
	int n,l = 0;

	printf("행렬 A는 다음과 같다.\n");
	printMat(A,3);
	printf("행렬 B는 다음과 같다.\n");
	printMat(B,3);
	printf("두행렬의 덧셈\n");
	addMat(A,B,q,3);
	printMat(q,3);  //호출하는거 중요함.
	printf("두행렬의 곱셈\n");
	multiMat(A,B,q,3);
	printMat(q,3);
	printf("A행렬의 n승(n은 지정)");
	powMat(A,q,3);
	printMat(q,3);
}

void printMat(int a[][3], int n)
{
	for (int i=0; i<n; i++){
		for (int j=0; j<3; j++)
			printf("%5d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

void addMat(int a[][3], int b[][3], int c[][3], int n)
{
	for (int i=0; i<n; i++)
		for (int j=0; j<3; j++) //행렬의 덧셈
			c[i][j]=a[i][j]+b[i][j];
}

void identity_matrix(int m[][3], int n)
{
	int i, j;
	for( i=0 ; i<n ; i++ ) {
		for( j=0 ; j<n ; j++ ) {
			if( i == j ) {
				m[i][j] = 1;
			}
			else {
				m[i][j] = 0;
			}
		}
	}
}

void copyMat(int a[][3], int c[][3], int n)
{
	int i, j;
	for( i=0 ; i<n ; i++ ) {
		for( j=0 ; j<n ; j++ ) {
			c[i][j] = a[i][j];
		}
	}
}

void powMat(int a[][3], int c[][3], int n)
{
	int x;
	int m[3][3];	// 임시 매트릭스

	printf("A행렬의 제곱을 진행할 제곱수n을 입력하세요. : ");
	scanf("%d", &x);
	printf("\nA행렬의 %d제곱 값\n",x);

	identity_matrix(c, n);

	for( int i=0 ; i<x ; i++ )
	{
		copyMat(c, m, n);		// c -> m
		multiMat(m, a, c, n);	// m * a -> c
	}
}

void multiMat(int a[][3], int b[][3], int c[][3], int n)
{
	for (int i=0; i<n; i++)
		for (int j=0; j<3; j++){
		c[i][j]=0;
		for (int k=0; k<3; k++)
			c[i][j]+=a[i][k]*b[k][j];
		}
}

