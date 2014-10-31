#include <stdio.h>

typedef struct
{
	char name[BUFSIZ];
	int win, tie, loss, point;
} TeamInfo;

#define MAXTEAM 6

void calc_point(TeamInfo *ti);
void sort_by_point(TeamInfo team[], int num);

main()
{
	char *filename = "input2.txt";
	FILE *fp;
	TeamInfo team[MAXTEAM];
	int i, team_num;
	
	fp = fopen(filename, "r");
	if( fp == NULL ) {
		perror(filename);
		return 1;
	}
	
	i = 0;
	while( fscanf(fp, "%s%d%d%d", team[i].name, &team[i].win,
								 &team[i].tie, &team[i].loss) != EOF )
	{
		++i;
	}
	team_num = i;
	
	fclose(fp);
	
	printf("Input Team Num = %d\n", team_num);
	
	// point calc
	for( i=0 ; i<team_num ; i++ )
		calc_point(team+i);

	// sort by point
	sort_by_point(team, team_num);
	
	// output
	puts("\tÆÀÀÌ¸§\t½Â\t¹«\tÆÐ\t½ÂÁ¡");
	for( i=0 ; i<team_num ; i++ ) {
		printf("\t%s\t%d\t%d\t%d\t%d\n", team[i].name, team[i].win,
						team[i].tie, team[i].loss, team[i].point);
	}
}

void calc_point(TeamInfo *ti)
{
	ti->point = ti->win * 3 + ti->tie * 1 + ti->loss * 0;
}

void sort_by_point(TeamInfo team[], int num)
{
	int i, j;
	TeamInfo tmp;
	
	for( i=0 ; i<num-1 ; i++ ) {
		for( j=i+1 ; j<num ; j++ ) {
			if( team[i].point < team[j].point ) {
				// swap data
				tmp = team[i];
				team[i] = team[j];
				team[j] = tmp;
			}
		}
	}
}
