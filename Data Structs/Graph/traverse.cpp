#inlcude<iostream>
#include<quene.cpp>
#include<ALGraph.cpp>			//链接邻接表 
#define ERROR 0;
#define OK 1;
#dedine Overflow 2;				//表示上溢 
#define Underflow 3;			//表示下溢 
#define NotPresent 4			//表示元素不存在 
#define Duplicate 5				//表示有重复元素

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
//邻接表的单一顶点DFS 
void DFS(mGraph *lg, int v, bool *visited) {
	ENode *w;
	visited[v] true;						//当标记物为真时 
	count<< " " << v <<endl;				//访问顶点v
	for(w = lg.A[v]; w; w = w->nextArc) {	//遍历v的邻接点 
		if(!visited[w->adjVex]) {
			DFS(w->adjVex, visited, ml);	//若w未被访问，则递归调用DFS 
		}
	}
}
//邻接表的全图DFS 
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

//邻接表的单一顶点BFS 
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
bool visited[maxVertexNum];  //访问标记数组
void BFS(LGraph lg, int v) 		{ 
	initQuene(q);				//初始化辅助队列q
	visited[v] = true;			//为顶点v做已访问标记 
	EnQuene(&q, v);				//顶点v入队Q 
	while(!isEmpty(q)) {
		queneFront(&q, &v);
		DeQuene(q);				//顶点v出队列 
		for(int i=0; i<lg.Vertices; ++i) {
			if(!visited[i] && lg.A[v][i] >0) {	//若未被访问且有权值,则将其访问并放入队列,注意这里判断的是lg.A[v][i]二维数组
				visited[i] = true; 		//为i做已访问标记 
				count<< i << endl;		
				EnQuene(&q, i);			//顶点i入队列 
			}//endif
		}
	}//endwhile
}
void BFSGraph(LGraph *lg) {
	int i=0;
	bool *visited = (bool*) malloc (lg.Vertices(bool)); //动态生成visited数组 
	for(i; i<lg.Vertices; ++i) {
		visited[i] = false;				//初始化visited数组
	} 
	for(i; i<lg.Vertices; ++i) {		//从零号开始BFS遍历 
		if(!visited[i])					//对每个连通分量调用一次BFS 
			BFS(lg, i);					//v(i)未被访问，从v(i)开始 
	}
	free(visited);
}

/***************************DFS traverse*************************/
 bool visited[maxVertexNum];			//访问已标记数组 
 void DFS(LGraph lg, int v) {
 	int j;
 	visited[v] = true;					//为顶点v做已访问标记 
 	for(j=0; j<lg.Vertices; ++j) {		//遍历v的邻接点 
 		if(!visited[j] && lg.A[v][j] > 0)	//当有未被访问且有权值 
 			DFS(lg, j);
	 }//endfor
 }
 void DFSGraph(LGraph *lg) {
 	int i;
 	bool *visited = (bool) malloc (lg.Vertices*sizeof(bool));
 	for(i=0; i<lg.Vertices; ++i) {
 		visited[i] = 0;					//visited数组初始化 
	 }
	 for(i=0; i<lg.Vertices; ++i) {		//检查未被访问的顶点 
	 	if(!visited[i]) {				//当未被访问有权值 
	 		DFS(lg, i);
		 }
	 }
	 free(visited);						//释放visited数组 
 }
 
 

/**********************BFS求单源最短路径问题********************************/
//void BFS_minDistance(LGraph lg, int u) {
//	//d[i]表示从从u到i结点的最短路径
//	for(int i=0; i<lg.Vertices; ++i) {	
//		d[i] = ;						//初始化路径长度 
//		visited[u] = true;	
//		d[u] = 0;
//		EnQuene(&q, u);
//		while(!isEmpty(q)) {			//bfs算法核心 
//			DeQuene(q, u);				//对头元素u出栈 
//			for(int i=0; i<lg.Vertices; ++i) {
//				if(!visited[w]) {		//w为尚未访问的邻接顶点 
//					visited[w] = true;	//设已访问标记 
//					d[w] = d[u] + 1;	//路径长度+1 
//					Enquene(q, w);		//顶点w入队 
//				}//endif
//			}
//		}//endwhile 
//	} 
//}













