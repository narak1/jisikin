#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
int main() 
{ 
   char *x, *q[100],buffer[100]; 
   int n=0,i, j; 
   printf("0입력시 종료\n"); 
   printf("최대 100문장 입력\n"); 
   while(1)
   { 
      printf("%d번째 문장",n+1); 
      gets(buffer); 
      if(buffer[0] == '0') {
      	break; 
      }
      q[n]=(char*)malloc( sizeof(char) * (strlen(buffer)+1) ); 
      strcpy(q[n],buffer); 
      n++; 
   } 
   printf("정렬 후\n"); 
   for(i=0 ; i<n ; i++) 
   { 
      printf("%s\n",q[i]); 
   } 
   for( i=n-1 ; i>0 ; i-- ) {
   		for( j=0 ; j<i ; j++ ) {
		   	if( strcmp(q[j], q[j+1]) > 0 ) {
		   		x = q[j];
		   		q[j] = q[j+1];
		   		q[j+1] = x;
		   	}
		} 
   } 
   printf("정렬 후\n"); 
   for(i=0 ; i<n ; i++) 
   { 
      printf("%s\n",q[i]); 
   } 
} 

