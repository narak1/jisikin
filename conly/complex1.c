#include <stdio.h>

struct complex {
	double r, i;
};

void get_input(struct complex *px);
struct complex complex_add(struct complex x, struct complex y);

int main()
{
	struct complex x, y, z;
	printf("첫번째 복소수를 입력하시오");
	get_input(&x);
	printf("두번째 복소수를 입력하시오");
	get_input(&y);
	z = complex_add(x, y);
	printf("%.1lf + %.1lfi\n", z.r, z.i);
	system("pause");
}

void get_input(struct complex *px)
{
	printf("(a, b):");
	scanf("%lf%lf", &px->r, &px->i);
}

struct complex complex_add(struct complex x, struct complex y)
{
	struct complex z;
	z.r = x.r + y.r;
	z.i = x.i + y.i;
	return z;
}

