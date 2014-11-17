#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define NUM 4
typedef struct DLN{
char start_node[20]; //현재 출발지명
char next_node[20]; //바로 다음 도착지명
int time; //출발지에서 다음도착지까지 시간 (minute)
double distance; //출발지에서 다음도착지까지의 거리(km)
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
DLN head_node; //설정을 위한 첫노드. 실제 레코드가 되진 않는다.
DLN* p[NUM]; //최대 NUM개 입력가능으로 한정짓는다.
int cnt;
char buffer[20];
DLN* start_node;
DLN* end_node;

init(&head_node);
for(cnt=0;cnt<NUM;cnt++){
printf("%d번째 목적지 데이터를 입력하시오....\n",cnt+1);
p[cnt] = (DLN*)malloc(sizeof(DLN));
printf("현재 출발지 이름(영문) : "); gets(p[cnt]->start_node); fflush(stdin);
printf("다음 도착지 이름(영문) : "); gets(p[cnt]->next_node); fflush(stdin);
printf("다음 도착지까지의 시간(단위:분) : "); scanf("%d",&(p[cnt]->time)); fflush(stdin);
printf("다음 도착지까지의 거리(단위:KM) : "); scanf("%lf", &(p[cnt]->distance)); fflush(stdin);
dinsert_node(&head_node, p[cnt]);
}
display(&head_node);
printf("출발지 입력 : "); gets(buffer); fflush(stdin); start_node = search(&head_node, buffer);
printf("start_node의 주소값 : %x\n",start_node);
printf("도착지 입력 : "); gets(buffer); fflush(stdin); end_node = search(&head_node, buffer);
printf("end_node의 주소값 : %x\n",end_node);
printf("소요시간 : %d분\n",time_account(start_node,end_node));
printf("거리 : %lf KM\n",DISTANCE(start_node,end_node));
}

