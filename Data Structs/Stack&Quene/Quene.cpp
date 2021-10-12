#include<iostream>
#define maxSize 50
#define FALSE 0
#define TRUE 1
#define ERROR -1
using namespace std;

typedef int T;
typedef struct quene {
	int front, rear, maxQuene;
	T Elements[maxSize];
}Quene;

//ѭ�����е�ʵ�� 
void createQuene(Quene *q, int maxsize) {
	q->front = q->rear = 0;
	q->maxQuene = maxsize;
}
bool isEmpty(Quene q) {
	return q.front == q.rear;
}
bool isFull(Quene q) {
	return (q.rear+1)%q.maxQuene == q.front;
}
void Append(Quene *q, T x) {	//��������������ָʾOverflow������ֵΪx����Ԫ�ؽ����У���Ϊ��βԪ�� 
	if(isFull(*q))
		count<< "Overflow" <<endl;
	else
		q->Elements[q->rear=(q->rear+1)%q->maxQuene] = x; 
}
void serve(Quene *q) {	//�������ѿգ���ָʾUnderflow������Ӷ�����ɾ��ͷԪ�� 
	if(isEmpty(*q))
		count<< "Underflow" <<endl;
	else
		q->front = (q->front+1)%q->maxQuene;
}
void QueneFront(Quene q, T *x) {	//������Ϊ�գ���ָʾUnderflow�������ڲ���x�з��ض�ͷԪ��ֵ 
	if(isEmpty(q))
		count<< "Underflow" <<endl;
	else
		*x = q.Elements[(q.front+1)%q.maxQuene];
} 

//linkQunen create
typedef struct {	//������н�� 
	T Element;
	struct LinkNode *next;
}LinkNode;
typedef struct quene {	    //��ʽ���� 
	LinkNode *front, *rear;		//���еĶ�ͷ�Ͷ�βָ�� 
}LinkQuene;

void initQuene(LinkQuene &q) {
	q.front = q.rear = (LinkNode*) malloc (sizeof(LinkNode));
	q.front->next = NULL;
}
bool isEmpty(LinkQuene q) {
	if(q.front == q.rear)
		return true;
	else
		return flase;
}
void EnQuene(LinkQuene *q, T x) {
	LinkNode *s = (LinkQuene*) malloc (sizeof(LinkNode));
	if(isFull(q))
		count<< "Overflow" <<endl;
	else
		s->Element = x; s->next = NULL;
		q->rear->next =  s;
		q.rear = s;
}
bool DeQuene(LinkQuene &q, T &x) {
	if(q.front == q.rear)
		return false;
	LinkNode *p = q.front->next;
	x = p->Element;
	q.front->next = p->next;
	if(q.rear == p)
		q.rear = q.front;
	free(p);
	return true;
}






