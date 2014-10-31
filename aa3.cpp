#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_PTS 10
int read_input(char *file, float x[], float y[], int *n);
main(int argc, char *argv[])
{
 int i, j, n;
 float x, y, t;
 float xi[MAX_PTS], yi[MAX_PTS];
 float fp[MAX_PTS], fc[MAX_PTS];
 if(argc < 3) {
  printf("Usage: %s input-file x\n", argv[0]);
  exit(0);
 }
 if(read_input(argv[1], xi, yi, &n) < 0) {
  printf("cannot read the input file: %s\n", argv[1]);
  exit(-1);
 }
 x = (float)atof(argv[2]);
 printf("=(xi, yi): input ========================\n");
 for(i=0;i<n;i++)
  printf("(%.5f, %.5f)\n", xi[i], yi[i]);
 printf("=========================================\n");
 for(i=0; i<n;i++) fc[i] = fp[i] = yi[i];
 for(i=1; i<n;i++) {
  for(j=1;j < n; j++)
   fc[j] = (fp[j] - fp[j-1]) / (xi[j] - xi[j-i]);
  for(j=1; j<n ; j++) fp[j] = fc[j];
 }
 y = 0.0;
 t = 1.0;
 for(i=0;i<n;i++) {
  y += (fp[i] * t);
  t *= (x - xi[i]);
 }
 printf("(x, P(x)) = (%.6f, %.6f)\n", x, y);
}
int read_input(char *file, float x[], float y[], int *n)
{
 int i;
 FILE *fp;
 if((fp = fopen(file, "r")) == (FILE *)0) return -1;
 fscanf(fp, "%d", (char *)n);
 for(i=0;i<(int)*n;i++)
  fscanf(fp, "%f%f", (char *)&x[i], (char *)&y[i]);
 return 1;
}
