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
		return NULL;				//搜索失败 
	if(k == root->data.k)			
		return root;				//搜索成功 
	if(k < root->data.k)
		return	findBST(root->Lchild, k);	//小于，搜索左子树			
	return findBST(root->Rchild, k);		//大于，搜索右子树 
}
int searchBST(BSTree Bt, Keytype k) {
		BSTNode *p = findBST(Bt.data, k);
		if(!p)
			return 0;
		return p.data;
}

//迭代法搜索 
BSNode *IsearchBST(BSTree Bt, Keytype &k) {
	while(!Bt && k != Bt->data) {	//若树空或等于根结点值，则结束循环 
		if(k < Bt->data)
			Bt = Bt->Lchild;		//小于，则在左子树上找 
		else						
			Bt = Bt->Rchild;		//大于，则在右子树上找 
	}
	return Bt->data;
}
//插入法 
void insertBST(BSTNode &root, Keytype k) {
	BTNode *p = root->data;
	if(!p) {						//原树为空，新插入的结点为根据点 
		p = (BSTNode *) malloc (sizeof(BSTNode));
		p->data = k;
		p->Lchild = p->Rchild = NULL;
		return 1; 					//返回1，则插入成功 
	}
	else if(k == p->data)			//树中存在相同关键字的结点，则插入失败 
		return 0;
	else if(k < p->data)			//关键字小于节点值，则插入到左子树去 
		return insertBST(p->Lchild, k);
	else 
		return insertBST(p->Rchild, k);
}
//插入法构造二叉树查找(排序)树 
void createBST(BSTree &Bt, Keytype str[], int len) {
	BSTNode *p = Bt.data;
	p = NULL;						//初始时树为空 
	int i = 0;
	while(i < len) {				//依次将每个关键字插入到二叉排序树中 
		insetBST(p, str[i]);
		i++;
	}
} 











