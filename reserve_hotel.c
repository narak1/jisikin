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
  printf("�ԽǷ�����: ");
  scanf("%d", &room_num);
  i = room_num/100 - 1;
  k = room_num%100 - 1;
  if(h->normal[i][k]==0)
  {
   printf("���������ϴ�. ������Ǽ���..\n");
   printf("�ݾ���10�����Դϴ�.\n");
   h->normal[i][k] = 1;
  }
  else
  {
   printf("���̰���á���ϴ�");
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

  printf("��Ƿ�����: ");
  scanf("%d",&room_num);
  
  i = room_num/100 - 1;
  k = room_num%100 - 1;
  if( h->normal[i][k] != 0 ) {
   printf("��������̳���?");
   printf("�ȳ���������.");
   h->normal[i][k] = 0;
  }
  else
  {
   printf("����Դϴ�");
  }
 }
 else
 {
  Room_print_special();
  
  printf("��Ƿ�����: \n");
  scanf("%d",&room_num);
  k = room_num%100 - 1;
  printf("��������̳���? Ư���̶�����?");
  if(h->special[k] == 1)
  {
   printf("�ݾ���100�����Դϴ�.");
  }
  else
  {
   printf("�ݾ���100����+ �����10����������110�����Դϴ�.");
  }
  printf("�ȳ���������");
  h->special[k] = 0;
 }
}
void Normal_Room()
{
 int in_out;
 puts("\n*************�Ϲݽ�***************");
 printf("<1>. �Խ�<2>. ���: ");
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
  printf("�����������Է����ּ���");
 }
}
void Special_Room()
{
 int in_out;
 puts("\n**************Ư ��*************");
 printf(" <1>. �Խ�<2>. ���: ");
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
  printf("���Ǻ������Է����ּ���");
 }
}
void Room_print_normal()
{
 int i,k;
 printf("\n**************�Ϲݽ��������Դϴ�.*****************\n");
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
 printf("\n***************Ư���������Դϴ�.******************\n");
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

 puts("\nRiver Side Hodel"); // �޸𸮰� ������ ������ ��� 0���� �ʱ�ȭ 
 Room_print_normal();
 Room_print_special();

	puts("\n\n");
	 
 h = &hotel;
 //init_Hotel();		// �޸𸮰� ���ÿ� ������ �ʱ�ȭ�� ���ϸ� ������ 
 puts("No Name Hodel"); 
 Room_print_normal();
 Room_print_special();

 do
 {
  printf("***************************************\n");
  printf("*************2��ȣ��*******************\n");
  printf("***************************************\n");
  printf("**<1>.�Ϲ�**<2>.Ư��**<3>.����*********\n");
  printf("**************<4>.����*****************\n");
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
   printf("���Ǻ����߿��������ּ���.\n");
  }
 }while(choice);
}
