#include <stdio.h>
#include <stdlib.h>

typedef struct simpleLink
{
	int val;
	struct simpleLink *link;
} SimpleLink;

void add(SimpleLink **head, int num);
void print(SimpleLink *head);

int main()
{
	SimpleLink *head = NULL;
	int num;

	while(1) {
		print(head);
		printf("Input number: ");
		scanf("%d", &num);
		if( num < 0 )
			break;
		add(&head, num);
	}
}

void add(SimpleLink **head, int num)
{
	SimpleLink *tmp, *pre, *cur;
	
	tmp = (SimpleLink *) malloc(sizeof(SimpleLink));
	tmp->val = num;
	tmp->link = NULL;
	
	pre = *head;
	if( pre == NULL ) {
		*head = tmp;
	}
	else if( pre->val > num ) {
		tmp->link = pre;
		*head = tmp;
	}
	else {
		cur = pre->link;
		while( cur ) {
			if( cur->val > num ) {
				pre->link = tmp;
				tmp->link = cur;
				break;
			}
			pre = cur;
			cur = pre->link;
		}
		if( cur == NULL ) {
			pre->link = tmp;
		}
	}
}

void print(SimpleLink *head)
{
	while( head ) {
		printf("%d -> ", head->val);
		head = head->link;
	}
	puts("NULL");
}
