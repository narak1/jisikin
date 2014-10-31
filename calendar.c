#include <stdio.h>
#include <time.h>

// Thu Jan 01 09:00:00 1970 from ctime()
//
enum WeekDay { Sun, Mon, Tue, Wed, Thu, Fri, Sat };
const char *week_day_name[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

int first_year = 1970; 
int first_day_week = Thu;
 
int isLeapYear(int y)
{
	int flag = 0;
	
	if( y % 400 == 0 ) flag = 1;
	else if( y % 100 == 0 ) flag = 0;
	else if( y % 4 == 0 ) flag = 1;

	return flag;
}

int calculateDays(int y, int m, int d)
{
	int month_day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = 0;
	int i;
	
	for( i=0 ; i<m-1 ; i++ ) {
		days += month_day[i];
		if( (i == 1) && isLeapYear(y) ) {	// 2���̰� �����̸� +1 �� �Ѵ�. 
			days++;
		}
	}
	days += d;
	
	return days;
}

main()
{
	int i, y, m, d, w;
	int total_day;
	
	printf("Input a day after %d-01-01 : ", first_year);
	scanf("%d%d%d", &y, &m, &d);
	
	total_day = 0;
	for( i=first_year ; i<y ; i++ ) {
		total_day += calculateDays(i, 12, 31);
	}
	total_day += calculateDays(y, m, d);
	--total_day;	// ������ ����. 
	
	w = total_day % 7;

	w = (w + first_day_week) % 7;
	printf("%d�� %d�� %d���� %s�����Դϴ�.\n", y, m, d, week_day_name[w]);
}
