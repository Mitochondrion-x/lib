#include<iostream>

using namespace std;

typedef struct DNode {
	Elemtype *data;
	struct DNode *prior,*next;
}DNode,*DLinkList;

bool insertDNode(DLinkList &L, int i, ElemType e) {
	DLinkList *s,*p;
	if(i<1 || i>length(L)+1) 
		return false;
		
	for(; ;) {
		
 		/* ��p֮�󣬲���s*/
		s->next = p->next;
		p->next->prior = s;
		s->prior = p;
		p->next = s;
	}
}

bool deleteDNode(DLinkList &L, int i, Elemtype *e) {
	DLinkList *p,*q;
	if(i<1 || i>length(L)+1) 
		return false;
		
	for(; ;) {
		/* ɾ��p�ĺ�̽��q*/
//		p->next = q->next;
//		q->next->prior = p;
//		free(q); 

		p->prior->next = p->next;
	 	p->next->prior = p->prior;
	 	free(q);
	}
}

