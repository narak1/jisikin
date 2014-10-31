#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Trump {
  char order;
  char shape[3];
  char number;
 }trump;

typedef struct User {
trump Card[7];
}user;


void make_card(trump m_card[]);
void display_card(trump m_card[]);
void shuffle_card(trump m_card[], user user_s[]);
void User_display(user user_s[]);
void arbitrary_card(trump arbit[], trump m_card[]);

int main() {
  trump card[52];
  user user_s[4];
  trump arbit[5];
  int i, j;

  make_card(card);
  printf("초기 상태의 카드들\n");
  display_card(card);

  shuffle_card(card, user_s);
  printf("\n\n섞어진 카드\n");

  display_card(card);
  printf("\n\nUser들이 들고있는 카드\n");
  User_display(user_s);
  arbitrary_card(arbit, card);

  return 0;
}


void make_card(trump m_card[]) {
  int i, j;
  char shape[4][3]={"♠", "◆", "♥", "♣"};

 for(i = 0; i<4; i++) {
   for(j = i*13; j < i*13+13; j++) {
    m_card[j].order=i;
    strcpy(m_card[j].shape, shape[i]);
    m_card[j].number=j%13+1;
   
switch(m_card[j].number) {
    case 1:
     m_card[j].number='A';
     break;
    case 11:
     m_card[j].number='J';
     break;
    case 12:
     m_card[j].number='Q';
     break;
    case 13:
     m_card[j].number='K';
     break;
    }
   }
  }
 }

void display_card(trump m_card[]) {
  int i;//, count = 0;
  
  for(i = 0; i<52; i++) {
   printf("%s", m_card[i].shape);
   
   if(10 < m_card[i].number)
    printf("%-2c  ", m_card[i].number);
   else
    printf("%-2d  ", m_card[i].number);
    //count++;
   
   if(i % 13+1 == 13) {
    printf("\n");
    //count = 0;
   }
  }
 }


 void shuffle_card(trump m_card[], user user_s[]) {
  int i, j, z, rnd, count = 0;
  trump temp;

 srand(time(NULL));

 for(i = 0; i < 52; i++) {
   rnd = rand()%52;
   temp = m_card[rnd];
   m_card[rnd] = m_card[i];
   m_card[i] = temp;
  }

 for(i = 0; i < 4; i++) {
for(j = 0; j < 7; j++) {
user_s[i].Card[j] = m_card[count];
count++;   
  } 
 }
}

 void User_display(user user_s[]) {
int i, j, z;
char Temp;

for(i = 0; i < 4; i++) {
printf("%d 번째 User의 카드  ", i+1);
for(j = 0; j < 7; j++) {
printf("%s", user_s[i].Card[j].shape);

if(10 < user_s[i].Card[j].number) 
printf("%-2c  ", user_s[i].Card[j].number);
else 
printf("%-2d  ", user_s[i].Card[j].number);
}
printf("\n");
}
 }

 void arbitrary_card(trump arbit[], trump m_card[]) {
int NumBer[5], i, j;
trump temp;
printf("\n\n임의의 숫자 5개를 입력하세요. (ex 1~54) 입력: ");

for(i = 0; i < 5; i++) {
scanf("%d", &NumBer[i]);
arbit[i] = m_card[NumBer[i]-1];
}
for(i = 0; i < 5; i++) {
for(j = i + 1; j < 5; j++) {
if(arbit[j].number == 65) {
temp = arbit[i];
arbit[i] = arbit[j];
arbit[j] = temp;
break;
}else if(arbit[i].number > arbit[j].number) {
temp = arbit[i];
arbit[i] = arbit[j];
arbit[j] = temp;
} 
}
}
printf("\n\n5장의 정렬된 임의의 카드\n");
for(i = 0; i < 5; i++) {
printf("%s", arbit[i].shape);

if(10 < arbit[i].number) 
printf("%-2c  ", arbit[i].number);
else 
printf("%-2d  ", arbit[i].number);
}
printf("\n\n");
 }
