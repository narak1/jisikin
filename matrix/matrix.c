#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int r, c;
	double **e;
} Matrix;

void init_matrix(Matrix *m, int r, int c);
void set_matrix(Matrix *m);
void print_matrix(Matrix *m);
double det_matrix(Matrix *m);
void free_matrix(Matrix *m);
int inverse_matrix(Matrix *m1, Matrix *m2);
void sub_matrix(Matrix *m1, int r, int c, Matrix *m2);
double det_matrix3(Matrix *m);	// 3x3 matrix determinant
void read_matrix(char *fname, Matrix *m);
void mul_matrix(Matrix *m1, Matrix *m2, Matrix *m3);

main(int argc, char **argv)
{
	Matrix m1, m2, m3;
	int rank, flag;
	double d;

	if( argc == 1) {
		srand(time(NULL));

		printf("Input matrix rank: ");
		scanf("%d", &rank);

		init_matrix(&m1, rank, rank);
		set_matrix(&m1);
	}
	else {
		read_matrix(argv[1], &m1);
		rank = m1.r;
	}

	init_matrix(&m2, rank, rank);
	init_matrix(&m3, rank, rank);

	puts("Matrix 1");
	print_matrix(&m1);

	if( rank == 3 ) {
		d = det_matrix3(&m1);
		printf("3x3 mat det = %g\n", d);
	}

	d = det_matrix(&m1);
	printf("determinant = %g\n", d);
	if( d != 0.0 ) {
		flag = inverse_matrix(&m1, &m2);
		if( flag ) {
			puts("Inverse Matrix");
			print_matrix(&m2);

			mul_matrix(&m1, &m2, &m3);
			puts("Verify");
			print_matrix(&m3);
		}
	}

	free_matrix(&m1);
	free_matrix(&m2);
}

void init_matrix(Matrix *m, int r, int c)
{
	int i;
	m->r = r;
	m->c = c;
	m->e = (double **) malloc(r* sizeof(double *));
	for( i=0 ; i<r ; i++ ) {
		m->e[i] = (double *) calloc(c, sizeof(double));
	}
}

void set_matrix(Matrix *m)
{
	int i, j;

	for( i=0 ; i<m->r ; i++ ) {
		for( j=0 ; j<m->c ; j++ ) {
			m->e[i][j] = (rand() % 10001) / 1000.0;		// 0.0 ~ 10.0
		}
	}
}

void read_matrix(char *fname, Matrix *m)
{
	FILE *fp;
	int i, j, rank;

	fp = fopen(fname, "r");
	if( fp == NULL ) {
		init_matrix(m, 0, 0);
		return;
	}

	fscanf(fp, "%d", &rank);
	init_matrix(m, rank, rank);
	for( i=0 ; i<rank ; i++ ) {
		for( j=0 ; j<rank ; j++ ) {
			fscanf(fp, "%lf", &(m->e[i][j]));
		}
	}

	fclose(fp);
}

void print_matrix(Matrix *m)
{
	int i, j;
	for( i=0 ; i<m->r ; i++ ) {
		for( j=0 ; j<m->c ; j++ ) {
			printf("%6.3lf ", m->e[i][j]);
		}
		puts("");
	}
}

double det_matrix(Matrix *m)
{
	double ret = 0.0, val;
	Matrix m2;
	int i, flag;

	if( m->r == m->c ) {
		if( m->r == 2 ) {
			ret = m->e[0][0] * m->e[1][1] - m->e[0][1] * m->e[1][0];
		}
		else {
			init_matrix(&m2, m->r-1, m->c-1);	// for sub matrix
			flag = 0;
			for( i=0 ; i<m->c ; i++ ) {
				sub_matrix(m, 0, i, &m2);
				val = m->e[0][i] * det_matrix(&m2);
				if( flag == 0 ) {
					flag = 1;
					ret += val;
				}
				else {
					flag = 0;
					ret -= val;
				}
			}
		}
	}
	return ret;
}

