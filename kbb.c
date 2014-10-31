#include <stdio.h>
#include <stdlib.h>
#include <time.h.>

void main()
{
	char a, b;
	int i, x, win = 0, lose = 0;
	
	srand(time(NULL));

for (i = 0; i<99999; i++)
{
x = rand() % 3+1;
printf("가위는 G, 바위는 B, 보자기는 P중 하나를 입려하시오.\n");
do {
	scanf("%c", &a);
	a = toupper(a);
} while ( ! (a=='G' || a=='B' || a=='P') );

if (x == 1)
{
b = 'G';
if (a == b)
printf("1비겼습니다.\n");
else if (a == 'B')
{
printf("2이겼습니다\n");
win++;
printf("%d : %d", win, lose);
}
else
{
printf("3졌습니다.\n");
lose++;
printf("%d : %d\n", win, lose);
}

}
else if (x == 2)
{
b = 'B';
if (a == b)
printf("5비겼습니다.\n");
else if (a == 'G')
{
printf("6졌습니다.\n");
lose++;
printf("%d : %d", win, lose);
}
else
{
printf("7이겼습니다.\n");
win++;
printf("%d : %d\n", win, lose);
}

}
else
{
b = 'P';
if (a == b)
printf("a비겼습니다.\n");
else if (a == 'B')
{
printf("b졌습니다.\n");
lose++;
printf("%d : %d", win, lose);
}
else
{
printf("c이겼습니다.\n");
win++;
printf("%d : %d\n", win, lose);
}

}
printf("%d\n", i);
}
}
