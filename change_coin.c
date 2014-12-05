#include <stdio.h>

#define MAXTYPE 100

void main()
{
	int coin[MAXTYPE][2];	/* 동전의 종류 */
	int money;				/* 교환할 총액 */
	int total;				/* 교환된 동전의 총 수 */
	int i, n;

	printf("동전의 종류 : ");
	scanf("%d", &n);
	for( i=0 ; i<n ; i++ ) {
		printf("동전의 금액과 수량 : ");
		scanf("%d%d", &coin[i][0], &coin[i][1]);
	}
	coin[i][0] = 0;		// end of coin type

	printf("교환할 액수 : ");
	scanf("%d", &money);

	total=0;				/* 교환된 동전의 총 수를 초기화 */

	/* 동전의 종류만큼 반복 수행한다 */
	for(i=0; coin[i][0] ; i++) {
		n = money / coin[i][0];
		n = n < coin[i][1] ? n : coin[i][1];	// 교환할 동전 수 계산
		if( n != 0 ) {
			printf("%d원 동전 %d개\n", coin[i][0], n);
			money -= n * coin[i][0];
			total += n;
		}
		if( money <= 0 ) break;
	}
	printf("동전의 수는 모두 %d\n", total);
	if( money != 0 ) {
		printf("교환 안된 돈은 %d\n", money);
	}
}
