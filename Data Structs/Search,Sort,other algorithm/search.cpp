
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


/*-----------------˳�����---------------------*/ 
//˳���---------------------�����ڱ� 
int Seq_Search(SSTable &S, Elemtype key) {
	int i = 0;
	while(i<S.length && S.data[i]!=key)
		i++;
	if(S.data[i] == x)
		return i+1;
	else
		return 0;
}
//˳���---------------------���ڱ�
int Seq_Search2(SSTable &S, Elemtype key) {
	int i = S.length;
	S.data[0] = key; //���ؼ��ִ����0λ�ô�����ֹԽ�� 
	while(S.data[i]=key)
		i--;
	return i;
}//һ��Ϊ�򻯱߽�����������ĸ��ӽڵ���ɳ�Ϊ�ڱ� 
/*  �ڱ�����Ҫ���þ����ڲ���ѭ���м����±�i�Ƿ�Խ��,һ��Խ��(i=0)����Ϊ���Ժ��Լ����бȽ�
ѭ���ж�������������ʹ�ò���ѭ���������Ϳ��Դﵽ�����ж��߽���ڵ�Ŀ�� */ 

//���� 
LNode* Search(LinkList &head, Elemtype key) {
	LinkList *p = head->next;
	while(!p) {
		if(p->data == key)
			return p;
		p = p->next;
	}
	return NULL;	
} 

/*-----------------���ֲ���---------------------*/ 
int BinSearch_iterate(int a[], int key) {
	int low = 0, high = n-1, 
	int mid;	//��ǰ�������Ԫ��
	while(low <= high) {
		mid = (low+high)/2;
		if(a[mid] == key)
			return mid;
		else if(a[mid] > key)
			high = mid-1;	//������� 
		else
			low = mid+1;	//�Ұ����� 
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

/*-----------------����������---------------------*/ 
BTNode* BSTSearch_iterate(LinkList &p, Elemtype key) {
	while(p != NULL) {
		if(key == p->data[key])
			return p;
		else if
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



