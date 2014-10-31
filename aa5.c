#include <stdio.h>
#include <string.h>

int split1(char *str, char *arr[]);
int split2(char *str, char *arr[]);

main()
{
	char *str = "1/1/1/3/3/1/1.242344/3.324523/4.231542";
	char *arr1[10], *arr2[10];
	int narr1, narr2;
	int i;
	char tmp[BUFSIZ];
	
	puts(str);
	
	strcpy(tmp, str);
	narr1 = split1(tmp, arr1);
	for( i=0 ; i<narr1 ; i++ ) {
		printf("%d: [%s]\n", i, arr1[i]);
	}
	
	strcpy(tmp, str);
	narr2 = split2(tmp, arr2);
	for( i=0 ; i<narr2 ; i++ ) {
		printf("%d: [%s]\n", i, arr2[i]);
	}
	
}

int split1(char *str, char *arr[])
{
	char *p, *d="/";
	int num;

	num = 0;
	p = strtok(str, d);
	while( p != NULL ) {
		arr[num] = p;
		++num;
		p = strtok(NULL, d);
	}
	return num;
}

int split2(char *str, char *arr[])
{
	char *p, *q, d='/';
	int num;

	num = 0;
	p = str;
	q = strchr(p, d);
	while( q != NULL ) {
		*q = 0;				// null terminated string
		arr[num] = p;
		++num;
		p = q + 1;
		q = strchr(p, d);
	}
	arr[num] = p;
	++num;
	return num;
}
