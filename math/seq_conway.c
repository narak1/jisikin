#include <stdio.h>

#define MAXN 100			/* 최대 단계 */
#define MAXN2 MAXN*MAXN		/* 배열의 최대 크기 */

int arr[2][MAXN2];			/* 수열 저장 배열 */
//int b[MAXN2];				/* 임시 배열*/

/* n번째 개미 수열 만들기 */
void make_gaemi(int n)
{
	int *a, *b, *t;			// 수열의 배열
    int i, j, k=2, c;

	a = arr[0];
	b = arr[1];

	a[0]=1;					/* 1 단계 초기 값 */
    printf("1 단계 : %d\n", a[0]);
    for( k=2 ; k<=n ; k++ )
    {
		t = a;		/* a배열의 내용을 b배열에 복사한다 */
		a = b;		// 포인터 변경으로 복사를 대체한다.
		b = t;

		a[0] = 0;		// initial

		// find digit type
		//
		for( j=0 ; j<MAXN2 && b[j] ; j++ ) {
			for( i=0 ; i<MAXN2 && a[i] ; i+=2 ) {
				if( b[j] == a[i] )
					break;
			}
			if( a[i] == 0 ) {	// 처음 나온 숫자
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

         /* k번째 단계의 수열 값 출력 */
         printf("%d 단계 : ", k);
         for (i=0; i<MAXN2 && a[i]!=0; i++)
              printf("%d", a[i]);
         printf("\n");
	}
}

void main()
{
     int n;

     scanf("%d", &n);

     make_gaemi(n);              /* 개미 수열 만들기 */
}

