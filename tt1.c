#include <stdio.h>
#include <ctype.h>
char Encrypt(char alpabet); 
int main(void)
{
 char letters[7][BUFSIZ], cypher[BUFSIZ];  
 int i, j;
 
 i=0, j=0;
 printf("%d자 이내의 글을 입력하시오:", BUFSIZ-1);
 for(i=0; i<7; i++)
 {
  gets(letters[i]);
  for( j=0; letters[i][j]; j++)
  {

  if(isupper(letters[i][j]))  
  {
   letters[i][j] = tolower(letters[i][j]);  
  }
  if(islower(letters[i][j])) 
    {
   cypher[j] = Encrypt(letters[i][j]); 
  }
  else {
  	cypher[j] = letters[i][j];
  }
 }
 printf("The cyphered text is %s\n", cypher);  
}
}

char Encrypt(char alpabet) 
{
 alpabet = (alpabet) + 2;
 return alpabet;
}
