#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM_OF_MEMBERS 15 // sns �������� ��
int link_data[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {0}; //���� link matrix 1���� matrix
int link_result[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {0}; //2�̱����� ���谡 ǥ�õ� matrix
void print_links(int data[][NUM_OF_MEMBERS] ); //2���� �迭 ���
void matrix_multiplication(int data[][NUM_OF_MEMBERS], int result[][NUM_OF_MEMBERS] ); //2���� �迭 ���� data X data ?-> result

int main( void )
{
	int i = 0;
	int j = 0;
	int num_of_steps=0;
	int ALL_ONES=0;

	srand( (unsigned int)time(NULL) );

	for(i = 0; i<NUM_OF_MEMBERS; i++ )
	{
		link_data[i][i] = 1;//i�� i�� ����� 1��. �� 1�� ǥ��
	}

	for(i = 0; i<NUM_OF_MEMBERS; i++ )
	{
		for(i = 0; i<NUM_OF_MEMBERS; i++ ) // �� user ���� 4���� ģ���� ģ���� �ִٰ� ���� .
		{
			j=0;
			while ( j<2 ) //i �� �� ���� ��ũ�� ��ũ�� �����ϰ� i�� �ƴ� �ٸ� user �� i�� ����
			{
				int new_link = rand()%NUM_OF_MEMBERS; //i �� random�ϰ� �ٸ� user�� 1���̶� �� ����
				if( new_link != i )
				{
					link_data[i][new_link] = 1;  //i �� new_link�� 1���̸�
					link_data[new_link][i] = 1; //new_link�� i�� 1��.
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
	print_links(link_data); // ���� 1�� ���� ���

	matrix_multiplication(link_data,link_result);
	puts("==================================================================");
	puts("Friends of friends matrix");
	puts("==================================================================");
	print_links(link_result); //���� 2�̱����� ���� ���
}

void matrix_multiplication(int data[][NUM_OF_MEMBERS],int result[][NUM_OF_MEMBERS])
{
//�����ؾ��� �κ�
//data matrix�� �� ������ result�� ����.

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
