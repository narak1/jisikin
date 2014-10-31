#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _information
{
	char name[20];
	char add[50];
	int age;
	int phone;
	struct _information *next;
} information;

information *head, *tail;

typedef struct _tapeinfor
{
	char tapename[20];
	int date;
	int grade;
	char director[10];
	struct _tapeinfor *ne;
} tapeinfor;

tapeinfor *d, *t;

typedef struct _lendinfor
{
	information *customer;
	tapeinfor *tape;
	time_t lend_day;
	int lend_fee;
	struct _lendinfor *next;
} lendinfo;

lendinfo *tapelend;

void InitInfo()
{
	head = (information *)malloc(sizeof(information));
	//tail = (information *)malloc(sizeof(information));
	head->next = NULL;
	//tail->next = NULL;
	d = (tapeinfor *)malloc(sizeof(tapeinfor));
	//t = (tapeinfor *)malloc(sizeof(tapeinfor));
	d->ne = NULL;
	//t->ne = NULL;
}

void addmember()
{
	information *New;
	New = (information *)calloc(1, sizeof(information));
	printf("ȸ�������� �����ϼ̽��ϴ�.\n");
	printf("��    �� : ");
	fgets(New->name, sizeof(New->name), stdin);
	printf("��    �� : ");
	scanf("%d", &New->age);
	getchar();
	printf("��    �� : ");
	fgets(New->add, sizeof(New->add), stdin);
	printf("��ȭ��ȣ : ");
	scanf("%d", &New->phone);
	getchar();
	New->next = head->next;
	head->next = New;
}

information *findmember()
{
	char name[20];
	int phone;
	information *s;

	printf("�˻��� ȸ���� �̸��� �Է��ϼ���: ");
	fgets(name, sizeof(name), stdin);
	printf("�˻��� ȸ���� ��ȭ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &phone);
	getchar();
	s = head->next;
	while (s)
	{
		if ((strcmp(s->name, name) == 0) && (s->phone == phone))
			break;
		s = s->next;
	}
	if (s)
	{
		printf("��    �� :%s\n", s->name);
		printf("��    �� :%d\n", s->age);
		printf("��    �� :%s\n", s->add);
		printf("��ȭ��ȣ :%d\n", s->phone);
	}
	else {
		printf("ã�� ȸ���� �����ϴ�.\n\n ");
	}

	return s;
}

void delmember()
{
	char name[20];
	int phone;
	information *p;
	information *s;

	printf("������ ȸ���� �̸��� �Է��ϼ���: ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = 0x00;
	printf("������ ȸ���� ��ȭ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &phone);
	getchar();
	p = head;
	s = p->next;
	while (s)
	{
		if ((strcmp(s->name, name) == 0) && (s->phone == phone))
			break;
		p = s;
		s = p->next;
	}
	if (s)
	{
		p->next = s->next;
		free(s);
		printf("�����Ǿ����ϴ�.\n");
	}
}

void memberlist()
{
	information *s;
	s = head->next;
	printf("���� ���ԵǾ� �ִ� ȸ������ ����Դϴ�.\n\n");
	while (s)
	{
		printf("ȸ���̸� :%s\n", s->name);
		s = s->next;
	}
}

void addtape()
{
	tapeinfor *N;
	N = (tapeinfor *)calloc(1, sizeof(tapeinfor));
	printf("Tape�߰��� �����ϼ̽��ϴ�.\n");
	printf("Tape ���� : ");
	fgets(N->tapename, sizeof(N->tapename), stdin);
	printf("Tape������ : ");
	scanf("%d", &N->date);
	getchar();
	printf("��    �� : ");
	fgets(N->director, sizeof(N->director), stdin);
	printf("��    �� : ");
	scanf("%d", &N->grade);
	getchar();
	N->ne = d->ne;
	d->ne = N;
}

tapeinfor *findtape()
{
	char na[20];
	tapeinfor *q;

	printf("�˻��� tape�� ������ �Է��ϼ���: ");
	fgets(na, sizeof(na), stdin);
	q = d->ne;
	while (q)
	{
		if (strcmp(q->tapename,na) == 0)
			break;
		q = q->ne;
	}
	if (q)
	{
		printf("tape���� :%s\n", q->tapename);
		printf("�� �� �� :%d\n", q->date);
		printf("��    �� :%s\n", q->director);
		printf("��    �� :%d\n", q->grade);
	}
	else {
		printf("ã�� tape�� �����ϴ�.\n\n ");
	}

	return q;
}

void deltape()
{
	char name[20];
	tapeinfor *p;
	tapeinfor *s;

	printf("������ tape�� ������ �Է��ϼ���: ");
	fgets(name, sizeof(name), stdin);

	p = d;
	s = p->ne;
	while (s)
	{
		if (strcmp(s->tapename, name) == 0)
			break;
		p = s;
		s = p->ne;
	}
	if (s)
	{
		p->ne = s->ne;
		free(s);
		printf("�����Ǿ����ϴ�.\n");
	}
}

void tapelist()
{
	tapeinfor *o;

	o = d->ne;
	printf("���� ��ϵǾ� �ִ� tape�� ����Դϴ�.\n\n");
	while (o)
	{
		printf("tape�̸� :%s\n", o->tapename);
		o = o->ne;
	}
}

void lend()
{
	information *p;
	tapeinfor *t;
	
	

void tapereturn();
void lending();

int main()
{
	int video;

	InitInfo();
	while(1)
	{
		printf("-------MENU------------\n\n");
		printf("1.  ȸ �� �� ��\n");
		printf("2.  ȸ �� �� ��\n");
		printf("3.  ȸ �� �� ��\n");
		printf("4.  ȸ �� �� ��\n");
		printf("5.  Tape  �� ��\n");
		printf("6.  Tape  �� ��\n");
		printf("7.  Tape  �� ��\n");
		printf("8.  Tape  �� ��\n");
		printf("9.  �� �� �� ��\n");
		printf("10. �� �� �� ��\n");
		printf("11. �� �� �� Ȳ\n");
		printf("12. ��       ��\n\n");
		printf("-----------------------\n\n");
		printf("�����ų ���α׷� ��ȣ�� �Է��ϼ��� :");
		scanf("%d", &video);
		getchar();
		switch(video)
		{
			case 1 :	addmember();	break;
			case 2 :	findmember();	break;
			case 3 :	delmember();	break;
			case 4 :	memberlist();	break;
			case 5 :	addtape();		break;
			case 6 :	findtape();		break;
			case 7 :	deltape();		break;
			case 8 :	tapelist();		break;
			case 9 :	lend();			break;
			case 10 :	tapereturn();	break;
			case 11 :	lending();		break;
			case 12 :	printf("���α׷��� �����մϴ�.\n");	break;
			default :	printf("�߸������̽��ϴ�. �ٽ��Է��ϼ���.\n");
		}
	}
}