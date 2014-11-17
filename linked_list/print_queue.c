#include <stdio.h>
#include <malloc.h>
typedef int element; // int��������ťelement���ڷ�����������
typedef struct QNode{ // ����ť�ǳ�带����ü������
element data;
struct QNode*link;
} QNode;

typedef struct{ // ����ť��������ϴ�������front��rear������ü������
QNode*front, *rear;
}LQueueType;
LQueueType*createLinkedQueue() // ���鿬��ť��������
{
LQueueType*LQ;
LQ = (LQueueType*)malloc(sizeof(LQueueType));
LQ->front=NULL;
LQ->rear=NULL;
return LQ;
}
int isEmpty(LQueueType*LQ) // ����ť����������Ȯ���ϴ¿���
{
	if (LQ->front == NULL) {
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else return 0;
}
void enQueue(LQueueType*LQ, element item) // ����ť��rear�����Ҹ������ϴ¿���
{
	QNode*newNode=(QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if(LQ->front == NULL) { // ���翬��ť�������ΰ��
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else { // ���翬��ť�������̾ƴѰ��
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}
element deQueue(LQueueType*LQ)
// ����ť����front ���Ҹ������ϰ��ȯ�ϴ¿���
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

int printLQ(LQueueType*LQ) // ����ť������ϴ¿���
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
		request = rand() % 4; // 0, 1, 2, 3 �߻�

		//request ��0�̸�continue
		if( request == 0 ) {
			; //no enQueue;
		}
		else {	// 	1 �Ǵ�2 �Ǵ�3�̸�
			//reques��enQueue,
			enQueue(LQ1, request);
			printf("%��û<%d>\n", request);
		}

		//i��¦���̸� 
		if( i % 2 == 0 ) {
			//ť�������̸�continue
			if( LQ1->front == NULL ) {
				continue;
			}
			else { 
				//�ƴϸ�
				ret = deQueue(LQ1);
				printf("����Ʈ<%d>\n" , ret);
			}
		}
		ret += printLQ(LQ1);	// ť������Ʈ�Ͽ�����Ȯ��
	}
	wait = ret / 10.0f;	// ��ձ�ð����;
	printf("��մ��ð�= %f\n", wait);
}
