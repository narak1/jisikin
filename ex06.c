#include <stdio.h>
#include <string.h>

main()
{
	char buf[BUFSIZ], buf2[BUFSIZ];
	int i, len;

	printf("input string   : ");
	gets(buf);

	len = strlen(buf);
	for( i=0 ; i<len ; i++ ) {
		buf2[i] = buf[len-1 - i];
	}
	buf2[len] = 0;		// NULL�� ������ ���ڿ��� �����.

	printf("reverse string : ");
	puts(buf2);
}
