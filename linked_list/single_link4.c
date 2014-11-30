#include <stdio.h>
#include <malloc.h>
#include <Windows.h>

#define ZERO 0

typedef struct node{
	int data;
	struct node *link;
}ND;

ND* makeNode();
void showMenu();
void inputData(ND** indata);
void showData(ND* indata);
void searchData(ND* indata, int insearch);
void selectDel(ND** indata, int inselect);

void main()
{
	ND* data = ZERO;
	int n, search, select;
	while(1){
		showMenu();
		printf("�� �� : "); scanf("%d", &n);
		if(n==1){
			inputData(&data);
		}else if(n==2){
			showData(data);
		}else if(n==3){
			printf("ã�� ������ �Է� : "); scanf("%d", &search);
			searchData(data, search);
		}else if(n==4){
			printf("���� �� ������ �Է� : "); scanf("%d", &select);
			selectDel(&data, select);
		}else if(n==5){

		}else if(n==6){

		}else if(n==7){

		}else if(n==8){
			printf("���α׷��� �����մϴ�.\n"); Sleep(1000); exit(1);
		}else{
			printf("�߸��� �Է� �Դϴ�.\n"); system("pause");
		}
	}//while
}//main

ND* makeNode()
{
	ND* node = (ND*)malloc(sizeof(ND));
	node->link = ZERO;
	return node;
}

void showMenu()
{
	system("cls");
	printf("# # # # # l i s t # # # # #\n");
	printf("1. ������ ���� - �Է¼��� ��\n");
	printf("2. ������ ���\n");
	printf("3. ������ �˻�\n");
	printf("4. ������ ���� ����\n");
	printf("5. ������ ��ü ����\n");
	printf("6. ������ ��ġ ���� ����[Ư�� ��ġ ��]\n");
	printf("7. ������ ��ġ ���� ����[Ư�� ��ġ ��]\n");
	printf("8. ���α׷� ����\n");
}

void inputData(ND** indata)
{
	ND* node, *temp;

	node = makeNode();
	printf("������ �Է� : "); scanf("%d", &(node->data));

	temp = *indata;
	if(temp == ZERO){
		*indata = node;
		return;
	}
	while(temp->link){			// ������ ����̸� ����
		temp = temp->link;
	}//while
	temp->link = node;
}//inputData

void showData(ND* node)
{
	if(node == ZERO){
		printf("�� �̻� ����� �����Ͱ� �����ϴ�.\n");
		system("pause");
		return;
	}
	printf("������ ��� : %d \n", node->data);
	showData(node->link);
}

void searchData(ND* node, int insearch)
{ //
	while(node)
	{
		if(node->data==insearch) break;
		node = node->link;
	}

	if( node == ZERO ) {
		printf("�����͸� ã���� �����ϴ�.\n"); system("pause");
	}
	else {
		printf("������ ��� : %d\n", node->data); system("pause");
	}
}

void selectDel(ND** indata, int inselect)
{
	ND* node = *indata, *pre;
	if( node == ZERO ) {
		printf("�����͸� ã���� �����ϴ�.\n"); system("pause"); return;
	}

	if(node->data == inselect){//ó���϶�o
		printf("������ ������ : %d \n", node->data);
		(*indata) = node->link;
		free(node); system("pause"); return;
	}

	pre = node;
	node = pre->link;
	while( node ) {
		if(node->data == inselect){//ó���� �ƴҶ�
			printf("������ ������ : %d \n", node->data);
			pre->link = node->link;
			free(node); system("pause"); return;
		}
		pre = node;
		node = pre->link;
	}
	if( node == ZERO ) {
		printf("ã�� ���� �����ϴ�.\n"); system("pause"); return;
	}
}
