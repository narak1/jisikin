#include <iostream>
#include <stdio.h>
using namespace std;

int start[12]={2, 5, 5, 1, 3, 6, 1, 4,0, 2, 5, 0};
int day[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month[7][7]={0};

void print_month(int start[], int x);

int main()
{
	int x,j;
	cout <<"����ϰ� ���� ���� �Է��ϼ��� : " ;
	cin >>x;
	print_month(start, x);
	cin >>j;
	
	return 0;
}

void print_month(int start[],int x)
{
	int k=0; // 7ĭ�� �����ֱ� ���� ����� ����
	int c=0; // �޷��� �ϰ��� �־��ֱ� ���� ����
	
	cout <<"  ��  ��  ȭ  ��  ��  ��  ��\n";
	for(int i=0; i<start[x-1]; i++){
		k++;
		printf("    ");
	}
	for(int i=0; i<5; i++){
		for(int j=0; j<7; j++){
			if(c==day[x-1])
				break;
			if((k%7==0) && (k>0))
				cout << endl;
			k++;c++;
			month[i][j]=c;
			printf("%4d", month[i][j]);
		}
	}
}
