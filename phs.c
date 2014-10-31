#include <stdio.h>

typedef struct node
{
   char num[6];
   char depart[10];
   char name[10];
   char rank[10];
   char idnum[15];
   char tel[15];
   struct node *next;
}Node;

typedef struct{
   Node* head;
}Node_h;

Node *head = NULL;
Node *tail = NULL;
Node *cur = NULL;

enum RankCode { Intern, Sawon, Daeri, Kwajang, Chajang, Bujang, LastRank };
const char *rank_name[LastRank] = { "����", "���", "�븮", "����", "����", "����" };
int basemoney[LastRank] = { 100, 200, 300, 400, 500, 600, };
int plusmoney[LastRank] = { 10, 20, 30, 40, 50, 60, };

const char *menu_str =
"������������������������������������\n"
"��         * PHS ���α׷� *       ��\n"
"����������  3. �޿����� ������������\n"
"��          �� �⺻������         ��\n"
"��          �� ���޼�������       ��\n"
"��          �� ������ȸ           ��\n"
"��          �� BACK               ��\n"
"������������������������������������\n"
"      ��ȣ�� �Է��� �ּ��� : _\b";

void e()
{
	char q[16];
	int total_pay=0;
	int overtime=0; //�ʰ��ٹ���
	int overmoney=7815; //5210*1.5
	int firstmoney=0; //����
	int basem=0;
	int plusm=0;
	int overpay=0;
	char input1[10];
	int input2;
	int input3;
	int i, flag;

	printf(menu_str);
	scanf("%d", &input2);
	
	 if (input2 == 1)
	 {
		puts("���� ������ �⺻����");
		for( i=0 ; i<LastRank ; i++ ) {
			printf("%s : %d��\n", rank_name[i], basemoney[i]);
		}
		puts("�Դϴ�.");

		printf("\n�⺻���� ������ ���ް� ���ο� �⺻���� �Է��ϼ���\n"
				"ex.���� 1000000\n");
		scanf("%s%d", input1, &input3);
		
		flag = 0;	// �Է� �߸� �˻縦 ���� ���� 
		for( i=0 ; i<LastRank ; i++ ) {
			if( strcmp(input1, rank_name[i]) == 0 ) {
				basemoney[i] = input3;
				flag = 1;
			}
		}
		if( flag == 0 ) {
			puts("�߸� �Է��ϼ̽��ϴ�.");
		}

		puts("���� ����� �⺻����");
		for( i=0 ; i<LastRank ; i++ ) {
			printf("%s : %d��\n", rank_name[i], basemoney[i]);
		}
		puts("�Դϴ�.");
	}
	else if (input2 == 2)
	{
		puts("���� ������ ���޼�����");
		for( i=0 ; i<LastRank ; i++ ) {
			printf("%s : %d��\n", rank_name[i], plusmoney[i]);
		}
		puts("�Դϴ�.");

		printf("\n���޼����� ������ ���ް� ���ο� ���޼����� �Է��ϼ���\n"
				"ex.���� 1000000\n");
		scanf("%s%d", input1 ,&input3);

		flag = 0;	// �Է� �߸� �˻縦 ���� ���� 
		for( i=0 ; i<LastRank ; i++ ) {
			if( strcmp(input1, rank_name[i]) == 0 ) {
				plusmoney[i] = input3;
				flag = 1;
			}
		}
		if( flag == 0 ) {
			puts("�߸� �Է��ϼ̽��ϴ�.");
		}

		puts("���� ����� ���޼�����");
		for( i=0 ; i<LastRank ; i++ ) {
			printf("%s : %d��\n", rank_name[i], basemoney[i]);
		}
		puts("�Դϴ�.");

	}
	else if(input2 == 3)
	{
		printf("������ ����Ͻ� �����ȣ�� �Է��ϼ���: \n");
		scanf("%s", q);

		cur=head;
		flag = 0;	// ����� ã�Ҵ��� �˻��ϴ� ���� 
		while( cur )
		{
			if( strcmp(cur->num, q) == 0 ) {
				flag = 1;
				break;
			}
			cur = cur->next;
		}

		if( flag == 1 ) {
			for( i=0 ; i<LastRank ; i++ ) {
				if( strcmp(cur->rank,rank_name[i]) == 0 ) {
					basem = basemoney[i];
					plusm = plusmoney[i];
					flag = 1;
					break;
				}
			}

			printf("�߰��ٹ��� �ð��� �Է����ּ���: ");
			scanf("%d", &overtime);
			printf("������ �ݾ��� �Է����ּ���: ");
			scanf("%d", &firstmoney);
			overpay = overtime * overmoney;
			total_pay = basem + plusm + overpay - firstmoney;
			printf("�̹��� �޿��� %d�� �Դϴ�.\n", total_pay);  
		}
		else {
			printf("%s �� ���� ����Դϴ�.\n", q);
		}
	}
	else {
		printf("���� �߸��Է��ϼ̽��ϴ�.\n");
	}
}

