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
		printf("입 력 : "); scanf("%d", &n);
		if(n==1){
			inputData(&data);
		}else if(n==2){
			showData(data);
		}else if(n==3){
			printf("찾을 데이터 입력 : "); scanf("%d", &search);
			searchData(data, search);
		}else if(n==4){
			printf("삭제 할 데이터 입력 : "); scanf("%d", &select);
			selectDel(&data, select);
		}else if(n==5){

		}else if(n==6){

		}else if(n==7){

		}else if(n==8){
			printf("프로그램을 종료합니다.\n"); Sleep(1000); exit(1);
		}else{
			printf("잘못된 입력 입니다.\n"); system("pause");
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
	printf("1. 데이터 저장 - 입력순서 순\n");
	printf("2. 데이터 출력\n");
	printf("3. 데이터 검색\n");
	printf("4. 데이터 지정 삭제\n");
	printf("5. 데이터 전체 삭제\n");
	printf("6. 데이터 위치 지정 저장[특정 위치 전]\n");
	printf("7. 데이터 위치 지정 저장[특정 위치 후]\n");
	printf("8. 프로그램 종료\n");
}

void inputData(ND** indata)
{
	ND* node, *temp;

	node = makeNode();
	printf("데이터 입력 : "); scanf("%d", &(node->data));

	temp = *indata;
	if(temp == ZERO){
		*indata = node;
		return;
	}
	while(temp->link){			// 마지막 노드이면 멈춤
		temp = temp->link;
	}//while
	temp->link = node;
}//inputData

void showData(ND* node)
{
	if(node == ZERO){
		printf("더 이상 출력할 데이터가 없습니다.\n");
		system("pause");
		return;
	}
	printf("데이터 출력 : %d \n", node->data);
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
		printf("데이터를 찾을수 없습니다.\n"); system("pause");
	}
	else {
		printf("데이터 출력 : %d\n", node->data); system("pause");
	}
}

void selectDel(ND** indata, int inselect)
{
	ND* node = *indata, *pre;
	if( node == ZERO ) {
		printf("데이터를 찾을수 없습니다.\n"); system("pause"); return;
	}

	if(node->data == inselect){//처음일때o
		printf("삭제할 데이터 : %d \n", node->data);
		(*indata) = node->link;
		free(node); system("pause"); return;
	}

	pre = node;
	node = pre->link;
	while( node ) {
		if(node->data == inselect){//처음이 아닐때
			printf("삭제할 데이터 : %d \n", node->data);
			pre->link = node->link;
			free(node); system("pause"); return;
		}
		pre = node;
		node = pre->link;
	}
	if( node == ZERO ) {
		printf("찾는 값이 없습니다.\n"); system("pause"); return;
	}
}
