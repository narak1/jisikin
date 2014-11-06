#include <stdio.h>
#include <malloc.h>
struct Node{
  int data;
  struct Node *link;
};
typedef struct Node Link;
Link *Get_node(){
 Link *tmp = (Link*)malloc(sizeof(Link));
 tmp->link=NULL;
 return tmp;
}
void insert_data(Link ** Head,int data)
{
	Link *tmp;
	tmp = Get_node();
	tmp->data = data;
	if(*Head != NULL)
	{
		tmp->link = *Head;
	}
	*Head = tmp;
}

void modify_data(Link *Head, int old, int data)
{
	while( Head ) {
		if( Head->data == old ) {
			Head->data = data;
			break;
		}
		Head = Head->link;
	}
}

void delete_data(Link **head, int data)
{
	Link *pre, *cur;
	
	if( *head == NULL ) {
		return;
	}

	pre = *head;
	cur = pre->link;
	if( pre->data == data ) {
		*head = cur;
		free(pre);
		return;
	}
	
	while( cur ) {
		if( cur->data == data ) {
			pre->link = cur->link;
			free(cur);
			break;
		}
		pre = cur;
		cur = pre->link;
	}
}

void search_data(Link *head, int data)
{
	while( head ) {
		if( head->data == data ) {
			printf("data=%d, node=%p, link=%p\n", head->data, head, head->link);
			break;
		}
		head = head->link;
	}	
}

void print_data(Link *head)
{
	while( head ) {
		printf("%d -> ", head->data);
		head = head->link;
	}
	puts("");
}

void add_data(Link *head, int old, int data)
{
	Link *tmp;

	while( head ) {
		if( head->data == old ) {
			tmp = Get_node();
			tmp->data = data;
			tmp->link = head->link;
			head->link = tmp;
			break;
		}
		head = head->link;
	}	
}

int main()
{
 Link *Head =NULL;
 insert_data(&Head,10);  //삽입
 insert_data(&Head,20);  //삽입
 insert_data(&Head,30);  //삽입
 insert_data(&Head,40);  //삽입
 modify_data(Head,20,22);  //수정  20을22로변경
 delete_data(&Head,20);  //삭제//20이라는 데이터를 삭제해라
 search_data(Head,22);  //검색  //22라는데이터를검색(출력값은 데이터와 노드의 주소)
 print_data(Head);  //출력 현재존재하는 노트의 데이터가 모두 출력
 add_data(Head,22,26);  //추가 //22뒤에 26을 추가
 print_data(Head);
 return 0;
}
