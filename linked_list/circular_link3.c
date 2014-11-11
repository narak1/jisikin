#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <time.h> 
#define STACK_SIZE 100 
#define cQ_SIZE 4 
typedef int element; 
typedef struct{ 
   element queue[cQ_SIZE]; // 1차원 배열 큐 선언 
   int front, rear; 
} cQueueType; 
cQueueType *createQueue() 
{ 
   cQueueType *cQ; 
   cQ = (cQueueType *)malloc(sizeof(cQueueType)); 
   cQ->front=0; // 원형 큐의 front 초기값 설정 
   cQ->rear=0; // 원형 큐의 rear 초기값 설정 
   return cQ; 
} 
int isEmpty(cQueueType *cQ) // 원형 큐가 공백인지 확인하는 연산 
{ 
   if (cQ->front == cQ->rear) { 
      printf("\n Circular Queue is empty! \n");  
      return 1; 
   } 
   else return 0; 
} 
int isFull(cQueueType *cQ) // 원형 큐가 포화 상태인지 확인하는 연산 
{ 
   if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) { 
      printf("\n Circular Queue is full! \n"); 
      return 1; 
   } 
   else return 0; 
} 
void enQueue(cQueueType *cQ, element item)  
// 원형 큐의 rear에 원소를 삽입하는 연산 
{ 
   if(isFull(cQ)) return; 
   else { 
      cQ->rear = (cQ->rear + 1) % cQ_SIZE; 
      cQ->queue[cQ->rear] = item; 
   } 
} 
element deQueue(cQueueType *cQ)  
// 원형큐의 front에서원소를 삭제하고 반환하는 연산 
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
	cQueueType *cQ1 = createQueue(); // 큐 생성 
	element data=0;
	int ret;
	srand(time(NULL)); 
	while (1) { 
		ret = rand() % 2; // odd or even
		
		//홀수이고, 
		//큐가 포화이면 continue 
		//아니면 ++data를 enQueue, printf(“삽입 <%d>\n”, data); 
		//짝수이면 
		//큐가 공백이면 continue 
		//아니면 ret = deQueue, printf(“삭제 <%d>\n”, ret); 
		//큐를 프린트하여 내용 확인 
		if( ret ) {	// odd
			if( isFull(cQ1) ) {
				continue;
			}
			else {
				enQueue(cQ1, ++data);
				printf("삽입 <%d>\n", data);
			}
		}
		else {	// even
			if( isEmpty(cQ1) ) {
				continue;
			}
			else {
				ret = deQueue(cQ1);
				printf("삭제 <%d>\n", ret);
			}
		}
		printQueue(cQ1);
		getchar(); 
	} 
}

