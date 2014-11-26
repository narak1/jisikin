#include <stdio.h>
//#define Hotel
struct Hotel
{
 int normal[9][10];
 int special[10];
};

Hotel riverSide;
Hotel *h = &riverSide;

void Room_print_normal();
void Room_print_special();

void init_Hotel()
{
 for(int i = 0; i<10; i++)
 {
  h->special[i] = 0;
 }
 for(int k = 0; k<9; k++)
 {
  for(int s = 0; s<10; s++)
  {
   h->normal[k][s] = 0;
  }
 }
}
void In(int ro1)
{
 int i,k;
 int room_num;
 if(ro1 == 1)
 {
  Room_print_normal();
  printf("입실룸지정: ");
  scanf("%d", &room_num);
  i = room_num/100 - 1;
  k = room_num%100 - 1;
  if(h->normal[i][k]==0)
  {
   printf("방이좋습니다. 좋은밤되세요..\n");
   printf("금액은10만원입니다.\n");
   h->normal[i][k] = 1;
  }
  else
  {
   printf("방이가득찼습니다");
  }
 }
}
void Out(int ro2)
{
 int i,k;
 int room_num;
 if(ro2==1)
 {
  Room_print_normal();

  printf("퇴실룸지정: ");
  scanf("%d",&room_num);
  
  i = room_num/100 - 1;
  k = room_num%100 - 1;
  if( h->normal[i][k] != 0 ) {
   printf("편안히쉬셨나요?");
   printf("안녕히가세요.");
   h->normal[i][k] = 0;
  }
  else
  {
   printf("빈방입니다");
  }
 }
 else
 {
  Room_print_special();
  
  printf("퇴실룸지정: \n");
  scanf("%d",&room_num);
  k = room_num%100 - 1;
  printf("편안히쉬셨나요? 특실이라좋죠?");
  if(h->special[k] == 1)
  {
   printf("금액은100만원입니다.");
  }
  else
  {
   printf("금액은100만원+ 음료수10만원으로총110만원입니다.");
  }
  printf("안녕히가세요");
  h->special[k] = 0;
 }
}
void Normal_Room()
{
 int in_out;
 puts("\n*************일반실***************");
 printf("<1>. 입실<2>. 퇴실: ");
 scanf("%d",&in_out);
 if(in_out == 1)
 {
  In(1);
 }
 else if(in_out == 2)
 {
  Out(1);
 }
 else
 {
  printf("위에보기중입력해주세요");
 }
}
void Special_Room()
{
 int in_out;
 puts("\n**************특 실*************");
 printf(" <1>. 입실<2>. 퇴실: ");
 scanf("%d", &in_out);
 
 if(in_out == 1)
 {
  In(2);
 }
 else if(in_out == 2)
 {
  Out(2);
 }
 else
 {
  printf("위의보기중입력해주세요");
 }
}
void Room_print_normal()
{
 int i,k;
 printf("\n**************일반실의정보입니다.*****************\n");
 puts("     1234567890");
 for(i = 0; i<9; i++)
 {
 	printf("%d: ", (i+1)*100);
  for(k = 0; k<10; k++)
  {
   if(h->normal[i][k] == 0)
   {
    printf("O");
   }
   else
   {
    printf("X");
   }
  }
  printf("\n");
 }
}
void Room_print_special()
{
 int j;
 printf("\n***************특실의정보입니다.******************\n");
 puts("12345678910");
 for(j = 0; j<10; j++)
 {
  if(h->special[j] == 0)
  {
   printf("O");
  }
  else
  {
   printf("X");
  }
 }
 printf("\n");
}
int main()
{
 struct Hotel hotel;
 int choice;

 puts("\nRiver Side Hodel"); // 메모리가 전역에 잡혀서 모두 0으로 초기화 
 Room_print_normal();
 Room_print_special();

	puts("\n\n");
	 
 h = &hotel;
 //init_Hotel();		// 메모리가 스택에 잡히고 초기화를 안하면 랜덤값 
 puts("No Name Hodel"); 
 Room_print_normal();
 Room_print_special();

 do
 {
  printf("***************************************\n");
  printf("*************2조호텔*******************\n");
  printf("***************************************\n");
  printf("**<1>.일반**<2>.특실**<3>.보기*********\n");
  printf("**************<4>.종료*****************\n");
  printf("Choice Num.. : ");
  scanf("%d", &choice);
  
  if(choice == 1)
  {
   Normal_Room();
  }
  else if (choice == 2)
  {
   Special_Room();
  }
  else if (choice == 3)
  {
   Room_print_normal();
   Room_print_special();
  }
  else if (choice == 4)
  {
   break;
  }
  else
  {
   printf("위의보기중에선택해주세요.\n");
  }
 }while(choice);
}
