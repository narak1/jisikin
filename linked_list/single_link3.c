#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _CARD {
 int no;
 char *name;
 int grade;
 char *stid;
} CARD; //CARD 구조체

typedef struct _node* pnode;

typedef struct _node {
 CARD element;
 pnode next;
} Node; //NODE 구조체

typedef struct _LIST {
 pnode head;
 int size;
} linkedlist; //LinkedList 구조체

pnode search(linkedlist *list, char *id);

void free_node(pnode node)
{
	if( node == NULL ) return;
	free(node->element.name);
	free(node->element.stid);
	free(node);
}

void add_item(linkedlist *plist){// 노드 추가 함수
 //linkedlist의 주소가 가리키는 값을 넘겨받음
 pnode node;//밑의 할당받은 공간의 시작주소를 Node의 포인터형으로 변환해 node에 저장
 node = (pnode)malloc(sizeof(Node));//자료형Node의 크기만큼 메모리할당
node->element.no = plist->size + 1;//node의 no에 linkedlist의 size를 1추가해서 넘겨 줌.
 node->element.name = (char*)malloc(sizeof(char)* 26);//동적메모리 할당
 node->element.stid = (char*)malloc(sizeof(char)* 13);// 동적메모리 할당
 node->next = NULL;//포인터변수 next 초기화
 printf("id:");
 scanf("%s", node->element.stid);//키보드로부터 입력받아 stid에 주소를넘겨줌
 printf("name:");
 scanf("%s", node->element.name);//키보드로부터 입력받아 name에 주소를넘겨줌
 printf("grade:");
 scanf("%d", &node->element.grade);//키보드로부터 입력받아 grade에 주소를넘겨줌

 if (plist->head != NULL){//만약에  plist의 head가 null이 아니라면
  node->next = plist->head;//node의 next영역에 plist의 head에 저장된 데이터의 주소를 대입
  plist->head = node;//plist의 head에 node의 주소대입
 }
 else
 {//null이라면
  plist->head = node;//head포인터에 node주소 저장
 }
 plist->size++;//plist의 멤버변수 사이즈를 1증가시킨다.
}

void insert(linkedlist *plist, char *id)
{
 pnode node;//밑의 할당받은 공간의 시작주소를 Node의 포인터형으로 변환해 node에 저장
 pnode position;//삽입되는 값
 node = (pnode)malloc(sizeof(Node));//자료형Node의 크기만큼 메모리할당
 node->element.no = plist->size + 1;//node의 no에 linkedlist의 size를 1추가해서 넘겨 줌.
 node->element.name = (char*)malloc(sizeof(char)* 26);//동적메모리 할당
 node->element.stid = (char*)malloc(sizeof(char)* 13);// 동적메모리 할당
 node->next = NULL;//포인터변수 next 초기화
 printf("id:");
 scanf("%s", node->element.stid);//키보드로부터 입력받아 stid에 주소를넘겨줌
 printf("name:");
 scanf("%s", node->element.name);//키보드로부터 입력받아 name에 주소를넘겨줌
 printf("grade:");
 scanf("%d", &node->element.grade);//키보드로부터 입력받아 grade에 주소를넘겨줌
 if ((position = search(plist, id)) != NULL){
  node->next = position->next;
  position->next = node;
 }
 else{
 	free_node(node);
  printf("not founded\n");
 }
}

void print_item(linkedlist *plist){//linkedlist의 주소가 가리키는 값을 넘겨받음
	struct _node *start = NULL;// _node 구조체의 포인터변수 start 선언 및 초기화.
	start = plist->head;//포인터변수 start에 plist가 가리키고 있는 head의 주소 저장
	printf("-----------------------\n");
	while (start != NULL)//start가 null이 아니면 무한 반복
	{
		printf("no: %d\n", start->element.no);//start의 멤버변수 element의 no 출력
		printf("id: %s\n", start->element.stid);//start의 멤버변수 element의 stid 출력
		printf("name: %s\n", start->element.name);//start의 멤버변수 element의 name 출력
		printf("grade: %d\n", start->element.grade);//start의 멤버변수 element의 grade 출력
		start = start->next;//포인터변수 start에 start의 멤버변수인 포인터변수 next의 주소를 대입
	}
}

pnode search(linkedlist *list, char *id)
{
  pnode pre=NULL;//이전노드가리킴
 //검색노드
 pnode index = list->head;
 while (index != NULL){
  if (strcmp(id, index->element.stid) == 0)
  {
   return index;
  }
  else{
   pre = index;
   index = index->next;
  }
 }
 return NULL;
}

void delete_item(linkedlist* List,char *stid)
{
	pnode index;//삭제할 노드 가리킬 노드
	pnode pre =NULL;//이전노드 가르킬 노드

	if( List == NULL || List->head == NULL ) {
		printf("Empty list.\n");
		return;
	}

	pre = List->head;
	if( strcmp(pre->element.stid, stid) == 0 ) {
		List->head = pre->next;
		free_node(pre);
		return;
	}

	index = pre->next;
	while( index ) {
		if( strcmp(index->element.stid, stid) == 0 ) {
			break;
		}
	}

	if (index != NULL) {
		pre->next = index->next;
		free_node(index);
		List->size--;
	}
	else {
		printf("DELETE error\n");
	}
}

void main()
{
	linkedlist stdCard;// linkedlist 변수 선언
	pnode find;
	char buf[32];

	stdCard.head = NULL;//stdCard의 멤버변수 head 초기화.
	stdCard.size = 0;;//stdCard의 멤버변수 size 초기화.
	add_item(&stdCard);//추가 아이템함수에 stdcard의 주소를 넘겨줌.
	add_item(&stdCard);
	add_item(&stdCard);
	print_item(&stdCard);// 출력아이템함수에 stdcard의 주소를 넘겨줌.

	printf("finding item's id : ");
	scanf("%s", buf);
	find = search(&stdCard, buf);
	if (find != NULL) {
		printf("stid = %s\t name = %s\n", find->element.stid, find->element.name);
	}
	else
		printf("not find\n");

	insert(&stdCard, buf);
	print_item(&stdCard);
	printf("---------------삭제------------------\n");
	delete_item (&stdCard, buf);
	print_item(&stdCard);
}
