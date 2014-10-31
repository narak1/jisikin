#include <stdio.h>
#include <stdlib.h>

int miro(int arr[10][20], int x, int y);

void main()
{
	int arr[10][20];
	int i, j;
	int x, y, c1, c2;
	FILE *fp;

	fp = fopen("matrix.txt", "r");

	for(i = 0; i < 10; i++){
		for(j = 0; j < 20; j++){
			fscanf(fp, "%d", &arr[i][j]);
		}
	}
	fclose(fp);

	int c = 0, x1 = 1, y1 = 1;

	for (;;) {
		if ((x == x1) && (y == y1)) {
			arr[x1][y1] = 5;
			break;
		}

		if (arr[x1 - 1][y1] == 0) {
			arr[x1][y1] = 2;
			x1--;
			c++;
		}
		else if (arr[x1 + 1][y1] == 0) {
			arr[x1][y1] = 2;
			x1++;
			c++;
		}
		else if (arr[x1][y1 - 1] == 0) {
			arr[x1][y1] = 2;
			y1--;
			c++;
		}
		else if (arr[x1][y1 + 1] == 0) {
			arr[x1][y1] = 2;
			y1++;
			c++;
		}
	}

	printf("이동 거리 %d \n", c);

	for (x = 0; x < 10; x++) {
		for (y = 0; y <20; y++) {
			printf("%d", arr[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}
