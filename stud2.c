#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define EXAM_NUM 4
#define STUDENT_NUM 8
#define CLASS_NUM 3

char StudentName[STUDENT_NUM][10]={
"공공공","일일일","이이이","삼삼삼","사사사","오오오","육육육","칠칠칠"};
char ExamName[EXAM_NUM][20]={
"4월월례고사","중간고사","5월평가","기말고사"};

int Score[EXAM_NUM][STUDENT_NUM][CLASS_NUM];
int Avr_score[EXAM_NUM][STUDENT_NUM]={0};
int Total_Avr_score[STUDENT_NUM]={0};

int calculate_average_student(int *p, int class_num);
void PRINT_NAME();
void PRINT_SCORE();
void main()
{
int a,b,c;
srand((unsigned)time(NULL));
for(a=0;a<EXAM_NUM;a++)
{
for(b=0;b<STUDENT_NUM;b++)
{
for(c=0;c<CLASS_NUM;c++)
{
Score[a][b][c]=(rand()%100)+1;
}
}
}


for(a=0;a<EXAM_NUM;a++)
{
for(b=0;b<STUDENT_NUM;b++)
{
Avr_score[a][b]=calculate_average_student(Score[a][b],8);//
}
}

for(a=0;a<STUDENT_NUM;a++)
{
for(b=0;b<EXAM_NUM;b++)
{
Total_Avr_score[a]+=Avr_score[a][b];
}
}

PRINT_NAME();
PRINT_SCORE();

}
void PRINT_NAME()
{
int i;
printf("\t\t");
for(i=0;i<STUDENT_NUM;i++)
{
printf("%s ",StudentName[i]);
}
printf("\n");
}
void PRINT_SCORE()
{
int i,j;
for(i=0;i<EXAM_NUM;i++)
{
printf("%s\t",ExamName[i]);
for(j=0;j<STUDENT_NUM;j++)
{
printf("%d  ",Avr_score[i][j]);
}
printf("\n");
}

printf("\n전체평균\t");
for(i=0;i<STUDENT_NUM;i++)
{
printf("%d  ",Total_Avr_score[i]);
}

}
int calculate_average_student(int *p, int class_num)
{
int i,j;
int result=0;
for(i=0;i<CLASS_NUM;i++)
{
	result += p[i];
}
return round((double)result / CLASS_NUM);
}
