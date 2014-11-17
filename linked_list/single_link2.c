#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*############################################################################
 Data types & Global data
#############################################################################*/
typedef struct __Node {
 int         data;
  struct __Node*  next;
}_NODE;
_NODE *Head; // linked list head
#define SIZE 5
_NODE NodeList[SIZE] = { { 10, NULL}, {20, NULL}, {30, NULL}, {40, NULL}, {50, NULL} };

_NODE * ex1_delete_first();
_NODE * ex2_delete_last();
_NODE * ex3_delete_a_specific_node();
/*############################################################################
 Library functions
#############################################################################*/
void build_LL()
{
 int i;

 Head =  &NodeList[0];
 for (i=0; i < SIZE; i++) {
  NodeList[i].next = &NodeList[i+1];
 }
 NodeList[i-1].next = NULL;
}
void dsp_LL()
{
 int i;
 _NODE *ptr;

 i = 0;
 ptr = Head;
 if (Head == NULL)
  printf("    HEAD (NULL) :: ");
 else
  printf("    HEAD (%2d) :: ", Head->data);

 while (ptr != NULL) {
  printf("(%2d) ", ptr->data);
  ptr = ptr->next;
  i++;
 }
 printf("\n");
}
/*############################################################################
 Main()
#############################################################################*/
void main()
{
 char op;
 int num;
 _NODE *deletedNodep; // deleted node pointer
 _NODE *wPtr;  // 작업용 임시 포인터
 Head = NULL;

 printf("\n####### 1. Deleted from Empty Linked list ####################\n\n");
 if (Head == NULL)
  printf("\t >> Linked-list is empty !! \n\n");
 printf("\n############## 2. Insert at first #################\n");
 printf("# We assume that the LL(linked-list) is not exmpty.\n\n");
 build_LL();
 printf(">> Before deleting : \n\n"); dsp_LL(Head);
 deletedNodep = Head;
 Head = Head->next;
 printf("\n\t Deleted node : 데이터 = %d \n\n", deletedNodep->data);
 printf(">> After deleting : \n\n");dsp_LL(Head);
 printf("\n############## 3. Delete at the tail #################\n");
 printf("# We assume that more than one nodes exists in the LL(linked-list)\n\n");
 build_LL();
 printf(">> Before deleting : \n\n"); dsp_LL(Head);
 wPtr = Head;
 while (wPtr->next->next != NULL) // Find the previous node of the last node
  wPtr = wPtr->next;


 deletedNodep = wPtr->next;   // deleted the last node
 wPtr->next = NULL;
 printf("\n\t Deleted node : 데이터 = %d \n\n", deletedNodep->data);

 printf(">> After deleting : \n\n");dsp_LL(Head);
 printf("\n############## 4. Delete node in the middle #################\n");
 printf("# We assume that the more than one node exist in the LL and \n");
 printf("# We will delete the node with value 30 in the LL \n");

 build_LL();
 printf(">> Before deleting : \n\n"); dsp_LL(Head);

 wPtr = Head;
 while (wPtr->next->data != 30)
  wPtr = wPtr->next;

 deletedNodep = wPtr->next;   // deleted the node with value 30
 wPtr->next = wPtr->next->next; // the node just after the deleted node
 printf("\n\t Deleted node : 데이터 = %d \n\n", deletedNodep->data);
 printf(">> After deleting : \n\n"); dsp_LL(Head);
  /*
   *  The exercises that you should do.
   */
 printf("\n------------------  Excerise 1 -----------------------\n");
 printf("| Delete the first node \n");
 printf("------------------------------------ -------------------\n");
 build_LL();
 dsp_LL();

 while (1) {
  printf(" - Choose a operation ( 'd' : delete, 그외 : exit >> ");
  scanf("%c", &op);
  fflush(stdin);
  if (op != 'd' )
   break;
  deletedNodep = ex1_delete_first();
  if (deletedNodep != NULL)
   printf("\n\t Deleted node : 데이터 = %d \n\n", deletedNodep->data);
  else
   printf("\n\t No delete because LL is empty !!>");
  printf("\n"); dsp_LL(); printf("\n");
 }
 printf("\n------------------  Excerise 2 -----------------------\n");
 printf("| Delete the last node \n");
 printf("------------------------------------ -------------------\n");
 build_LL();
 dsp_LL();

 while (1) {
  printf(" - Choose a operation ( 'd' : delete, 그외 : exit >> ");
  scanf("%c", &op);
  fflush(stdin);
  if (op != 'd' )
   break;
  deletedNodep = ex2_delete_last();
  if (deletedNodep != NULL)
   printf("\n\t Deleted node : 데이터 = %d \n\n", deletedNodep->data);
  else
   printf("\n\t No delete because LL is empty !!>\n");
  printf("\n"); dsp_LL(); printf("\n");
 }
 printf("\n------------------  Excerise 3-----------------------\n");
 printf("| Delete node with a specific data vluae \n");
 printf("------------------------------------ -------------------\n");
 build_LL();
 dsp_LL();

 while (1) {
  printf(" - Number to delete (0~90) (exit 99) >> ");
  scanf("%d", &num);
  fflush(stdin);
  if (num == 99 )
   break;
  deletedNodep = ex3_delete_a_specific_node(num);
  if (deletedNodep != NULL)
   printf("\n\t Deleted node : 데이터 = %d \n\n", deletedNodep->data);
  else
   printf("\n\t No delete because such a node does not exist !!>\n");
  printf("\n"); dsp_LL(); printf("\n");
 }
}
/*############################################################################
 Exercise 1 : Delete the first node
- (OUT) Node 주소 : The address of the deleted node
    NULL   : When LL is empty
#############################################################################*/
_NODE *ex1_delete_first()
{
 _NODE * cur;
 cur = Head;
 if (Head == NULL)
  return NULL;
 else
  cur = Head;
  Head = cur->next;
 return cur;
}
/*############################################################################
 Exercise 2 : Delete the last node
 - (OUT) Node 주소 : The address of the deleted node
     NULL   : When LL is empty
#############################################################################*/
_NODE *ex2_delete_last(_NODE *iPtr)
{

 _NODE * tempPtr;
 _NODE * lastPtr;
 if(Head == NULL)
 {
  return NULL;
 }
 if(Head->next == NULL)
 {
  lastPtr = Head;
  Head = NULL;
  return lastPtr;
 }
  tempPtr =Head;
 while(tempPtr->next->next != NULL)
 {

  tempPtr = tempPtr->next;
 }
 lastPtr = tempPtr->next;
    tempPtr->next =NULL;

 return lastPtr;
}

/*############################################################################
 Exercise 3 : Delete the node with input value
 - (IN) value : the value of which
 - (OUT) Node 주소 : when a node with the input value is found.
     NULL   : otherwises
#############################################################################*/
_NODE *ex3_delete_a_specific_node(int value)
{
 _NODE * tempPtr;
 _NODE * prevPtr;
 /*
  * 1. When LL is empty
  */
	if(Head == NULL)
	{
		return NULL;
	}

 /*
  * 2. If LL has only one node   ===>  If the value is first node
  */
	if( Head->data == value) {
		tempPtr = Head;
		Head = tempPtr->next;
		return tempPtr;
	}

 /*
  * 3. When LL has more than one node
  */
	prevPtr = Head;
	tempPtr = prevPtr->next;
	while( tempPtr ) {
		if( tempPtr->data == value ) {
			prevPtr->next = tempPtr->next;
			break;
		}
		prevPtr = tempPtr;
		tempPtr = prevPtr->next;		
	}
	return tempPtr;
}
