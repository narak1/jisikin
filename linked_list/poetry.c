#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Poetry
{
	char m_author[20];
	char m_text[1000];
	struct Poetry* pNext;
}Poetry;

char *trim(char buf[])
{
	char *p = buf;
	int i;
	while( *p ) {					// left trim
		if( *p == ' ' || *p == '\n' || *p == '\t' )
			;
		else {
			break;
		}
		++p;
	}
	for( i=strlen(p)-1 ; i>=0 ; i-- ) {	// right trim
		if( p[i] == ' ' || p[i] == '\n' || p[i] == '\t' )
			;
		else {
			p[i+1] = 0;
			break;
		}
	}
	return p;
}

int main()
{
	char name[20];
	char A[100];
	Poetry* pHeader, *pTemp;
	Poetry* pPeotry;
	FILE *pF;
	int i,j=0; // 변수 설정

	pF = fopen("Input_database.txt","r");
	if (pF == NULL){
		printf("파일이 없습니다\n");
		exit(1);
	}

	printf("검색할 시인 : ");
	gets(name);

	pPeotry = (Poetry*)malloc(sizeof(Poetry)* 7);

	//리스트 연결
	for (i = 0; i < 6; i++){
		pPeotry[i].pNext = &pPeotry[i + 1];
	}
	pPeotry[i].pNext = NULL;
	pHeader = &pPeotry[0];

	// 구조체에 자료 대입
	pTemp = NULL;
	while( fgets(A, 100, pF) != NULL )
	{
		if (A[0] == '>'){
			if( pTemp == NULL ) {
				pTemp = pHeader;
			}
			else {
				pTemp = pTemp->pNext;
			}
			strcpy(pTemp->m_author, trim(A+1));
			pTemp->m_text[0] = 0;
		}
		else if( pTemp != NULL ) {
			strcat(pTemp->m_text, A);
		}
	}
	fclose(pF);

	// 자료 검색
	pTemp = pHeader;
	while( pTemp != NULL )
	{
		if (strcmp(pTemp->m_author,name)==0){
			printf("작가 : %s \n", pTemp->m_author);
			printf("%s", pTemp->m_text);
			break;
		}
		pTemp = pTemp->pNext;
	}
	if( pTemp == NULL )
	{
		printf("해당 작가의 시조는 검색 되지 않습니다");
	}

	free(pPeotry);
	getchar();

	return 0;
}
