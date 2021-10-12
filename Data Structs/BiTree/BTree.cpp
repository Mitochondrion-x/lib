#include<iostream>
using namespace std;

//��---��ʽ�洢 
typedef char Elemtype;
typedef int Status;
//typedef struct {
//	Elemtype *data;
//	stuct btnode *Lchild, *Rchild;
//}BTNode;
//typedef struct {
//	struct btnode *Root;
//}BTree;
typedef struct {
	Elemtype *data;
	struct btnode *Lchild, *Rchild;
}BTNode, *BTree;

BTNode *NewNode() {
	BTNode *p = (BTNode*) malloc (sizeof(BTNode));
	if(isFull(p))
		count<< "Overflow" <<endl;
	//	exit(1);
	return p;
}
void createBT(BTree *root) {
	root->data = NULL;
}
void MakeBT(BTree *Bt, Elemtype x, BTree *Lt, BTree *Rt) { //����һ�Ŷ�����*Bt��xΪ*Bt�ĸ�����Ԫ��ֵ��*Lt��Ϊ*Bt����������*Bt��Ϊ��������*Lt��*Rt����Ϊ�ն����� 
	
}
void BreakBT(BTree *Bt, Elmetype *x, BTree *Lt, BTree *Rt) { //���������ǿգ����ֶ�����*Bt��Ϊ�����֣�*xΪ������ֵ��*LtΪԭ*Bt����������*RtΪԭ*Bt����������*Bt�����Ϊ������ 
	
}
void visit(BTNode *root) {
	count<< "BTNode is :" << root->data <<endl;
}

/**********************�������ı���**********************/ 
//Recursion
void preOrder(BTNode root) {
	if(root != NULL) {				//������ڵ㲻Ϊ��,���еݹ� 
		(*visit)(root);				//���ʸ��ڵ� 
		preOrder(root->Lchild);		//���������� 
		preOrder(root->Rchild);		//���������� 
	}
}
void inOrder(BTNode *root) {
	if(root != NULL) {
		preOrder(root->Lchild);
		visit(root);
		preOrder(root->Rchild);
	}
}
void postOrd(BTNode *root) {
	if(root != NULL) {
		preOrder(root->Lchild);
		preOrder(root->Rchild);
		visit(root);
	}
}
//Iteration
void IpreOrder(BTree root) { //������---������� 
	initStack(s); BTNode *p = root;  //��ʼ��ջs��p�Ǳ���ָ�� 	
	while(p || !isEmpty(s)) {	     //ջ���ջ�p����ʱѭ�� 
		if(p) {						//һ·���� 
			visit(p); push(s, p); 	//���ʵ�ǰ�ڵ㣬����ջ
			p = p->Lchild; 			//���Ӳ���,һֱ������ 
		}
		else {						//��ջ����ת���ջ���������� 
			pop(s, p);				//ջ��Ԫ�س�ջ 
			p = p->Rchild;			//���������ߣ�p��ֵΪ��ǰ�����Һ��� 
		}							//����whileѭ����������if-else��� 
	}
} 

void IinOrder(Btree root) {	//������---������� 
	initStack(s); BTNode *p = root;	//��ʼ��ջs��p�Ǳ���ָ��
	while(p || !isEmpty(s)) {		//ջ���ջ�p����ʱѭ��
		if(p) {						//һ·���� 
			push(s, p);				//��ǰ�ڵ���ջ 
			p = p->Lchild;			//���Ӳ��գ�һֱ��ǰ�� 
		}
		else {						//��ջ����ת���ջ���������� 
			pop(s, p); visit(p);	//ջ��Ԫ�س�ջ�������ʸ��ڵ� 
			p = p->Rchild;			//���������ߣ�p��ֵΪ��ǰ�����Һ���
		}							//����whileѭ����������if-else��� 
	}
}
void levelOrder(BTree root) {
	initQuene(q); BTNode *p = root;	//��ʼ���������У�p�Ǳ���ָ��
	EnQuene(q, p);					//�����ڵ���� 
	while(!isEmpty(q)) {			//���в�����ѭ�� 
		DeQuene(q, p);				//��ͷ������ 
		visit(p);					//���ʳ��ӽ�� 
		if(p->Lchild = NULL) 
			EnQuene(q, p->Lchild);	//���������գ����������������� 
		if(p->Rchild = NULL)
			EnQuene(q, p->Rchild);	//���������գ�����������������
	}
}

