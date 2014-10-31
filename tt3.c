#include <stdio.h>
#include <string.h>
#include <ctype.h>

int LWord (char Statement[]);

main()
{
	char buf[500], *ptr;
	char *statements[300];
	int i, len, st_num, word_num;

	puts("Input Text:");
	len = 0;
	ptr = buf;
	while( fgets(ptr, 500-len-1, stdin) != NULL )	// read one line from stdin
	{
		if( *ptr == '\n' )	// end of input
			break;

		len = strlen(ptr);	// get input length
		ptr += len;			// move buffer pointer

		if( len >= 500-1 )	// max input
			break;
	}

	// splite each statement
	ptr = buf;
	st_num = 0;
	for( i=0 ; i<500 ; i++ ) {
		if( buf[i] == 0 )
			break;
			
		if( buf[i] == '.' ) {		// find end of statement
			statements[st_num] = ptr;
			++st_num;
			buf[i] = 0;				// make null terminated string
			ptr = buf + i + 1;
		}
	}

	// print
	word_num = 0;
	for( i=0 ; i<st_num ; i++ ) {
		word_num += LWord(statements[i]);
	}
	printf("total numbers of words is %d\n", word_num);
	printf("mean number of words is %.3f\n", (float)word_num / st_num);
}

int LWord (char Statement[])
{
	char *p;
	int word_num, is_word;

	p = Statement;
	word_num = 0;
	is_word = 0;
	while( *p ) {
		if( isspace(*p) ) {		// if white space
			if( is_word ) {		// is word
				is_word = 0;
				++word_num;
			}
		}
		else {
			is_word = 1;
		}
		
		++p;
	}

	if( is_word )		// last word 
		++word_num;

	return word_num;
}
