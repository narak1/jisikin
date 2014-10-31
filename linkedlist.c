#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*#####################################################################
 Implementation Mode definition
######################################################################*/
// 아래 구현 모드는 정렬 모드와 버퍼 모드를 각각
// 나타내는 상수 심볼 정의 입니다. 해당하는 경우에만
// 커맨트를 지우면 됩니다.
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
 Main 함수 부
 ************************************************************************/
int main(void)
{
 int   num = 0;
 char  selMenu = '0';
 int  temp;  
/**** 구현 모드 표시 ****/
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
/* 1. FreeList Display only for Static-buffer mode ㅇ*/
#ifdef STATIC_BUFFER_MODE
 build_free_list();
 dsp_freeLL();
#endif 
 /* 2. Insert & Delete Node 동작 */
 while(1)
 {
  printf("*** 동작 선택 ( 입력 : 'i'  / 삭제 : 'd'  /  종료 : 'e' ) ?  ");
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
    dsp_LL(); // 현재 링크 디스플레이한것을 나타내준다
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
    printf("\n\t 프로그램 종료");
    exit(1);
    break;
   default:
    printf("\n\t 잘못된 명령어 입력입니다.\n\n");
    break;
  }
 }
}
/*######################################################
 Linked-List 관련 함수
 ######################################################*/
 _NODE  *LLHead;  // Linked List head

/*===============================================
 Linked-list를 Display하는 함수
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
 입력값을 갖는 노드를 삭제
 - Delete한 노드를 찾은 경우:
    해당 Deleted Node를 Linked List에서 삭제후 free list에 등록하며
  리턴 값은 SUCCESS
 - Delete한 노드가 없는 경우 :  리턴값은 FAIL
================================================*/
int delete_LL_node(int delValue )       // 해야되는거 delete 변경
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
  if (curPtr->num == delValue ){          // Delete할 대상 노드를 찾은 경우
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
 Node inserting 함수
 - Sorted 버전과 Non-sorted 버전에 대해 한 버전만 작성
***************************************************************************/
#ifdef SORTED_DATA_MODE
/*===============================================
* Desp: 전체 Linked-List에 오름차순으로 정렬될수 있도록 노드를 삽입함
          동일한 데이터는 중복으로 등록될 수 없음
  - 정상적으로 Insert한 경우 : 리턴값은 SUCCESS
  - 정상적으로 Insert 하지 못한 경우: 리턴값 은 아래 와 같음
     * Free Node가 없는 경우: FAIL_ALREDY_EXisT
     * 이미 값이 있는 경우 : FAIL_ALREADY_EXIST
================================================*/
int insert_LL_node(int insValue ) 
{
 /*&&& 이 채워야 할 부분 &&&*/
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
 - 리스트 맨 앞에 무조건 삽입함 ( 동일한 데이터도 중복으로
  등록가능 함 )
 - 정상적으로 Insert한 경우 : 리턴값은 SUCCESS
 - 정상적으로 Insert 하지 못한 경우: 리턴값 은 아래 와 같음
     * Free Node가 없는 경우: FAIL_NO_BUFFER
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
 2. Node Memory 버퍼 관련
 - 구조체 배열의 버퍼를 사용하는 버전과
   malloc()/free()를 사용하는 버전이 존재하는데 해당하는
   것을 구현
######################################################*/
#ifdef STATIC_BUFFER_MODE
/*************************************************************************
   2-1. Free Node Buffer 를 사용하는 버전
 ************************************************************************/
#define  SIZE    5   // Node 개수
_NODE *FreeLLHead;    // Free Node를 담은 Linked List
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
 Free Linked-list를 Display하는 함수
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
 Free list로부터 노드 한개를 얻어내는 함수
 - If Free list is empty, return NULL. Otherwise retun the address
  of the first node.
================================================*/
_NODE* get_free_node()          // 프리리스트에서 노드를 갖고옴
{

 /*&&&  채워야 할 부분 &&&*/

}
/*===============================================
 Node를 반납하는 함수
 -반납시 노드의 num 필드를 99로 셋팅 해서 Free 리스트의
   의 맨앞에 등록  
 -Parm: freeNode - 반납할 노드
 -Ret  : void
================================================*/
void put_free_node(_NODE *freeNode)
{
 /*&&&  채워야 할 부분 &&&*/
}
#else
/**********************************************************************
 2-2. malloc()/free() 를 사용하는 version
***********************************************************************/
/*==============================================
 Free list로부터 노드 한개를 얻어내는 함수
 - malloc() 함수를 사용
================================================*/
_NODE* get_free_node()
{
 return(_NODE *)malloc( sizeof(_NODE));
}
/*==============================================
 Free list로부터 노드 한개를 얻어내는 함수
 - free() 함수를 사용
================================================*/
void put_free_node(_NODE * freeNode)
{
 free( freeNode );
}
#endif
