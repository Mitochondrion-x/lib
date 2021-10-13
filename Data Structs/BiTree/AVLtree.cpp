#inlcude<iostream>
using namespace std;
typedef char Elemtype;

typedef struct {
	ELmetype *data;
	int BF;
	struct avlnode *Lchild, *Rchild;
}AVLNode, *AVLtree;

