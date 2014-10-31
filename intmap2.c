#include <stdio.h>
#include <string.h>

#define ROW 5
#define COL 5
#define SIZ (ROW*COL)

int find_line(char maps[ROW][COL], char lines[][COL]);
void add_position(char maps[ROW][COL]);
int dup_check(char line[], char lines[][COL], int no);

int main(int argc, char **argv)
{
	char maps[ROW][COL];
	int num = 53177070;
	int i, j, r, c;
	char lines[12][COL];	// max line is 12
	int lineno, no2;
	char lines2[12][COL];
		
	if( argc > 1 ) {
		num = strtol(argv[1], NULL, 10);
	}

	printf("num=%d, %08X\n", num, num);
	for( i=0 ; i<SIZ ; i++ ) {
		r = i / COL;
		c = i % COL;
		num >>= 1;
		maps[r][c] = num & 1;
	}

	// step 1
	//
	for( r=0 ; r<ROW ; r++ ) {
		for( c=0 ; c<COL ; c++ ) {
			if( maps[r][c] == 1 ) {
				printf("%2d ", r*COL+c+1);
			}
			else {
				printf("   ");
			}
		}
		puts("");
	}
	
	// step 2
	//
	lineno = find_line(maps, lines);

	// print
	for( i=0 ; i<lineno ; i++ ) {
		printf("(%d) %d", i+1, lines[i][0]);
		for( c=1 ; c<COL ; c++ ) {
			printf("-%d", lines[i][c]);
		}
		puts("");
	}
	
	// step 3
	add_position(maps);
	no2 = find_line(maps, lines2);
	// print
	j = 0;
	for( i=0 ; i<no2 ; i++ ) {
		// duplicate remove..
		if( dup_check(lines2[i], lines, lineno) == 1 ) {
			continue;
		}
		
		++j;
		printf("(%d) %d", lineno+j, lines2[i][0], lineno);
		for( c=1 ; c<COL ; c++ ) {
			printf("-%d", lines2[i][c]);
		}
		puts("");
	}
}

int dup_check(char line[], char lines[][COL], int no)
{
	int i, flag;	
	flag = 0;
	for( i=0 ; i<no ; i++ ) {
		if( memcmp(line, lines[i], COL) == 0 ) {
			flag = 1;
			break;
		}
	}
	return flag;
}

void add_position(char maps[ROW][COL])
{
	char buf[BUFSIZ];
	char *p, *q;
	int num;
	
	printf("위치 추가: ");
	gets(buf);
	p = buf;
	do {
		q = strchr(p, ',');
		if( q != NULL ) {
			*q = 0;
		}
		num = strtol(p, NULL, 10) - 1;
		maps[num/COL][num%COL] = 1;
		p = q + 1;
	} while( q );
}

int find_line(char maps[ROW][COL], char lines[][COL]) 
{
	int lineno = 0;
	int i, r, c;

	// 1) horizontal
	for( r=0 ; r<ROW ; r++ ) {
		i = 1;	// flag
		for( c=0 ; c<COL ; c++ ) {
			if( maps[r][c] == 0 ) {
				i = 0;
				break;
			}
		}
		if( i == 1 ) {	// means all 1 -> find line
			for( c=0 ; c<COL ; c++ ) {
				lines[lineno][c] = r * COL + c + 1;
			}
			++lineno;
		}
	}
	// 2) vertical
	for( c=0 ; c<COL ; c++ ) {
		i = 1;	// flag
		for( r=0 ; r<ROW ; r++ ) {
			if( maps[r][c] == 0 ) {
				i = 0;
				break;
			}
		}
		if( i == 1 ) {	// means all 1 -> find line
			for( r=0 ; r<ROW ; r++ ) {
				lines[lineno][r] = r * COL + c + 1;
			}
			++lineno;
		}
	}
	// 4) / diagonal
	i = 1;
	for( c=0 ; c<COL ; c++ ) {
		if( maps[c][COL-1-c] == 0 ) {
			i = 0;
			break;
		}
	}
	if( i == 1 ) {
		for( c=0 ; c<COL ; c++ ) {
			lines[lineno][c] = c * COL + (COL-1-c) + 1;
		}
		++lineno;			
	}
	// 3) right diagonal
	i = 1;
	for( c=0 ; c<COL ; c++ ) {
		if( maps[c][c] == 0 ) {
			i = 0;
			break;
		}
	}
	if( i == 1 ) {
		for( c=0 ; c<COL ; c++ ) {
			lines[lineno][c] = c * COL + c + 1;
		}
		++lineno;			
	}
	
	return lineno;
}

