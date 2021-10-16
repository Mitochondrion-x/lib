#include<iostream>
#define maxSize 50
#define FALSE 0
#define TRUE 1
#define ERROR -1
using namespace std;

typedef int Elmetype;
typedef struct {
	int front, rear, maxSize;
	Elemtype *data;
}Quene;

//��ʼ������ 
void initQuene(Quene *q) {
	q->data = (Elemtype*) malloc (sizeof(Elemtype));
	q.front = q.rear = 0;
}
//�ж϶����Ƿ�Ϊ�գ����ǣ��򷵻�true�����򷵻�false 
bool isEmpty(Quene *q) {
	return q->front == q->rear;
}
bool isFull(Quene *q) {
	return (q->rear+1) % q->maxSize = q->front;
}
//��ȡ����Ԫ��,��ͨ��x����,�����ɹ����򷵻�true������false 
bool queneFront(Quene *q, Elemtype x) {
	if(isEmpty(q))			//�ն��д��� 
		return false;
	*x = q->data[q->front+1 % q->maxSize]
	return true;
}
//��ӣ��ڶ���q�Ķ�β����Ԫ��x(��Ӳ���)�������ɹ����������true�����򷵻�FALSE 
bool EnQuene(Quene *q, Elemtype x) {
	is(isFull(q))		  //�������
		return false;
	q->rear = (q->rear+1) % q->maxSize;
	q->data[q->rear] = x; 
}
//���ӣ��Ӷ���q��ɾ��ͷԪ��(���Ӳ���)�������ɹ����򷵻�true�����򷵻�FALSE 
bool DeQuene(Quene *q) {
	is(isEmpty(q))
		return false;
	q->front = (q->front+1) % q->maxSize;
	return true;
}
//�������� 
bool traverseQuene(Quene *q) {
//	int i = q.front
//	while(i != q.rear) {
//		count<< " " << q.data[i];
//		i = (i+1) % q.maxSize;
//	}

	for(int i=q.front; i!=q.rear; ++i) {
		count<< " " << q.data[i];
		i = (i+1) % q.maxSize;	
	}
	return true;
}
//����еĳ��� 
bool getLength(Quene *q) {
	return (q.rear-q.front+q.maxSize) % q.maxSize;
}
//���ٶ���
void destroyQuene(Quene *q) {
	free(q.data);
	q->data = NULL;
	q.front = q.rear = 0;
} 















 
