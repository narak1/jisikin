#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*#####################################################################
 Implementation Mode definition
######################################################################*/
// �Ʒ� ���� ���� ���� ���� ���� ��带 ����
// ��Ÿ���� ��� �ɺ� ���� �Դϴ�. �ش��ϴ� ��쿡��
// Ŀ��Ʈ�� ����� �˴ϴ�.
#define SORTED_DATA_MODE
//#define STATIC_BUFFER_MODE
/*#####################################################################
 General Constant definition
######################################################################*/
#define SUCCESS       1
#define FAIL         0
#define FAIL_ALREADY_EXIST   2 /* Used in the insert() */
#define FAIL_NO_BUFFER    3 /* Used in the insert()*/
/*#####################################################################
 Type definition
######################################################################*/
typedef struct __Node{
  int         num;
    struct __Node* nextp;
}_NODE;
/*#####################################################################
 Global Variables
######################################################################*/

/*#####################################################################
 Local Function Prototypes
######################################################################*/
void   dsp_LL();
int    insert_LL_node(int insValue);
int     delete_LL_node(int delValue);
#ifdef STATIC_BUFFER_MODE
void   build_free_list();
void   dsp_freeLL();
#endif     
_NODE*  get_free_node();
void   put_free_node(_NODE *node);
/*************************************************************************
 Main �Լ� ��
 ************************************************************************/
int main(void)
{
 int   num = 0;
 char  selMenu = '0';
 int  temp;  
/**** ���� ��� ǥ�� ****/
#ifdef SORTED_DATA_MODE
#ifdef STATIC_BUFFER_MODE
 printf("### Sorted-DATA(1) & Static-BUFFER(1) Mode ###\n\n");
#else
 printf("### Sorted-DATA(1) & dynamic-BUFFER(0) Mode ###\n\n");
#endif
#else
#ifdef STATIC_BUFFER_MODE
 printf("### Unsorted-DATA(0) & Static-BUFFER(1) Mode ###\n\n");
#else
 printf("### Unsorted-DATA(0) & dynamic-BUFFER(0) Mode ###\n\n");
#endif
#endif
/* 1. FreeList Display only for Static-buffer mode ��*/
#ifdef STATIC_BUFFER_MODE
 build_free_list();
 dsp_freeLL();
#endif 
 /* 2. Insert & Delete Node ���� */
 while(1)
 {
  printf("*** ���� ���� ( �Է� : 'i'  / ���� : 'd'  /  ���� : 'e' ) ?  ");
  selMenu = getch();
  printf("%c\n", selMenu);
  switch(selMenu){
   case 'i' :  /*2-1 Insert */
    printf(" >> Type the number to insert ? ");
    scanf("%d", &num);
    fflush(stdin);
    if( ( temp = insert_LL_node(num) ) != SUCCESS ){       
     if ( temp == FAIL_ALREADY_EXIST )
      printf("\n\t FAILURE : Already exist !!\n");
     else
      printf("\n\t FAILURE : Free node is not available !!\n"); 
    }
    dsp_LL(); // ���� ��ũ ���÷����Ѱ��� ��Ÿ���ش�
#ifdef STATIC_BUFFER_MODE
    dsp_freeLL();
#endif   
    break;
   case 'd' :  /* 2-2 Delete */
    printf(" >> Type the number to delete ? ");
    scanf("%d", &num);
    fflush(stdin);
    if ( delete_LL_node(num) == FAIL )
    {
     printf("\n\t FAILURE. No search value !!\n");
    }
    dsp_LL();
    
#ifdef STATIC_BUFFER_MODE
    dsp_freeLL();
#endif   
    break;
   case 'e' :   /* 2-3 Exit */
    printf("\n\t ���α׷� ����");
    exit(1);
    break;
   default:
    printf("\n\t �߸��� ��ɾ� �Է��Դϴ�.\n\n");
    break;
  }
 }
}
/*######################################################
 Linked-List ���� �Լ�
 ######################################################*/
 _NODE  *LLHead;  // Linked List head

/*===============================================
 Linked-list�� Display�ϴ� �Լ�
================================================*/
void dsp_LL()
{
 int i=0;
 _NODE *ptr;
 ptr = LLHead;
 
 printf("\n\t LinkedList => ");
 while( ptr != NULL )
 {
  printf("[%d]", ptr->num);
  if ( ptr->nextp != NULL )
   printf(" ");
  ptr = ptr->nextp;
  i++;
 }
 printf ("\t : Total (%d) nodes\n", i);
}
/*===============================================
 �Է°��� ���� ��带 ����
 - Delete�� ��带 ã�� ���:
    �ش� Deleted Node�� Linked List���� ������ free list�� ����ϸ�
  ���� ���� SUCCESS
 - Delete�� ��尡 ���� ��� :  ���ϰ��� FAIL
================================================*/
int delete_LL_node(int delValue )       // �ؾߵǴ°� delete ����
{
 _NODE *curPtr;
 _NODE *prevPtr;
 curPtr = LLHead;
 if( curPtr == NULL ){
  return FAIL;
 }
 if( curPtr->num == delValue)
 {
  LLHead = curPtr->nextp;
  put_free_node(curPtr);
  return SUCCESS;
 }
 prevPtr = curPtr;
 curPtr = curPtr->nextp;
 while (curPtr)
 {
  if (curPtr->num == delValue ){          // Delete�� ��� ��带 ã�� ���
   prevPtr->nextp = curPtr->nextp;
   put_free_node(curPtr);
   return SUCCESS;
  }
  //*** insert your code heare ***/
  LLHead = curPtr->nextp;
  put_free_node(curPtr);
 }
 return FAIL;
}

