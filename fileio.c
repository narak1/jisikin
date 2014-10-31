#include <stdio.h>
#include <stdlib.h>

#define MAXDATA	10000

typedef struct 
{ 
	int Hackbun; //학번 
	char Name[20]; //이름 
	char Major[20]; //전공 
	int Grade; //학년 
	char Mail[50]; //메일주소 
}Information; 

void main() 
{ 
	int i = 0;
	char *fname = "student_old_master.txt";
	Information *Data[MAXDATA];  // 포인터를 저장할 배열, 메모리 크기는 MAXDATA * 4 
	Information *t;				//  임시변수
	int datanum;				// 읽은 데이타 수 
	FILE *OMF = NULL; 
	OMF = fopen(fname, "r"); 
	if( OMF == NULL ) {
		perror(fname);
		return;
	}
	
	while (!feof(OMF)) 
	{ 
		t = (Information*)malloc(sizeof(Information)); 
		fscanf(OMF, "%d%s%s%d%s", &t->Hackbun, t->Name, t->Major, &t->Grade, t->Mail); 
		printf("%d %s %s %d %s\n", t->Hackbun, t->Name, t->Major, t->Grade, t->Mail); 
		Data[i] = t;	// 할당된 메모리를 배열에서 관리 
		i++; 
	} 
	datanum = i;		// 전체 데이타 수를 변수에 저장 
	
	fclose(OMF); 
	
	for( i=0 ; i<datanum ; i++)
		free(Data[i]); 
}

