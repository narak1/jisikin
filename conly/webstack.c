#include <stdio.h>
#include <string.h>

#define MAXSTACK (100+1)
#define MAXURLLEN (70+1)

typedef struct
{
	int sp, top;
	char url[MAXSTACK][MAXURLLEN];	
} DualStack;

typedef enum { Back, Forward, Visit, Quit, MaxCmd } Command;
const char *command[] = { "BACK", "FORWARD", "VISIT", "QUIT" };

void stack_init(DualStack *st);
char* stack_back(DualStack *st);
char* stack_fore(DualStack *st);
void stack_new(DualStack *st, char *url);

Command find_commad(char *cmd_str, char **url)
{
	int i, cmd;
	for( i=0 ; i<MaxCmd-Back ; i++ ) {
		if( strncmp(cmd_str, command[i], strlen(command[i])) == 0 ) {
			break;
		}
	}
	cmd = i + Back;
	
	if( cmd == Visit ) {
		*url = cmd_str + strlen(command[cmd]) + 1;
	}
	
	return cmd;
}

main()
{
	char cmd_str[100], *url;
	Command cmd;
	DualStack web;
	
	stack_init(&web);
	stack_new(&web, "http://www.acm.org/");
	
	do {
		gets(cmd_str);
		cmd = find_commad(cmd_str, &url);
		switch(cmd) {
			case Back:
				url = stack_back(&web);
				if( url == NULL ) {
					puts("Ignored");
				}
				else {
					puts(url);
				}
				break;
			case Forward:
				url = stack_fore(&web);
				if( url == NULL ) {
					puts("Ignored");
				}
				else {
					puts(url);
				}
				break;
			case Visit:
				stack_new(&web, url);
				puts(url);
				break;
			case Quit:
				break;
		}
	} while( cmd != Quit );
}

void stack_init(DualStack *st)
{
	st->sp = st->top = -1;
}

char* stack_back(DualStack *st)
{
	char *ret;
	if( st->sp <= 0 ) {
		ret = NULL;
	}
	else {
		--(st->sp);
		ret = st->url[st->sp];
	}
	return ret;
}

char* stack_fore(DualStack *st)
{
	if( st->sp == st->top ) {
		return NULL;
	}
	else {
		++(st->sp);
		return st->url[st->sp];
	}
}

void stack_new(DualStack *st, char *url)
{
	++(st->sp);
	st->top = st->sp;
	strcpy(st->url[st->sp], url);
}
