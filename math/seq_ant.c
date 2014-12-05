#include <stdio.h>
 
#define MAXN 100                  /* 최대 단계 */
#define MAXN2 MAXN*MAXN  /* 배열의 최대 크기 */
 
int a[MAXN2];                       /* 개미수열 저장 배열 */
int b[MAXN2];                       /* 임시 배열*/
 
/* n번째 개미 수열 만들기 */
void make_gaemi(int n)
{
    int i, j, k=2, c;
 
a[0]=1; /* 1 단계 초기 값 */
    printf("1 단계 : %d\n", a[0]);
    while (n>1) {
         /* a배열의 내용을 b배열에 복사한다 */
         for (i=0; i<MAXN2 && a[i]!=0; i++)
              b[i]=a[i];
         i=0;
         j=0;
         while (j<MAXN2 && b[j]!=0) {
a[i]=b[j]; /* 짝수번째 수는 값. 그대로 저장 */
              c=b[j];
              i=i+1;
a[i]=0; /* 홀수번째는 반복횟수, 0으로 초기화 */
              /* 동일한 값의 연속 횟수 계산 */
              for ( ; c==b[j]; j++)
                   a[i]++;
              i=i+1;
         }
         /* k번째 단계의 수열 값 출력 */
         printf("%d 단계 : ", k++);
         for (i=0; i<MAXN2 && a[i]!=0; i++)
              printf("%d", a[i]);
         printf("\n");
         n--;
     }
}
 
void main()
{
     int n;
 
     scanf("%d", &n);
 
     make_gaemi(n);              /* 개미 수열 만들기 */
}

