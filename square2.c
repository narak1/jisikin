#include <stdio.h>

int main()
{
	int i, n, r;
	int mx, my, m;

	printf("Center position : ");
	scanf("%d", &n);
	mx = n % 10;
	my = n / 10;
	if( mx >= 5 ) mx = 9 - mx;
	if( my >= 5 ) my = 9 - my;
	m = mx < my ? mx : my;

	printf("Distance (less or equal %d) : ", m);
	scanf("%d", &r);

	for( i=0 ; i<100 ; i++ ) {
		mx = abs((i % 10) - (n % 10));
		my = abs((i / 10) - (n / 10));
		if( (mx == r && my <= r) || (my == r && mx <= r) ) {
			printf("## ");			
		}
		else {
			printf("%02d ", i);
		}
		if(i%10==9) puts("");
	}
}
