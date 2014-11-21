#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *eng;
	char *kor;
} Data;

typedef struct _node
{
	Data data;
	struct _node *left;
	struct _node *right;
} Node;

void InsertNode(Node **tree, Node *cur);
void LoadDic(FILE *fp, Node **root);
void InorderSaveDic(FILE *fp, Node *node);
void LevelorderSaveDic(FILE *fp, Node *node);

int main(int argc, char **argv)
{
	const char *fname = "MyDic.txt";
	FILE *fp;
	Node *root = NULL, *tmp;
	char eng[BUFSIZ], kor[BUFSIZ];

	if( argc > 1 ) {
		fname = argv[1];
	}

	fp = fopen(fname, "r");
	if( fp != NULL ) {
		LoadDic(fp, &root);
		fclose(fp);
	}

	while(1) {
		printf("Input english word (\"-\" for quit) : ");
		scanf("%s", eng);
		if( eng[0] == '-' ) break;

		printf("Input korean word : ");
		scanf("%s", kor);

		tmp = (Node *) malloc(sizeof(Node));
		tmp->data.eng = strdup(eng);
		tmp->data.kor = strdup(kor);
		tmp->left = NULL;
		tmp->right = NULL;

		InsertNode(&root, tmp);
	}

	fp = fopen(fname, "w");
	if( fp != NULL ) {
		LevelorderSaveDic(fp, root);
		fclose(fp);
	}
	else {
		perror(fname);
	}
}

void LoadDic(FILE *fp, Node **root)
{
	char eng[BUFSIZ], kor[BUFSIZ];
	Node *node;
	while( fscanf(fp, "%s%s", eng, kor) != EOF )
	{
		node = (Node *) malloc(sizeof(Node));
		node->data.eng = strdup(eng);
		node->data.kor = strdup(kor);
		node->left = NULL;
		node->right = NULL;

		InsertNode(root, node);		
	}
}

void InsertNode(Node **tree, Node *cur)
{
	Node *tmp = *tree;
	if( tmp == NULL ) {
		*tree = cur;
	}
	else if( strcmp(cur->data.eng, tmp->data.eng) < 0 ) {
		InsertNode(&(tmp->left), cur);
	}
	else {
		InsertNode(&(tmp->right), cur);
	}
}

void InorderSaveDic(FILE *fp, Node *node)
{
   if (node == NULL)
   {
      printf("저장할 데이터가 없습니다.\n");
      return;
   }
   else
   {
      InorderSaveDic(fp, node->left);
      fprintf(fp, "%3s %3s\n", node->data.eng, node->data.kor);
      InorderSaveDic(fp, node->right);
   }
}

void LevelorderSaveDic(FILE *fp, Node *node)
{
	if (node == NULL) return;

	fprintf(fp,"%3s %3s\n", node->data.eng, node->data.kor);
	LevelorderSaveDic(fp, node->left);
	LevelorderSaveDic(fp, node->right);
}

