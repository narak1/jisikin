#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXST	10
#define IDBASE	14011

enum OrderType { NO_ORDER, ID_ORDER, PT_ORDER };

typedef struct
{
	int id, point, order;
} Student;

main()
{
	Student class1[MAXST], *st;
	int i, j;
	void print_data(Student *st, int num, int order);
	void sort_data(Student *st, int num, int order);

	srand(time(NULL));

	for( i=0 ; i<MAXST ; i++ )
	{
		st = class1 + i;
		st->id = (rand() % 10) + IDBASE;
		st->point = rand() % 101;				// 0 ~ 100

		/* 학번 중복 검사 */
		for( j=0 ; j<i ; j++ ) {
			if( st->id == class1[j].id ) {	// 중복
				--i;	// 재시도를 위해서
				break;	// 중복검사 빠져나감
			}
		}
	}

	print_data(class1, MAXST, NO_ORDER);

	// sort by point
	sort_data(class1, MAXST, PT_ORDER);
	
	// set order
	st = class1;
	st->order = 1;
	for( i=1 ; i<MAXST ; i++ ) {
		++st;
		if( st->point == (st-1)->point )
			st->order = (st-1)->order;
		else
			st->order = i+1;
	}
	
	print_data(class1, MAXST, PT_ORDER);

	// sort by id
	sort_data(class1, MAXST, ID_ORDER);
	print_data(class1, MAXST, ID_ORDER);
}

void print_data(Student *st, int num, int order)
{
	int i;

	for( i=0 ; i<num ; i++ ) {
		if( order == NO_ORDER ) {
			printf("%d %3d\n", st->id, st->point);
		}
		else if( order == ID_ORDER ) {
			printf("%d %3d %2d\n", st->id, st->point, st->order);
		}
		else if( order == PT_ORDER ) {
			printf("%2d %d %3d\n", st->order, st->id, st->point);
		}
		++st;
	}
}

void sort_data(Student *st, int num, int order)
{
	int i, j;
	void swap_data(Student *st1, Student *st2);

	for( i=0 ; i<num-1 ; i++ ) {
		for( j=i+1 ; j<num ; j++ ) {
			if( order == ID_ORDER ) {
				if( (st+i)->id > (st+j)->id )
					swap_data(st+i, st+j);
			}
			else if( order == PT_ORDER ) {
				if( (st+i)->point < (st+j)->point )
					swap_data(st+i, st+j);
			}
		}
	}
}

void swap_data(Student *st1, Student *st2)
{
	Student tmp;
	tmp = *st1;
	*st1 = *st2;
	*st2 = tmp;
}
