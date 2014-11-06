#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodetype
{
	int info;
	struct nodetype *next;
} node;

node *rear;

void main()
{
	void initialize();
	node *getnode();
	void addnode(int);
	void display();
	void deletenode();
	char choice;
	int data;
	
	initialize();
	do{
		fflush(stdin);
		system("cls");
		printf("\n�Է� - i(insert),d(delete),q(quit) : ");
		scanf("%c",&choice);
		switch(choice){
			case 'i':
			case 'I':
				printf("\n���� �Է��ϼ��� : ");
				scanf("%d",&data);
				addnode(data);
				break;
			case 'd':
			case 'D':
				deletenode();
				break;
			case 'q':
			case 'Q':
				while(rear)
				deletenode();
				exit(0);
			default:
				printf("\n�߸� �Է��ϼ̽��ϴ�.");
		}
		system("cls");
		printf("\nť�� ��� : \n");
		display();
		printf("����Ϸ��� Ű�� ��������...\n");
		getch();
	}while(1);
}

void initialize()
{
	rear=NULL;
}

node *getnode()
{
	node *newptr=NULL;
	newptr=(node *)malloc(sizeof(node));
	return(newptr);
}

void addnode(int value)
{
	node *ptr = getnode();
	ptr -> info = value;
	if(rear==NULL) {
		ptr->next = ptr;
	}
	else {
		ptr -> next = rear->next;
		rear->next = ptr;
	}
	rear = ptr;
}

void display()
{
	node *temp;
	printf("\nRear -> ");
	if(rear != NULL)
	{
		temp = rear->next;
		while( temp != rear )
		{
			printf("%d -> ",temp->info);
			temp = temp->next;
		}
		printf("%d -> ",rear->info);
		printf("Rear\n");
	}
	else {
		printf("NULL\n");
	}
}

void deletenode()
{
	node *ptr;
	if(rear==NULL){
		printf("\nť�� ������ϴ�.\n");
	}
	else{
		ptr = rear->next;
		if( ptr == rear ) {	// one element
			rear = NULL;
		}
		else {
			rear->next = ptr->next;
		}
		free(ptr);
	}
}

