#include <stdio.h>
 
#define MAXN 100                  /* �ִ� �ܰ� */
#define MAXN2 MAXN*MAXN  /* �迭�� �ִ� ũ�� */
 
int a[MAXN2];                       /* ���̼��� ���� �迭 */
int b[MAXN2];                       /* �ӽ� �迭*/
 
/* n��° ���� ���� ����� */
void make_gaemi(int n)
{
    int i, j, k=2, c;
 
a[0]=1; /* 1 �ܰ� �ʱ� �� */
    printf("1 �ܰ� : %d\n", a[0]);
    while (n>1) {
         /* a�迭�� ������ b�迭�� �����Ѵ� */
         for (i=0; i<MAXN2 && a[i]!=0; i++)
              b[i]=a[i];
         i=0;
         j=0;
         while (j<MAXN2 && b[j]!=0) {
a[i]=b[j]; /* ¦����° ���� ��. �״�� ���� */
              c=b[j];
              i=i+1;
a[i]=0; /* Ȧ����°�� �ݺ�Ƚ��, 0���� �ʱ�ȭ */
              /* ������ ���� ���� Ƚ�� ��� */
              for ( ; c==b[j]; j++)
                   a[i]++;
              i=i+1;
         }
         /* k��° �ܰ��� ���� �� ��� */
         printf("%d �ܰ� : ", k++);
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
 
     make_gaemi(n);              /* ���� ���� ����� */
}

