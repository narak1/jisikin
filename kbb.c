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
printf("������ G, ������ B, ���ڱ�� P�� �ϳ��� �Է��Ͻÿ�.\n");
do {
	scanf("%c", &a);
	a = toupper(a);
} while ( ! (a=='G' || a=='B' || a=='P') );

if (x == 1)
{
b = 'G';
if (a == b)
printf("1�����ϴ�.\n");
else if (a == 'B')
{
printf("2�̰���ϴ�\n");
win++;
printf("%d : %d", win, lose);
}
else
{
printf("3�����ϴ�.\n");
lose++;
printf("%d : %d\n", win, lose);
}

}
else if (x == 2)
{
b = 'B';
if (a == b)
printf("5�����ϴ�.\n");
else if (a == 'G')
{
printf("6�����ϴ�.\n");
lose++;
printf("%d : %d", win, lose);
}
else
{
printf("7�̰���ϴ�.\n");
win++;
printf("%d : %d\n", win, lose);
}

}
else
{
b = 'P';
if (a == b)
printf("a�����ϴ�.\n");
else if (a == 'B')
{
printf("b�����ϴ�.\n");
lose++;
printf("%d : %d", win, lose);
}
else
{
printf("c�̰���ϴ�.\n");
win++;
printf("%d : %d\n", win, lose);
}

}
printf("%d\n", i);
}
}
