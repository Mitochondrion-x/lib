#inlcude<iostream>
#define ERROR 0;
#define OK 1;
#dedine Overflow 2;				//��ʾ���� 
#define Underflow 3;			//��ʾ���� 
#define NotPresent 4			//��ʾԪ�ز����� 
#define Duplicate 5				//��ʾ���ظ�Ԫ�� 
using namespace std;

typedef int EdgeType;
/*
typedef struct {
	int adjVex;					//���ⶥ��u���ڵĽ�� 
	EdgeType w;					//�ߵ�Ȩֵ 
	sturct ENode *nextArc;		//ָ����һ���߽�� 
}ENode;
typedef struct {
	int Vertices;				//�ڽӱ�Ķ����� 
	ENode **A;					//�ڽӱ�*******ָ��һάָ������ 
}LGraph; 				*/
typedef struct {
	int adjVex;						//���ⶥ��u���ڵĽ�� 
	int Vertices;					//�ڽӱ�Ķ����� 
	EdgeType w;						//�ߵ�Ȩֵ
	struct ENode *nextArc, **A;		//ָ����һ���߽��, �ڽӱ�*******ָ��һάָ������ 
}ENode, *LGraph;

//�ڽӱ�Ĵ��� 
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
//�ڽӱ������ (�ĳ���int�ͣ��з���ֵ),���ͷ�һά����,���ͷ�ָ������
void destroyGraph(LGraph *lg) {
	int i;
	ENode *p, *q;
	for(i=0; i<lg->Vertices; ++i) {
		p = lg->A[i];			//ָ��pָ�򶥵�i�ĵ�����ĵ�һ���߽�� 
		q = p;								
		while(p) {				//�ͷŶ���i�ĵ����������б߽�� 
			p = p->nextArc;
			free(p);
			q = p;
		}
	}
	free(lg->A);				//�ͷ���Ϊָ������A�Ĵ洢�ռ� 
	return 1;					//��Ϊint�������з���ֵ 
} 
ENode *NewENode(int vex, EdgeType weight, ENode *nextarc) {
	ENode *p;
	p = (ENode*) malloc (sizeof(ENode));	//Ϊ�µĽ�����ռ� 
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
	p = lg->A[u];			//ָ��pָ�򶥵�u�ĵ�����ĵ�һ���߽�� 
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
		return Depliacte;				//�˱��Ѵ��ڣ����ش��� 

//	p = (ENode*) malloc (sizeof(ENode));	//Ϊ�µĽ�����ռ�
//	p->adjVex = v;							
//	p->w = w;
//	p->nextArc = lg->A[u];					//Ϊ�µı߽����뵥�������ǰ�� 
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
	while(p && p->adjVex != v) {	//���Ҵ�ɾ�����Ƿ���� 
		q = p;
		p = p->nextArc;
	}
	if(!p)	return NotPresent;		//pΪ�գ���ɾ���߲���զ 
	if(q)
		q->nextArc = p->nextArc;	//�ӵ�����ɾ���˱� 
	free(p);
	return true;
}


















