#include <stdio.h>
#include <ctype.h>
#include <string.h>

main()
{
	char buf[BUFSIZ];
	int i, len;

	while(1) {
		printf("���ڿ��� �Է��ϼ���(����:0) : ");
		gets(buf);
		if( buf[0] == '0' )
			break;

		printf("��ȯ�� ���ڿ� : ");
		len = strlen(buf);
		for( i=0 ; i<len ; i++ ) {
			if( (buf[i]>='A') && (buf[i]<='Z') ) {	// �빮��
				putchar(buf[i] + 'a' - 'A');
			}
			else if( islower(buf[i]) ) {		// �ҹ���
				putchar(toupper(buf[i]));
			}
			else {
				putchar(buf[i]);
			}
		}
		puts("");
	}
}
