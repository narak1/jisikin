#include <stdio.h>
#include <stdlib.h>

#define MAXDATA	10000

typedef struct 
{ 
	int Hackbun; //�й� 
	char Name[20]; //�̸� 
	char Major[20]; //���� 
	int Grade; //�г� 
	char Mail[50]; //�����ּ� 
}Information; 

void main() 
{ 
	int i = 0;
	char *fname = "student_old_master.txt";
	Information *Data[MAXDATA];  // �����͸� ������ �迭, �޸� ũ��� MAXDATA * 4 
	Information *t;				//  �ӽú���
	int datanum;				// ���� ����Ÿ �� 
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
		Data[i] = t;	// �Ҵ�� �޸𸮸� �迭���� ���� 
		i++; 
	} 
	datanum = i;		// ��ü ����Ÿ ���� ������ ���� 
	
	fclose(OMF); 
	
	for( i=0 ; i<datanum ; i++)
		free(Data[i]); 
}

