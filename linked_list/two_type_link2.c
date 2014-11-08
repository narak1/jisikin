#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _jumsu
{
	int val;
	struct _jumsu *next;
} Jumsu;

typedef struct _person
{
	char *name;
	Jumsu *jumsu;
	struct _person *link;
} Person;

void read_file(const char *fname, Person *head);
void print_person(Person *p);

int main(int argc, char **argv)
{
	const char* fname = "jumsu.txt";
	Person head;
	
	if( argc > 1 ) {
		fname = argv[1];
	}

	read_file(fname, &head);
	puts("read result");	
	print_person(head.link);
}

Person *find_person(Person *head, char *name)
{
	Person *cur;
	cur = head->link;
	while( cur ) {
		if( strcmp(cur->name, name) == 0 ) {
			break;
		}
		cur = cur->link;
	}
	return cur;
}

void read_file(const char *fname, Person *head)
{
	FILE *fp;
	char name[BUFSIZ];
	int val;
	Person *cur, *tail;
	Jumsu *tmp, *pre;
	
	fp = fopen(fname, "r");
	if( fp == NULL ) {
		perror(fname);
		return;
	}
	
	tail = head;
	while( fscanf(fp, "%s%d", name, &val) != EOF )
	{
		cur = find_person(head, name);
		if( cur == NULL ) {
			cur = (Person *) malloc(sizeof(Person));
			cur->name = strdup(name);
			cur->jumsu = NULL;
			cur->link = NULL;
			
			tail->link = cur;
			tail = cur;
		}
		
		// add jumsu
		tmp = (Jumsu *) malloc(sizeof(Jumsu));
		tmp->val = val;
		tmp->next = NULL;
	
		pre = cur->jumsu;
		if( pre == NULL ) {
			cur->jumsu = tmp;
		}
		else {
			while( pre->next ) {
				pre = pre->next;
			}
			pre->next = tmp;
		}
	}
	fclose(fp);
}

void print_person(Person *p)
{
	Jumsu *j;
	while( p ) {
		printf("%-10s", p->name);
		j = p->jumsu;
		while( j ) {
			printf(" %d", j->val);
			j = j->next;
		}
		puts("");
		p = p->link;
	}
}

void sort_person(Person *head)
{
	Person *pre, *cur, *post, *tmp;
	int flag;

	if( head ==  NULL || head->link == NULL ) {
		return;
	}

	do {
		pre = head;
		cur = pre->link;
		post = cur->link;
		flag = 0;		// exchange flag
		while( post ) {
			if( strcmp(cur->name, post->name) > 0 ) {
				flag = 1;
				cur->link = post->link;
				pre->link = post;
				post->link = cur;
				
				pre = post;
				//cur is not change
				post = cur->link;
			}
			else {
				pre = cur;
				cur = post;
				post = cur->link;
			}
		}
	} while( flag );	
}
