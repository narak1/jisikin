#include <stdio.h>
#include <string.h>
char High_Freq(int NLetter[]);

int main(void)
{
 char letters[500];         // <-여기
 char *p;
 int i, len;
 int num_alpha['Z'-'A'+1] = { 0, };	// initialize all zero
 
 printf("500자 이내의 글을 입력하시오:");
 len = 0;
 p = letters;
 while( 1 )
 {
 	fgets(p, 500-len-1, stdin);
 	
 	if( p[0] == '\n' )
 		break;
 		
 	len = strlen(letters);
 	if(len >= 500-1)
 		break;
 		
	p = letters + len;
}
 
 for(i=0; i<strlen(letters); i++)
 {
	if(isupper(letters[i]))
	{
	   letters[i] = tolower (letters[i]); 
	}
	
	if(islower (letters[i]))
	{
		num_alpha[letters[i]-'a']++;
	}
 }
 
 printf("The letter of the highest frequency is %c\n", High_Freq(num_alpha));
}
 
char High_Freq(int NLetter[])    //<- 가장 높은 빈도의 영문자 구하기
{
	int i, max_idx, max_num;
	
	max_idx = 0;
	max_num = NLetter[0];
	for( i=1 ; i<='Z'-'A' ; i++ )
	{
		if( NLetter[i] > max_num )
		{
			max_idx = i;
			max_num = NLetter[i];
		}
	}
	
	return 'a'+max_idx;
}
