#include<iostream>
using namespace std;

//树---链式存储 
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
void MakeBT(BTree *Bt, Elemtype x, BTree *Lt, BTree *Rt) { //构造一颗二叉树*Bt，x为*Bt的根结点的元素值，*Lt成为*Bt的左子树，*Bt成为右子树，*Lt和*Rt都成为空二叉树 
	
}
void BreakBT(BTree *Bt, Elmetype *x, BTree *Lt, BTree *Rt) { //若二叉树非空，则拆分二叉树*Bt成为三部分，*x为根结点的值，*Lt为原*Bt的左子树，*Rt为原*Bt的右子树，*Bt自身成为二叉树 
	
}
void visit(BTNode *root) {
	count<< "BTNode is :" << root->data <<endl;
}

/**********************二叉树的遍历**********************/ 
//Recursion
void preOrder(BTNode root) {
	if(root != NULL) {				//如果根节点不为空,进行递归 
		(*visit)(root);				//访问根节点 
		preOrder(root->Lchild);		//遍历左子树 
		preOrder(root->Rchild);		//遍历右子树 
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
void IpreOrder(BTree root) { //迭代法---先序遍历 
	initStack(s); BTNode *p = root;  //初始化栈s，p是遍历指针 	
	while(p || !isEmpty(s)) {	     //栈不空或p不空时循环 
		if(p) {						//一路向左 
			visit(p); push(s, p); 	//访问当前节点，并入栈
			p = p->Lchild; 			//左孩子不空,一直向左走 
		}
		else {						//出栈，并转向出栈结点的右子树 
			pop(s, p);				//栈顶元素出栈 
			p = p->Rchild;			//向右子树走，p赋值为当前结点的右孩子 
		}							//返回while循环继续进入if-else语句 
	}
} 

void IinOrder(Btree root) {	//迭代法---中序遍历 
	initStack(s); BTNode *p = root;	//初始化栈s，p是遍历指针
	while(p || !isEmpty(s)) {		//栈不空或p不空时循环
		if(p) {						//一路向左 
			push(s, p);				//当前节点入栈 
			p = p->Lchild;			//左孩子不空，一直向前走 
		}
		else {						//出栈，并转向出栈结点的右子树 
			pop(s, p); visit(p);	//栈顶元素出栈，并访问根节点 
			p = p->Rchild;			//向右子树走，p赋值为当前结点的右孩子
		}							//返回while循环继续进入if-else语句 
	}
}
void levelOrder(BTree root) {
	initQuene(q); BTNode *p = root;	//初始化辅助队列，p是遍历指针
	EnQuene(q, p);					//将根节点入队 
	while(!isEmpty(q)) {			//队列不空则循环 
		DeQuene(q, p);				//队头结点出队 
		visit(p);					//访问出队结点 
		if(p->Lchild = NULL) 
			EnQuene(q, p->Lchild);	//右子树不空，则左子树根结点入队 
		if(p->Rchild = NULL)
			EnQuene(q, p->Rchild);	//右子树不空，则右子树根结点入队
	}
}

/*******************先序遍历创建二叉树***********************/
BTree preCreateBT(BTNode *root) {
	char ch;
	ch = getchar();
	if(ch == '#') {					//输入为#表示这里建立空二叉树，即遍历算法的空操作 
		root = NULL;
	}
	else {
		root = (BTNode*) malloc (sizeof(BTNode));
		root->data = ch;			//构造根结点 
		root->Lchild = preCreateBT(root->Lchild);
		root->Rchild = preCreateBT(root->Rchild);
	}
}

/**********************求二叉树的结点数**********************/ 
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

/********************求二叉树的叶子结点数********************/
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

/**********************求二叉树的高度***********************/ 
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

/******************求树中关键字的最大值********************/
int maxValue(BTNode root) {
	int maxV=0;
	if(root == NULL) 
		return 0; 
	else {
		maxV = maxValue(root->Lchild) > maxValue(root->Rchild) ? maxValue(root->Lchild) : maxValue(root->Rchild);
		return root->data>maxV?root->data:maxV; 
	}
}

/********************复制一棵二叉树************************/
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


/********************中序线索树的构造**********************/
typedef struct {
	Elemtype *data;
	sturct THreadNode *Lchild, *Rchild;		//左,右孩子指针 
	int Ltag, Rtag;							//左,右线索标志 
}ThreadNode, *ThreadTree;

void makeInThread(ThreadNode *root, ThreadNode *p) {
	if(root)
		return 0;
	else {
		makeInThread(root->Lchild, p);		//递归，线索化二叉树 
		if(root->Lchild == NULL) {			//左子树为空,建立前驱线索 
			root->Lchild = p;
			root->Ltag = 1;
		}
		if(p != NULL && p->Rchild == NULL) {
			p->Rchild = p;					//建立前驱结点的后继线索 
			p->Rtag = 1;
		}
		p = root;							//标记当前节点成为刚刚访问过的结点 
		makeInOrder(root->Lchild, p);		//递归，线索化二叉树 
	}
}
void createInThread(ThreadTree Bt) {
	ThreadTree *p =  NULL;
	if(Bt != NULL) {						//非空二叉树，线索化 
		makeInThread(Bt, p);				//线索化二叉树 
		p->Rchild = NULL;					//处理遍历的最后一个节点 
		p->Rtag = 1;
	}
}
//求中序线索二叉树中中序序列下的后继：
ThreadNode *firstNode(ThreadNode *root) {
	while(root->Ltag == 0)
		root = root->Lchild;				//最左下结点(不一定是叶结点) 
		return root;
}
//求中序线索二叉树中结点p在中序序列下的后继：
ThreadNode *nextNode(ThreadNode *root) {
	if(root->Rtag == 0)
		return firstNode(root->Rchild);
	else
		return root->Rchild; 				//Rtag==1 直接返回后继续线索 
} 
//利用上面两个算法，可以写出不含头节点的中序线索二叉树的中序遍历的算法 
void inOrder(ThreadNode *root) {
	for(ThreadNode *root = first(root); root != NULL; root = nextNode(p=root))
		visit(root);
}











