#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 노드로 사용 될 구조체 */
struct elt {
   char name[10];
   struct elt *next;
};
typedef struct elt ELEMENT;
typedef ELEMENT *LINK;
void WaitingList();              /* 대기자 명단 출력 함수 */
void AddQ();                   /* 대기자 명단 추가 함수 */
void DeleteQ();                 /* 대기자 명단 삭제 함수 */
void input();                   /* 매뉴얼 번호를 입력 받기 위한 함수 */
LINK q;                       /* 원형 연결리스트의 포인터 */
int count;                      /* 대기자의 총 수를 나타내기 위해 */
char names[10];
int order;
LINK fq;		/* Free List Pointer */
int main()
{
   while(1) {
      printf("         ****** 미 선 이 네  항 공 사 ******        \n");
      printf("\n╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋\n");
      printf(" 매 뉴 얼 \n");
      printf("━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
      printf("++[ 1 ]++  현재 대기자 명단 출력     \n");
      printf("++[ 2 ]++  대기자 명단 추가          \n");
      printf("++[ 3 ]++  대기자 명단 삭제          \n");
      printf("++[ 4 ]++ 종료 \n\n");
      printf("━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      printf("원하시는 매뉴얼을 선택해주세요.\n");
      printf("╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋\n\n");
      printf("입력 : ");
      input(); /* 매뉴얼 번호 입력 함수 호출 */
      /* 입력받은 매뉴얼의 번호에 따라 처리하는 함수 호출 */
      switch(order) {
      /* 대기자 명단 출력을 선택했을 경우 */
      case 1:
         printf("\n ╋╋╋ 현재 대기자 명단 ╋╋╋ \n");
         WaitingList();
         printf("╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋\n\n\n");
         break;
      /* 대기자 명단 추가를 선택했을 경우 */
      case 2:
         printf("\n ╋╋╋ 대기자 명단 추가 ╋╋╋ \n");
         AddQ();
         printf("\n╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋\n\n\n");
         break;
      /* 대기자 명단 삭제를 선택했을 경우 */
      case 3:
         printf("\n ╋╋╋ 대기자 명단 삭제 ╋╋╋ \n");
         DeleteQ();
         printf("\n╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋\n\n\n");
         break;
      /* 종료를 선택했을 경우 */
      case 4:
         printf("\n ╋╋╋ 이용해 주셔서 감사합니다. ╋╋╋ \n");
         exit(0);
      }
   }
}
/* 대기자 명단 출력하는 함수 */
void WaitingList()
{
   int i, j=0;
   LINK p;
   /* 대기자가 없는 경우 오류 처리 */
   if(count <= 0) {
      printf("\n 현재 대기자가 없습니다. \n\n\n");
   }
   else {
   	  printf("q = %p ; fq = %p\n", q, fq);
   	  puts("---------------------");
      p = q -> next;
      for(i = 0; i < count; i++) {
//         printf(" %3d 번 : %s\n", i+1, p -> name);     
         printf("p = %p ; %3d 번 : %s\n", p, i+1, p -> name);     
         p = p -> next;
      }
   }
   printf("현재 대기자는 %3d명 입니다.\n", count);
}
/* 대기자 명단 추가하는 함수 */
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
   printf("이름을 입력해 주세요 : ");
   scanf("%s",x->name);

   /* 현재 대기자가 없는 경우 */
   if(q == NULL) {
      q = x;
      x -> next = q;
   }
   /* 대기자가 있는 경우 */
   else {
      x -> next = q -> next;
      q -> next = x;
      q = x;
   }
   count++;
   WaitingList();
}
/* 대기자 명단 삭제하는 함수 */
void DeleteQ()
{
   LINK x;
   /* 대기자가 없는 경우 (Queue-Empty) 오류 처리 */
   if(q == NULL) {
      printf("\n 삭제 할 대기자가 없습니다. \n");
      printf(" 다시 확인해 주세요 \n\n\n");
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
/* 매뉴얼 번호 입력하는 함수 */
void input()
{
   scanf("%d", &order);
   /* 1~4 이외의 값을 입력받은 경우 오류 처리 */
   if (order < 1 || order > 4) {
         printf("잘못 입력 하셨습니다. 1~4번까지 매뉴얼만 있습니다. \n");
         printf("다시 입력해주세요.\n");
         printf("입력 : ");
         input();
   }
}
