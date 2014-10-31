---- Problem 1
[code]
#include <stdio.h>
main()
{
	int i, num[10], cnt;
	puts("Input 10 integer numbers between 0 and 100.");
	for( i=0 ; i<10 ; i++ ) {
		scanf("%d", &cnt);
		if( (cnt < 0) || (cnt > 100) ) {
			printf("Invalid number %d\n", cnt);
			--i;
		}
		else {
			num[i] = cnt;
		}
	}
	cnt = 0;
	for( i=0 ; i<10 ; i++ ) {
		if( num[i] >= 50 ) {
			++cnt
		}
	}
	printf("Count = %d\n", cnt);
}
[/code]

---- Problem2
[code]
typedef enum { Dog, Cat, Fish, Undef, } PetKind;
const char *pet_kind_string[] = { "Dog", "Cat", "Fish", "Undef" };

typedef struct Pet
{
	char name[256];
	int age;
	PetKind kind;
	float weight;
} SPET;

void printPet(SPET *pet)
{
	puts("Pet Information");
	printf("NAME: %s\n", pet->name);
	printf("AGE : %d\n", pet->age);
	printf("KIND: %s\n:, pet_kind_string[pet->kind]);
	printf("WGHT: %f\n", pet->weight);
}

int setPet(SPET *pet, char *name, int age, PetKind kind, float w)
{
	if( (kind < Dog) || (kind >= Undef) ) {
		kind = Undef;
	}
	strcpy(pet->name, name);
	pet->age = age;
	pet->kind = kind;
	pet->weight = w;
}

main()
{
	SPET myPet;

	setPet(&myPet, "elli", 3, Cat, 3.75f);
	printPet(&myPet);
}
[/code]

---- Problem 3
[code]
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int n;
	
	srand(time(NULL));
	n = rand() % 3 + 1;
	if( n == 1 ) {
		puts("Yes, I will go and party!!!");
	}
	else if( n == 2 ) {
		puts("Not sure, not feeling well...");
	}
	else {
		puts("Nah, will stay home and study");
	}
}
[/code]

---- Problem 4
[code]
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* medal_type[] = { "Gold", "Silver", "Bronze" };
const int medal_num = sizeof(medal_type) / sizeof(const char*);

#define MAX_ATH 10

void swap_int(int *n, int *m)
{
	int i;
	i = *n, *n = *m, *m = i;
}

void swap_double(double *d, double *e)
{
	double f;
	f = *d, *d = *e, *e = f;
}

main()
{
	double athlete[MAX_ATH];
	int ranking[MAX_ATH];
	int num_ath;
	int i, j;

	srand(time(NULL));

	num_ath = 3;

	for( i=0 ; i<num_ath ; i++ ) {
		athlete[i] = (rand() % 101) / 100.0 + 9.50;
	}
	for( i=0 ; i<num_ath ; i++ ) {
		printf("Athlete %d: %.2lfsec ", i+1, athlete[i]);
	}
	putchar('\n');
	/* find ranking */
	// initialize
	for( i=0 ; i<num_ath ; i++ ) {
		ranking[i] = i+1;
	}
	// sorting
	for( i=0 ; i<num_ath-1 ; i++ ) {
		for( j=i+1 ; j<num_ath ; j++ ) {
			if( athlete[i] > athlete[j] ) {
				swap_double(&athlete[i], &athlete[j]);
				swap_int(&ranking[i], &ranking[j]);
			}
		}
	}
	// print
	for( i=0 ; i<medal_num ; i++ ) {
		printf("Place #%d (%s medal): Athlete %d\n",
			i+1, medal_type[i], ranking[i]);
	}
}
[/code]
