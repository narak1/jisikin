#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define D2V(a) ((a) - '0')
#define V2D(a) ((a) + '0')

typedef struct st_digit
{
	char digit;
	struct st_digit *next;
} Digit;


Digit* new_digit(char ch)
{
	Digit *d;
	d = (Digit *) malloc(sizeof(Digit));
	d->digit = ch;
	d->next = NULL;
	return d;
}

void add_digit(Digit **a, char ch)
{
	Digit *d;
	d = new_digit(ch);
	d->next = *a;			// insert 1st position
	*a = d;
}

void put_number(Digit *a)
{
	if( a == NULL ) return;
	put_number(a->next);
	putchar(a->digit);
}

Digit* add_number(Digit *a, Digit *b)
{
	int val, carry = 0;
	Digit *head, *curr;
	if( a == NULL || b == NULL ) return NULL;

	val = D2V(a->digit) + D2V(b->digit);
	carry = val / 10;
	val %= 10;
	head = curr = new_digit( V2D(val) );
	a = a->next;
	b = b->next;
	while( a != NULL && b != NULL ) {
		val = D2V(a->digit) + D2V(b->digit) + carry;
		carry = val / 10;
		val %= 10;
		curr->next = new_digit( V2D(val) );
		curr = curr->next;
		a = a->next;
		b = b->next;
	}
	while( a != NULL ) {
		val = D2V(a->digit) + carry;
		carry = val / 10;
		val %= 10;
		curr->next = new_digit( V2D(val) );
		curr = curr->next;
		a = a->next;
	}
	while( b != NULL ) {
		val = D2V(b->digit) + carry;
		carry = val / 10;
		val %= 10;
		curr->next = new_digit( V2D(val) );
		curr = curr->next;
		b = b->next;
	}
	return head;
}

int main()
{
	Digit *a, *b, *c;
	char ch, newline='\n';

	a = b = c = NULL;	// initialize

	puts("Input a very long natural number:");
	while( (ch = getchar()) != '\n' ) {
		if( isdigit(ch) ) {
			add_digit(&a, ch);
		}
	}
	printf("a=");
	put_number(a); putchar(newline);

	puts("Input another very long natural number:");
	while( (ch = getchar()) != '\n' ) {
		if( isdigit(ch) ) {
			add_digit(&b, ch);
		}
	}
	printf("b=");
	put_number(b); putchar(newline);

	c = add_number(a, b);
	printf("c=");
	put_number(c); putchar(newline);
}
