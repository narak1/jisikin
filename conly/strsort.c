#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
int main() 
{ 
   char *x, *q[100],buffer[100]; 
   int n=0,i, j; 
   printf("0�Է½� ����\n"); 
   printf("�ִ� 100���� �Է�\n"); 
   while(1)
   { 
      printf("%d��° ����",n+1); 
      gets(buffer); 
      if(buffer[0] == '0') {
      	break; 
      }
      q[n]=(char*)malloc( sizeof(char) * (strlen(buffer)+1) ); 
      strcpy(q[n],buffer); 
      n++; 
   } 
   printf("���� ��\n"); 
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
   printf("���� ��\n"); 
   for(i=0 ; i<n ; i++) 
   { 
      printf("%s\n",q[i]); 
   } 
} 

