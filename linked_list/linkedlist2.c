#include <stdio.h>
#include <stdlib.h>

#define MALLOC(a,b) ((a) = (b*)malloc(sizeof(b)))

typedef struct ListNode *listPointer;
typedef struct ListNode
{
	int data;
	listPointer link;
} listNode;
 
listPointer creat2()
{ /* 2���� ��带 ���� ���� ����Ʈ�� ����*/
	listPointer first, second;
	MALLOC(first, listNode);
	MALLOC(second, listNode);
	second->link = NULL;
	second->data = 20;
	first->data = 10;
	first -> link = second;
	return first;
}

void insert(listPointer *first, listPointer x)
{ /* data = 50�� ���ο� ��带 ü��
    first�� ��� x�ڿ� ���� */
	listPointer temp;
	MALLOC(temp, listNode);
	temp->data = 50;
	if (*first) {
		temp -> link = x-> link;
		x->link = temp;
	}
	else {
		temp-> link = NULL;
		*first = temp;	
	}
}

void deletel (listPointer *first, listPointer trail, listPointer x)
{/* ����Ʈ�κ��� ��带 ����, trail�� ������ x�� ���� ����̸� first�� ����Ʈ�� ����*/
	if (trail) {
		trail -> link = x-> link;
		free(x);
	}
}
 
 
void printList (listPointer first)
{
	printf("The list contains : ");
	for (; first ; first = first -> link) {
		printf("%4d -> ", first -> data);
	}
	printf("\n");
}

int main()
{
	listPointer mylist;
	
	mylist = creat2();
	printList(mylist);
	
	insert(&mylist, mylist->link);		// 20 �ڿ� �߰� 
	insert(&mylist, mylist);			// 10 �ڿ� �߰� 
	printList(mylist);

	deletel(&mylist, mylist, mylist->link);		// 10 ���� 50 ����
	printList(mylist);
}
