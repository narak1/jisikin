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
  printf("1. ������ \n");
  printf("2. ���α׷� ���� \n");
  printf("---------------------- \n");
  printf("���� = ");
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
 //ó�� ��� ����
 p = (node*)malloc(sizeof(node));
 p->data = 1;
 p->link = NULL; // ����ų�� ��� NULL�� ����
 head = p;
 last = p; // ó������ �������̴ϱ� ��Ʈ ������
 
 //�ι�° ��� ����
 p = (node*)malloc(sizeof(node));
 p->data = 2;
 p->link = NULL; // ����ų�� ��� NULL�� ����
 
 //�� ��带 ����
 last->link = p;
 last = p; // �ι�° ��尡 �������̴ϱ� ��Ʈ ������

 //����° ��带 ����
 p = (node*)malloc(sizeof(node));
 p->data = 3;
 p->link = NULL;
 last->link=p; // �ι�° ��忡 �����Ű��
 last=p; // ������ ���� ����° ��尡 ��

 p = (node*)malloc(sizeof(node));
 p->data = 4;
 p->link = NULL;
 last->link=p; // ����
 last = p;
 // ����Ʈ�� ���
 p=head; //����Ʈ�� ó������ �����ϰڴٴ� ��
 while(p != NULL) { 
  printf ("%d--->",p->data); // ���� �ƴѵ��� ��� ����ϴ°� ���̳����� ������
  p=p->link; // �������
 printf ("\n");
 }
}
