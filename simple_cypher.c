#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv)
{
	int key[] = { 5, 2, -1, 2, -3, 2, -4, -2, 6, 4 };
	int i, keylen;
	FILE *fp;
	char *filename, *mode;
	char buf[BUFSIZ], *p;
	int idx;
	char usage[] = { "%s <-e|-d> filename\n" };

	if( argc <= 2 ) {
		fprintf(stderr, usage, argv[0]);
		return 0;
	}

	mode = argv[1];
	filename = argv[2];

	fp = fopen(filename, "r");
	if( fp == NULL ) {
		perror(filename);
		return 1;
	}

	keylen = sizeof(key) / sizeof(int);

	if( strcmp(mode, "-e") != 0 ) {			// decode
		for( i=0 ; i<keylen ; i++ ) {
			key[i] = -key[i];				// change sign for decode
		}
	}

	idx = 0;
	while( fgets(buf, BUFSIZ, fp) != NULL ) {
		p = buf;
		while( *p ) {
			if( isupper(*p) ) {
				*p = *p + key[idx % keylen];
				if( *p > 'Z' )
					*p -= 26;
				else if( *p < 'A' )
					*p += 26;
				++idx;
			}
			else if( islower(*p) ) {
				*p = *p + key[idx % keylen];
				if( *p > 'z' )
					*p -= 26;
				else if( *p < 'a' )
					*p += 26;
				++idx;
			}
			++p;
		}
		fputs(buf, stdout);
	}

	fclose(fp);
}