/*************************************************************************
 Node inserting �Լ�
 - Sorted ������ Non-sorted ������ ���� �� ������ �ۼ�
***************************************************************************/
#ifdef SORTED_DATA_MODE
/*===============================================
* Desp: ��ü Linked-List�� ������������ ���ĵɼ� �ֵ��� ��带 ������
          ������ �����ʹ� �ߺ����� ��ϵ� �� ����
  - ���������� Insert�� ��� : ���ϰ��� SUCCESS
  - ���������� Insert ���� ���� ���: ���ϰ� �� �Ʒ� �� ����
     * Free Node�� ���� ���: FAIL_ALREDY_EXisT
     * �̹� ���� �ִ� ��� : FAIL_ALREADY_EXIST
================================================*/
int insert_LL_node(int insValue ) 
{
 /*&&& �� ä���� �� �κ� &&&*/
	_NODE *newNodep;
	_NODE *pre, *cur;
	
	newNodep = get_free_node();
	if( newNodep == NULL)
		return FAIL_NO_BUFFER;
		
	newNodep->num = insValue;
	
	if( LLHead == NULL ) {
		newNodep->nextp = NULL;
		LLHead = newNodep;
	}
	else if( LLHead->num >= insValue ) {
		newNodep->nextp = LLHead;
		LLHead = newNodep;		
	}
	else {
		pre = LLHead;
		cur = pre->nextp;
		while( cur ) {
			if( cur->num >= insValue ) {
				pre->nextp = newNodep;
				newNodep->nextp = cur;
				break;
			}
			pre = cur;
			cur = pre->nextp;
		}
		if( cur == NULL ) {		// not inserted
			pre->nextp = newNodep;
			newNodep->nextp = NULL;
		}
	}
	
	return SUCCESS;
}
#else
/*===============================================
* Non sorted version
 - ����Ʈ �� �տ� ������ ������ ( ������ �����͵� �ߺ�����
  ��ϰ��� �� )
 - ���������� Insert�� ��� : ���ϰ��� SUCCESS
 - ���������� Insert ���� ���� ���: ���ϰ� �� �Ʒ� �� ����
     * Free Node�� ���� ���: FAIL_NO_BUFFER
================================================*/
int insert_LL_node(int insValue )
{
 _NODE *newNodep;
 newNodep = get_free_node();
 if( newNodep == NULL)
  return FAIL_NO_BUFFER;
 newNodep -> num = insValue;
 newNodep -> nextp = LLHead;
 LLHead = newNodep;
 return SUCCESS;
}
#endif

/*#####################################################
 2. Node Memory ���� ����
 - ����ü �迭�� ���۸� ����ϴ� ������
   malloc()/free()�� ����ϴ� ������ �����ϴµ� �ش��ϴ�
   ���� ����
######################################################*/
#ifdef STATIC_BUFFER_MODE
/*************************************************************************
   2-1. Free Node Buffer �� ����ϴ� ����
 ************************************************************************/
#define  SIZE    5   // Node ����
_NODE *FreeLLHead;    // Free Node�� ���� Linked List
_NODE  Node[SIZE];  // Node Buffer
/*==============================================
 Free list
================================================*/
void build_free_list()
{
 int  i = 0;
 for( i = 0;  i <= SIZE;  i++)
 {
  Node[i].num = 99;
  if(i+1 != SIZE)
   Node[i].nextp = &Node[i+1];
 }
 Node[i].nextp = NULL;
 FreeLLHead = &Node[0];
}
/*===============================================
 Free Linked-list�� Display�ϴ� �Լ�
================================================*/
void dsp_freeLL()
{
 int i=0;
 _NODE *ptr;
 
 ptr = FreeLLHead;
 printf("\t FreeList   => ");
 while( ptr != NULL )
 {
  printf("[%d]", ptr->num);
  if ( ptr->nextp != NULL )
   printf(" ");
  ptr = ptr->nextp;
  i++;
 }
 printf ("\t : Total (%d) nodes\n", i);
 printf("\n");
}
/*==============================================
 Free list�κ��� ��� �Ѱ��� ���� �Լ�
 - If Free list is empty, return NULL. Otherwise retun the address
  of the first node.
================================================*/
_NODE* get_free_node()          // ��������Ʈ���� ��带 �����
{

 /*&&&  ä���� �� �κ� &&&*/

}
/*===============================================
 Node�� �ݳ��ϴ� �Լ�
 -�ݳ��� ����� num �ʵ带 99�� ���� �ؼ� Free ����Ʈ��
   �� �Ǿտ� ���  
 -Parm: freeNode - �ݳ��� ���
 -Ret  : void
================================================*/
void put_free_node(_NODE *freeNode)
{
 /*&&&  ä���� �� �κ� &&&*/
}
#else
/**********************************************************************
 2-2. malloc()/free() �� ����ϴ� version
***********************************************************************/
/*==============================================
 Free list�κ��� ��� �Ѱ��� ���� �Լ�
 - malloc() �Լ��� ���
================================================*/
_NODE* get_free_node()
{
 return(_NODE *)malloc( sizeof(_NODE));
}
/*==============================================
 Free list�κ��� ��� �Ѱ��� ���� �Լ�
 - free() �Լ��� ���
================================================*/
void put_free_node(_NODE * freeNode)
{
 free( freeNode );
}
#endif
