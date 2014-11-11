#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <time.h> 
#define STACK_SIZE 100 
#define cQ_SIZE 4 
typedef int element; 
typedef struct{ 
   element queue[cQ_SIZE]; // 1���� �迭 ť ���� 
   int front, rear; 
} cQueueType; 
cQueueType *createQueue() 
{ 
   cQueueType *cQ; 
   cQ = (cQueueType *)malloc(sizeof(cQueueType)); 
   cQ->front=0; // ���� ť�� front �ʱⰪ ���� 
   cQ->rear=0; // ���� ť�� rear �ʱⰪ ���� 
   return cQ; 
} 
int isEmpty(cQueueType *cQ) // ���� ť�� �������� Ȯ���ϴ� ���� 
{ 
   if (cQ->front == cQ->rear) { 
      printf("\n Circular Queue is empty! \n");  
      return 1; 
   } 
   else return 0; 
} 
int isFull(cQueueType *cQ) // ���� ť�� ��ȭ �������� Ȯ���ϴ� ���� 
{ 
   if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) { 
      printf("\n Circular Queue is full! \n"); 
      return 1; 
   } 
   else return 0; 
} 
void enQueue(cQueueType *cQ, element item)  
// ���� ť�� rear�� ���Ҹ� �����ϴ� ���� 
{ 
   if(isFull(cQ)) return; 
   else { 
      cQ->rear = (cQ->rear + 1) % cQ_SIZE; 
      cQ->queue[cQ->rear] = item; 
   } 
} 
element deQueue(cQueueType *cQ)  
// ����ť�� front�������Ҹ� �����ϰ� ��ȯ�ϴ� ���� 
{ 
   if (isEmpty(cQ)) return -1; 
   else { 
      cQ->front = (cQ->front + 1) % cQ_SIZE; 
      return cQ->queue[cQ->front]; 
   } 
} 
void printQueue(cQueueType *cQ)
{
	int i, num, idx;
	num = cQ->rear - cQ->front;
	if( num < 0 ) {
		num += cQ_SIZE;
	}
	for( i=0 ; i<num ; i++ ) {
		idx = (i + cQ->front + 1) % cQ_SIZE;
		printf("%d -> ", cQ->queue[idx]);
	}
	puts(" END");
}
void main(void)  
{ 
	cQueueType *cQ1 = createQueue(); // ť ���� 
	element data=0;
	int ret;
	srand(time(NULL)); 
	while (1) { 
		ret = rand() % 2; // odd or even
		
		//Ȧ���̰�, 
		//ť�� ��ȭ�̸� continue 
		//�ƴϸ� ++data�� enQueue, printf(������ <%d>\n��, data); 
		//¦���̸� 
		//ť�� �����̸� continue 
		//�ƴϸ� ret = deQueue, printf(������ <%d>\n��, ret); 
		//ť�� ����Ʈ�Ͽ� ���� Ȯ�� 
		if( ret ) {	// odd
			if( isFull(cQ1) ) {
				continue;
			}
			else {
				enQueue(cQ1, ++data);
				printf("���� <%d>\n", data);
			}
		}
		else {	// even
			if( isEmpty(cQ1) ) {
				continue;
			}
			else {
				ret = deQueue(cQ1);
				printf("���� <%d>\n", ret);
			}
		}
		printQueue(cQ1);
		getchar(); 
	} 
}

