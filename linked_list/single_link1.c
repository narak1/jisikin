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
 insert_data(&Head,10);  //����
 insert_data(&Head,20);  //����
 insert_data(&Head,30);  //����
 insert_data(&Head,40);  //����
 modify_data(Head,20,22);  //����  20��22�κ���
 delete_data(&Head,20);  //����//20�̶�� �����͸� �����ض�
 search_data(Head,22);  //�˻�  //22��µ����͸��˻�(��°��� �����Ϳ� ����� �ּ�)
 print_data(Head);  //��� ���������ϴ� ��Ʈ�� �����Ͱ� ��� ���
 add_data(Head,22,26);  //�߰� //22�ڿ� 26�� �߰�
 print_data(Head);
 return 0;
}
