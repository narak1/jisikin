#include<stdio.h>
#include<stdlib.h>
/////////////////////////////////////
// Student ����ü ����.
// �й��� int������,
// �̸��� char�� �迭��,
// ������ int������ ��������.
// struct Student�� Student�� ������.
//////////////////////////////////////
typedef struct Student{
int stunum;
char name[30];
int grade;
}Student;
void SortArray(Student data[],int size); //�迭�� �����ϴ� �Լ�.
void PrintArray(Student data[],int size); //�迭�� ����ϴ� �Լ�.
int main()
{
Student *data; //�����ͷ� ����ü data�� ����
char str[10];
int size,i;
FILE *fp; //���Ϻ��� fp ����
fp = fopen("list2.txt","r"); //list2.txt������ �б���� �����´�.
if(fp != NULL) //������ ����� ���������� ����.
{
fscanf(fp,"%s %d",str,&size); //���� ù��° �ٿ� �ִ� �ο����� ����.
data = (Student*)malloc(sizeof(Student)*size); //���� size��ŭ �����޸� �Ҵ�.
if(data != NULL) //�����޸��Ҵ��� ���������� ����.
{
for(i=0;i<size;i++) //�迭 ù��°ĭ���� size��ŭ ĭ���� �ݺ�
{
fscanf(fp,"%d %s %d",&data[i].stunum,data[i].name,&data[i].grade); //���Ͽ��� �й�,�̸�,������ ���ʴ�� �о�ͼ� �迭�� �����Ѵ�.
}

	SortArray(data, size);
	
PrintArray(data,size); //�迭�� ����ϴ� �Լ�.
free(data); //�����޸��Ҵ� ����
}
else printf("�����޸��Ҵ翡 �����߽��ϴ�.\n"); //�����޸� �Ҵ� ����
fclose(fp); //������ �ݴ´�.
}
else printf("������ �������� �ʽ��ϴ�.\n"); //���� �������� ����
return 0;
}

/////////////////////////////////////
// �迭�� ����ϴ� �Լ�.
// �Ķ���ͷ� Student���� �迭��
// int������ �迭�� size�� ������.
//////////////////////////////////////
void PrintArray(Student data[],int size)
{
int i;
for(i=0;i<size;i++) //�迭 ù��°ĭ���� size��ŭ ĭ���� �ݺ�
{
printf("%d %s %d\n",data[i].stunum,data[i].name,data[i].grade); //�迭�� ���
}
}

/////////////////////////////////////
// �迭�� �����ϴ� �Լ�.
// �Ķ���ͷ� Student���� �迭��
// int������ �迭�� size�� ������.
//////////////////////////////////////
void SortArray(Student data[],int size)
{
	int i, j;
	int Compare(Student *s1, Student *s2);
	void Swap(Student *s1, Student *s2);

	for(i=size-1 ; i>0 ; i--)
	{
		for( j=0 ; j<i ; j++ ) {
			if( Compare(&data[j], &data[j+1]) < 0 ) {	// ������ ������ ������ ��ġ �ٲٱ� 
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
