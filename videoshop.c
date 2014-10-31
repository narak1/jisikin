#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
	int lend_fee;
	time_t lend_day;
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
	printf("회원가입을 선택하셨습니다.\n");
	printf("이    름 : ");
	gets(New->name);
	printf("나    이 : ");
	scanf("%d", &New->age);
	getchar();
	printf("주    소 : ");
	gets(New->add);
	printf("전화번호 : ");
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

	printf("검색할 회원의 이름을 입력하세요: ");
	gets(name);
	printf("검색할 회원의 전화번호를 입력하세요: ");
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
		printf("이    름 :%s\n", s->name);
		printf("나    이 :%d\n", s->age);
		printf("주    소 :%s\n", s->add);
		printf("전화번호 :%d\n", s->phone);
	}
	else {
		printf("찾는 회원이 없습니다.\n\n ");
	}

	return s;
}

void delmember()
{
	char name[20];
	int phone;
	information *p;
	information *s;

	printf("삭제할 회원의 이름을 입력하세요: ");
	gets(name);
	printf("삭제할 회원의 전화번호를 입력하세요: ");
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
		printf("삭제되었습니다.\n");
	}
}

void memberlist()
{
	information *s;
	s = head->next;
	printf("현재 가입되어 있는 회원들의 목록입니다.\n\n");
	while (s)
	{
		printf("회원이름 :%s\n", s->name);
		s = s->next;
	}
}

void addtape()
{
	tapeinfor *N;
	N = (tapeinfor *)calloc(1, sizeof(tapeinfor));
	printf("Tape추가를 선택하셨습니다.\n");
	printf("Tape 제목 : ");
	gets(N->tapename);
	printf("Tape개봉일 : ");
	scanf("%d", &N->date);
	getchar();
	printf("감    독 : ");
	gets(N->director);
	printf("등    급 : ");
	scanf("%d", &N->grade);
	getchar();
	N->ne = d->ne;
	d->ne = N;
}

tapeinfor *findtape()
{
	char na[20];
	tapeinfor *q;

	printf("검색할 tape의 제목을 입력하세요: ");
	gets(na);
	q = d->ne;
	while (q)
	{
		if (strcmp(q->tapename,na) == 0)
			break;
		q = q->ne;
	}
	if (q)
	{
		printf("tape제목 :%s\n", q->tapename);
		printf("개 봉 일 :%d\n", q->date);
		printf("감    독 :%s\n", q->director);
		printf("등    급 :%d\n", q->grade);
	}
	else {
		printf("찾는 tape가 없습니다.\n\n ");
	}

	return q;
}

void deltape()
{
	char name[20];
	tapeinfor *p;
	tapeinfor *s;

	printf("삭제할 tape의 제목을 입력하세요: ");
	gets(name);

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
		printf("삭제되었습니다.\n");
	}
}

void tapelist()
{
	tapeinfor *o;

	o = d->ne;
	printf("현재 등록되어 있는 tape의 목록입니다.\n\n");
	while (o)
	{
		printf("tape이름 :%s\n", o->tapename);
		o = o->ne;
	}
}

void print_lend_info(lendinfo *info)
{
	information *c;
	tapeinfor *t;
	struct tm *tp;
	char buf[40];

	c = info->customer;
	t = info->tape;
	tp = localtime(&info->lend_day);
	strftime(buf, 40, "%Y-%m-%d %H:%M:%S", tp);

	printf("대여고객 :%s\n", c->name);
	printf("전화번호 :%d\n", c->phone);
	printf("tape제목 :%s\n", t->tapename);
	printf("대 여 료 :%d\n", info->lend_fee);
	printf("대 여 일 :%s\n", buf);
}

void lend()
{
	tapeinfor *t;
	lendinfo *info;

	t = findtape();
	// 데이프가 대여된 상태인지 확인
	info = tapelend;
	while( info ) {
		if( info->tape == t ) {		// find tape
			print_lend_info(info);
			return;
		}
		info = info->next;
	}

	info = (lendinfo *) malloc(sizeof(lendinfo));
	info->tape = t;
	info->customer = findmember();
	printf("대여료: ");
	scanf("%d", &info->lend_fee);
	info->lend_day = time(NULL);
	info->next = tapelend;
	tapelend = info;
}

void tapereturn()
{
	tapeinfor *t;
	lendinfo *info, *pre;

	t = findtape();
	// 데이프가 대여된 상태인지 확인
	info = tapelend;
	while( info ) {
		if( info->tape == t ) {		// find tape
			break;
		}
		pre = info;
		info = info->next;
	}

	if( info ) {
		print_lend_info(info);
		if( info == tapelend ) {
			tapelend = info->next;
		}
		else {
			pre->next = info->next;
		}
		free(info);
	}
}

void lending()
{
	lendinfo *info;
	info = tapelend;
	while( info ) {
		print_lend_info(info);
		info = info->next;
	}
}

int main()
{
	int video;

	InitInfo();
	do {
		printf("-------MENU------------\n\n");
		printf("1.  회 원 가 입\n");
		printf("2.  회 원 검 색\n");
		printf("3.  회 원 삭 제\n");
		printf("4.  회 원 목 록\n");
		printf("5.  Tape  추 가\n");
		printf("6.  Tape  검 색\n");
		printf("7.  Tape  삭 제\n");
		printf("8.  Tape  목 록\n");
		printf("9.  대 여 하 기\n");
		printf("10. 반 납 받 기\n");
		printf("11. 대 여 상 황\n");
		printf("12. 종       료\n\n");
		printf("-----------------------\n\n");
		printf("실행시킬 프로그램 번호를 입력하세요 :");
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
			case 12 :	printf("프로그램을 종료합니다.\n");	break;
			default :	printf("잘못누르셨습니다. 다시입력하세요.\n");
		}
	} while(video!=12);
}
