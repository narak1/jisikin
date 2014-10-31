#include <stdio.h>
#include <stdlib.h>

void init_board(char board[][3]);
int get_player_move(int palyer, char board[][3]);
void disp_board(char board[][3]);

enum PlayerCode { Computer, Player };
const char *player_name[] = { "Computer", "Player" };

int main(void) 
{
	char board[3][3]; 
	int player, quit=0;
	
	srand(time(NULL));
	
	init_board(board);
	disp_board(board);
	player = Player;
	do {	
		if( player == Computer )
			player = Player;
		else
			player = Computer;
			
		quit = get_player_move(player, board);
		disp_board(board);
		if( quit ) {
			quit = check_board(player, board);
			if( quit == 0 )
				printf("%s win!\n", player_name[player]);
		}
	} while(quit != 0);
	
	return 0;
}

void init_board(char board[][3])
{
	int x, y;
	for(x=0; x<3; x++)
		for(y=0; y<3; y++) 
			board[x][y] = ' ';
}
void disp_board(char board[3][3])
{
	int i;
	for(i=0; i<3; i++){ 
		printf("---|---|---\n");
		printf(" %c | %c | %c \n",board[i][0], board[i][1], board [i][2]);
	}
	printf("---|---|---\n");
}
int check_board(int player, char board[3][3])
{
	int i, j, flag;
	char ch;
	
	if( player == Computer )
		ch = 'X';
	else
		ch = 'O';

	// check horizontal
	for( i=0 ; i<3 ; i++ ) {
		flag = 0;
		for( j=0 ; j<3 ; j++ ) {
			if( board[i][j] != ch ) {
				flag = 1;
				break;
			}
		}
		if( flag == 0 )
			break;
	}
	
	// check vertical
	if( flag ) {		
		for( i=0 ; i<3 ; i++ ) {
			flag = 0;
			for( j=0 ; j<3 ; j++ ) {
				if( board[j][i] != ch ) {
					flag = 1;
					break;
				}
			}
			if( flag == 0 )
				break;
		}
	}

	// check diagonal
	if( flag ) {
		flag = 0;
		for( i=0 ; i<3 ; i++ ) {
			if( board[i][i] != ch ) {
				flag = 1;
				break;
			}
		}
	}
	if( flag ) {
		flag = 0;
		for( i=0 ; i<3 ; i++ ) {
			if( board[i][2-i] != ch ) {
				flag = 1;
				break;
			}
		}
	}
	
	return flag;
}
int get_player_move(int player, char board[3][3]) 
{
	int x, y, done = 0;
	
	while(done != 1) {
		if( player == Player ) {
			printf("(x, y) 좌표(종료-1, -1): ");
			scanf("%d %d", &x, &y);
		}
		else {
			x = rand() % 3;
			y = rand() % 3;
		}
	
		if( x == -1 && y == -1 )
			return 0;
		else if(board[x][y]== ' ')
			break; 
		else if( player == Player )
			printf("잘못된 위치입니다.\n");
	}
	if( player == 0 ) {
		printf("Computer move (%d, %d)\n", x, y);
		board[x][y] = 'X';
	}
	else board[x][y] = 'O';
	return 1;
}
