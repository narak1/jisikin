#include <stdio.h>

#define MAXN 100			/* �ִ� �ܰ� */
#define MAXN2 MAXN*MAXN		/* �迭�� �ִ� ũ�� */

int arr[2][MAXN2];			/* ���� ���� �迭 */
//int b[MAXN2];				/* �ӽ� �迭*/

/* n��° ���� ���� ����� */
void make_gaemi(int n)
{
	int *a, *b, *t;			// ������ �迭
    int i, j, k=2, c;

	a = arr[0];
	b = arr[1];

	a[0]=1;					/* 1 �ܰ� �ʱ� �� */
    printf("1 �ܰ� : %d\n", a[0]);
    for( k=2 ; k<=n ; k++ )
    {
		t = a;		/* a�迭�� ������ b�迭�� �����Ѵ� */
		a = b;		// ������ �������� ���縦 ��ü�Ѵ�.
		b = t;

		a[0] = 0;		// initial

		// find digit type
		//
		for( j=0 ; j<MAXN2 && b[j] ; j++ ) {
			for( i=0 ; i<MAXN2 && a[i] ; i+=2 ) {
				if( b[j] == a[i] )
					break;
			}
			if( a[i] == 0 ) {	// ó�� ���� ����
				a[i] = b[j];
				a[i+2] = 0;
			}
		}

		// find digit count
		//
		for( i=0 ; i<MAXN2 && a[i] ; i+=2 ) {
			c = 0;
			for( j=0 ; j<MAXN2 && b[j] ; j++ ) {
				if( a[i] == b[j] )
					++c;
			}
			a[i+1] = c;
		}

         /* k��° �ܰ��� ���� �� ��� */
         printf("%d �ܰ� : ", k);
         for (i=0; i<MAXN2 && a[i]!=0; i++)
              printf("%d", a[i]);
         printf("\n");
	}
}

void main()
{
     int n;

     scanf("%d", &n);

     make_gaemi(n);              /* ���� ���� ����� */
}

