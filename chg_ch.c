#include <stdio.h>
#include <ctype.h>

main()
{
	char buf[BUFSIZ];
	char *p, *q;
	int flag;

	while(1) {
		printf("Input : ");
		p = gets(buf);
		if( buf[0] == 0 )	// blank line
			break;
			
		q = p;	// buf 사용, 또는 다른 메모리 버퍼사용 
		flag = 0;
		while( *p ) {
			if(isupper(*p))
			{
				*q = tolower(*p);
				flag = 0;
			}
			else if(islower(*p)) {
				*q = toupper(*p);
				flag = 0;
			}
			else if( isspace(*p) )
			{
				if( flag == 0 ) {
					*q = *p;
				}
				else {
					--q;
				}
				
				flag = 1;
			}
			else {
				*q = *p;
				flag = 0;
			}
			
			++p;
			++q;
		}
		*q = 0;		// NULL terminated string
		
		printf("Output: %s\n", buf);
	}
}
