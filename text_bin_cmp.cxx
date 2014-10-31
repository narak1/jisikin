//�ǽ� 4. ����ü, �����޸�, ������, �����߻� 
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
		cout << "�л� �� �Է� : ";
		cin >> nstu;
	} while( ! (nstu >= Min && nstu <= Max) );

	list = new GRADE[nstu];
	
	srand((unsigned int)time(NULL));
	
	for (int i=0 ; i<nstu ; i++ )
	{
		p = list + i;
		p->score = rand() % (TOPSCORE + 1); // ������ �Է� �������Ƿ� rand �̿��� ���� �����ϴµ� 0���� 100������ �ʿ��� //100�� �������ؼ� +1 
		p->gpa = double(p->score) / TOPSCORE * TOPGPA;
	}
	
	for (int i=0 ; i<nstu-1 ; i++ ) // �������� �ڱ�� ���ϹǷ� ������ �ձ��� �� 
	{
		p = list + i;
		for (int j=i+1 ; j<nstu ; j++ )
		{
			q = list + j;
			if (q->score > p->score)
				swap(p, q); //1����� ������� ���� // �״��� �л��� ��� �� 
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

