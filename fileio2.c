#include <cstdio>
#include <cstdlib>

int main()
{
	const char *in_fname = "HW6Prob2In.dat";
	const char *out_fname = "HW6Prob2Out.dat";
	double *data = NULL;
	const int block = 1000;
	int num = 0;
	
	FILE *fp = fopen(in_fname, "r");
	if( fp == NULL ) {
		perror(in_fname);
		return 0;
	}
	
	while( !feof(fp) ) {
		if( num % block == 0 ) {	// resize memory
			data = (double *) realloc(data, (num+block) * sizeof(double));
			if( data == NULL ) {
				printf("memory alloc error: size=%d\n", num + block);
				break;
			}
		}
		fscanf(fp, "%lf", &data[num]);
		++num;
	}
	
	fclose(fp);
	
	// find min, max, avg
	double min = data[0];
	double max = data[0];
	double sum = data[0];
	for( int i=1 ; i<num ; i++ ) {
		min = min < data[i] ? min : data[i];
		max = max > data[i] ? max : data[i];
		sum += data[i];
	}

	FILE *fp = fopen(out_fname, "w");
	if( fp == NULL ) {
		perror(out_fname);
		return 0;
	}

	fprintf(fp, "Max Value = %lg\n", max);	
	printf("Max Value = %lg\n", max);	
	
	fprintf(fp, "Mim Value = %lg\n", min);	
	printf("Mim Value = %lg\n", min);	
	
	fprintf(fp, "Average   = %lg\n", sum/num);	
	printf("Average   = %lg\n", sum/num);	
	
	fclose(fp);
}
