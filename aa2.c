#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static int num = 0;
static char **name;
static char *quit = "quit";
void insert(char p[100])
{
	int i;
	char *q;

	printf("문자를 입력하세요 : " );
	gets(p);
	if (strcmp(p,quit) == 0)
		return;

	// memory allocation
	name = (char **) realloc(name, sizeof(char*) * (num+1));
	name[num] = (char *) malloc(sizeof(char) * (strlen(p)+1));
	strcpy(name[num], p);

	for( i=num ; i>0 ; i-- )
	{
		if( strcmp(name[i], name[i-1]) < 0 )
		{
			q = name[i];
			name[i] = name[i-1];
			name[i-1] = q;
		}
	}

	num++;
}
int main(void)
{
 int i=0;
 char p[100];
 while(1)
 {
  insert(p);
  if (strcmp(p,quit) == 0)
  {
   for (i=0;i<num;i++)
   {
    printf("%s\n" , name[i]);
   }
   printf("함수를 종료합니다\n");
   break;
  }
 }
 for( i=0 ; i<num ; i++ )
 	free(name[i]);
 free(name);
 return 0;
}
 
