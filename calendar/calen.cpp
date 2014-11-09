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
	cout <<"출력하고 싶은 월을 입력하세요 : " ;
	cin >>x;
	print_month(start, x);
	cin >>j;
	
	return 0;
}

void print_month(int start[],int x)
{
	int k=0; // 7칸을 맞춰주기 위해 사용한 변수
	int c=0; // 달력의 일값을 넣어주기 위한 변수
	
	cout <<"  일  월  화  수  목  금  토\n";
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
