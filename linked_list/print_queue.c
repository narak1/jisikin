#include <stdio.h>
#include <malloc.h>
typedef int element; // int형을연결큐element의자료형으로정의
typedef struct QNode{ // 연결큐의노드를구조체로정의
element data;
struct QNode*link;
} QNode;

typedef struct{ // 연결큐에서사용하는포인터front와rear를구조체로정의
QNode*front, *rear;
}LQueueType;
LQueueType*createLinkedQueue() // 공백연결큐생성연산
{
LQueueType*LQ;
LQ = (LQueueType*)malloc(sizeof(LQueueType));
LQ->front=NULL;
LQ->rear=NULL;
return LQ;
}
int isEmpty(LQueueType*LQ) // 연결큐가공백인지확인하는연산
{
	if (LQ->front == NULL) {
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else return 0;
}
void enQueue(LQueueType*LQ, element item) // 연결큐의rear에원소를삽입하는연산
{
	QNode*newNode=(QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if(LQ->front == NULL) { // 현재연결큐가공백인경우
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else { // 현재연결큐가공백이아닌경우
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}
element deQueue(LQueueType*LQ)
// 연결큐에서front 원소를삭제하고반환하는연산
{
	QNode*old = LQ->front;
	element item;
	if (isEmpty(LQ)) return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if(LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

int printLQ(LQueueType*LQ) // 연결큐를출력하는연산
{
	int len=0;
	QNode*temp = LQ->front;
	printf(" Linked Queue : [");
	while(temp) {
		printf("%3d", temp->data);
		temp = temp->link;
		len++;
	}
	printf(" ] \n");
	return len;
}

void main(void)
{
	LQueueType*LQ1 = createLinkedQueue();
	element data;
	int i, request, ret;
	int len=0;
	float wait;
	srand(time(NULL));
	
	ret = 0;
	for (i=1; i<=10; i++)
	{
		request = rand() % 4; // 0, 1, 2, 3 발생

		//request 가0이면continue
		if( request == 0 ) {
			; //no enQueue;
		}
		else {	// 	1 또는2 또는3이면
			//reques를enQueue,
			enQueue(LQ1, request);
			printf("%요청<%d>\n", request);
		}

		//i가짝수이면 
		if( i % 2 == 0 ) {
			//큐가공백이면continue
			if( LQ1->front == NULL ) {
				continue;
			}
			else { 
				//아니면
				ret = deQueue(LQ1);
				printf("프린트<%d>\n" , ret);
			}
		}
		ret += printLQ(LQ1);	// 큐를프린트하여내용확인
	}
	wait = ret / 10.0f;	// 평균기시간계산;
	printf("평균대기시간= %f\n", wait);
}
