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

//初始化队列 
void initQuene(Quene *q) {
	q->data = (Elemtype*) malloc (sizeof(Elemtype));
	q.front = q.rear = 0;
}
//判断队列是否为空，若是，则返回true，否则返回false 
bool isEmpty(Quene *q) {
	return q->front == q->rear;
}
bool isFull(Quene *q) {
	return (q->rear+1) % q->maxSize = q->front;
}
//获取队首元素,并通过x返回,操作成功，则返回true，否则false 
bool queneFront(Quene *q, Elemtype x) {
	if(isEmpty(q))			//空队列处理 
		return false;
	*x = q->data[q->front+1 % q->maxSize]
	return true;
}
//入队，在队列q的队尾插入元素x(入队操作)。操作成功，则而返回true，否则返回FALSE 
bool EnQuene(Quene *q, Elemtype x) {
	is(isFull(q))		  //溢出处理
		return false;
	q->rear = (q->rear+1) % q->maxSize;
	q->data[q->rear] = x; 
}
//出队，从队列q中删除头元素(出队操作)。操作成功，则返回true，否则返回FALSE 
bool DeQuene(Quene *q) {
	is(isEmpty(q))
		return false;
	q->front = (q->front+1) % q->maxSize;
	return true;
}
//遍历队列 
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
//求队列的长度 
bool getLength(Quene *q) {
	return (q.rear-q.front+q.maxSize) % q.maxSize;
}
//销毁队列
void destroyQuene(Quene *q) {
	free(q.data);
	q->data = NULL;
	q.front = q.rear = 0;
} 















 
