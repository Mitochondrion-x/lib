#inlcude<iostream>
#include<quene.cpp>
#include<ALGraph.cpp>			//�����ڽӱ� 
#define ERROR 0;
#define OK 1;
#dedine Overflow 2;				//��ʾ���� 
#define Underflow 3;			//��ʾ���� 
#define NotPresent 4			//��ʾԪ�ز����� 
#define Duplicate 5				//��ʾ���ظ�Ԫ��

//tyepedef int EdgeType;
//typedef struct {
//	int Vertex;
//	EdgeType noEdge;
//	EdgeType **A;
//}mGraph;

//typedef struct {
//	int vertice, adjVex;
//	EdgeType w;
//	struct ENode *nextarc, **A;
//}ENnode, *LGraph;


/*
//�ڽӱ�ĵ�һ����DFS 
void DFS(mGraph *lg, int v, bool *visited) {
	ENode *w;
	visited[v] true;						//�������Ϊ��ʱ 
	count<< " " << v <<endl;				//���ʶ���v
	for(w = lg.A[v]; w; w = w->nextArc) {	//����v���ڽӵ� 
		if(!visited[w->adjVex]) {
			DFS(w->adjVex, visited, ml);	//��wδ�����ʣ���ݹ����DFS 
		}
	}
}
//�ڽӱ��ȫͼDFS 
void DFSFraph(LGraph *lg) {
	int n = lg->Vertices;
//	bool *visited = (bool*) malloc (n*sizeof(bool));
	bool visited[maxSize];
	for(i=0; i<n; ++i) {
		visited[i] = 0;
	}
	for(i=0; i<n; ++i) {
		if(!visited[i]) {
			DFS(lg, i, visited);
		}
	}
	free(visited);
}

//�ڽӱ�ĵ�һ����BFS 
void BFS(LGraph *lg, EdgeType v, bool *visited) {
	ENode *w, Quene *q,  EdgeType u,;
	createQuene(&q, lg.Vertices);
	visited[v] = true;	count<< " " << v <<endl;
	EnQuene(&q, v);
	while(!isEmpty) {
		queneFront(q, &v);
		DeQuene(&q);
		for(w = lg.A[v]; w; w = w->nextArc) {
			if(!visited[w->adjVex]) {
				visited[w->adjVex] = true;
				count<< " " << w->adjVex <<endl;
				Enquene(&q, w->adjVex);	
			}
		}
	}
}
void BFDGraph(LGraph *lg) {
	
}   */
/***************************BFS traverse*************************/ 
bool visited[maxVertexNum];  //���ʱ������
void BFS(LGraph lg, int v) 		{ 
	initQuene(q);				//��ʼ����������q
	visited[v] = true;			//Ϊ����v���ѷ��ʱ�� 
	EnQuene(&q, v);				//����v���Q 
	while(!isEmpty(q)) {
		queneFront(&q, &v);
		DeQuene(q);				//����v������ 
		for(int i=0; i<lg.Vertices; ++i) {
			if(!visited[i] && lg.A[v][i] >0) {	//��δ����������Ȩֵ,������ʲ��������,ע�������жϵ���lg.A[v][i]��ά����
				visited[i] = true; 		//Ϊi���ѷ��ʱ�� 
				count<< i << endl;		
				EnQuene(&q, i);			//����i����� 
			}//endif
		}
	}//endwhile
}
void BFSGraph(LGraph *lg) {
	int i=0;
	bool *visited = (bool*) malloc (lg.Vertices(bool)); //��̬����visited���� 
	for(i; i<lg.Vertices; ++i) {
		visited[i] = false;				//��ʼ��visited����
	} 
	for(i; i<lg.Vertices; ++i) {		//����ſ�ʼBFS���� 
		if(!visited[i])					//��ÿ����ͨ��������һ��BFS 
			BFS(lg, i);					//v(i)δ�����ʣ���v(i)��ʼ 
	}
	free(visited);
}

/***************************DFS traverse*************************/
 bool visited[maxVertexNum];			//�����ѱ������ 
 void DFS(LGraph lg, int v) {
 	int j;
 	visited[v] = true;					//Ϊ����v���ѷ��ʱ�� 
 	for(j=0; j<lg.Vertices; ++j) {		//����v���ڽӵ� 
 		if(!visited[j] && lg.A[v][j] > 0)	//����δ����������Ȩֵ 
 			DFS(lg, j);
	 }//endfor
 }
 void DFSGraph(LGraph *lg) {
 	int i;
 	bool *visited = (bool) malloc (lg.Vertices*sizeof(bool));
 	for(i=0; i<lg.Vertices; ++i) {
 		visited[i] = 0;					//visited�����ʼ�� 
	 }
	 for(i=0; i<lg.Vertices; ++i) {		//���δ�����ʵĶ��� 
	 	if(!visited[i]) {				//��δ��������Ȩֵ 
	 		DFS(lg, i);
		 }
	 }
	 free(visited);						//�ͷ�visited���� 
 }
 
 

/**********************BFS��Դ���·������********************************/
//void BFS_minDistance(LGraph lg, int u) {
//	//d[i]��ʾ�Ӵ�u��i�������·��
//	for(int i=0; i<lg.Vertices; ++i) {	
//		d[i] = ;						//��ʼ��·������ 
//		visited[u] = true;	
//		d[u] = 0;
//		EnQuene(&q, u);
//		while(!isEmpty(q)) {			//bfs�㷨���� 
//			DeQuene(q, u);				//��ͷԪ��u��ջ 
//			for(int i=0; i<lg.Vertices; ++i) {
//				if(!visited[w]) {		//wΪ��δ���ʵ��ڽӶ��� 
//					visited[w] = true;	//���ѷ��ʱ�� 
//					d[w] = d[u] + 1;	//·������+1 
//					Enquene(q, w);		//����w��� 
//				}//endif
//			}
//		}//endwhile 
//	} 
//}













