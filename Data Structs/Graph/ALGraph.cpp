#inlcude<iostream>
#define ERROR 0;
#define OK 1;
#dedine Overflow 2;				//表示上溢 
#define Underflow 3;			//表示下溢 
#define NotPresent 4			//表示元素不存在 
#define Duplicate 5				//表示有重复元素 
using namespace std;

typedef int EdgeType;
/*
typedef struct {
	int adjVex;					//任意顶点u相邻的结点 
	EdgeType w;					//边的权值 
	sturct ENode *nextArc;		//指向下一个边结点 
}ENode;
typedef struct {
	int Vertices;				//邻接表的顶点数 
	ENode **A;					//邻接表*******指向一维指针数组 
}LGraph; 				*/
typedef struct {
	int adjVex;						//任意顶点u相邻的结点 
	int Vertices;					//邻接表的顶点数 
	EdgeType w;						//边的权值
	struct ENode *nextArc, **A;		//指向下一个边结点, 邻接表*******指向一维指针数组 
}ENode, *LGraph;

//邻接表的创建 
void createGraph(LGraph *lg, int nSize) {
	int i;
	lg->Vertices = nSize;
	lg->A = (ENode**) malloc (nSize*sizeof(ENode*));
	if(!lg->A)
		return ERROR;
	else
		for(i=0; i<lg->Vertices; ++i) {
			lg->A[i] = NULL;
		}
		return OK;
} 
//邻接表的销毁 (改成了int型，有返回值),先释放一维数组,再释放指针数组
void destroyGraph(LGraph *lg) {
	int i;
	ENode *p, *q;
	for(i=0; i<lg->Vertices; ++i) {
		p = lg->A[i];			//指针p指向顶点i的单链表的第一个边结点 
		q = p;								
		while(p) {				//释放顶点i的单链表中所有边结点 
			p = p->nextArc;
			free(p);
			q = p;
		}
	}
	free(lg->A);				//释放以为指针数组A的存储空间 
	return 1;					//改为int函数，有返回值 
} 
ENode *NewENode(int vex, EdgeType weight, ENode *nextarc) {
	ENode *p;
	p = (ENode*) malloc (sizeof(ENode));	//为新的结点分配空间 
	p->adjVex = vex;
	p->w = weight;
	p->nextArc = nextarc;
	return p;
} 
bool exist(LGraph *lg, int u, int v) {
	ENode *p;
	int n = lg.Vertices;
	if(u<0 || v<0 || u>n-1 || v>n-1 || u==v) 
		return flase;
	p = lg->A[u];			//指针p指向顶点u的单链表的第一个边结点 
	while(p != NULL && p->adjVex != v) {
		p = p->nextArc;
	}
	if(!p)
		return false;
	return true;
}
bool add(LGraph *lg, int u, int v, EdgeType w) {
	ENode *p;
	int n = lg->Vertices;
	if(u<0 || v<0 || u>n-1 || v>n-1 || u== v)
		return false;
	if(exist(*lg, u, v))
		return Depliacte;				//此边已存在，返回错误 

//	p = (ENode*) malloc (sizeof(ENode));	//为新的结点分配空间
//	p->adjVex = v;							
//	p->w = w;
//	p->nextArc = lg->A[u];					//为新的边结点插入单链表的最前面 
//	lg->A[u] = p;
	p = NewENode(v, w, lg->A[u])
		lg->A[u] = p;
	return true;
}
bool del(LGraph *lg, int u, int v) {
	int n = lg.Vertices;
	ENode *p, *q;
	if(u<0 || v<0 || u>n-1 || v>n-1 || u==v)	
		return false;	
	p = lg->A[u];
	q = NULL;
	while(p && p->adjVex != v) {	//查找待删除边是否存在 
		q = p;
		p = p->nextArc;
	}
	if(!p)	return NotPresent;		//p为空，待删除边不存咋 
	if(q)
		q->nextArc = p->nextArc;	//从单链表删除此边 
	free(p);
	return true;
}


















