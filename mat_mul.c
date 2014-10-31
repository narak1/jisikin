#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct matrix
{
	int r, c;
	double **e;
} Matrix;

void set_random_matrix(Matrix *m, int r, int c);
void print_matrix(Matrix *m);
int multiply_matrix(Matrix *m1, Matrix *m2, Matrix *m3);
void free_matrix(Matrix *m);

main()
{
	Matrix m1, m2, m3;
	int i, j, k;
	int flag;

	m1.r = m2.r = m3.r = 0;	// init

	srand(time(NULL));

	i = rand() % 10 + 1;
	j = rand() % 10 + 1;
	k = rand() % 10 + 1;

	set_random_matrix(&m1, i, j);
	set_random_matrix(&m2, j, k);

	puts("Matrix #1");
	print_matrix(&m1);
	puts("Matrix #2");
	print_matrix(&m2);

	flag = multiply_matrix(&m1, &m2, &m3);
	if( flag ) {
		puts("Result Matrix");
		print_matrix(&m3);
	}
	else {
		puts("Cannot multiply matrix.");
	}

	free_matrix(&m1);
	free_matrix(&m2);
	free_matrix(&m3);
}

void set_random_matrix(Matrix *m, int r, int c)
{
	int i, j;

	if( m->r ) {
		free_matrix(m);
	}

	m->r = r;
	m->c = c;
	m->e = (double **) malloc(r * sizeof(double *));
	for( i=0 ; i<r ; i++ ) {
		m->e[i] = (double *) malloc(c * sizeof(double));
		for( j=0 ; j<c ; j++ ) {
			m->e[i][j] = ((rand() % 2001) - 1000) / 100.0;
		}
	}
}

void print_matrix(Matrix *m)
{
	int i, j;
	for( i=0 ; i<m->r ; i++ ) {
		for( j=0 ; j<m->c ; j++ ) {
			printf("%8.3lf ", m->e[i][j]);
		}
		putchar('\n');
	}
}

int multiply_matrix(Matrix *m1, Matrix *m2, Matrix *m3)
{
	int i, j, k;

	if( m3->r ) {
		free_matrix(m3);
	}
	if( (m1->r == 0) || (m2->r == 0) || (m1->c != m2->r) ) {
		return 0;
	}

	m3->r = m1->r;
	m3->c = m2->c;
	m3->e = (double **) malloc(m3->r * sizeof(double *));
	for( i=0 ; i<m3->r ; i++ ) {
		m3->e[i] = (double *) malloc(m3->c * sizeof(double));
		for( j=0 ; j<m3->c ; j++ ) {
			m3->e[i][j] = 0.0;
			for( k=0 ; k<m1->c ; k++ ) {
				m3->e[i][j] += m1->e[i][k] * m2->e[k][j];
			}
		}
	}

	return 1;
}

void free_matrix(Matrix *m)
{
	int i;
	for( i=0 ; i<m->r ; i++ ) {
		free(m->e[i]);
	}
	free(m->e);
	m->r = 0;
}
