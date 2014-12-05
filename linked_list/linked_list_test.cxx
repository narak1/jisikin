#include <iostream>

struct IntListElem
{
	IntListElem* next;
	int value;
};

struct IntList
{
	int count;
	IntListElem* first;
};

void empty_list (IntList* l)
{
	l->first = 0;
	l->count = 0;
}

// x ist Lange; l ist Zeiger auf die Liste, die wir fullen wollen
// x is long ; l pointer to the list that we want to fill
//
IntList* volle_liste (IntList* l, int x, bool zyklus)
{
	if (x == 0)
		return l;

	IntListElem* last;
	last = new IntListElem;
	last->value = 0;

	l->first = last;

	for (int i = 1; i < x; i = i+1)
	{
		IntListElem* a = new IntListElem;
		a->value = i;
		a->next = NULL;

		last->next = a;			// 노드 연결
		a = last;				// 추가한 노드를 마지막 으로 설정
		l->count = l->count +1; //count erhohen	/ count increase
	}

	if (zyklus)	{				// cycle 값이 true 이면
		last->next = l->first;	// 원형 링크드 리스트로 만듬.
	}							//  하지만 원형 리스트는 리스트 포인터가 (여기서는 l->first)
								//  마지막 노드를 가리켜야 함. 즉, 이렇게 하면 짝퉁 -,-;

	return l;
}

// hase / rabbit (토끼) _ igel / hedgehog (고슴도치)
// 
// 뭐하자는 건지 모르겠음.
// 무슨 경주를 하면서 만나는지 아닌지 판별하는 것 같음
//
IntList* hase_igel (IntList* l) //L ist Zeiger auf Liste / L is pointer to list
{
	IntListElem* hase = l->first;
	IntListElem* igel = l->first;

	hase = hase->next;
	hase = hase->next;
	igel = igel->next;

	while ((hase != igel) && (hase->next != 0))
	{
		hase = hase->next;
		if (hase->next != 0)
			hase = hase->next;
		igel = igel->next;
	}

	if (hase->next ==0)
		std::cout << "Die Liste ist nicht zyklisch. " << std::endl;	// The list is not cyclic
	else
		std::cout << "Die Liste ist zyklisch. " << std::endl;		// The list is cyclic
}

int main ()
{
	IntList* nListe = new IntList;
	empty_list (nListe); //Neue leere Liste, auf die der Zeiger z zeigt.
						// New empty list pointed to by the pointer z .

	IntList* kListe = new IntList;
	empty_list (kListe);

	int n;
	std::cout << "Gebe ein n ein ";		// Give a a n
	std::cin >> n;

	int k;
	std::cout << "Gebe ein k ein ";
	std::cin >> k;

	volle_liste (nListe, n, true);		// 짝퉁 원형 리스트 생성
	volle_liste (kListe, k, false);		// 단일 연결 리스트 생성
	std::cout<<"nliste"<<std::endl;		// nList
	IntListElem* b = kListe->first;

	while (b->next != 0)				// kList 의 마지막 노드를 찾음
	{
		b = b->next;
	}

	b->next = nListe->first;			// kList 끝에 nList 를 연결
	kListe->count = kListe->count + nListe->count;
	std::cout<<"Anschluss"<<std::endl;	// connection
	std::cout<<hase_igel(kListe)<<std::endl;
}
