#include <stdio.h>
#include <malloc.h>

 typedef struct node
 {
  int data;
  struct node *link;
 }node;
 node *head, *p, *last;

void createNode();

void main()
{
 int in;
 while (1)
 {
  printf("***** MENU ***** \n");
  printf("1. 노드생성 \n");
  printf("2. 프로그램 종료 \n");
  printf("---------------------- \n");
  printf("선택 = ");
  scanf("%d",&in);
   if (in == 1)
   {
    createNode();
   }
   else if (in == 2)
    break;
 }
}

void createNode()
{
 //처음 노드 생성
 p = (node*)malloc(sizeof(node));
 p->data = 1;
 p->link = NULL; // 가리킬게 없어서 NULL로 써줌
 head = p;
 last = p; // 처음이자 마지막이니까 라스트 붙혀줌
 
 //두번째 노드 생성
 p = (node*)malloc(sizeof(node));
 p->data = 2;
 p->link = NULL; // 가리킬게 없어서 NULL로 써줌
 
 //두 노드를 연결
 last->link = p;
 last = p; // 두번째 노드가 마지막이니까 라스트 붙혀줌

 //세번째 노드를 생성
 p = (node*)malloc(sizeof(node));
 p->data = 3;
 p->link = NULL;
 last->link=p; // 두번째 노드에 연결시키고
 last=p; // 마지막 노드는 세번째 노드가 됨

 p = (node*)malloc(sizeof(node));
 p->data = 4;
 p->link = NULL;
 last->link=p; // 연결
 last = p;
 // 리스트를 출력
 p=head; //리스트의 처음부터 시작하겠다는 뜻
 while(p != NULL) { 
  printf ("%d--->",p->data); // 널이 아닌동안 계속 출력하는거 널이나오면 끝나게
  p=p->link; // 다음노드
 printf ("\n");
 }
}
