#include <stdio.h>
#include <stdlib.h>

#define MAXELEM 10000
 
typedef struct
{
	int row;
	int col;
	int value;
} element;

typedef struct
{
	int rows;				// 행의 크기 
	int cols;				// 열의 크기 
	int terms;				// 항의 개수
	element *elem[MAXELEM];	// 항 
} SparseMatrix;

int position_compare(element *e1, element *e2);
void print_matrix(SparseMatrix *m);

void main(int argc, char **argv)
{
	SparseMatrix a;
	SparseMatrix b;
	SparseMatrix c;
	element *e;
	
	int i, j, k, flag;

	FILE *fp;
	char *fname = "matrix.txt";
	
	if( argc > 1 ) {
		fname = argv[1];
	}
	
	fp = fopen(fname, "r");
	if( fp == NULL ) {
		perror(fname);
		return;
	}

	a.terms = 0;	// init matrix
	b.terms = 0;
	c.terms = 0;
	
	fscanf(fp, "%d %d %d", &a.rows, &a.cols, &a.terms);
	for (i = 0; i < a.terms; i++) {
		e = (element *) malloc(sizeof(element));
		a.elem[i] = e;
		fscanf(fp, "%d%d%d", &e->row, &e->col, &e->value);
	}
	
	puts("Matrix A");
	print_matrix(&a);

	fscanf(fp, "%d %d %d", &b.rows, &b.cols, &b.terms);
	for (i = 0; i < a.terms; i++) {
		element *e = (element *) malloc(sizeof(element));
		b.elem[i] = e;
		fscanf(fp, "%d%d%d", &e->row, &e->col, &e->value);
	}
	
	puts("Matrix B");
	print_matrix(&b);

	if( a.rows != b.rows || a.cols != b.cols ) {
		puts("Matrix size mismatch!");
		return;
	}
	
	i = j = k = 0;
	while(1)
	{
		e = (element *) malloc(sizeof(element));
		
		if( i == a.terms && j == b.terms ) {
			break;
		}
		else if( i < a.terms && j < b.terms ) {
			flag = position_compare(a.elem[i], b.elem[j]);
			if( flag == 0 ) {
				e->row = a.elem[i]->row;
				e->col = a.elem[i]->col;
				e->value = a.elem[i]->value + b.elem[i]->value;
				++i;
				++j;
			}
			else if( flag < 0 ) {
				*e = *(a.elem[i]);
				++i;
			}
			else {
				*e = *(b.elem[j]);
				++j;
			}
		}
		else if( i<a.terms ) {
			*e = *(a.elem[i]);
			++i;
		}
		else {
			*e = *(b.elem[j]);
			++j;
		}
		
		c.elem[k] = e;
		++k;
	}
	c.terms = k;
	
	puts("Matrix C");
	print_matrix(&c);
	
	for( i=0 ; i<a.terms ; i++ )
		free(a.elem[i]);
	for( i=0 ; i<b.terms ; i++ )
		free(b.elem[i]);
	for( i=0 ; i<c.terms ; i++ )
		free(c.elem[i]);
}

int position_compare(element *e1, element *e2)
{
	if( e1->row == e2->row )
		return e1->col - e2->col;
	else
		return e1->row - e2->row;
}

void print_matrix(SparseMatrix *m)
{
	int i;
	for( i=0 ; i<m->terms ; i++ ) {
		printf("%d %d %d\n",
			 m->elem[i]->row, m->elem[i]->col, m->elem[i]->value);
	}
}
