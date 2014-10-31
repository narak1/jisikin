#include <stdio.h>
#include <ctype.h>
#include <string.h>

main()
{
	char buf[BUFSIZ];
	int i, len;

	while(1) {
		printf("문자열을 입력하세요(종료:0) : ");
		gets(buf);
		if( buf[0] == '0' )
			break;

		printf("변환된 문자열 : ");
		len = strlen(buf);
		for( i=0 ; i<len ; i++ ) {
			if( (buf[i]>='A') && (buf[i]<='Z') ) {	// 대문자
				putchar(buf[i] + 'a' - 'A');
			}
			else if( islower(buf[i]) ) {		// 소문자
				putchar(toupper(buf[i]));
			}
			else {
				putchar(buf[i]);
			}
		}
		puts("");
	}
}
