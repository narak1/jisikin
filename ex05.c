#include <stdio.h>

main()
{
	int amount;
	int unit[] = { 10000, 5000, 1000, 500, 100, 50, 10 };
	int i, num;

	printf("�ݾ��� �Է��ϰ� Enter>");
	scanf("%d", &amount);
	puts("ȭ�����");
	for( i=0 ; i<sizeof(unit)/sizeof(int) ; i++ ) {
		num = amount / unit[i];
		printf("%5d���� : %d\n", unit[i], num);

		amount -= num * unit[i];
	}
}
