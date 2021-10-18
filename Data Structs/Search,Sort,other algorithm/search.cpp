
typedef struct {
	Elemtype *data;
	int length;
}SSTable;

typedef struct LNode {
	Elemtype *data;
	int length;
	struct Lnode *next;
}LNode,*LinkList;

typedef struct BTNode {
	Elemtype *data;
	int length;
	struct BTNode *lChild, *rChild;
}BTNode,*LinkList; 


/*-----------------顺序查找---------------------*/ 
//顺序表---------------------不带哨兵 
int Seq_Search(SSTable &S, Elemtype key) {
	int i = 0;
	while(i<S.length && S.data[i]!=key)
		i++;
	if(S.data[i] == x)
		return i+1;
	else
		return 0;
}
//顺序表---------------------带哨兵
int Seq_Search2(SSTable &S, Elemtype key) {
	int i = S.length;
	S.data[0] = key; //将关键字存放在0位置处，防止越界 
	while(S.data[i]=key)
		i--;
	return i;
}//一切为简化边界条件而引入的附加节点均可称为哨兵 
/*  哨兵的主要作用就是在查找循环中监视下表i是否越界,一旦越界(i=0)，因为可以和自己进行比较
循环判断条件不成立就使得查找循环结束，就可以达到忽略判定边界调节的目的 */ 

//链表 
LNode* Search(LinkList &head, Elemtype key) {
	LinkList *p = head->next;
	while(!p) {
		if(p->data == key)
			return p;
		p = p->next;
	}
	return NULL;	
} 

/*-----------------二分查找---------------------*/ 
int BinSearch_iterate(int a[], int key) {
	int low = 0, high = n-1, 
	int mid;	//当前区间存在元素
	while(low <= high) {
		mid = (low+high)/2;
		if(a[mid] == key)
			return mid;
		else if(a[mid] > key)
			high = mid-1;	//左半区间 
		else
			low = mid+1;	//右半区间 
	}
	return -1; 
}

int BinSearch_recursion(int a[], int low, int high, int key) {
	int mid;
	if(low <= high) {
		mid = (low+high)/2;
		if(a[mid] == key)
			return mid;
		if(a[mid] > key)
			return BinSearch_recursion(a, low, mid-1, key)
		else
			return BinSearch_recursion(a, mid+1, high, key)
	}
	else
		return -1; 
}

/*-----------------二叉排序树---------------------*/ 
BTNode* BSTSearch_iterate(LinkList &p, Elemtype key) {
	while(p != NULL) {
		if(key == p->data[key])
			return p;
		else if(key < p->data[key])
			p = p->lChild;
		else
			p = p->rChild;
	}
	return NULL;
}

BTNode* BSTSearch_recursion(LinkList &p, Elemtype key) {
	if(p == NULL)
		return NULL;
	else {
		if(key ==  p->data.key)
			return p;
		else if(key < p->data[key])
			return BSTSearch(p->lChild, key);
		else
			return BSTSearch(p->rChild, key);
	}	
}



