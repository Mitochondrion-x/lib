#inlcude<iostream>
using namespace std;
typedef char Keytype;
typedef int BOOL;
typedef struct {
	Keytype *data;
	struct bstnode *Lchild, *Rchild;
}BSTNode, *BSTree;

BSTNode *findBST(BSTNode *root, Keytype k) {
	if(!p)
		return NULL;				//����ʧ�� 
	if(k == root->data.k)			
		return root;				//�����ɹ� 
	if(k < root->data.k)
		return	findBST(root->Lchild, k);	//С�ڣ�����������			
	return findBST(root->Rchild, k);		//���ڣ����������� 
}
int searchBST(BSTree Bt, Keytype k) {
		BSTNode *p = findBST(Bt.data, k);
		if(!p)
			return 0;
		return p.data;
}

//���������� 
BSNode *IsearchBST(BSTree Bt, Keytype &k) {
	while(!Bt && k != Bt->data) {	//�����ջ���ڸ����ֵ�������ѭ�� 
		if(k < Bt->data)
			Bt = Bt->Lchild;		//С�ڣ��������������� 
		else						
			Bt = Bt->Rchild;		//���ڣ��������������� 
	}
	return Bt->data;
}
//���뷨 
void insertBST(BSTNode &root, Keytype k) {
	BTNode *p = root->data;
	if(!p) {						//ԭ��Ϊ�գ��²���Ľ��Ϊ���ݵ� 
		p = (BSTNode *) malloc (sizeof(BSTNode));
		p->data = k;
		p->Lchild = p->Rchild = NULL;
		return 1; 					//����1�������ɹ� 
	}
	else if(k == p->data)			//���д�����ͬ�ؼ��ֵĽ�㣬�����ʧ�� 
		return 0;
	else if(k < p->data)			//�ؼ���С�ڽڵ�ֵ������뵽������ȥ 
		return insertBST(p->Lchild, k);
	else 
		return insertBST(p->Rchild, k);
}
//���뷨�������������(����)�� 
void createBST(BSTree &Bt, Keytype str[], int len) {
	BSTNode *p = Bt.data;
	p = NULL;						//��ʼʱ��Ϊ�� 
	int i = 0;
	while(i < len) {				//���ν�ÿ���ؼ��ֲ��뵽������������ 
		insetBST(p, str[i]);
		i++;
	}
} 











