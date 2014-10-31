#include <stdio.h>
#include <string.h>

main(int argc, char **argv)
{
	int i, x, y;
	int dx[] = { 23-7, 31-7, 23-7, 0 };
	int dy[] = { 0, 92-85, 100-85, 100-85 };

	if( argc < 3 )
	{
		return;
	}
	
	x = strtol(argv[1], NULL, 10);
	y = strtol(argv[2], NULL, 10);
	printf("%d,%d", x, y);
	for( i=0 ; i<4 ; i++ )
	{
		printf(",%d,%d", x+dx[i], y+dy[i]);
	}
	puts("");
}
