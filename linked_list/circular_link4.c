#include <stdio.h>
#include <stdlib.h>
struct list{
       int num;
       struct list *link;
};

struct list *createnode()
{
	struct list *h;
	h=(struct list *)malloc(sizeof(struct list));
	
	h->link=NULL;
	h->num=0;
	
	return h;
}
void addnode(struct list *L, int i)
{
	struct list *p, *n;
	
	n=createnode();
	n->num=i;
	
	if(L->link==NULL)
	{
		n->link=n;
	}
	else
	{
		p=L->link;
		n->link = p->link;
		p->link=n;
	}
	L->link=n;	// L->link 가 n을 가리키는지 p를 가리키는지에 따라...
}

void addnode2(struct list *L, int i)
{
	struct list*p,*n;
	
	n=createnode();
	n->num=i;

	if(L->link==NULL)
	{
		n->link=n;
	}
	else
	{
		p=L->link;
		n->link = p->link;
		p->link=n;
	}
}
int countnode(struct list *L)
{
     struct list *p;
     int count=1;
    
     p=L->link;
     do{
        p=p->link;
        count++;
     }while(p!=L->link);
     return count;
}
int searchnode(struct list *L, int i)
{
	struct list *p;
	int count=0;
	
	p=L->link;
	do{
		p=p->link;
		count++;
		if(i==p->num) break;
	}while(p!=L->link);
	return count;
}
void deletenode(struct list *L, int i)
{
	struct list *p, *tmp;
	
	if( L->link == NULL ) return;
	
	p = L->link;
	if( p->num == i ) {
		// last node delete is careful
		//
		tmp = p->link;
		while( tmp != L->link ) {
			p = tmp;
			tmp = p->link;
		}
		p->link = tmp->link;
		L->link = p;
		free(tmp);
	}
	else {
		tmp = p->link;
		while( tmp != L->link ) {
			if( tmp->num == i ) {	// find
				p->link = tmp->link;
				free(tmp);
				break;
			}
			p = tmp;
			tmp = p->link;
		}
		
	}
}
    
void printnode(struct list *L)
{
	struct list *p;

	if( L==NULL || L->link == NULL ) {
		puts("Empty");
		return;
	}
	
	p=L->link;	
	do{
		p=p->link;
		printf("%5d -> ", p->num);
	} while(p!=L->link);
	puts("");
}

int main(int argc, char *argv[])
{
    struct list *L;
    int i,j,s,c,d,q;
   
    L=createnode();
   
    for(i=1;i<=5;i++)
    {
     addnode(L, i*10);
    }
    printnode(L);
   
    printf("추가할 값을 입력하세요 : ");
    scanf("%d", &j);
    addnode2(L, j);
    printnode(L);
   
    printf("찾을 값을 입력하세요 : ");
    scanf("%d", &s);
    c=searchnode(L,s);
    printf("\n반시계방향 : %5d\n\n", c);
    d=countnode(L);
    printf("  시계방향 : %5d\n\n", d-c);
   
    printnode(L);
   
    printf("삭제값을 입력하세요 : ");
    scanf("%d", &q);
    deletenode(L, q);
    printf("삭제후 출력\n");
    printnode(L);    
   
 
  system("PAUSE"); 
  return 0;
}

