#include<stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	int N, C, K, *S;	// ���������� �������͸� �̿��ϹǷ� �� ����

	printf("input 1~10000 : ");
	scanf("%d",&N);
	if(N<2){
		printf("stop\n");
		return 0;
	}

	C = 0;
	K = 2;
	S = NULL;
	while( N > 1 ) {
		if( N % K == 0 ) {
			if( C % 100 == 0 ) {	// memoey resize
				S = (int *) realloc(S, (C+100)*sizeof(int));
			}
			N /= K;
			S[C] = K;
			C++;
		}
		else if( (K*K) > N ) {
			K = N;		// N�� ���̻� ���������� ���� 
		}
		else {
			K++;
		}
	}

	if( C == 1 ) {
		puts("����");
	}
	else {
		for( K=0 ; K<C ; K++ ) {
			printf("%d ", S[K]);
		}
		puts("");
	}
}
