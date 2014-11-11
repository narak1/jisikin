#include <stdio.h>
void Tri(int n, int M);
void Tri2(int i, int n);
void Tri1(int r, int c, int M);

int main()
{
	int x, y;
	printf("Tri(x, y): ");
	scanf("%d%d", &x, &y);
	Tri(x, y);
	puts("");
	Tri1(x, 1, y);
}

void Tri(int n, int M)
{
	if( n > M ) return;
	Tri2(1, n);
	putchar('\n');
	Tri(n+1, M);
}

void Tri2(int i, int n)
{
	if( i > n ) return;
	putchar('*');
	Tri2(i+1, n);
}

void Tri1(int r, int c, int M)
{
	if( r > M ) return;
	if( c > r ) {
		putchar('\n');
		Tri1(r+1, 1, M);
	}
	else {
		putchar('*');
		Tri1(r, c+1, M);
	}
}
