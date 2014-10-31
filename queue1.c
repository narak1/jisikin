/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
 * Description  : Circular Queue ����
 * Author        : UTRCy
 * Last mod.  : 2014. 10. 9,   
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE  5
#define SUCCESS   1
#define FAIL     0
#define TRUE     1
#define FALSE    0
/*=======================================================================
  Function prototypes for Local Functions
=======================================================================*/
int   enqueue(char data);
char  dequeue();
void  dsp_queue();
/*=======================================================================
  Circular Queue Data structure
=======================================================================*/
char  CQueue[QUEUE_SIZE];  // Circular Queue Buffer
int   in  = 0;        // Circular Queue In pointer
int   out = 0;        // Circular Queue Out pointer
int   queue_flag = 0; // Queue is Empty(0), Full(1), these case in == out
enum QueueFlag { QueueEmpty, QueueFull, QueueNormal };
/*=======================================================================
 * main()
 *=======================================================================*/
int main()
{
 char selMenu;
 char retValue;
 char data;
 for (;;)
 {
  fflush(stdin);
  //��� ����
  printf("###��ɼ���>>");
  printf( " 'i' : Enqueue  'o' : Dequeue  'd' : Queue Display  'e' : exit >> ");
  retValue = scanf("%c", &selMenu);
  fflush(stdin);
 
  switch (selMenu) {
  case 'i' :
   printf("\n   *Enqueue �� ����Ÿ�� �Է��ϼ��� : ");
   scanf("%c", &data);
   if ( enqueue(data) == FAIL )
   {
    printf("\n\t ^-^ Circular Queue�� FULL�� �Ǿ� Inqueue �Ҽ� �����ϴ�.\n\n");
   }
   else
   {
    printf("\n\t ^-^ Enqueue [%c] Success !!\n\n", data);
    dsp_queue();
   }
   break;
  
  case 'o' :
   if ( (dequeue(&data)) == FAIL )
   {
    printf("\n\t ^-^ Circular Queue�� Empty�� �Ǿ� dequeue �Ҽ� �����ϴ�.\n\n");
   }
   else
   {
    printf("\n\t ^-^ Dequeue [%c] Success !!\n\n", data);
    dsp_queue();
   }
   break;
  case 'd' :
    dsp_queue();
    break;
   
   case 'e' :
    printf("### ���α׷� ����.!!\n");
    exit(0);
  default:
    printf("\n\t ERROR : Ÿ���� ��� ������ �ƴմϴ�. �ٽ� �����ϼ���.. \n\n");
   
  }//switch
 }//for
 return SUCCESS;
}

/*=======================================================================
 Enqueue a char to the circular queue
 - Input : Data to enqueue
 * Ret  : Success 1, Fail 0 - Stack Full
 *=======================================================================*/
int enqueue(char data)
{
	if( queue_flag == QueueFull )
	{
		return FAIL;
	}

	CQueue[in] = data;
	in = (in + 1) % QUEUE_SIZE;
	if( in == out ) {
		queue_flag = QueueFull;
	}
	else {
		queue_flag = QueueNormal;
	}
		
	return SUCCESS;
}
/*=======================================================================
 Dequeue a char to the circular queue
  - ret : SUCCESS when 1, Fail 0 - Stack Empty
 *=======================================================================*/
char dequeue(char *data)
{
	if( queue_flag == QueueEmpty )
	{
		return FAIL;
	}

 	*data = CQueue[out];
 	out = (out + 1) % QUEUE_SIZE;
 	if( in == out ) {
 		queue_flag = QueueEmpty;
 	}
 	else {
		queue_flag = QueueNormal; 		
 	}
 		
   return SUCCESS;
}
/*=======================================================================
  Desplay the contents of the queue
 *=======================================================================*/
void dsp_queue()
{
	int i, num;

	if( queue_flag == QueueEmpty )
	{
		puts("Queue is empty!\n");
	}
	else
	{
		num = in - out;
		if( num <= 0 ) {
			num += QUEUE_SIZE;
		}
			
		for( i=0 ; i<num ; i++ )
		{
			printf("%d : %c\n", i+1, CQueue[(i+out) % QUEUE_SIZE]);		
		}
		puts("");
	}
}
