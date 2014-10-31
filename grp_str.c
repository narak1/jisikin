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
	char buf[BUFSIZ];	// ����� ũ�� ��´�.
	char *str;			// ���Ϲ��� ������
	char *grp[3];		// �����ڷ� �и��� �� ���ڿ�

	printf("Input string: ");
	scanf("%s", buf);

	str = group_str(buf, BUFSIZ);	// �迭 ��ü�� ũ�⸦ ���� �ش�.

	printf("%s_%s\n", buf, str);
	
	// str �� ������ ã�Ƽ� ������ ���ڿ��� �и��� ���� ����
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

	len = strlen(buf) + 1;		// null ����
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
	while( *ptr ) {		// �Է¹��ڿ��� NULL ���� ����
		if( isalpha(*ptr) ) {	// ������
			grp[0][i] = *ptr;
			++i;
		}
		else if( isdigit(*ptr) ) {	// ����
			grp[1][j] = *ptr;
			++j;
		}
		else {		// �׿� ����
			grp[2][k] = *ptr;
			++k;
		}

		++ptr;
	}

	grp[0][i] = 0;		// null terminated ���ڿ��� ����
	grp[1][j] = 0;
	grp[2][k] = 0;

	ptr = grp[0];		// same as strcpy(ptr, grp[0]);
	strcat(ptr, " ");	// ���ڿ� ������ (������, ���� �ƴ� ������ ���� ����. NULL �� ����
	strcat(ptr, grp[1]);
	strcat(ptr, " ");
	strcat(ptr, grp[2]);

	return ptr;
}

