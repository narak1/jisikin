
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fix_num(int n);

main(int argc, char **argv)
{
	int pw;
	char buf[12];
	int first_len;
	char xbuf[8], *ybuf;
	int x, y;

	printf("Input PW: ");
	scanf("%d", &pw);

	/* int to string */
	sprintf(buf, "%d", pw);

	first_len = buf[0] - '0';
	strncpy(xbuf, buf+1, first_len);
	xbuf[first_len] = 0;
	ybuf = buf + 1 + first_len;

	x = strtol(xbuf, NULL, 10);
	y = strtol(ybuf, NULL, 10);

	x = fix_num(x);
	y = fix_num(y);

	printf("x_pos=%d, y_pos=%d\n", x, y);
}

int fix_num(int n)
{
	int i;
	i = 1;
	while( i < n ) {
		n -= i;
		i *= 10;
	}
	return n;
}
