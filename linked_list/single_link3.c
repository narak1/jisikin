#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _CARD {
 int no;
 char *name;
 int grade;
 char *stid;
} CARD; //CARD ����ü

typedef struct _node* pnode;

typedef struct _node {
 CARD element;
 pnode next;
} Node; //NODE ����ü

typedef struct _LIST {
 pnode head;
 int size;
} linkedlist; //LinkedList ����ü

pnode search(linkedlist *list, char *id);

void free_node(pnode node)
{
	if( node == NULL ) return;
	free(node->element.name);
	free(node->element.stid);
	free(node);
}

void add_item(linkedlist *plist){// ��� �߰� �Լ�
 //linkedlist�� �ּҰ� ����Ű�� ���� �Ѱܹ���
 pnode node;//���� �Ҵ���� ������ �����ּҸ� Node�� ������������ ��ȯ�� node�� ����
 node = (pnode)malloc(sizeof(Node));//�ڷ���Node�� ũ�⸸ŭ �޸��Ҵ�
node->element.no = plist->size + 1;//node�� no�� linkedlist�� size�� 1�߰��ؼ� �Ѱ� ��.
 node->element.name = (char*)malloc(sizeof(char)* 26);//�����޸� �Ҵ�
 node->element.stid = (char*)malloc(sizeof(char)* 13);// �����޸� �Ҵ�
 node->next = NULL;//�����ͺ��� next �ʱ�ȭ
 printf("id:");
 scanf("%s", node->element.stid);//Ű����κ��� �Է¹޾� stid�� �ּҸ��Ѱ���
 printf("name:");
 scanf("%s", node->element.name);//Ű����κ��� �Է¹޾� name�� �ּҸ��Ѱ���
 printf("grade:");
 scanf("%d", &node->element.grade);//Ű����κ��� �Է¹޾� grade�� �ּҸ��Ѱ���

 if (plist->head != NULL){//���࿡  plist�� head�� null�� �ƴ϶��
  node->next = plist->head;//node�� next������ plist�� head�� ����� �������� �ּҸ� ����
  plist->head = node;//plist�� head�� node�� �ּҴ���
 }
 else
 {//null�̶��
  plist->head = node;//head�����Ϳ� node�ּ� ����
 }
 plist->size++;//plist�� ������� ����� 1������Ų��.
}

void insert(linkedlist *plist, char *id)
{
 pnode node;//���� �Ҵ���� ������ �����ּҸ� Node�� ������������ ��ȯ�� node�� ����
 pnode position;//���ԵǴ� ��
 node = (pnode)malloc(sizeof(Node));//�ڷ���Node�� ũ�⸸ŭ �޸��Ҵ�
 node->element.no = plist->size + 1;//node�� no�� linkedlist�� size�� 1�߰��ؼ� �Ѱ� ��.
 node->element.name = (char*)malloc(sizeof(char)* 26);//�����޸� �Ҵ�
 node->element.stid = (char*)malloc(sizeof(char)* 13);// �����޸� �Ҵ�
 node->next = NULL;//�����ͺ��� next �ʱ�ȭ
 printf("id:");
 scanf("%s", node->element.stid);//Ű����κ��� �Է¹޾� stid�� �ּҸ��Ѱ���
 printf("name:");
 scanf("%s", node->element.name);//Ű����κ��� �Է¹޾� name�� �ּҸ��Ѱ���
 printf("grade:");
 scanf("%d", &node->element.grade);//Ű����κ��� �Է¹޾� grade�� �ּҸ��Ѱ���
 if ((position = search(plist, id)) != NULL){
  node->next = position->next;
  position->next = node;
 }
 else{
 	free_node(node);
  printf("not founded\n");
 }
}

void print_item(linkedlist *plist){//linkedlist�� �ּҰ� ����Ű�� ���� �Ѱܹ���
	struct _node *start = NULL;// _node ����ü�� �����ͺ��� start ���� �� �ʱ�ȭ.
	start = plist->head;//�����ͺ��� start�� plist�� ����Ű�� �ִ� head�� �ּ� ����
	printf("-----------------------\n");
	while (start != NULL)//start�� null�� �ƴϸ� ���� �ݺ�
	{
		printf("no: %d\n", start->element.no);//start�� ������� element�� no ���
		printf("id: %s\n", start->element.stid);//start�� ������� element�� stid ���
		printf("name: %s\n", start->element.name);//start�� ������� element�� name ���
		printf("grade: %d\n", start->element.grade);//start�� ������� element�� grade ���
		start = start->next;//�����ͺ��� start�� start�� ��������� �����ͺ��� next�� �ּҸ� ����
	}
}

pnode search(linkedlist *list, char *id)
{
  pnode pre=NULL;//������尡��Ŵ
 //�˻����
 pnode index = list->head;
 while (index != NULL){
  if (strcmp(id, index->element.stid) == 0)
  {
   return index;
  }
  else{
   pre = index;
   index = index->next;
  }
 }
 return NULL;
}

void delete_item(linkedlist* List,char *stid)
{
	pnode index;//������ ��� ����ų ���
	pnode pre =NULL;//������� ����ų ���

	if( List == NULL || List->head == NULL ) {
		printf("Empty list.\n");
		return;
	}

	pre = List->head;
	if( strcmp(pre->element.stid, stid) == 0 ) {
		List->head = pre->next;
		free_node(pre);
		return;
	}

	index = pre->next;
	while( index ) {
		if( strcmp(index->element.stid, stid) == 0 ) {
			break;
		}
	}

	if (index != NULL) {
		pre->next = index->next;
		free_node(index);
		List->size--;
	}
	else {
		printf("DELETE error\n");
	}
}

void main()
{
	linkedlist stdCard;// linkedlist ���� ����
	pnode find;
	char buf[32];

	stdCard.head = NULL;//stdCard�� ������� head �ʱ�ȭ.
	stdCard.size = 0;;//stdCard�� ������� size �ʱ�ȭ.
	add_item(&stdCard);//�߰� �������Լ��� stdcard�� �ּҸ� �Ѱ���.
	add_item(&stdCard);
	add_item(&stdCard);
	print_item(&stdCard);// ��¾������Լ��� stdcard�� �ּҸ� �Ѱ���.

	printf("finding item's id : ");
	scanf("%s", buf);
	find = search(&stdCard, buf);
	if (find != NULL) {
		printf("stid = %s\t name = %s\n", find->element.stid, find->element.name);
	}
	else
		printf("not find\n");

	insert(&stdCard, buf);
	print_item(&stdCard);
	printf("---------------����------------------\n");
	delete_item (&stdCard, buf);
	print_item(&stdCard);
}
