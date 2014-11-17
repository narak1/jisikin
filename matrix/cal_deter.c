#include <stdio.h>

int main()
{
	int m2x2[2][2] = { { 10, 2 }, { 11, 18 } };
	int m3x3[3][3] = { {23,11,92},{4,8,18},{7,14,17}};
	
	printf("determinant = %d\n", deter2(m2x2));
	printf("determinant = %d\n", deter3(m3x3));
}

int deter2(int m[2][2])
{
	return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

int deter3(int m[2][2])
{
	return m[0][0] * m[1][1] * m[2][2] - m[0][0] * m[1][2] * m[2][1]
		+ m[0][1] * m[1][2] * m[2][0] - m[0][1] * m[1][0] * m[2][2]
		+ m[0][2] * m[1][0] * m[2][1] - m[0][2] * m[1][1] * m[2][0];
}

