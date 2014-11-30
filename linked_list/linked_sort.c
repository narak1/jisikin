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
  printf("입력 : ");
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
   low_Price(&head);	// head 의 node가 바뀔 수 있음.
   system("pause");
   continue;
  case 4 :
  	high_Area(&head);
   system("pause");
   continue;
  case 5 :
   break;
  default :
   printf("잘못 입력하셨습니다.\n");
   system("pause");
   continue;
  }
  break;
 }
}
void showMenu()
{
 printf("####### 부동산 정보 프로그램 ######\n");
 printf("1. 주택 정보 입력[추가]\n");
 printf("2. 전체 정보 출력\n");
 printf("3. 매매가 낮은 순으로# 정보 조회\n");
 printf("4. 주택면적 넓은 순으로 정보 조회\n");
 printf("5. 프로그램 종료\n");
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
 printf("주택 이름 입력 : ");
 gets(cur->name);
 printf("매매가 입력 : ");
 scanf("%d",&cur->price);
 printf("주택면적 입력 : ");
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
  printf("\n저장된 정보가 없습니다.\n");
  return;
 }
 while(head!=NULL)
 {
  printf("=============================\n");
  printf("주택이름 : %s \n",head->name);
  printf("매매가 : %d \n",head->price);
  printf("면적 : %d \n",head->area);
  printf("=============================\n");
  head=head->link;
 }
}

enum SortMode { ASC=1, DESC=-1 };		// 오름차순, 내림차순 

int compare_Price(Land *n1, Land *n2)
{
	return n1->price - n2->price;
}

int compare_Area(Land *n1, Land *n2)
{
	return n1->area - n2->area;
}

void sort(Land **head, int (*cmp)(Land *,Land *), int mode);

void low_Price(Land **head)     // 이부분인데 도저히 감이 안옴...
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
