#include<iostream>
#define maxSize 50
#define FALSE 0
#define TRUE 1
#define ERROR -1
using namespace std;

typedef int BOOL;
typedef int T;

//SeaStack achieve
typedef struct stack {
	int top,maxStack;
	T Elements[maxSize];
}Stack;


void createStack(Stack *s, int maxsize) {
	s->top = -1;
	s->maxStack = maxsize;
}
bool isEmpty(Stack *s) {
	return s.top < 0;
}
bool isFull(Stack *s) {
	return s.top >= s.maxStack-1;
}
void push(Stack *s,T x) {
	if(isFull(*s))
		count<< "Overflow" <<endl;
	else
		s->Elements[++s->top] = x;
}
void pop(Stack *s) {
	if(isEmpty(*s))
		count<< "Underflow" <<endl;
	else
		s->top--;
}
void StackTop(Stack s, T *x) {	//若堆栈为空，则显示下溢，否则在参数x中返回堆栈元素的值 
	if(isEmpty(*s))
		count<< "Underflow" <<endl;
	else
		*x = s->Elements[s.top];
}
void printStack(Stack *s) {
	for(int i=0; i<maxSize; ++i) {
		*s = s->Elements[i];
	}
}

void main(void) {
	Stack s, T x;
	createStack(&s, 10);
	push(&s, 10); push(&s, 15);
	printStack(s);
	pop(&s); pop (&s);
	if(isEmpty(s))
		count<<  "Is empty." <<endl;
	else
		count<< "Is not empty." <<endl;
	printStack(s);
}


//LinkList create
typedef struct node {
	T Element;
	struct node *Link;
}LinkNode;
typedef struct stack {
	Node *top;
}LinkStack;

//push & pop
void push(Stack *s, T x) {
	Node *p = NewNode2(x);
	p->Link = s->top;
	s->top = p;
}
void pop(Stack *s) {
	Node *p = s->top;
	s->top = p->Link;
	free(p);
}

 







