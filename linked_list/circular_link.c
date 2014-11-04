#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ���� ��� �� ����ü */
struct elt {
   char name[10];
   struct elt *next;
};
typedef struct elt ELEMENT;
typedef ELEMENT *LINK;
void WaitingList();              /* ����� ��� ��� �Լ� */
void AddQ();                   /* ����� ��� �߰� �Լ� */
void DeleteQ();                 /* ����� ��� ���� �Լ� */
void input();                   /* �Ŵ��� ��ȣ�� �Է� �ޱ� ���� �Լ� */
LINK q;                       /* ���� ���Ḯ��Ʈ�� ������ */
int count;                      /* ������� �� ���� ��Ÿ���� ���� */
char names[10];
int order;
LINK fq;		/* Free List Pointer */
int main()
{
   while(1) {
      printf("         ****** �� �� �� ��  �� �� �� ******        \n");
      printf("\n��������������������������������������������������\n");
      printf(" �� �� �� \n");
      printf("��������������������������������������������������\n\n");
      printf("++[ 1 ]++  ���� ����� ��� ���     \n");
      printf("++[ 2 ]++  ����� ��� �߰�          \n");
      printf("++[ 3 ]++  ����� ��� ����          \n");
      printf("++[ 4 ]++ ���� \n\n");
      printf("����������������������������������������������������\n");
      printf("���Ͻô� �Ŵ����� �������ּ���.\n");
      printf("��������������������������������������������������\n\n");
      printf("�Է� : ");
      input(); /* �Ŵ��� ��ȣ �Է� �Լ� ȣ�� */
      /* �Է¹��� �Ŵ����� ��ȣ�� ���� ó���ϴ� �Լ� ȣ�� */
      switch(order) {
      /* ����� ��� ����� �������� ��� */
      case 1:
         printf("\n ������ ���� ����� ��� ������ \n");
         WaitingList();
         printf("��������������������������������\n\n\n");
         break;
      /* ����� ��� �߰��� �������� ��� */
      case 2:
         printf("\n ������ ����� ��� �߰� ������ \n");
         AddQ();
         printf("\n��������������������������������\n\n\n");
         break;
      /* ����� ��� ������ �������� ��� */
      case 3:
         printf("\n ������ ����� ��� ���� ������ \n");
         DeleteQ();
         printf("\n��������������������������������\n\n\n");
         break;
      /* ���Ḧ �������� ��� */
      case 4:
         printf("\n ������ �̿��� �ּż� �����մϴ�. ������ \n");
         exit(0);
      }
   }
}
/* ����� ��� ����ϴ� �Լ� */
void WaitingList()
{
   int i, j=0;
   LINK p;
   /* ����ڰ� ���� ��� ���� ó�� */
   if(count <= 0) {
      printf("\n ���� ����ڰ� �����ϴ�. \n\n\n");
   }
   else {
   	  printf("q = %p ; fq = %p\n", q, fq);
   	  puts("---------------------");
      p = q -> next;
      for(i = 0; i < count; i++) {
//         printf(" %3d �� : %s\n", i+1, p -> name);     
         printf("p = %p ; %3d �� : %s\n", p, i+1, p -> name);     
         p = p -> next;
      }
   }
   printf("���� ����ڴ� %3d�� �Դϴ�.\n", count);
}
/* ����� ��� �߰��ϴ� �Լ� */
void AddQ()
{
   LINK x;
   if( fq == NULL ) {
     x = (LINK) malloc (sizeof(ELEMENT));
   }
   else {
     x = fq;
     fq = fq->next;
   }
   printf("�̸��� �Է��� �ּ��� : ");
   scanf("%s",x->name);

   /* ���� ����ڰ� ���� ��� */
   if(q == NULL) {
      q = x;
      x -> next = q;
   }
   /* ����ڰ� �ִ� ��� */
   else {
      x -> next = q -> next;
      q -> next = x;
      q = x;
   }
   count++;
   WaitingList();
}
/* ����� ��� �����ϴ� �Լ� */
void DeleteQ()
{
   LINK x;
   /* ����ڰ� ���� ��� (Queue-Empty) ���� ó�� */
   if(q == NULL) {
      printf("\n ���� �� ����ڰ� �����ϴ�. \n");
      printf(" �ٽ� Ȯ���� �ּ��� \n\n\n");
   }
   else {
   	  x = q->next;
      if( count == 1 ) {
   	     q = NULL;
   	  }
   	  else {
         q -> next = x -> next;
   	  }

   	  x->next = fq;		/* move x to free queue */
   	  fq = x;

      count--;
      WaitingList();
   }
}
/* �Ŵ��� ��ȣ �Է��ϴ� �Լ� */
void input()
{
   scanf("%d", &order);
   /* 1~4 �̿��� ���� �Է¹��� ��� ���� ó�� */
   if (order < 1 || order > 4) {
         printf("�߸� �Է� �ϼ̽��ϴ�. 1~4������ �Ŵ��� �ֽ��ϴ�. \n");
         printf("�ٽ� �Է����ּ���.\n");
         printf("�Է� : ");
         input();
   }
}
