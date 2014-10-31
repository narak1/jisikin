#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SET_SIZE 100 
#define HAVE_ELEMENT 0 
#define DO_NOT_HAVE_ELEMENT 1 
int hasElement(int set[], int size, int element); 
int setUnion(int set1[], int size1, int set2[], int size2, int result_set[]); 
int setIntersecton(int set1[], int size1, int set2[], int size2, int result_set[]); 
int setComplements(int set1[], int size1, int set2[], int size2, int result_set[]); 
void printSet(int set[], int size); 
int main(int argc, char *argv[]) { 
   int i = 0; 
   int SetA[MAX_SET_SIZE]; 
   int SetB[MAX_SET_SIZE]; 
   int SetC[MAX_SET_SIZE * 2]; 
   int SizeOfSetA = 0; 
   int SizeOfSetB = 0; 
   int SizeOfSetC = 0; 
   printf("Enter the size of Set A:"); 
   scanf("%d", &SizeOfSetA); 
   while (i < SizeOfSetA) 
   { 
      printf("Enter the number for Set A (%d/%d):", i + 1, SizeOfSetA); 
      scanf("%d", &SetA[i]); 
      if (hasElement(SetA, i, SetA[i]) == DO_NOT_HAVE_ELEMENT) //if it is not redundant 
      { 
         i++; 
      } 
      else 
      { 
         printf("It is redundant. Please retry.\n"); 
      } 
   } 
   printf("Enter the size of Set B:"); 
   scanf("%d", &SizeOfSetB); 
   i = 0; 
   while (i < SizeOfSetB) 
   { 
      printf("Enter the number for Set B (%d/%d):", i + 1, SizeOfSetB); 
      scanf("%d", &SetB[i]); 
      if (hasElement(SetB, i, SetB[i]) == DO_NOT_HAVE_ELEMENT) //if it is not redundant 
      { 
         i++; 
      } 
      else 
      { 
         printf("It is redundant. Please retry.\n"); 
      } 
   } 
   printf("Set A: "); 
   printSet(SetA, SizeOfSetA); 
   printf("Set B: "); 
   printSet(SetB, SizeOfSetB); 
   SizeOfSetC = setUnion(SetA, SizeOfSetA, SetB, SizeOfSetB, SetC); // Union, SetC is the result set 
   printf("Union of SetA and SetB: "); 
   printSet(SetC, SizeOfSetC); 
   SizeOfSetC = setIntersecton(SetA, SizeOfSetA, SetB, SizeOfSetB, SetC); //Intersection, SetC is the result set 
   printf("Intersection of SetA and SetB: "); 
   printSet(SetC, SizeOfSetC); 
   SizeOfSetC = setComplements(SetA, SizeOfSetA, SetB, SizeOfSetB, SetC); //Complements, SetC is the result set 
   printf("Set-theoretic difference of SetA and SetB (SetA - SetB): "); 
   printSet(SetC, SizeOfSetC); 
   return 0; 
} 
/* 
If the set has the element, returns 0; 
else return 1; 
*/ 
int hasElement(int set[], int size, int element) 
{ 
   int i = 0; 
   for (i = 0; i < size; i++) 
   { 
      if (set[i] == element) 
      return HAVE_ELEMENT; // we found it! 
   } 
   return DO_NOT_HAVE_ELEMENT; 
} 
void printSet(int set[], int size) 
{ 
   int i = 0; 
   printf("{ "); 
      for (i = 0; i < size; i++) 
      { 
         if (i < size - 1) printf("%d, ", set[i]); 
         else printf("%d ", set[i]); 
      } 
   printf("}\n"); 
} 
int setUnion(int set1[], int size1, int set2[], int size2, int result_set[]) 
{ 
	int i, n=0;
	
	// copy set 1
	for( i=0 ; i<size1 ; i++ ) {
		result_set[n++] = set1[i];
	}
	
	// add set 2
	for (i=0; i<size2; i++) 
	{ 
		if (hasElement(set1, size1, set2[i]) == DO_NOT_HAVE_ELEMENT ) {
			result_set[n++] = set2[i];
		} 
	} 
	return n; 
} 
int setIntersecton(int set1[], int size1, int set2[], int size2, int result_set[]) 
{ 
	int i, n=0; 	
	for (i = 0; i < size1; i++) 
	{ 
		if (hasElement(set2, size2, set1[i]) == HAVE_ELEMENT ) {
			result_set[n++] = set1[i];
		} 
	} 
	return n; 
} 
int setComplements(int set1[], int size1, int set2[], int size2, int result_set[]) 
{ 
	int i, n=0; 	
	for (i = 0; i < size1; i++) 
	{ 
		if (hasElement(set2, size2, set1[i]) == DO_NOT_HAVE_ELEMENT ) {
			result_set[n++] = set1[i];
		} 
	} 
	return n; 
} 

