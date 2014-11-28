#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node* left;
 struct node* right;
}node;
node* insert(node* a, int num)
{
  if(a==NULL)
  {
   a = (node*)malloc(sizeof(node));
   a->data = num;
   a->left = NULL;
   a->right = NULL;
   return a;
  }
 
  if(num< a->data )
  {
    a->left= insert(a->left,num);
  }
  else  
  {
    a->right =  insert(a->right, num);
  }
   return a;
}

void print_tree_pre(node *a)
{
	if( a == NULL ) return;
	printf("%d\n", a->data);
	print_tree_pre(a->left);
	print_tree_pre(a->right);
}
void print_tree_in(node *a)
{
	if( a == NULL ) return;
	print_tree_in(a->left);
	printf("%d\n", a->data);
	print_tree_in(a->right);
}

void print_tree_post(node *a)
{
	if( a == NULL ) return;
	print_tree_post(a->left);
	print_tree_post(a->right);
	printf("%d\n", a->data);
}
int main()
{
	node* a = NULL;
	a = insert(a, 13);
	a = insert(a, 15);
	a = insert(a, 10);
	a = insert(a, 17);
	puts("node order print");
	print_tree_pre(a);
	puts("sorted print");
	print_tree_in(a);
}