/*******************�����������������***********************/
BTree preCreateBT(BTNode *root) {
	char ch;
	ch = getchar();
	if(ch == '#') {					//����Ϊ#��ʾ���ｨ���ն��������������㷨�Ŀղ��� 
		root = NULL;
	}
	else {
		root = (BTNode*) malloc (sizeof(BTNode));
		root->data = ch;			//�������� 
		root->Lchild = preCreateBT(root->Lchild);
		root->Rchild = preCreateBT(root->Rchild);
	}
}

/**********************��������Ľ����**********************/ 
int size(BTNode *root) {				
	if(!root)
		return 0;
	return size(root->Lchild) + size(root->Rchild) + 1;
}
int Isize(BTNode *root) {	
	int t, t1, t2; 
	if(!root) return 0;
	else {
		t1 = size(root->Lchild);
		t2 = size(root->Rchild);
	}
	t = t1+t2+1;
	return t;
}
int SizeofBT(BTree Bt) {
	return size(Bt->data);
}

/********************���������Ҷ�ӽ����********************/
int leaf(BTNode *root) {
	if(root == NULL)
		return 0;
	if(root->Lchild == NULL) && (root->Rchild == NULL)
		return 1;
	return leaf(root->Lchild) +leaf(root->Rchild); 
}
int leafofBT(BTree Bt) {
	return leaf(Bt->data);
}

/**********************��������ĸ߶�***********************/ 
int maxDepth(BTNode *root) {
	if(!root)
		return 0;
	return max(maxDepth(root->Lchild), maxDepth(root->Rchild)) + 1;
}
//int minDepth(BTNode *p) {
//	if(!p)
//		return 0;
//	if(!p->Lchild)
//		return minDepth(p->Rchild) + 1;
//	if(!p->Rchild)
//		return minDepth(p->Lchild) + 1;
//	return min(minDepth(p->Lchild), minDepth(p->Rchild)) + 1;
//}

int maxDepthofBT(BTree Bt) {
	return Depth(Bt.data);
}

/******************�����йؼ��ֵ����ֵ********************/
int maxValue(BTNode root) {
	int maxV=0;
	if(root == NULL) 
		return 0; 
	else {
		maxV = maxValue(root->Lchild) > maxValue(root->Rchild) ? maxValue(root->Lchild) : maxValue(root->Rchild);
		return root->data>maxV?root->data:maxV; 
	}
}

/********************����һ�ö�����************************/
BTNode *copy(BTNode *root) {
	BTNode *p;
	if(!root)
		return 0;
	else {
//		p = NewNode();
		p = (BTNode*) malloc (sizeof(BTNode));
		p->data = root->data;
		p->Lchild = copy(root->Lchild);
		p->Rchild = copy(root->Rchild);
		return p;
	}
}
BTree copyofBT(BTree Bt) {
	BTree a;
	a.data = copy(Bt.data);
	return a;
}


/********************�����������Ĺ���**********************/
typedef struct {
	Elemtype *data;
	sturct THreadNode *Lchild, *Rchild;		//��,�Һ���ָ�� 
	int Ltag, Rtag;							//��,��������־ 
}ThreadNode, *ThreadTree;

void makeInThread(ThreadNode *root, ThreadNode *p) {
	if(root)
		return 0;
	else {
		makeInThread(root->Lchild, p);		//�ݹ飬������������ 
		if(root->Lchild == NULL) {			//������Ϊ��,����ǰ������ 
			root->Lchild = p;
			root->Ltag = 1;
		}
		if(p != NULL && p->Rchild == NULL) {
			p->Rchild = p;					//����ǰ�����ĺ������ 
			p->Rtag = 1;
		}
		p = root;							//��ǵ�ǰ�ڵ��Ϊ�ոշ��ʹ��Ľ�� 
		makeInOrder(root->Lchild, p);		//�ݹ飬������������ 
	}
}
void createInThread(ThreadTree Bt) {
	ThreadTree *p =  NULL;
	if(Bt != NULL) {						//�ǿն������������� 
		makeInThread(Bt, p);				//������������ 
		p->Rchild = NULL;					//������������һ���ڵ� 
		p->Rtag = 1;
	}
}
//���������������������������µĺ�̣�
ThreadNode *firstNode(ThreadNode *root) {
	while(root->Ltag == 0)
		root = root->Lchild;				//�����½��(��һ����Ҷ���) 
		return root;
}
//�����������������н��p�����������µĺ�̣�
ThreadNode *nextNode(ThreadNode *root) {
	if(root->Rtag == 0)
		return firstNode(root->Rchild);
	else
		return root->Rchild; 				//Rtag==1 ֱ�ӷ��غ�������� 
} 
//�������������㷨������д������ͷ�ڵ����������������������������㷨 
void inOrder(ThreadNode *root) {
	for(ThreadNode *root = first(root); root != NULL; root = nextNode(p=root))
		visit(root);
}











