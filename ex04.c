#include <stdio.h>

main()
{
	char buf[BUFSIZ];
	int len, i;
	int Userlength(char *str);

	for( i=0 ; i<3 ; i++ ) {
		printf("�ܾ�(���ڿ�) �Է� : ");
		scanf("%s", buf);
		len = Userlength(buf);
		printf("%s�ܾ��� ���� : %d��\n", buf, len);
	}
}

int Userlength(char *str)
{
	int i;

	i = 0;
	while( *str ) {		// NULL �̸� ���� ����
		++i;			// ���� ���� ����
		++str;			// ���ڿ� ������ �̵�
	}

	return i;
}
