#include <stdio.h>

#define LASTSTAGE	10
#define MAXSTAGE (LASTSTAGE+2)

void print_stage_score(int pins[][2], int score[], int total, int stage, int count);

main()
{
	int stage_pins[MAXSTAGE][2] = { 0, };
	int stage_score[MAXSTAGE] = { 0, };
	char input[4];
	int down_pin, remain_num;
	int total_score, more_throw;
	int i, j;

	more_throw = 0;
	for( i=0 ; i<MAXSTAGE ; i++ )
	{
		printf("%d stage down pin num (s means strike) : ", i+1);
		scanf("%s", input);
		if( isdigit(input[0]) ) {
			down_pin = input[0] - '0';
			remain_num = 10 - down_pin;
			stage_pins[i][0] = down_pin;
		}
		else if( input[0] == 's' ) {
			remain_num = 0;
			stage_pins[i][0] = 10;
		}
		else {
			puts("Invalid Input!");
			--i;
			continue;
		}

		stage_score[i] = stage_pins[i][0];

		// strike & spare calc
		if( i-1 >= 0 ) {	// previous stage
			if( stage_pins[i-1][0] == 10 ) {	// strike
				stage_score[i-1] += stage_pins[i][0];
				if( i-2 >= 0 ) {
					if( stage_pins[i-2][0] == 10 )	// double strike
					{
						stage_score[i-2] += stage_pins[i][0];
					}
				}
			}
			else if(stage_score[i-1] == 10 ) {	// spare
				stage_score[i-1] += stage_pins[i][0];
			}
		}

		total_score = stage_score[i];
		for( j=0 ; j<i ; j++ ) {
			if( i == LASTSTAGE ) {
				break;
			}
			total_score += stage_score[j];
		}

		print_stage_score(stage_pins, stage_score, total_score, i, 0);

		if( i < LASTSTAGE ) {
			if( remain_num == 0 ) {
				more_throw = 2;		// LASTSTAGE check or not, no problem
				continue;
			}
		}
		else {
			--more_throw;
			if( more_throw == 0 ) {
				break;
			}
			else if( remain_num == 0 ) {
				continue;
			}
		}

		// 2nd throw
second_throw:

		printf("%d stage down pin num (s means spare) : ", i+1);
		scanf("%s", input);
		if( isdigit(input[0]) ) {
			stage_pins[i][1] = input[0] - '0';
			if( stage_pins[i][1] > remain_num ) {
				puts("Invalid pin number!");
				goto second_throw;
			}
		}
		else if( input[0] == 's' ) {
			stage_pins[i][1] = remain_num;
		}
		else {
			puts("Invalid Input!");
			goto second_throw;
		}

		stage_score[i] += stage_pins[i][1];

		// strike & spare calc
		if( i-1 >= 0 ) {	// previous stage
			if( stage_pins[i-1][0] == 10 ) {	// strike
				stage_score[i-1] += stage_pins[i][1];
			}
		}

		total_score = stage_score[i];
		for( j=0 ; j<i ; j++ ) {
			if( i == LASTSTAGE ) {
				break;
			}
			total_score += stage_score[j];
		}

		print_stage_score(stage_pins, stage_score, total_score, i, 1);

		if( i < LASTSTAGE ) {
			if( remain_num == 0 ) {
				more_throw = 1;
				continue;
			}
		}
		else {
			break;
		}
	}
}

void print_stage_score(int pins[][2], int score[], int total, int stage, int count)
{
	int i;

	for( i=0 ; i<=stage ; i++ ) {
		printf("%3d ", i+1);
	}
	puts("");
	puts("=========================================");

	for( i=0 ; i<=stage ; i++ ) {
		if( pins[i][0] == 10 ) {
			printf("  S ");
		}
		else {
			printf("%3d ", pins[i][0]);
		}
	}
	puts("");

	for( i=0 ; i<=stage+count-1 ; i++ ) {
		if( pins[i][0] == 10 ) {
			printf("    ");
		}
		else if( score[i] >= 10 ) {
			printf("  s ");
		}
		else {
			printf("%3d ", pins[i][1]);
		}
	}
	puts("");
	puts("-----------------------------------------");

	for( i=0 ; i<=stage ; i++ ) {
		if( i == LASTSTAGE ) {
			break;
		}
		printf("%3d ", score[i]);
	}
	for( ; i<LASTSTAGE ; i++ ) {
		printf("    ");
	}
	printf(" : %3d\n\n", total);
}
