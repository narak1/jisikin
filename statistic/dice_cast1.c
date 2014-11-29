#include <stdio.h>
#include <stdlib.h>

int yut(double p)	// return - 1:��, 0:��
{
	double r;
	r = ((rand() * rand()) % RAND_MAX) / (double)(RAND_MAX-1); // make 0.0 ~ 1.0
	return r < p;
}

int tetrahedron()
{
	return rand() % 4 + 1;	// 1 or 2 or 3 or 4
}

int dice()
{
	return rand() % 6 + 1;
}

int main()
{
	int i, n;
	double p;
	int r1, r2;
	char *str[] = { "��", "��" };
	char* fname = "result.txt";
	FILE *fp;

	srand(time(NULL));

	p = 0.4;

	printf("Input number of throwing: ");
	scanf("%d", &n);

	//fp = stdout;
	fp = fopen(fname, "w");
	if( fp == NULL ) {
		perror(fname);
		return 1;
	}

	fputs("������     �ֻ��� �Ǵ� ���ü\n", fp);
	fputs("------------------------------\n", fp);
	for( i=0 ; i<n ; i++ ) {
		r1 = yut(p);
		if( r1 == 1 ) r2 = dice();
		else r2 = tetrahedron();
		fprintf(fp, "%s\t\t%d\n", str[r1], r2);
	}
	fclose(fp);
}
