#include <stdio.h>
#include <stdlib.h>
#include "seq.h"

typedef struct elem_struct
{
	ETYPE val;
	struct elem_struct *next, *prev;
} Elem;

struct seq_struct
{
	int num;
	Elem *front, *back;
};

Seq seq_create()
{
	Seq tmp;
	tmp = (Seq) malloc(sizeof(struct seq_struct));
	if( tmp != NULL ) {
		tmp->num = 0;
		tmp->front = tmp->back = NULL;	/* initialize pointer */
	}
	return tmp;
}

void seq_free(Seq seq)
{
	Elem *cur, *tmp;
	cur = seq->front;
	while( cur != NULL ) {
		tmp = cur->next;
		free(cur);
		cur = tmp;
	};
	free(seq);
}

#ifdef GENERIC
void seq_print(Seq seq, void (* print_func)(void *))
{
	Elem *cur;
	cur = seq->front;
	while( cur != NULL ) {
		print_func(cur);
		cur = cur->next;
	}
}
#else
void seq_print(Seq seq)
{
	Elem *cur;
	printf("[");
	cur = seq->front;
	while( cur != NULL ) {
		printf(" %d", cur->val);
		cur = cur->next;
	}
	puts("]");
}
#endif

int seq_size(Seq seq)
{
	return seq->num;
}

void seq_add_front(Seq seq, ETYPE val)
{
	Elem *cur, *tmp;
	cur = seq->front;
	tmp = (Elem *) malloc(sizeof(Elem));
	tmp->val = val;
	tmp->next = cur;
	tmp->prev = NULL;
	if( cur != NULL )
		cur->prev = tmp;

	++seq->num;
	seq->front = tmp;
	if( seq->back == NULL )	/* empty sequence */
		seq->back = tmp;
}

ETYPE seq_del_front(Seq seq)
{
	ETYPE ret;
	Elem *cur, *tmp;
	cur = seq->front;
	if( cur != NULL ) {
		ret = cur->val;
		tmp = cur->next;
		free(cur);

		--seq->num;
		seq->front = tmp;
		if( tmp != NULL ) {
			tmp->prev = NULL;
		}
		else {
			seq->back = NULL;
		}
	}
	return ret;
}

void seq_add_back(Seq seq, ETYPE val)
{
	Elem *cur, *tmp;
	cur = seq->back;
	tmp = (Elem *) malloc(sizeof(Elem));
	tmp->val = val;
	tmp->next = NULL;
	tmp->prev = cur;
	if( cur != NULL )
		cur->next = tmp;

	++seq->num;
	seq->back = tmp;
	if( seq->front == NULL )	/* empty sequence */
		seq->front = tmp;
}

ETYPE seq_del_back(Seq seq)
{
	ETYPE ret;
	Elem *cur, *tmp;
	cur = seq->back;
	if( cur != NULL ) {
		ret = cur->val;
		tmp = cur->prev;
		free(cur);

		--seq->num;
		seq->back = tmp;
		if( tmp != NULL ) {
			tmp->next = NULL;
		}
		else {
			seq->front = NULL;
		}
	}
	return ret;
}

ETYPE seq_peek_front(Seq seq)
{
	ETYPE ret;
	Elem *cur;
	cur = seq->front;
	if( cur != NULL )
		ret = cur->val;
	return ret;
}

ETYPE seq_peek_back(Seq seq)
{
	ETYPE ret;
	Elem *cur;
	cur = seq->back;
	if( cur != NULL )
		ret = cur->val;
	return ret;
}

Seq seq_clone(Seq seq)
{
	Seq seq2;
	Elem *cur, *cur2, *tmp;

	seq2 = (Seq) malloc(sizeof(struct seq_struct));
	seq2->num = seq->num;
	cur = seq->front;
	if( cur == NULL ) {		/* empty sequence */
		seq2->front = seq2->back = NULL;
		return seq2;
	}

	cur2 = (Elem *) malloc(sizeof(Elem));
	cur2->val = cur->val;	/* THIS HAS A PROBLEM for generic */
	cur2->prev = NULL;
	seq2->front = cur2;
	while( (cur = cur->next) != NULL ) {
		tmp = cur2;
		cur2 = (Elem *) malloc(sizeof(Elem));
		cur2->val = cur->val;
		cur2->prev = tmp;
		tmp->next = cur2;
	}
	cur2->next = NULL;
	seq2->back = cur2;

	return seq2;
}

Seq seq_concat(Seq s1, Seq s2)
{
	Elem *cur, *cur2;

	if( s1 == s2 ) {
		/*return NULL;*/	/* really?? i'm confused. how do this condition? */
		return s1;
	}

	cur = s1->back;
	cur2 = s2->front;

	cur->next = cur2;
	cur2->prev = cur;
	s1->back = s2->back;

	free(s2);
	return s1;
}

ETYPE * seq_to_array(Seq seq)
{
	ETYPE *array;
	Elem *cur;
	int i;

	if( seq->num == 0 )
		return NULL;

	array = (ETYPE *) malloc(sizeof(ETYPE) * seq->num);
	cur = seq->front;
	for( i=0 ; i<seq->num ; i++ ) {
		array[i] = cur->val;
		cur = cur->next;
	}
	return array;
}

#ifdef GENERIC
Seq seq_filter_eq(Seq seq, int (*cmp)(ETYPE a, ETYPE b), ETYPE x)
{
	Seq seq2;
	Elem *cur;

	seq2 = seq_create();
	cur = seq->front;
	while( cur != NULL ) {
		if( cmp(cur->val, x) == 0 ) {
			seq_add_back(seq2, cur->val);
		}
		cur = cur->next;
	}
	return seq2;
}

Seq seq_filter_lt(Seq seq, int (*cmp)(ETYPE a, ETYPE b), ETYPE x)
{
	Seq seq2;
	Elem *cur;

	seq2 = seq_create();
	cur = seq->front;
	while( cur != NULL ) {
		if( cmp(cur->val, x) < 0 ) {
			seq_add_back(seq2, cur->val);
		}
		cur = cur->next;
	}
	return seq2;
}

Seq seq_filter_gt(Seq seq, int (*cmp)(ETYPE a, ETYPE b), ETYPE x)
{
	Seq seq2;
	Elem *cur;

	seq2 = seq_create();
	cur = seq->front;
	while( cur != NULL ) {
		if( cmp(cur->val, x) > 0 ) {
			seq_add_back(seq2, cur->val);
		}
		cur = cur->next;
	}
	return seq2;
}
#else
Seq seq_filter_eq(Seq seq, ETYPE x)
{
	Seq seq2;
	Elem *cur;

	seq2 = seq_create();
	cur = seq->front;
	while( cur != NULL ) {
		if( cur->val == x ) {
			seq_add_back(seq2, cur->val);
		}
		cur = cur->next;
	}
	return seq2;
}

Seq seq_filter_lt(Seq seq, ETYPE x)
{
	Seq seq2;
	Elem *cur;

	seq2 = seq_create();
	cur = seq->front;
	while( cur != NULL ) {
		if( cur->val < x ) {
			seq_add_back(seq2, cur->val);
		}
		cur = cur->next;
	}
	return seq2;
}

Seq seq_filter_gt(Seq seq, ETYPE x)
{
	Seq seq2;
	Elem *cur;

	seq2 = seq_create();
	cur = seq->front;
	while( cur != NULL ) {
		if( cur->val > x ) {
			seq_add_back(seq2, cur->val);
		}
		cur = cur->next;
	}
	return seq2;
}
#endif

