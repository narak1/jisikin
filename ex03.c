#include <stdio.h>

main()
{
	int Getintegral(double val);
	double Getfractional(double val);

	double val;

	printf("�Ǽ��� �Է��ϼ��� : ");
	scanf("%lf", &val);
	printf("%lf�� ������ : %d\n", val, Getintegral(val));
	printf("%lf�� �Ҽ��� : %lf\n", val, Getfractional(val));
}

int Getintegral(double val)
{
	return (int)val;
}

double Getfractional(double val)
{
	return val - (int)val;
}
