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

//³õÊ¼»¯ 
bool InitSize(LinkList *L) {
	L = (LNode*) malloc (sizeof(LNode)*Elemtyep);
	if(!L->length == NULL) 
		return false;
	L->length = 0;
	return true;
}

//Á´±í´æ´¢µÄÄæÖÃ---Ë«Á´±í 
void reverse(LinkList &L) {
	LinkList *begin = _head;
	LinkList *end = _end;
	while(begin != end && begin->prev != end) {
		swap(begin->data,end->data);
		begin = begin->next;
		end = end->prev;
	}
	
}
