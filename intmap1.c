#include <stdio.h>
int main() 
{ 
      int n, m, r, k; 
      int val = 53177070;       
      char result[5][5]; 
      
      for(n=25; n>0; n--){               
             m = 1<<n;           
             r = val & m; 
             if(r) *(result[0]+n-1) = n; 
             else *(result[0]+n-1) = NULL; 
      } 
      for (n=0; n<5; n++) 
      { 
             for (k=0; k<5; k++) 
             { 
                    if (result[n][k]!=NULL) printf("%2d ", result[n][k]); 
                    else printf("%2c ", result[n][k]); 
             } 
             printf("\n"); 
      } 
   return 0; 
} 