double det_matrix3(Matrix *m)
{
	double ret = 0.0, val;
	int i, j, k;

	for( i=0 ; i<3 ; i++ ) {
		val = 1.0;
		for( j=0 ; j<3 ; j++ ) {
			k = i + j;
			if( k >= 3 )
				k -= 3;
			val *= m->e[j][k];
		}
		ret += val;
	}

	for( i=0 ; i<3 ; i++ ) {
		val = 1.0;
		for( j=0 ; j<3 ; j++ ) {
			k = i - j;
			if( k < 0 )
				k += 3;
			val *= m->e[j][k];
		}
		ret -= val;
	}

	return ret;
}

void free_matrix(Matrix *m)
{
	int i;
	for( i=0 ; i<m->r ; i++ )
		free(m->e[i]);
	free(m->e);
	m->e = NULL;
	m->r = m->c = 0;
}

int inverse_matrix(Matrix *m1, Matrix *m2)
{
	int i, j, k;
	double ratio;
	Matrix m;

	// copy matrix
	init_matrix(&m, m1->r, m1->c);
	for( i=0 ; i<m1->r ; i++ ) {
		for( j=0 ; j<m1->c ; j++ ) {
			m.e[i][j] = m1->e[i][j];
		}
	}

	// make identity matrix
	for( i=0 ; i<m2->r ; i++ ) {
		for( j=0 ; j<m2->c ; j++ ) {
			if( i == j )
				m2->e[i][j] = 1.0;
			else
				m2->e[i][j] = 0.0;
		}
	}

	// lower triangle elimination
	for( k=0 ; k<m.r-1 ; k++ ) {
		for( i=k+1 ; i<m.r ; i++ ) {
			if( m.e[k][k] == 0.0 ) {
				puts("Cannot find inverse matrix using elimination method");
				return 0;
			}
			ratio = m.e[i][k] / m.e[k][k];
			for( j=k ; j<m.c ; j++ ) {
				m.e[i][j] -= m.e[k][j] * ratio;
			}
			for( j=0 ; j<m.c ; j++ ) {
				m2->e[i][j] -= m2->e[k][j] * ratio;
			}
		}
	}

	puts("Upper triangle Matrix");
	print_matrix(&m);
	puts("Lower triangle Matrix");
	print_matrix(m2);

	// make diagonal to 1.0
	for( i=0 ; i<m.r ; i++ ) {
		ratio = m.e[i][i];		// diagonal element
		m.e[i][i] = 1.0;
		for( j=i+1 ; j<m.c ; j++ ) {
			m.e[i][j] /= ratio;
		}
		for( j=0 ; j<=i ; j++ ) {
			m2->e[i][j] /= ratio;
		}
	}

	puts("Diagonal Unit Upper triangle Matrix");
	print_matrix(&m);
	puts("Lower triangle Matrix");
	print_matrix(m2);

	// upper triangle elimination
	for( k=m1->r-1 ; k>0 ; k-- ) {
		for( i=k-1 ; i>=0 ; i-- ) {
			ratio = m.e[i][k];
			m.e[i][k] = 0.0;
			for( j=0 ; j<m.c ; j++ ) {
				m2->e[i][j] -= m2->e[k][j] * ratio;
			}
		}
	}

	puts("Identity Matrix");
	print_matrix(&m);
	puts("Inverse Matrix");
	print_matrix(m2);

	return 1;
}

void sub_matrix(Matrix *m1, int r, int c, Matrix *m2)
{
	int i, j;
	int i2, j2;

	for( i=0,i2=0 ; i<m1->r ; i++ ) {
		if( i == r )
			continue;
		for( j=0,j2=0 ; j<m1->c ; j++ ) {
			if( j == c )
				continue;
			m2->e[i2][j2] = m1->e[i][j];
			++j2;
		}
		++i2;
	}
}

void mul_matrix(Matrix *m1, Matrix *m2, Matrix *m3)
{
	int i, j, k;

	if( m1->c != m2->r ) {
		printf("Invalid matrix size %dx%d * %dx%d\n", m1->r, m1->c, m2->r, m2->c);
		return;
	}

	for( i=0 ; i<m1->r ; i++ ) {
		for( j=0 ; j<m2->c ; j++ ) {
			m3->e[i][j] = 0.0;
			for( k=0 ; k<m1->c ; k++ ) {
				m3->e[i][j] += m1->e[i][k] * m2->e[k][j];
			}
		}
	}
}
