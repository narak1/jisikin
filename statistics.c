#include <stdio.h>
#include <stdlib.h>

#define MAXSTUD	1000
#define MAXSUBJ	5

typedef struct
{
	char id[10];
	char name[12];
	float subject[MAXSUBJ];
	float aver;
} StdMark;

main()
{
	char *filename = "stdmark.txt";
	char *result = "stdmarkgr.txt";
	FILE *fp;
	StdMark stud[MAXSTUD];
	float sub_total[MAXSUBJ], stud_total;
	int i, j, num;

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
		for( i=0 ; i<MAXSUBJ ; i++ ) {
			fscanf(fp, "%f", &(stud[num].subject[i]));
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
		for( j=0 ; j<MAXSUBJ ; j++ ) {
			stud_total += stud[i].subject[j];
			sub_total[j] += stud[i].subject[j];
		}
		stud[i].aver = stud_total / MAXSUBJ;
	}

	// print
	for( i=0 ; i<num ; i++ ) {
		printf("%8s %10s", stud[i].id, stud[i].name);
		for( j=0 ; j<MAXSUBJ ; j++ )
			printf(" %5.1f", stud[i].subject[j]);
		printf(" %5.1f\n", stud[i].aver);
	}

	// subject average print
	printf("%8s %10s", "", "");
	for( j=0 ; j<MAXSUBJ ; j++ )
		printf(" %5.1f", sub_total[j] / num);
	puts("");
}
