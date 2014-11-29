#include <stdio.h>
#include <string.h>

const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

unsigned int str_to_num(char *ptr, int base);
char *num_to_str(unsigned int num, int base, char buf[], int buff_size);
char *num_to_str2(int num, int base, char buf[], int buff_size);

main()
{
	int base;
	char buf[BUFSIZ];
	unsigned int num;

	printf("Input base (2,8,10,16 or 32이하 자연수) : ");
	scanf("%d", &base);
	if( (base < 2) || (base > 32) ) {
		puts("Invalid base.");
		return;
	}

	printf("Input number string : ");
	fflush(stdin);
	gets(buf);

	num = str_to_num(buf, base);

	printf("10진수: %s\n", num_to_str(num, 10, buf, BUFSIZ));
	printf(" 2진수: %s\n", num_to_str(num, 2, buf, 100));
	printf(" 8진수: %s\n", num_to_str(num, 8, buf, 100));
	printf("16진수: %s\n", num_to_str(num, 16, buf, 100));

	printf("Input number : ");
	scanf("%d", &num);
	printf("Input minus base : ");
	scanf("%d", &base);
	printf("%d진수: %s\n", base, num_to_str2(num, base, buf, 100));
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

char *num_to_str2(int num, int base, char buf[], int buff_size)
{
	char *p;
	int val;

	p = buf + buff_size - 1;
	*p = 0;		// make null terminated string
	if( num == 0 ) {
		--p;
		*p = '0';
	}
	while( num ) {
		val = num % base;
		num /= base;
		if( val < 0 ) {
			val -= base;
			num++;
		}
		--p;
		*p = digits[val];
	}
	return p;
}
