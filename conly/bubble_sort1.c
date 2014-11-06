#include<stdio.h>
#include<stdlib.h>
/////////////////////////////////////
// Student 구조체 선언.
// 학번을 int형으로,
// 이름을 char형 배열로,
// 성적을 int형으로 변수선언.
// struct Student를 Student로 정의함.
//////////////////////////////////////
typedef struct Student{
int stunum;
char name[30];
int grade;
}Student;
void SortArray(Student data[],int size); //배열을 정렬하는 함수.
void PrintArray(Student data[],int size); //배열을 출력하는 함수.
int main()
{
Student *data; //포인터로 구초체 data를 선언
char str[10];
int size,i;
FILE *fp; //파일변수 fp 선언
fp = fopen("list2.txt","r"); //list2.txt파일을 읽기모드로 가져온다.
if(fp != NULL) //파일을 제대로 가져왔으면 진행.
{
fscanf(fp,"%s %d",str,&size); //파일 첫번째 줄에 있는 인원수를 읽음.
data = (Student*)malloc(sizeof(Student)*size); //읽은 size만큼 동적메모리 할당.
if(data != NULL) //동적메모리할당을 성공했으면 진행.
{
for(i=0;i<size;i++) //배열 첫번째칸부터 size만큼 칸까지 반복
{
fscanf(fp,"%d %s %d",&data[i].stunum,data[i].name,&data[i].grade); //파일에서 학번,이름,성적을 차례대로 읽어와서 배열에 저장한다.
}

	SortArray(data, size);
	
PrintArray(data,size); //배열을 출력하는 함수.
free(data); //동적메모리할당 해제
}
else printf("동적메모리할당에 실패했습니다.\n"); //동적메모리 할당 실패
fclose(fp); //파일을 닫는다.
}
else printf("파일이 존재하지 않습니다.\n"); //파일 가져오기 실패
return 0;
}

/////////////////////////////////////
// 배열을 출력하는 함수.
// 파라미터로 Student형의 배열과
// int형으로 배열의 size를 가져옴.
//////////////////////////////////////
void PrintArray(Student data[],int size)
{
int i;
for(i=0;i<size;i++) //배열 첫번째칸부터 size만큼 칸까지 반복
{
printf("%d %s %d\n",data[i].stunum,data[i].name,data[i].grade); //배열을 출력
}
}

/////////////////////////////////////
// 배열을 정렬하는 함수.
// 파라미터로 Student형의 배열과
// int형으로 배열의 size를 가져옴.
//////////////////////////////////////
void SortArray(Student data[],int size)
{
	int i, j;
	int Compare(Student *s1, Student *s2);
	void Swap(Student *s1, Student *s2);

	for(i=size-1 ; i>0 ; i--)
	{
		for( j=0 ; j<i ; j++ ) {
			if( Compare(&data[j], &data[j+1]) < 0 ) {	// 앞쪽이 성적이 낮으면 위치 바꾸기 
				Swap(&data[j], &data[j+1]);
			}
		}
	}
}

int Compare(Student *s1, Student *s2)
{
	return s1->grade - s2->grade;
}

void Swap(Student *s1, Student *s2)
{
	Student tmp;
	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
