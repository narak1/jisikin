#include <stdio.h>
#include <stdlib.h>

typedef struct stDataNode
{
	char id;
	struct stDataNode *child;
	struct stDataNode *next;
} DataNode;

DataNode* add_node(DataNode *p, char d);
DataNode* find_node(DataNode *node, char id);
void print_tree(DataNode *node, int depth);

char *data = "(A(B(E(K,L),F),C(G),D(H(M),I,J)))";

main(int argc, char **argv)
{
	DataNode *root, *tmp;
	
	root = add_node(NULL, 'A');
	
	tmp = add_node(root, 'B');
	tmp = add_node(tmp, 'E');
	tmp = add_node(tmp, 'K');
	tmp = add_node(tmp, 'L');
	
	tmp = find_node(root, 'B');
	tmp = add_node(tmp, 'F');
	
	tmp = add_node(root, 'C');
	tmp = add_node(tmp, 'G');
	
	tmp = add_node(root, 'D');
	tmp = add_node(tmp, 'H');
	tmp = add_node(tmp, 'M');
	
	tmp = find_node(root, 'D');
	tmp = add_node(tmp, 'I');
	tmp = add_node(tmp, 'J');
	
	print_tree(root, 0);				
}

DataNode* add_node(DataNode *p, char d)
{
	DataNode *t;
	
	if( p != NULL && p->next != NULL )		// add to child
	{
		t = (DataNode *) malloc(sizeof(DataNode));
		t->id = '.';
		t->child = p->next;
		p->next = t;
		
		p = t;
	}
	t = (DataNode *) malloc(sizeof(DataNode));
	t->id = d;
	t->child = NULL;
	t->next = NULL;
	
	if( p != NULL )
		p->next = t;
	
	return t;
}

DataNode* find_node(DataNode *node, char id)
{
	DataNode *t;
	
	if( node == NULL )
		return NULL;
		
	if( node->id == id )
		return node;
		
	t = find_node(node->next, id);
	if( t == NULL )
		t = find_node(node->child, id);
		
	return t;
}

void print_tree(DataNode *node, int depth)
{
	int i;
	
	if( node == NULL )
		return;
		
	for( i=0 ; i<depth ; i++ )
		putchar('\t');
	printf("%c\n", node->id);
	print_tree(node->next, depth+1);
	print_tree(node->child, depth);
}
