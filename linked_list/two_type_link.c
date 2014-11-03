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

void read_file(const char *fname, Person **head);
void print_person(Person *p);
void sort_person(Person **head);

int main(int argc, char **argv)
{
	const char* fname = "jumsu.txt";
	Person *ybs;
	
	if( argc > 1 ) {
		fname = argv[1];
	}

	ybs = NULL;
	read_file(fname, &ybs);
	puts("read result");	
	print_person(ybs);
	
	// sort
	sort_person(&ybs);
	puts("sort result");
	print_person(ybs);	
}

char* rtrim(char *p)
{
	char *q;
	if( p == NULL || *p == 0 )
		return p;
		
	q = p + strlen(p) - 1;
	while( isspace(*q) ) {
		--q;
	}
	q[1] = 0;
	return p;
}

void read_file(const char *fname, Person **head)
{
	FILE *fp;
	char buf[BUFSIZ], *p;
	Person *tmp;
	Jumsu *pre, *cur;
	
	fp = fopen(fname, "r");
	if( fp == NULL ) {
		perror(fname);
		return;
	}
	
	while( fscanf(fp, "%s", buf) != EOF ) {
		tmp = (Person *) malloc(sizeof(Person));
		tmp->link = *head;
		*head = tmp;
		tmp->name = strdup(buf);
		tmp->jumsu = NULL;
		// jumsu
		fgets(buf, BUFSIZ-1, fp);
		rtrim(buf);
		p = buf;
		pre = tmp->jumsu;
		while( *p ) {
			cur = (Jumsu *) malloc(sizeof(Jumsu));
			cur->next = NULL;
			if( pre == NULL ) {
				tmp->jumsu = cur;
			}
			else {
				pre->next = cur;
			}
			cur->val = strtol(p, &p, 10);
			
			pre = cur;
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

void sort_person(Person **head)
{
	Person hdr, *pre, *cur, *post, *tmp;
	int flag;
	
	if( head == NULL || *head == NULL ) {
		return;
	}

	hdr.link = *head;
	do {
		pre = &hdr;
		cur = pre->link;
		post = cur->link;
		flag = 0;				// exchange flag
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
	*head = hdr.link;
}
