#include <stdio.h>

main()
{
	int amount;
	int unit[] = { 10000, 5000, 1000, 500, 100, 50, 10 };
	int i, num;

	printf("금액을 입력하고 Enter>");
	scanf("%d", &amount);
	puts("화폐단위");
	for( i=0 ; i<sizeof(unit)/sizeof(int) ; i++ ) {
		num = amount / unit[i];
		printf("%5d원권 : %d\n", unit[i], num);

		amount -= num * unit[i];
	}
}
