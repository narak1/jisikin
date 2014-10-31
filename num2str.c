#include <stdio.h>
#include <string.h>

const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

unsigned int str_to_num(char *ptr, int base);
char *num_to_str(unsigned int num, int base, char buf[], int buff_size);

main()
{
	int base;
	char buf[BUFSIZ];
	unsigned int num;
	
	printf("Input base (2,8,10,16 or 32���� �ڿ���) : ");
	scanf("%d", &base);
	if( (base < 2) || (base > 32) ) {
		puts("Invalid base.");
		return;
	}
	
	printf("Input number string : ");
	fflush(stdin);
	gets(buf);
	
	num = str_to_num(buf, base);
	
	printf("10����: %s\n", num_to_str(num, 10, buf, BUFSIZ));
	printf(" 2����: %s\n", num_to_str(num, 2, buf, 100));
	printf(" 8����: %s\n", num_to_str(num, 8, buf, 100));
	printf("16����: %s\n", num_to_str(num, 16, buf, 100));	
}

unsigned int str_to_num(char *ptr, int base)
{
	unsigned int num, val;
	num = 0;
	while( *ptr ) {
		if( isdigit(*ptr) ) {
			val = *ptr - '0';
		}
		else if( isupper(*ptr) ) {
			val = *ptr - 'A' + 10;
		}
		else if( islower(*ptr) ) {
			val = *ptr - 'a' + 10;
		}
		else {
			val = -1;
		}
		
		if( (val == -1) || (val >= base) ) {
			printf("Invalid digit %c for base %d.\n", *ptr, base);
			num = 0;
			break;
		}
		
		num *= base;
		num += val;
		
		++ptr;
	}
	return num;
}

char *num_to_str(unsigned int num, int base, char buf[], int buff_size)
{
	char *p;
	unsigned int val;
	
	p = buf + buff_size - 1;
	*p = 0;		// make null terminated string
	if( num == 0 ) {
		--p;
		*p = '0';
	}
	while( num ) {
		val = num % base;
		num /= base;
		--p;
		*p = digits[val];		
	}
	return p;
}
