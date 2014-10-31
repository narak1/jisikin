#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define NUM 4
typedef struct DLN{
char start_node[20]; //���� �������
char next_node[20]; //�ٷ� ���� ��������
int time; //��������� �������������� �ð� (minute)
double distance; //��������� ���������������� �Ÿ�(km)
struct DLN* llink;
struct DLN* rlink;
}DLN;

void init(DLN* phead){
phead->llink = phead;
phead->rlink = phead;
}
void display(DLN* phead){
DLN* p;
for(p=phead->rlink; p!=phead; p=p->rlink){
printf("<---|%x|%s|%s|%d|%lf|--->\n",p,p->start_node,p->next_node,p->time,p->distance);
}
printf("\n");
}
void dinsert_node(DLN* before, DLN* new_node){
new_node->llink = before;
new_node->rlink = before->rlink;
before->rlink->llink = new_node;
before->rlink = new_node;
}
void dremove_node(DLN* phead_node,DLN* removed){
if(removed == phead_node) return;
removed->llink->rlink = removed->rlink;
removed->rlink->llink = removed->llink;
free(removed);
}
DLN* search(DLN* head, char* buff){
DLN* p;
p = head;
while(p!=NULL){
if(!strcmp(&(*buff),p->start_node)) return p;
p=p->rlink;
}
}
int time_account(DLN* s, DLN* e)
{
DLN* p;
int time_sum=0;
p=s;
while(p != e){
time_sum += (p->time);
p = p->rlink;
}
return time_sum;
}
double DISTANCE(DLN* s, DLN* e)
{
DLN* p;
double dis_sum = 0;
p = s;
while(p != e){
dis_sum += p->distance;
p = p->rlink;
}
return dis_sum;
}
main(){
DLN head_node; //������ ���� ù���. ���� ���ڵ尡 ���� �ʴ´�.
DLN* p[NUM]; //�ִ� NUM�� �Է°������� �������´�.
int cnt;
char buffer[20];
DLN* start_node;
DLN* end_node;

init(&head_node);
for(cnt=0;cnt<NUM;cnt++){
printf("%d��° ������ �����͸� �Է��Ͻÿ�....\n",cnt+1);
p[cnt] = (DLN*)malloc(sizeof(DLN));
printf("���� ����� �̸�(����) : "); gets(p[cnt]->start_node); fflush(stdin);
printf("���� ������ �̸�(����) : "); gets(p[cnt]->next_node); fflush(stdin);
printf("���� ������������ �ð�(����:��) : "); scanf("%d",&(p[cnt]->time)); fflush(stdin);
printf("���� ������������ �Ÿ�(����:KM) : "); scanf("%lf", &(p[cnt]->distance)); fflush(stdin);
dinsert_node(&head_node, p[cnt]);
}
display(&head_node);
printf("����� �Է� : "); gets(buffer); fflush(stdin); start_node = search(&head_node, buffer);
printf("start_node�� �ּҰ� : %x\n",start_node);
printf("������ �Է� : "); gets(buffer); fflush(stdin); end_node = search(&head_node, buffer);
printf("end_node�� �ּҰ� : %x\n",end_node);
printf("�ҿ�ð� : %d��\n",time_account(start_node,end_node));
printf("�Ÿ� : %lf KM\n",DISTANCE(start_node,end_node));
}

