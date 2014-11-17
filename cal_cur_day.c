#include <stdio.h>
#include <time.h>

#define DAY_TO_SEC (24 * 60 * 60)

int total_day_of_month(int y, int m)
{
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day;
	day = days[m-1];
	if( m == 2 ) {
		if( y % 400 == 0 )		++day;
		else if( y % 100 == 0 )	;
		else if( y % 4 == 0 )	++day;
		else					;
	}
	return day;
}

int total_day_of_year(int y)
{
	int i, day;
	day = 0;
	for( i=1 ; i<=12 ; i++ )
		day += total_day_of_month(y, i);
	return day;
}

int main()
{
	int t, i, n;
	int y, m, d, H, M, S;
	
	t = time(NULL);
	for( i=1970 ; ; i++ ) {
		n = total_day_of_year(i) * DAY_TO_SEC;
		if( t <= n ) {
			y = i;
			break;
		}
		t -= n;
	}
	
	for( i=1 ; i<=12 ; i++ ) {
		n = total_day_of_month(y, i) * DAY_TO_SEC;
		if( t <= n ) {
			m = i;
			break;
		}
		t -= n;
	}
	
	d = t / DAY_TO_SEC + 1;
	t %= DAY_TO_SEC;
	
	H = t / 3600;
	t %= 3600;
	M = t / 60;
	S = t % 60;
	
	printf("%d-%02d-%02d\n", y, m, d);
	printf("%02d:%02d:%02d\n", H, M, S);
}

