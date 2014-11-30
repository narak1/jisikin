#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
typedef struct node
{
 char name[100];
 int price;
 int area;
 struct node *link;
}Land;

void showMenu();
Land* makeNode();
void add_Data(Land **);
void show_Data(Land *);
void low_Price(Land **);
void high_Area(Land **);
void main()
{
 int num;
 Land *head=NULL;
 while(1)
 {
  system("cls");
  showMenu();
  printf("�Է� : ");
  scanf("%d",&num);
  fflush(stdin);
  switch(num)
  {
  case 1 :
   add_Data(&head);
   system("pause");
   continue;
  case 2 :
   show_Data(head);
   system("pause");
   continue;
  case 3 :
   low_Price(&head);	// head �� node�� �ٲ� �� ����.
   system("pause");
   continue;
  case 4 :
  	high_Area(&head);
   system("pause");
   continue;
  case 5 :
   break;
  default :
   printf("�߸� �Է��ϼ̽��ϴ�.\n");
   system("pause");
   continue;
  }
  break;
 }
}
void showMenu()
{
 printf("####### �ε��� ���� ���α׷� ######\n");
 printf("1. ���� ���� �Է�[�߰�]\n");
 printf("2. ��ü ���� ���\n");
 printf("3. �ŸŰ� ���� ������# ���� ��ȸ\n");
 printf("4. ���ø��� ���� ������ ���� ��ȸ\n");
 printf("5. ���α׷� ����\n");
 printf("####################################\n");
}
Land* makeNode()
{
 Land *pt=(Land*)malloc(sizeof(Land));
 pt->link=NULL;
 return pt;
}
void add_Data(Land **head)
{
 Land *cur, *tmp;

 cur = makeNode();
 printf("���� �̸� �Է� : ");
 gets(cur->name);
 printf("�ŸŰ� �Է� : ");
 scanf("%d",&cur->price);
 printf("���ø��� �Է� : ");
 scanf("%d",&cur->area);

 if(*head==NULL)
 {
  *head=cur;
  return;
 }
 tmp=*head;
 while(tmp->link!=NULL)
 {
  tmp=tmp->link;
 }
 tmp->link=cur;
}
void show_Data(Land *head)
{
 if(head==NULL)
 {
  printf("\n����� ������ �����ϴ�.\n");
  return;
 }
 while(head!=NULL)
 {
  printf("=============================\n");
  printf("�����̸� : %s \n",head->name);
  printf("�ŸŰ� : %d \n",head->price);
  printf("���� : %d \n",head->area);
  printf("=============================\n");
  head=head->link;
 }
}

enum SortMode { ASC=1, DESC=-1 };		// ��������, �������� 

int compare_Price(Land *n1, Land *n2)
{
	return n1->price - n2->price;
}

int compare_Area(Land *n1, Land *n2)
{
	return n1->area - n2->area;
}

void sort(Land **head, int (*cmp)(Land *,Land *), int mode);

void low_Price(Land **head)     // �̺κ��ε� ������ ���� �ȿ�...
{
	sort(head, compare_Price, ASC);
	show_Data(*head);
}

void high_Area(Land **head)
{
	sort(head, compare_Area, DESC);
	show_Data(*head);
}

void sort(Land **head, int (*cmp)(Land *,Land *), int mode)
{
	Land root, *pre, *cur;
	int flag;

	if( *head == NULL || (*head)->link == NULL ) {
		return;
	}

	root.link = *head;
	do {
		flag = 0;		// 1: not sort done, 0: all sorted, so done.
		pre = &root;
		cur = pre->link;
		while( cur->link ) {
			if( cmp(cur, cur->link) * mode > 0 ) {
				flag = 1;
				pre->link = cur->link;			// swap two nodes
				cur->link = cur->link->link;
				pre->link->link = cur;

				pre = pre->link;		// next node for check
			}
			else {
				pre = cur;
				cur = pre->link;
			}
		}
	} while( flag );
	*head = root.link;
}
