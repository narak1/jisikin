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
const char *rank_name[LastRank] = { "인턴", "사원", "대리", "과장", "차장", "부장" };
int basemoney[LastRank] = { 100, 200, 300, 400, 500, 600, };
int plusmoney[LastRank] = { 10, 20, 30, 40, 50, 60, };

const char *menu_str =
"┌────────────────┐\n"
"│         * PHS 프로그램 *       │\n"
"├────  3. 급여관리 ─────┤\n"
"│          ① 기본급조정         │\n"
"│          ② 직급수당조정       │\n"
"│          ③ 월급조회           │\n"
"│          ④ BACK               │\n"
"└────────────────┘\n"
"      번호를 입력해 주세요 : _\b";

void e()
{
	char q[16];
	int total_pay=0;
	int overtime=0; //초과근무간
	int overmoney=7815; //5210*1.5
	int firstmoney=0; //가불
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
		puts("현재 설정된 기본급은");
		for( i=0 ; i<LastRank ; i++ ) {
			printf("%s : %d원\n", rank_name[i], basemoney[i]);
		}
		puts("입니다.");

		printf("\n기본급을 조정할 직급과 새로운 기본급을 입력하세요\n"
				"ex.인턴 1000000\n");
		scanf("%s%d", input1, &input3);
		
		flag = 0;	// 입력 잘못 검사를 위한 변수 
		for( i=0 ; i<LastRank ; i++ ) {
			if( strcmp(input1, rank_name[i]) == 0 ) {
				basemoney[i] = input3;
				flag = 1;
			}
		}
		if( flag == 0 ) {
			puts("잘못 입력하셨습니다.");
		}

		puts("새로 변경된 기본급은");
		for( i=0 ; i<LastRank ; i++ ) {
			printf("%s : %d원\n", rank_name[i], basemoney[i]);
		}
		puts("입니다.");
	}
	else if (input2 == 2)
	{
		puts("현재 설정된 직급수당은");
		for( i=0 ; i<LastRank ; i++ ) {
			printf("%s : %d원\n", rank_name[i], plusmoney[i]);
		}
		puts("입니다.");

		printf("\n직급수당을 조정할 직급과 새로운 직급수당을 입력하세요\n"
				"ex.인턴 1000000\n");
		scanf("%s%d", input1 ,&input3);

		flag = 0;	// 입력 잘못 검사를 위한 변수 
		for( i=0 ; i<LastRank ; i++ ) {
			if( strcmp(input1, rank_name[i]) == 0 ) {
				plusmoney[i] = input3;
				flag = 1;
			}
		}
		if( flag == 0 ) {
			puts("잘못 입력하셨습니다.");
		}

		puts("새로 변경된 직급수당은");
		for( i=0 ; i<LastRank ; i++ ) {
			printf("%s : %d원\n", rank_name[i], basemoney[i]);
		}
		puts("입니다.");

	}
	else if(input2 == 3)
	{
		printf("월급을 출력하실 사원번호를 입력하세요: \n");
		scanf("%s", q);

		cur=head;
		flag = 0;	// 사원을 찾았는지 검사하는 변수 
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

			printf("야간근무한 시간을 입력해주세요: ");
			scanf("%d", &overtime);
			printf("가불한 금액을 입력해주세요: ");
			scanf("%d", &firstmoney);
			overpay = overtime * overmoney;
			total_pay = basem + plusm + overpay - firstmoney;
			printf("이번달 급여는 %d원 입니다.\n", total_pay);  
		}
		else {
			printf("%s 는 없는 사번입니다.\n", q);
		}
	}
	else {
		printf("값을 잘못입력하셨습니다.\n");
	}
}

