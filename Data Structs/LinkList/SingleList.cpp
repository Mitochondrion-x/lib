#include <iostream>
#define N 9999
using namespace std;

typedef struct LNode {
	ElemType data;			//data field
	struct LNode *next;		//pointer field
	const int length;		
}LNode,*LinkList;			//Linklist == Lnode*

Status initSize(LinkList *L);
Status inverseList(LinkList *L);
Status List_headInsert(LinkList &L , int x);
Status List_tailInsert(LinkList &L, int x);
void inverse(LinkList *L);

void initSize(LinkList &L) {
	L->next = NULL;
	L->length = 0;
}

void inverse(LinkList *L) {
	LinkList *p = L->next, *q;
	L->next = NULL;
	while(p) {
		q = p->next;
	}
}

LinkList List_headInsert(LinkList &L , int x) {		//o(n)
	LNode *s;
	L = (LinkList) malloc (sizeof(LNode));		//create head_node
	L->next = NULL;
	std:: cin >> x;								
	for(int i=0; i<=N; i++) {					//traverse
		s = (LNode *) malloc (sizeof(LNode));	//create new node
		s->data = x;
		
		s->next = L->next;
		L->next = s;		//new node insert table,and L is head_pointer
		
	}
	return L;
}

LinkList List_tailInsert(LinkList &L, int x) {		//o(n)
	LNode *s, *r = L;
	L = (LinkList) malloc (sizeof(LNode));
	L->next = NULL;
	std:: cin >> x;
	for(int i=0; i<=x; i++) {
		s = (LNode*) malloc (sizeof(LNode));
		
		s->data = x;
		r->next = s;
		r = r->next;
		
	}
	r->next = NULL;
	return L;
}

LNode *LocationElem(LinkList L,ElemType e) {
	LNode *p = L->next;
	for(; P != NULL && p->data != e ; p++)
		p = p->next;
	return p;
}

LNode *GetElem(LinkList L, int x) {
	int i=1;		//¼ÆÊýÆ÷
	LNode *p = L->next;
	if(x == 0)   return L;
	if(x < 1)	 return NULL;
	for(; p != NULL && i < x;) {
		p = p->next
		i++
	}
	 return p;
}

void insertNode(LinkList L, int i, ElemType e) {

//	LNode *p;
//	p = GetElem(L,i-1);
//	L->next = p->next;
//	p->next = s;

	if(i<1 || i>L > length(L)+1)					//illegal insert 
		return ;
	
	LNode *s = (LinkList) malloc (sizeof(LNode));	//create head_node
	s->data = x;									//value for data field
	
	/*  core code    */ 
	LNode *p = GetElem(L,i-1);		//find i that Precursor node	
	s->next = p->next;				//excute insert 
	p->next = s;
	
}

bool deleteNode(LinkList L, int i; ElemType &e) {  //É¾³ý½áµã*p 
	if(i<1 || i>Length(L))			//illegal delete
		return false;
	LNode *s,*p;		//s: Predecessor node of the deleted node
						//p: Auxiliary pointer	
   
    /*  core code    */ 
	s = GetElem(L,i-1); //²éÕÒÉ¾³ýÎ»ÖÃµÄÇ°Çý½áµã	
	p = s->next;		//pÖ¸ÏòÐèÒªÉ¾³ýµÄ½áµã 
	s->next = p->next;	//½«*p½áµã´ÓÁ´±íÖÐ'¶Ï¿ª' 
	
	e = p->data;		//½«Öµ¸³¸øe 	
	free(e);			//ÊÍ·ÅÐèÒªÉ¾³ýµÄ½áµã 
	
	return true;
}


LinkList inverseList(LinkList *L) {
	
}


