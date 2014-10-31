#include <stdio.h>

main()
{
	char buf[BUFSIZ];
	int len, i;
	int Userlength(char *str);

	for( i=0 ; i<3 ; i++ ) {
		printf("단어(문자열) 입력 : ");
		scanf("%s", buf);
		len = Userlength(buf);
		printf("%s단어의 길이 : %d자\n", buf, len);
	}
}

int Userlength(char *str)
{
	int i;

	i = 0;
	while( *str ) {		// NULL 이면 루프 종료
		++i;			// 세는 숫자 증가
		++str;			// 문자열 포인터 이동
	}

	return i;
}
