#inlcude<iostream>
using namespace std;

typedef int Status;
typedef enum {   				//图的类型定义 
	DG, UDG;	 				//0——有向图， 1——无向图 
}GraphKind;
typedef struct {				//图的类型信息 
	int info;
}InfoType; 

// Status Adjacent(G, x, y)		//判断图G是否存在边<x, y> or <x, y>. 
	




/************************邻接矩阵的定义******************************/ 
#dfeine maxVertexNum 50							//顶点数目的最大值 
typedef char VertrxType;						//顶点的数据类型	
typedef int EdgeType;							//带权图中边权值的数据类型 
typedef struct {
	VertrxType Vex[maxVertexNum];				//顶点表 
	EdgeType Edge[maxVertexNum][maxVertexNum];	//邻接矩阵,边表 
	int vexnum, arcnum;							//图的当前顶点数和弧数 
}mGraft;


/************************邻接表的定义******************************/
#define maxVertexNum 50 		//图中顶点数目的最大值 
typedef struct {				//边表结点				
	int adjvex;					//该弧所指向的顶点的位置 
	struct arcnode *next;		//指向下一条弧的指针 
  //InfoType info				//网的边权值 
}ArcNode;
typedef struct VNode {			//顶点表结点 
	VertexType *data;			//顶点信息 
	ArcNode *firstarc;			//指向第一条依附该节点的弧的指针 
}VNode, AdjList[maxVert];
typedef struct {
	AdjList vertices;			//邻接表 
	int vexnum, arcnum;			//图的定点数和弧数 
//	int IncInfo;
//	GraphKind kind;
}ALGraph;						//ALGraph是以邻接表存储的图类型 








