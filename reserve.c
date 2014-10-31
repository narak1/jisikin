#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXTABLE 20

struct Table
{
	int table_size;
	char guest_name[32];
	int guest_num;
};

struct Table rest_tbl[MAXTABLE];

void init_table();
int reserve(char *name, int num);
void print_reserve();
int check_reserve();

int reserve1(char *name, int num);
int reserve2(char *name, int num);

main()
{
	char name[32];
	int num, flag;

	srand(time(NULL));

	init_table();

	do {

		printf("예약 이름: ");
		scanf("%s", name);
		num = (rand() % 8) + 1;

		flag = reserve2(name, num);
		if( flag < 0 ) {
			printf("%d명 자리가 없습니다.\n", num);
		}
		else {
			printf("%d번 테이블 %d명 자리에 %d명 예약되었습니다.\n",
					 flag+1, rest_tbl[flag].table_size, num);
			print_reserve();
		}
	} while( check_reserve() );
}

void init_table()
{
	int i;
	for( i=0 ; i<5 ; i++ ) rest_tbl[i].table_size = 4;
	for(    ; i<10 ; i++ ) rest_tbl[i].table_size = 2;
	for(    ; i<13 ; i++ ) rest_tbl[i].table_size = 1;
	for(    ; i<18 ; i++ ) rest_tbl[i].table_size = 6;
	for(    ; i<20 ; i++ ) rest_tbl[i].table_size = 8;
}

int reserve(char *name, int num)
{
	int i;

	for( i=0 ; i<MAXTABLE ; i++ ) {
		if( (rest_tbl[i].table_size >= num) && (rest_tbl[i].guest_num == 0) )
		{
			strcpy(rest_tbl[i].guest_name, name);
			rest_tbl[i].guest_num = num;
			break;
		}
	}

	if( i < MAXTABLE )
		return i;
	else
		return -1;		// reserve fail
}

void print_reserve()
{
	int i;

	for( i=0 ; i<MAXTABLE ; i++ ) {
		printf("%d번 테이블: ", i+1);
		if( rest_tbl[i].guest_num == 0 ) {
			printf("비어있음, %d명 자리", rest_tbl[i].table_size);
		}
		else {
			printf("%s, %d명 예약됨", rest_tbl[i].guest_name, rest_tbl[i].guest_num);
		}

		if( i % 2 == 0 )
			printf(", ");
		else
			puts("");
	}
}

int check_reserve()
{
	int i, cnt;

	cnt = 0;
	for( i=0 ; i<MAXTABLE ; i++ ) {
		if( rest_tbl[i].guest_num == 0 ) {
			++cnt;
		}
	}

	return cnt;
}

int reserve1(char *name, int num)
{
	int i;
	int st_idx[] = { 10, 5, 0, 0, 13, 13, 18, 18 };
	int ed_idx[] = { 12, 9, 4, 4, 17, 17, 19, 19 };

	for( i=st_idx[num] ; i<=ed_idx[num] ; i++ ) {
		if( (rest_tbl[i].table_size >= num) && (rest_tbl[i].guest_num == 0) )
		{
			strcpy(rest_tbl[i].guest_name, name);
			rest_tbl[i].guest_num = num;
			break;
		}
	}

	if( i <= ed_idx[num] )
		return i;
	else
		return -1;		// reserve fail
}

int reserve2(char *name, int num)
{
	int i, idx;
	int chk_idx[MAXTABLE] = { 10, 11, 12, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 13, 14, 15, 16, 17, 18, 19 };

	for( i=0 ; i<MAXTABLE ; i++ ) {
		idx = chk_idx[i];
		if( (rest_tbl[idx].table_size >= num) && (rest_tbl[idx].guest_num == 0) )
		{
			strcpy(rest_tbl[idx].guest_name, name);
			rest_tbl[idx].guest_num = num;
			break;
		}
	}

	if( i < MAXTABLE )
		return chk_idx[i];
	else
		return -1;		// reserve fail
}

