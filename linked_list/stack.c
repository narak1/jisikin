#include <stdio.h> 
#include <stdlib.h> 
typedef struct node 
{ 
   int data; 
   struct node *pNext; 
} node; 
node *head, *tail = NULL; 
void push(int val) 
{ 
   struct node *new, *temp; 
   temp = head->pNext; 
   new = (node *)malloc(sizeof(node)); 
   new->data = val; 
   new->pNext = temp; 
   head->pNext = new; 
} 
void pop() 
{ 
   struct node *del; 
   del = head->pNext; 
   head->pNext = del->pNext; 
   free(del); 
} 
void init() 
{ 
   head = (node *)malloc(sizeof(node)); 
   tail = (node *)malloc(sizeof(node)); 
   head->pNext = tail; 
} 
void printStack() 
{ 
   node *now; 
   printf("PrintStack() : "); 
   for(now = head->pNext; now != tail; now = now->pNext) 
   { 
      printf("%d ", now->data); 
   } 
   printf("\n"); 
} 
int main(void) 
{ 
   init(); 
   push(19); 
   push(28); 
   push(74); 
   push(10); 
   printStack(); 
   pop(); 
   pop(); 
   pop(); 
   pop(); 
   return 0; 
} 
