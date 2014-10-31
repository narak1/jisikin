#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
	unsigned int id;	// or char id[10];
	char name[32];		// enough size
	float credit;
	char birthday[12];	// include NULL
	struct Student *left;	// pre pointer
	struct Student *right;	// post pointer
} student;

void insert_node(student **root, student *tmp);

void print_node(student *node);
void print_preorder(student *node);
void print_inorder(student *node);
void print_postorder(student *node);

int main(int argc, char **argv)
{
	char *filename = "student.txt";
	FILE *fp;
	student *root, *tmp;
	unsigned int id;
	
	if( argc > 1 ) {
		filename = argv[1];
	}
	
	fp = fopen(filename, "r");
	if( fp == NULL ) {
		perror(filename);
		return 1;
	}
	
	root = NULL;
	while( fscanf(fp, "%u", &id) != EOF )
	{
		tmp = (student *) malloc(sizeof(student));
		tmp->id = id;
		tmp->left = NULL;
		tmp->right = NULL;
		fscanf(fp, "%s%f%s", tmp->name, &tmp->credit, tmp->birthday);

		insert_node(&root, tmp);
	}
	
	fclose(fp);
	
	puts("preorder");
	print_preorder(root);
	puts("inorder");
	print_inorder(root);
	puts("postorder");
	print_postorder(root);
}

void insert_node(student **root, student *tmp)
{
	struct Student *cur;
	
	if( *root == NULL )	{	// empty tree
		*root = tmp;
		return;
	}
	
	cur = *root;
	while( cur != NULL )
	{
		if( tmp->id < cur->id ) {
			if( cur->left == NULL ) {	// find position
				cur->left = tmp;
				break;
			}
			else {
				cur = cur->left;
			}
		}
		else {
			if( cur->right == NULL ) {
				cur->right = tmp;
				break;
			}
			else {
				cur = cur->right;
			}
		}
	}
}

void print_node(student *node)
{
	printf("%u %-15s %3.1f %s\n", node->id, node->name, node->credit, node->birthday);
}

void print_preorder(student *node)
{
	if( node == NULL )
		return;
		
	print_node(node);
	print_preorder(node->left);
	print_preorder(node->right);
}


void print_inorder(student *node)
{
	if( node == NULL )
		return;
		
	print_inorder(node->left);
	print_node(node);
	print_inorder(node->right);
}

void print_postorder(student *node)
{
	if( node == NULL )
		return;
		
	print_postorder(node->left);
	print_postorder(node->right);
	print_node(node);
}

