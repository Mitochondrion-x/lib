#inlcude<iostream>
using namespace std;

typedef int Status;
typedef enum {   				//ͼ�����Ͷ��� 
	DG, UDG;	 				//0��������ͼ�� 1��������ͼ 
}GraphKind;
typedef struct {				//ͼ��������Ϣ 
	int info;
}InfoType; 

// Status Adjacent(G, x, y)		//�ж�ͼG�Ƿ���ڱ�<x, y> or <x, y>. 
	




/************************�ڽӾ���Ķ���******************************/ 
#dfeine maxVertexNum 50							//������Ŀ�����ֵ 
typedef char VertrxType;						//�������������	
typedef int EdgeType;							//��Ȩͼ�б�Ȩֵ���������� 
typedef struct {
	VertrxType Vex[maxVertexNum];				//����� 
	EdgeType Edge[maxVertexNum][maxVertexNum];	//�ڽӾ���,�߱� 
	int vexnum, arcnum;							//ͼ�ĵ�ǰ�������ͻ��� 
}mGraft;


/************************�ڽӱ�Ķ���******************************/
#define maxVertexNum 50 		//ͼ�ж�����Ŀ�����ֵ 
typedef struct {				//�߱���				
	int adjvex;					//�û���ָ��Ķ����λ�� 
	struct arcnode *next;		//ָ����һ������ָ�� 
  //InfoType info				//���ı�Ȩֵ 
}ArcNode;
typedef struct VNode {			//������� 
	VertexType *data;			//������Ϣ 
	ArcNode *firstarc;			//ָ���һ�������ýڵ�Ļ���ָ�� 
}VNode, AdjList[maxVert];
typedef struct {
	AdjList vertices;			//�ڽӱ� 
	int vexnum, arcnum;			//ͼ�Ķ������ͻ��� 
//	int IncInfo;
//	GraphKind kind;
}ALGraph;						//ALGraph�����ڽӱ�洢��ͼ���� 








