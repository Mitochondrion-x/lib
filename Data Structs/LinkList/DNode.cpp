#inlcude<iostream>
using namespace std;

typedef struct LNode {
	Elemtype *data;
	int length;
	struct LNode *next,*prev;
}DNode,*LinkList;

void swap(int *a,int *b) {
	int temp = a;
	a = b;
	b = temp;
}

//初始化 
bool InitSize(LinkList *L) {
	L = (LNode*) malloc (sizeof(LNode)*Elemtype);
	if(!L->length == NULL) 
		return false;
	L->length = 0;
	return true;
}

//链表存储的逆置---双链表 
void reverse(LinkList &L) {
	LinkList *begin = _head;
	LinkList *end = _end;
	while(begin != end && begin->prev != end) {
		swap(begin->data,end->data);
		begin = begin->next;
		end = end->prev;
	}
	
}
