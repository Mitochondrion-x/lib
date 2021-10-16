#inlcude<iostream>
#define ERROR 0;
#define OK 1;
#dedine Overflow 2;				//表示上溢 
#define Underflow 3;			//表示下溢 
#define NotPresent 4			//表示元素不存在 
#define Duplicate 5				//表示右重复元素 

typedef int EdgeType;
typedef struct {		
	int Vertices;				//图的顶点数
	int	Sides;					//边数 
	EdgeType NoEdge;			//两点间无边时的值	
	EdgeType **A;				//邻接矩阵*******指向一维指针数组
}mGraph;

//创建一个能容纳n个元素的邻接矩阵 
void createGraph(mGraph *mg, int n, EdgeType noEdgeValue) {
	int i, j;
	mg->NoEdge = noEdgeValue;										//初始化没有边的取值 
	mg->Vertices = n;											//初始化顶点数 
	mg->A = (EdgeType**) malloc (n*sizeof(EdgeType*));			//生成长度为n的一维数组 
	for(i=0; i<n; ++i) {										//动态生成二维数组 
		mg->A[i] = (EdgeType) malloc (n*sizeof(EdgeType));		
		for(j=0; j<n; ++j)
			mg->A[i][j] = mg->NoEdge;								//初始化时权重都设为-1 
		mg->A[i][i] = 0; 
	}
} 
//邻接矩阵的撤销(改成了int型，有返回值),先释放一维数组,再释放指针数组
int Destory(mGraph *mg) {
	int i;
	int n = mg->Vertices 
	for(i=0; i<n; ++i) {
		free(mg->A[i]);						//释放n个一维数组的存储空间 
	}
	free(mg->A);							//释放一维数组的存储空间 
	return 1;
}
//邻接矩阵的边的搜索 
bool exist(mGraph *mg, int i, int j) {
	int n = mg->Vertices;
	if(i<0 || j<0 || i>mg->n-1 || j>mg->n-1 || i==j || mg->A[i][j]==mg->NoEdge)
		return false;
	return true;
}
bool addmGraph(mGraph *mg, int u, int v, EdgeType w) {
	int n = mg->Vertices;
	if(u<0 || v<0 || u>n-1 || v>n-1 ||  u==v || mg->A[u][v] 1= mg->NoEdge) 
		count<< "BadInput" <<endl;
		return flase;
	mg->A[u][v] = w;
	return true; 
}
//bool delmgGraph(mGraph *mg, int u, int v) {
//	int n = mg->Vertices;
//	if(u<0 || v<0 || u>n-1 || v>n-1 || u==v || mg->A[u][v] = mg->Vertices)
//		return false;
//	mg->A[u][v] = mg->NoEdge;
//	return true;
//}
int delmGraph(mGraph *mg, int u, int v) {
	int n = mg->Vertices;
	if(u<0 || v<0 || u>n-1 || v>n-1 || u==v || mg->A[u][v] = mg->NoEdge)
		count<< "BadInput" <<endl;
		return ERROR;
	if(mg->A[u][v] == mg->NoEdge)
		return NotPresent;				//若待删边不存在，则返回出错信息 
	mg->A[u][v] = mg->NoEdge;			//删除边 
	mg->Sides--;						//边-1 
	mreturn OK;
}














