#include <stdio.h>
#include "seq.h"

int menu()
{
	int m;

	puts("\n=== PRIME TESTBED ===");
	puts("1. Generate Prime.");
	puts("2. Print");
	puts("3. Peek & Delete Test");
	puts("9. Filter Test");
	puts("0. Quit");
	puts("=====================");
	printf("Select? ");
	scanf("%d", &m);
	return m;
}

Seq gen_prime();
void peek_delete(Seq);
void filter_test(Seq);

main()
{
	Seq prime;
	int m;

	m = menu();
	while( m ) {
		switch( m ) {
		case 1: prime = gen_prime(); break;
		case 2: seq_print(prime); break;
		case 3: peek_delete(prime); break;
		case 9: filter_test(prime); break;
		}
		m = menu();
	}
}

int is_prime(int n)
{
	int i, flag;
	flag = 1;
	for( i=3 ; i*i<=n ; i+=2 ) {
		if( n % i == 0 ) {
			flag = 0;
			break;
		}
	}
	return flag;
}

Seq gen_prime()
{
	Seq p;
	int i, n;

	printf("Input max n: ");
	scanf("%d", &n);
	p = seq_create();
	if( n > 2 )	seq_add_front(p, 2);
	if( n > 3 )	seq_add_back(p, 3);
	for( i=6 ; i<=n ; i+=6 ) {
		if( is_prime(i-1) )
			seq_add_front(p, i-1);
		if( is_prime(i+1) )
			seq_add_back(p, i+1);
	}
	return p;
}

void peek_delete(Seq seq)
{
	int val;

	printf("ALL: "); seq_print(seq);
	printf("First Value : %d\n", seq_peek_front(seq));
	printf("Last Value : %d\n", seq_peek_back(seq));

	puts("Delete front...");
	val = seq_del_front(seq);
	printf("return value=%d\n", val);
	printf("sequence: "); seq_print(seq);

	puts("Delete back...");
	val = seq_del_back(seq);
	printf("return value=%d\n", val);
	printf("sequence: "); seq_print(seq);
}

void filter_test(Seq all)
{
	Seq flt1, flt2, concat, dup;

	printf("ALL: "); seq_print(all);

	flt1 = seq_filter_lt(all, 50);
}
