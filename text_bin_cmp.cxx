//실습 4. 구조체, 동적메모리, 참조자, 난수발생 
#include <iostream> 
#include <stdlib.h> // srand(), rand() 
#include <iomanip> 
#include <time.h> //time() 
#include <math.h> 
using namespace std;
const int Min = 10;
const int Max = 20;
const int TOPSCORE = 99;
const double TOPGPA = 4.3;

struct GRADE
{
	int score;
	double gpa;
};  // struct grade = GRADE 

void swap(GRADE *a, GRADE *b)
{
	GRADE c = *a;
	*a = *b;
	*b = c;
}

int main(void)
{
	int    nstu;
	GRADE *list, *p, *q;

	do {
		cout << "학생 수 입력 : ";
		cin >> nstu;
	} while( ! (nstu >= Min && nstu <= Max) );

	list = new GRADE[nstu];
	
	srand((unsigned int)time(NULL));
	
	for (int i=0 ; i<nstu ; i++ )
	{
		p = list + i;
		p->score = rand() % (TOPSCORE + 1); // 점수들 입력 귀찮으므로 rand 이용해 변수 생성하는데 0부터 100까지만 필요함 //100도 쓰기위해서 +1 
		p->gpa = double(p->score) / TOPSCORE * TOPGPA;
	}
	
	for (int i=0 ; i<nstu-1 ; i++ ) // 마지막은 자기와 비교하므로 마지막 앞까지 비교 
	{
		p = list + i;
		for (int j=i+1 ; j<nstu ; j++ )
		{
			q = list + j;
			if (q->score > p->score)
				swap(p, q); //1등부터 꼴찌까지 나열 // 그다음 학생과 계속 비교 
		}
	}

	for (int i=0 ; i<nstu-1 ; i++ )
	{
		p = list + i;
		cout << setw(2) << i+1 << "   " << setw(2) << p->score << "   "
			 << fixed << setprecision(6) << p->gpa << endl;
	}

	text_save();
	bin_save();
	text_load();
	bin_load();
	
	delete[] list;
	return 0;
}

