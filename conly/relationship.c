#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM_OF_MEMBERS 15 // sns 가입자의 수
int link_data[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {0}; //최초 link matrix 1촌의 matrix
int link_result[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {0}; //2촌까지의 관계가 표시된 matrix
void print_links(int data[][NUM_OF_MEMBERS] ); //2차원 배열 출력
void matrix_multiplication(int data[][NUM_OF_MEMBERS], int result[][NUM_OF_MEMBERS] ); //2차원 배열 논리곱 data X data ?-> result

int main( void )
{
	int i = 0;
	int j = 0;
	int num_of_steps=0;
	int ALL_ONES=0;

	srand( (unsigned int)time(NULL) );

	for(i = 0; i<NUM_OF_MEMBERS; i++ )
	{
		link_data[i][i] = 1;//i와 i의 관계는 1촌. 즉 1로 표시
	}

	for(i = 0; i<NUM_OF_MEMBERS; i++ )
	{
		for(i = 0; i<NUM_OF_MEMBERS; i++ ) // 각 user 마다 4명의 친구가 친구가 있다고 가정 .
		{
			j=0;
			while ( j<2 ) //i 가 두 개의 링크를 링크를 연결하고 i가 아닌 다른 user 가 i와 연결
			{
				int new_link = rand()%NUM_OF_MEMBERS; //i 가 random하게 다른 user가 1촌이라 고 가정
				if( new_link != i )
				{
					link_data[i][new_link] = 1;  //i 와 new_link가 1촌이면
					link_data[new_link][i] = 1; //new_link와 i도 1촌.
					j++;
				}
			}
		}
	}
//	link_data[1][3] = link_data[3][1] = 1;
//	link_data[3][6] = link_data[6][3] = 1;

	puts("==================================================================");
	puts("Friends matrix");
	puts("==================================================================");
	print_links(link_data); // 최초 1촌 관계 출력

	matrix_multiplication(link_data,link_result);
	puts("==================================================================");
	puts("Friends of friends matrix");
	puts("==================================================================");
	print_links(link_result); //계산된 2촌까지의 관계 출력
}

void matrix_multiplication(int data[][NUM_OF_MEMBERS],int result[][NUM_OF_MEMBERS])
{
//구현해야할 부분
//data matrix의 논리 제곱을 result에 저장.

	// data matrix is symmetrix matrix
	// result matrix also symmetrix
	int i, j, k, r;
	for( i=0 ; i<NUM_OF_MEMBERS ; i++ ) {
		result[i][i] = 1;
		for( j=i+1 ; j<NUM_OF_MEMBERS ; j++ ) {
			r = 0;
			for( k=0 ; k<NUM_OF_MEMBERS ; k++ ) {
				r |= data[i][k] & data[k][j];
			}
			result[i][j] = r;
			result[j][i] = r;
		}
	}
}

void print_links(int data[][NUM_OF_MEMBERS] )
{
	int i, j;
	for( i=0 ; i<NUM_OF_MEMBERS ; i++ ) {
		for( j=0 ; j< NUM_OF_MEMBERS ; j++ ) {
			printf("%d ", data[i][j]);
		}
		puts("");
	}
}
