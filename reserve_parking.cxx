#include <stdio.h>
#include <string.h>
#include <Windows.h>
#define MAX 25
#define ROW 5
#define COL 5

struct parking
{
	int jucha;
	char sign[4];
	char car_no[8];
};

int main()
{
	struct parking arr[ROW][COL];
	int i, j, k = 0;
	int tot = 0, car = 0;
	char car_no[8];

	system("mode con:cols=100 lines=30");
	system("title �������� ���α׷�");

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			tot++;
			arr[i][j].jucha = tot;
			strcpy(arr[i][j].sign, "��");
			arr[i][j].car_no[0] = 0;
		}
	}

	tot = 0;
	for (;;)
	{
		system("cls");
		for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				printf("%5d%2s[%6s]", arr[i][j].jucha, arr[i][j].sign, arr[i][j].car_no);
			}
			printf("\n");
		}
		printf("��������=%d\n", MAX - tot);
		printf("\n\n");

		do
		{
			printf("����:1 ����:0 �� ������ȣ=>");
			scanf("%d%s", &car, car_no);
		} while (car > 1);

		if ((tot >= MAX) && (car == 1))
		{
			printf("\a\a\a\a\a");
			printf("����! ���������� �����ϴ�! \n \n");
			system("pause");
			continue;
		}

		k = 0;
		if (car == 1)
		{
			for (i = 0; i < ROW; i++)
			{
				for (j = 0; j < COL; j++) {
					if (strcmp(arr[i][j].sign, "��") == 0)
					{
						strcpy(arr[i][j].sign, "��");
						strcpy(arr[i][j].car_no, car_no);
						k = 1;
						++tot;
						break;
					}
				}
				if( k ) break;
			}
		}
		else
		{
			for (i = 0; i < ROW; i++)
			{
				for (j = 0; j < COL; j++) {
					if (strcmp(arr[i][j].car_no, car_no) == 0)
					{
						strcpy(arr[i][j].sign, "��");
						arr[i][j].car_no[0] = 0;
						k = 1;
						--tot;
						break;
					}
				}
				if( k ) break;
			}
		}
	}
}

