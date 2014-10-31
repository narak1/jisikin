#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void input_print();
char* group_str(char *buf, int size);

main()
{
	input_print();
}

void input_print()
{
	char buf[BUFSIZ];	// 충분히 크게 잡는다.
	char *str;			// 리턴받을 포인터
	char *grp[3];		// 구별자로 분리해 낸 문자열

	printf("Input string: ");
	scanf("%s", buf);

	str = group_str(buf, BUFSIZ);	// 배열 전체의 크기를 같이 준다.

	printf("%s_%s\n", buf, str);
	
	// str 을 구별자 찾아서 각각의 문자열로 분리해 낼수 있음
	grp[0] = str;

	str = strchr(str, ' ');
	*str = 0;
	++str;
	grp[1] = str;
	
	str = strchr(str, ' ');
	*str = 0;
	++str;
	grp[2] = str;
	
	printf("Each: [%s] [%s] [%s]\n", grp[0], grp[1], grp[2]);
}

char* group_str(char *buf, int size)
{
	int len;
	char *grp[3], *ptr;
	int i, j, k;

	len = strlen(buf) + 1;		// null 포함
	if( len*4 < size ) {
		grp[0] = buf + len;
		grp[1] = buf + len*2;
		grp[2] = buf + len*3;
	}
	else if( len*2 < size ) {
		grp[0] = buf + len;
		grp[1] = (char *) malloc(len);
		grp[2] = (char *) malloc(len);
	}
	else {
		grp[0] = (char *) malloc(len);
		grp[1] = (char *) malloc(len);
		grp[2] = (char *) malloc(len);
	}

	i = j = k = 0;
	ptr = buf;
	while( *ptr ) {		// 입력문자열의 NULL 까지 루프
		if( isalpha(*ptr) ) {	// 영문자
			grp[0][i] = *ptr;
			++i;
		}
		else if( isdigit(*ptr) ) {	// 숫자
			grp[1][j] = *ptr;
			++j;
		}
		else {		// 그외 문자
			grp[2][k] = *ptr;
			++k;
		}

		++ptr;
	}

	grp[0][i] = 0;		// null terminated 문자열로 만듬
	grp[1][j] = 0;
	grp[2][k] = 0;

	ptr = grp[0];		// same as strcpy(ptr, grp[0]);
	strcat(ptr, " ");	// 문자열 구별자 (영문자, 숫자 아닌 임의의 문자 가능. NULL 도 가능
	strcat(ptr, grp[1]);
	strcat(ptr, " ");
	strcat(ptr, grp[2]);

	return ptr;
}

