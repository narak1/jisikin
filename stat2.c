#include <stdio.h>
#include <stdlib.h>

#define MAXSTUD	1000
#define MAXSUBJ	5

typedef struct
{
	char id[10];
	char name[12];
	int data_idx;	// 정렬을 한다면 필요함. 
	float aver;
} StdMark;

main()
{
	char *filename = "stdmark.txt";
	char *result = "cal_average.txt";
	FILE *fp;
	StdMark stud[MAXSTUD];
	float subject[MAXSTUD][MAXSUBJ];
	float sub_total[MAXSUBJ], stud_total;
	int i, j, idx, num;

	// file open
	fp = fopen(filename, "r");
	if( fp == NULL ) {
		perror(filename);
		return 1;
	}

	// file read
	num = 0;
	while( fscanf(fp, "%s", stud[num].id) != EOF )
	{
		fscanf(fp, "%s", stud[num].name);
		stud[num].data_idx = num;
		for( i=0 ; i<MAXSUBJ ; i++ ) {
			fscanf(fp, "%f", &(subject[num][i]));
		}
		++num;
	}

	fclose(fp);

	// initialize
	for( i=0 ; i<MAXSUBJ ; i++ )
		sub_total[i] = 0.0f;

	// calc
	for( i=0 ; i<num ; i++ ) {
		stud_total = 0.0f;
		idx = stud[i].data_idx;		// 학생 데이터가 정렬이 되었다면 필요함 
		for( j=0 ; j<MAXSUBJ ; j++ ) {
			stud_total += subject[idx][j];
			sub_total[j] += subject[i][j];
		}
		stud[i].aver = stud_total / MAXSUBJ;
	}

	// output
	fp = fopen(result, "w");
	if( fp == NULL ) {
		perror(result);
		return 2;
	}
	
	for( i=0 ; i<num ; i++ ) {
		fprintf(fp, "%8s %10s", stud[i].id, stud[i].name);
		idx = stud[i].data_idx;		// 학생 데이터가 정렬이 되었다면 필요함
		for( j=0 ; j<MAXSUBJ ; j++ )
			fprintf(fp, " %5.1f", subject[idx][j]);
		fprintf(fp, " %5.1f\n", stud[i].aver);
	}

	// subject average print
	fprintf(fp, "%8s %10s", "", "");
	for( j=0 ; j<MAXSUBJ ; j++ )
		fprintf(fp, " %5.1f", sub_total[j] / num);
	fputs("", fp);
}

