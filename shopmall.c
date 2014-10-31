#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define scanf_s scanf

#define N 6
void display_menu();
void compute_buy();
void compute_list();
int sangpum[N]={0,5000,4000,3000,2000,1000};
char *name[N]={"", "�ѿ�", "�ı�", "�Ź�", "����", "����"};
int buy_info[N];		//  ��ǰ �ֹ� ���� 

int main()
{
	int service;

	do {
		system("cls");
		display_menu();
		printf(" �� ���ϴ� ���񽺸� ����:   ");
		scanf_s("%d",&service);
		system("cls");
		switch (service)
		{
			case 1: compute_buy(); break;
			case 2: compute_list(); break;
		}
	} while(service != 3);
}

void compute_buy()
{
	int i, su, total;
 
	printf("����������������������������������\n");
	printf("��>>��ǰ �ֹ��ϱ�               ��\n");
	printf("����ǰ��                  ����  ��\n");
	printf("��1. �ѿ�                5000 ����\n");
	printf("��2. �ı�                4000 ����\n");
	printf("��3. �Ź�                3000 ����\n");
	printf("��4. ����                2000 ����\n");
	printf("��5. ����                1000 ����\n");
	printf("����������������������������������\n");
	printf("���ϴ� ��ǰ�� ��ȣ: ");
	scanf_s("%d",&i);
	if( i >= N ) {
		;	// ���� ó��... 
	}

	printf("\n %s��(��) �ֹ��� ������? ",name[i]);
	scanf_s("%d",&su);
	total = sangpum[i]*su;
	buy_info[i] += su;
	printf("\n �ֹ��Ͻ� %s %d ���� �� %d�� �Դϴ� \n\n\n", name[i],su,total);
	printf("��� ���񽺸� ���Ͻø� �ƹ�Ű�� ��������.\n");
	getch();
	//system("pause");
}

void compute_list()
{
	int i, total, line_no;

	line_no = 0;
	total = 0;
	printf("����������������������������������\n");
	printf("����ǰ��        ����        ���ݦ�\n");
	printf("����������������������������������\n");
	for( i=0 ; i<N ; i++ ) {
		if( buy_info[i] > 0 ) {
			++line_no;
			total += buy_info[i] * sangpum[i];
	printf("��%-10s  %6d        %4d��\n",name[i],buy_info[i],sangpum[i]);
		}
	}
	for( i=1 ; i<N-line_no ; i++ ) {
	printf("��                              ��\n");
	}
	printf("��==============================��\n");
	printf("���Ѿ�                  %8d��\n",total);
	printf("��(��) ���θ�                   ��\n");
	printf("���� Tel)                       ��\n");
	printf("����������������������������������\n");
	
	printf("��� ���񽺸� ���Ͻø� �ƹ�Ű�� ��������.\n");
	getch();
	//system("pause"); 
}
void display_menu()
{
	printf("����������������������������\n");
	printf("��>>>  ȯ���մϴ�         ��\n");
	printf("�� ���θ�                 ��\n");
	printf("��          Menu          ��\n");
	printf("���ܡ� 1.��ǰ �ֹ��ϱ�    ��\n");
	printf("���ܡ� 2.�ֹ��� Ȯ���ϱ�  ��\n");
	printf("���ܡ� 3.�����ϱ�         ��\n");
	printf("��                        ��\n");
	printf("����������������������������\n");
}
