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
{ /* 2개의 노드를 가진 연결 리스트의 생성*/
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
{ /* data = 50인 새로운 노드를 체인
    first의 노드 x뒤에 삽입 */
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
{/* 리스트로부터 노드를 삭제, trail은 삭제될 x의 선행 노드이며 first는 리스트의 시작*/
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
	
	insert(&mylist, mylist->link);		// 20 뒤에 추가 
	insert(&mylist, mylist);			// 10 뒤에 추가 
	printList(mylist);

	deletel(&mylist, mylist, mylist->link);		// 10 뒤의 50 삭제
	printList(mylist);
}
