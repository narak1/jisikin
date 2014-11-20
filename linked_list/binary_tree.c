#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 typedef struct Student
 {
    char id[10];
    char name[10]; 
    struct Student *left; 
    struct Student *right; 
 } STUDENT;
 void insert_node(STUDENT **tree, STUDENT *tmp);
STUDENT* binarytree_search(STUDENT *cur, char *key);
STUDENT* binarytree_delete(STUDENT **cur, char *key);
 void print_node(STUDENT *node);
 void preorder(STUDENT *node);
 void inorder(STUDENT *node);
 void postorder(STUDENT *node);
 
 int main(int argc, char **argv)
 {
    char *filename="Student.txt";
  FILE *fp;
    STUDENT *tree, *tmp, *find;
    char id[10];
    
   fp = fopen(filename, "r");
    if( fp == NULL ) {
       perror(filename);
       return 1;
    }
    tree = NULL;
    while( fscanf(fp, "%s", id) != EOF )
    {
       tmp = (STUDENT *) malloc(sizeof(STUDENT));
       strcpy(tmp->id, id);
       tmp->left = NULL;
       tmp->right = NULL;
       fscanf(fp, "%s", tmp->name);
       insert_node(&tree, tmp);
    }
    fclose(fp);
    puts("preorder");
    preorder(tree);
    puts("inorder");
    inorder(tree);
    puts("postorder");
    postorder(tree);

	while(1){
		printf("input id for search! (stop=-1) : ");
		scanf("%s", id);
		if( id[0] == '-' ) break;
		find = binarytree_search(tree, id);
		if(find!=NULL)
			printf("found %s\n", find->name);
		else
			printf("Not found\n");
	}
	
	// delete node
	while(1)
	{
		printf("input id for delete (stop=-1) : ");
		scanf("%s", id);
		if( id[0] == '-' ) break;
		find = binarytree_delete(&tree, id);
		if(find!=NULL) {
			printf("delete %s\n", find->name);
			free(find);
			
		    puts("preorder");
		    preorder(tree);
		    puts("inorder");
		    inorder(tree);
		    puts("postorder");
		    postorder(tree);
		}
		else {
			printf("Not found\n");
		}
	}
    return 0;
}

STUDENT *binarytree_search(STUDENT *cur, char *key)
{
   STUDENT *found;
   if(cur==NULL)
    return NULL;
   if(!strcmp(cur->id, key))
       return cur;
   else if(strcmp(cur->id, key)>0)
  binarytree_search(cur->left, key);
   else 
  binarytree_search(cur->right, key);    
 }
 
 void insert_node(STUDENT **tree, STUDENT *tmp)
 {
    struct Student *cur;
    if( *tree == NULL ) { // empty tree 
       *tree = tmp; 
       return; 
    } 
    cur = *tree;
    if( strcmp(cur->id, tmp->id)>0)
    {    
      if(cur->left!=NULL) 
    insert_node(&cur->left, tmp);
      else 
    cur->left = tmp;
   }else {
      if(cur->right!=NULL) 
    insert_node(&cur->right, tmp);
      else
    cur->right = tmp;
   }
 }
 void print_node(STUDENT *node)
 {
    printf("%s\t%s\n", node->id, node->name);
 }
 void preorder(STUDENT *node)
 {
    if( node == NULL )
  return;
    print_node(node);
    preorder(node->left);
    preorder(node->right);
 }
 void inorder(STUDENT *node)
 {
    if( node == NULL )
  return;
    inorder(node->left);
    print_node(node);
    inorder(node->right);
 }
 void postorder(STUDENT *node)
 {
    if( node == NULL )
  return;
    postorder(node->left);
    postorder(node->right);
    print_node(node);
 }

int is_leaf(STUDENT *node)
{
	return (node->left == NULL && node->right == NULL);
}

STUDENT *get_right_leaf(STUDENT *parent)
{
	STUDENT *node;
	if( parent == NULL ) return NULL;
	
	node = parent->right;
	if( node == NULL ) return NULL;
	
	if( is_leaf(node) ) {
		parent->right = NULL;
		return node;
	}
	
	return get_right_leaf(node);
}

STUDENT *get_left_leaf(STUDENT *parent)
{
	STUDENT *node;
	if( parent == NULL ) return NULL;
	
	node = parent->left;
	if( node == NULL ) return NULL;
	
	if( is_leaf(node) ) {
		parent->left = NULL;
		return node;
	}
	
	return get_left_leaf(node);
}

STUDENT *binarytree_delete(STUDENT **cur, char *key)
{
	STUDENT *node, *leaf;
	
	if( *cur == NULL ) return NULL;

	node = *cur;
	leaf = NULL;
	if( strcmp(node->id, key) == 0 ) {
		if( is_leaf(node) ) {
			*cur = NULL;
			return node;
		}

		// promotion child
		//
		if( node->left != NULL && node->left->right == NULL ) {
			node->left->right = node->right;
			*cur = node->left;
			return node;
		}
		if( node->right != NULL && node->right->left == NULL ) {
			node->right->left = node->left;
			*cur = node->right;
			return node;
		}

		// get available leaf
		//
		if( leaf == NULL ) {
			leaf = get_right_leaf(node->left);
			if( leaf == NULL ) {
				leaf = get_left_leaf(node->right);
			}
		}

		if( leaf != NULL ) {
			leaf->left = node->left;
			leaf->right = node->right;
			*cur = leaf;
			return node;
		}
		else {
			puts("Difficult or select any leaf node and replace.");
			return NULL;
		}
	}
	else if( strcmp(node->id, key) > 0 ) {
		return binarytree_delete( &(node->left), key);
	}
	else {
		return binarytree_delete( &(node->right), key);
	}
}

