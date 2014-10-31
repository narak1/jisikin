#include <stdio.h>

main()
{
	int Getintegral(double val);
	double Getfractional(double val);

	double val;

	printf("실수를 입력하세요 : ");
	scanf("%lf", &val);
	printf("%lf의 정수부 : %d\n", val, Getintegral(val));
	printf("%lf의 소수부 : %lf\n", val, Getfractional(val));
}

int Getintegral(double val)
{
	return (int)val;
}

double Getfractional(double val)
{
	return val - (int)val;
}
