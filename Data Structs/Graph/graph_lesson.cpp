#inlcude<iostream>
#define ERROR 0;
#define OK 1;
#dedine Overflow 2;				//��ʾ���� 
#define Underflow 3;			//��ʾ���� 
#define NotPresent 4			//��ʾԪ�ز����� 
#define Duplicate 5				//��ʾ���ظ�Ԫ�� 

typedef int EdgeType;
typedef struct {		
	int Vertices;				//ͼ�Ķ�����
	int	Sides;					//���� 
	EdgeType NoEdge;			//������ޱ�ʱ��ֵ	
	EdgeType **A;				//�ڽӾ���*******ָ��һάָ������
}mGraph;

//����һ��������n��Ԫ�ص��ڽӾ��� 
void createGraph(mGraph *mg, int n, EdgeType noEdgeValue) {
	int i, j;
	mg->NoEdge = noEdgeValue;										//��ʼ��û�бߵ�ȡֵ 
	mg->Vertices = n;											//��ʼ�������� 
	mg->A = (EdgeType**) malloc (n*sizeof(EdgeType*));			//���ɳ���Ϊn��һά���� 
	for(i=0; i<n; ++i) {										//��̬���ɶ�ά���� 
		mg->A[i] = (EdgeType) malloc (n*sizeof(EdgeType));		
		for(j=0; j<n; ++j)
			mg->A[i][j] = mg->NoEdge;								//��ʼ��ʱȨ�ض���Ϊ-1 
		mg->A[i][i] = 0; 
	}
} 
//�ڽӾ���ĳ���(�ĳ���int�ͣ��з���ֵ),���ͷ�һά����,���ͷ�ָ������
int Destory(mGraph *mg) {
	int i;
	int n = mg->Vertices 
	for(i=0; i<n; ++i) {
		free(mg->A[i]);						//�ͷ�n��һά����Ĵ洢�ռ� 
	}
	free(mg->A);							//�ͷ�һά����Ĵ洢�ռ� 
	return 1;
}
//�ڽӾ���ıߵ����� 
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
		return NotPresent;				//����ɾ�߲����ڣ��򷵻س�����Ϣ 
	mg->A[u][v] = mg->NoEdge;			//ɾ���� 
	mg->Sides--;						//��-1 
	mreturn OK;
}














