#include <stdio.h>

main()
{
	char buf[BUFSIZ], buf2[BUFSIZ];
	char *p, *q;
	
	printf("���ڿ��� �Է��ϼ���: ");
	gets(buf);
	
	p = buf;
	q = buf2;
	while( *p ) {
		*q = *p;
		++p;
		++q;
	}
	*q = *p;	// NULL copy
	
	printf("����� ���ڿ�: ");
	puts(buf2);
}
