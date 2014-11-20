#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_num(char *ptr)
{
	int flag = 0;
	if( *ptr == '-' || *ptr == '+' ) {
		++ptr;
	}
	while( *ptr ) {
		if( isdigit(*ptr) )
			flag = 1;
		else if( *ptr == '.' )
			;
		else {
			flag = 0;
			break;
		}
		++ptr;
	}
	return flag;
}

int get_num(char *ptr)
{
	int num;
	
	num = strtol(ptr, NULL, 10);	// atoi() is not standard function
	if( abs(num) < 10 ) {
		num *= 10;			// append 0
	}
	else {
		while( abs(num) > 100 ) {
			num /= 10;		// trunc last digit
		}
	}
	return num;
}

#define EMPTY	0x80000000
#define FULL	0x7FFFFFFF
#define STSIZE	1024

typedef struct { int val[STSIZE]; int sp; } Stack;

void push(Stack *st, int data);
int pop(Stack *st);

int main()
{
	char buf[BUFSIZ];
	int operand[20];
	int i, num;
	char operator[] = { "+-/*+-*/-+" };

	Stack opr, opd;
	int num1, num2, num3;
	int op;
	
	opr.sp = 0;
	opd.sp = 0;
	
	puts("Input data:");
	num = 0;
	while( scanf("%s", buf) != EOF )
	{
		if( is_num(buf) ) {
			operand[num] = get_num(buf);
			++num;
		}
		else if( isalpha(buf[0]) ) {
			operand[num] = buf[0];
			++num;
		}

		// dup check
		for( i=0 ; i<num-1 ; i++ ) {
			if( operand[i] == operand[num-1] ) {	// dup
				--num;
				break;
			}
		}

		if( num >= 20 ) break;
	}
	
	for( i=0 ; i<num ; i++ ) {
		printf("%d ", operand[i]);
	}
	puts("");
	
	// push stack
	for( i=0 ; i<num ; i++ ) {
		push(&opd, operand[i]);
	}
	for( i=0 ; operator[i] ; i++ ) {
		push(&opr, operator[i]);
	}
	
	// pop & calc
	while(1)
	{
		num1 = pop(&opd);
		num2 = pop(&opd);
		printf("pop %d %d\n", num1, num2);
		op = pop(&opr);
		printf("pop %c\n", op);
		if( num1 == EMPTY || num2 == EMPTY || op == EMPTY )
		{
			break;
		}
	
		if( op == '+' ) num3 = num1 + num2;
		else if( op == '-' ) num3 = num1 - num2;
		else if( op == '*' ) num3 = num1 * num2;
		else if( num2 != 0 ) num3 = num1 / num2;
		else break;		// error

		if( num2 < 0 ) {
			printf("%d%c(%d)=%d\n", num1, op, num2, num3);
		}
		else {
			printf("%d%c%d=%d\n", num1, op, num2, num3);
		}
		
		push(&opd, num3);
		printf("push %d\n", num3);
	}
}

void push(Stack *st, int data)
{
	if( st->sp >= STSIZE ) return;
	
	st->val[st->sp] = data;
	++(st->sp);
}

int pop(Stack *st)
{
	if( st->sp <= 0 ) return EMPTY;
	
	--(st->sp);
	return st->val[st->sp];
}

