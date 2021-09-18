#include<iostream>
#define Maxsize 50

using namespace std;

typedef struct LNode{
	Elemtype *data;
	int length,Maxsize;
	struct LNode *next;	
}LNode,*LinkList;



