#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define scanf_s scanf

#define N 6
void display_menu();
void compute_buy();
void compute_list();
int sangpum[N]={0,5000,4000,3000,2000,1000};
char *name[N]={"", "한우", "식권", "신발", "버거", "우유"};
int buy_info[N];		//  상품 주문 내역 

int main()
{
	int service;

	do {
		system("cls");
		display_menu();
		printf(" ▶ 원하는 서비스를 선택:   ");
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
 
	printf("┌───────────────┐\n");
	printf("│>>상품 주문하기               │\n");
	printf("│제품명                  가격  │\n");
	printf("│1. 한우                5000 원│\n");
	printf("│2. 식권                4000 원│\n");
	printf("│3. 신발                3000 원│\n");
	printf("│4. 버거                2000 원│\n");
	printf("│5. 우유                1000 원│\n");
	printf("└───────────────┘\n");
	printf("원하는 상품의 번호: ");
	scanf_s("%d",&i);
	if( i >= N ) {
		;	// 오류 처리... 
	}

	printf("\n %s을(를) 주문할 개수는? ",name[i]);
	scanf_s("%d",&su);
	total = sangpum[i]*su;
	buy_info[i] += su;
	printf("\n 주문하신 %s %d 개는 총 %d원 입니다 \n\n\n", name[i],su,total);
	printf("계속 서비스를 원하시면 아무키나 누르세요.\n");
	getch();
	//system("pause");
}

void compute_list()
{
	int i, total, line_no;

	line_no = 0;
	total = 0;
	printf("┌───────────────┐\n");
	printf("│상품명        개수        가격│\n");
	printf("│───────────────│\n");
	for( i=0 ; i<N ; i++ ) {
		if( buy_info[i] > 0 ) {
			++line_no;
			total += buy_info[i] * sangpum[i];
	printf("│%-10s  %6d        %4d│\n",name[i],buy_info[i],sangpum[i]);
		}
	}
	for( i=1 ; i<N-line_no ; i++ ) {
	printf("│                              │\n");
	}
	printf("│==============================│\n");
	printf("│총액                  %8d│\n",total);
	printf("│(주) 쇼핑몰                   │\n");
	printf("│☎ Tel)                       │\n");
	printf("└───────────────┘\n");
	
	printf("계속 서비스를 원하시면 아무키나 누르세요.\n");
	getch();
	//system("pause"); 
}
void display_menu()
{
	printf("┌────────────┐\n");
	printf("│>>>  환영합니다         │\n");
	printf("│ 쇼핑몰                 │\n");
	printf("│          Menu          │\n");
	printf("│●→ 1.상품 주문하기    │\n");
	printf("│●→ 2.주문서 확인하기  │\n");
	printf("│●→ 3.종료하기         │\n");
	printf("│                        │\n");
	printf("└────────────┘\n");
}
