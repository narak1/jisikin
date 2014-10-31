#include <stdio.h>

main()
{
	char buf[BUFSIZ], buf2[BUFSIZ];
	char *p, *q;
	
	printf("문자열을 입력하세요: ");
	gets(buf);
	
	p = buf;
	q = buf2;
	while( *p ) {
		*q = *p;
		++p;
		++q;
	}
	*q = *p;	// NULL copy
	
	printf("복사된 문자열: ");
	puts(buf2);
}
