#include <stdio.h>

#define MAXTYPE 100

void main()
{
	int coin[MAXTYPE][2];	/* ������ ���� */
	int money;				/* ��ȯ�� �Ѿ� */
	int total;				/* ��ȯ�� ������ �� �� */
	int i, n;

	printf("������ ���� : ");
	scanf("%d", &n);
	for( i=0 ; i<n ; i++ ) {
		printf("������ �ݾװ� ���� : ");
		scanf("%d%d", &coin[i][0], &coin[i][1]);
	}
	coin[i][0] = 0;		// end of coin type

	printf("��ȯ�� �׼� : ");
	scanf("%d", &money);

	total=0;				/* ��ȯ�� ������ �� ���� �ʱ�ȭ */

	/* ������ ������ŭ �ݺ� �����Ѵ� */
	for(i=0; coin[i][0] ; i++) {
		n = money / coin[i][0];
		n = n < coin[i][1] ? n : coin[i][1];	// ��ȯ�� ���� �� ���
		if( n != 0 ) {
			printf("%d�� ���� %d��\n", coin[i][0], n);
			money -= n * coin[i][0];
			total += n;
		}
		if( money <= 0 ) break;
	}
	printf("������ ���� ��� %d\n", total);
	if( money != 0 ) {
		printf("��ȯ �ȵ� ���� %d\n", money);
	}
}
