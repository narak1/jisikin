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

		last->next = a;			// ��� ����
		a = last;				// �߰��� ��带 ������ ���� ����
		l->count = l->count +1; //count erhohen	/ count increase
	}

	if (zyklus)	{				// cycle ���� true �̸�
		last->next = l->first;	// ���� ��ũ�� ����Ʈ�� ����.
	}							//  ������ ���� ����Ʈ�� ����Ʈ �����Ͱ� (���⼭�� l->first)
								//  ������ ��带 �����Ѿ� ��. ��, �̷��� �ϸ� ¦�� -,-;

	return l;
}

// hase / rabbit (�䳢) _ igel / hedgehog (����ġ)
// 
// �����ڴ� ���� �𸣰���.
// ���� ���ָ� �ϸ鼭 �������� �ƴ��� �Ǻ��ϴ� �� ����
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

	volle_liste (nListe, n, true);		// ¦�� ���� ����Ʈ ����
	volle_liste (kListe, k, false);		// ���� ���� ����Ʈ ����
	std::cout<<"nliste"<<std::endl;		// nList
	IntListElem* b = kListe->first;

	while (b->next != 0)				// kList �� ������ ��带 ã��
	{
		b = b->next;
	}

	b->next = nListe->first;			// kList ���� nList �� ����
	kListe->count = kListe->count + nListe->count;
	std::cout<<"Anschluss"<<std::endl;	// connection
	std::cout<<hase_igel(kListe)<<std::endl;
}
