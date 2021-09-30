#include<iostream>
using namespace std;

typedef struct {
	Elemtype *data;
	int length;
}SeqList;

void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//�÷��η���L(low ~ high)���ж�·�鲢����
void merge_sort(SeqList &L, int low, int high) {	 
	 int mid;
	 //���䳤�ȴ���1 
	 if(low<high) {
	 	//�ֽ� 
	 	mid = (low+high)/2;
	 	//�ݹ����� 
		merge_sort(L, low, mid);
	 	merge_sort(L, mid+1, high);
	 	//��ϣ��������������ϲ���Ϊһ�������� 
		merge(L, low, mid, high);
	}
}//MergeSortDC


//��L(low,high)�������� 
void quick_sort(SeqList &L, int low, int high) {
	int pivotpos;	//���ֺ�Ļ�׼��¼��λ�� 
	if(low<high) {  //�������䳤�ȴ���1ʱ�������� 
		//��L(L, low, high)������ 
		pivotpos = Partition(L, low, high);
		
		quick_sort(L, low, pivotpos-1);	//����������л��� 
		quick_sort(L, pivotpos+1, high)	//����������л��� 
	}
}//QuickSort
int Partition(SeqList &L, int low, int high){  //һ�˻��� 
	Elemtype privot = L->data[low];	//����ǰ���е�һ��Ԫ����Ϊ���ᣬ�Ա���л��� 
	while(low<high) {	//ѭ���������� 
		for(; low<high&&L->data[high]>=pivot; --high)
			L->data[low] = L->data[high]; //��������С��Ԫ���ƶ������ 
		for(; low<high&&A[low]<=pivot; ++low)
			L->data[high] = L->data[low]; //��������С��Ԫ���ƶ����Ҷ� 
	}
	L->data[low] = pivot; //����Ԫ�ص�����λ�� 
	return low;		//���ش�����������λ�� 
}




//��L(1~n)���ɳ�ʼ�� 
void heap_sort(SeqList &L) {
	int i;
	Build_MaxHeap(L);	//��L(1~n)���ɳ�ʼ�� 
	for(i=L.length; i>1; --i)	{//�Ե�ǰ������L(1~n)���ж�����,����n-1�� 
//		L->data[0] = L->data[1];
//		L->data[1] = L->data[i];
//		L->data[i] = L->data[0];
		swap(&L->data[1], &L->data[i]);	//��ջ�������һ������ 
		Heapify(L, 1, i-1);	//��L(1~i-1)���µ����ɶ�,����L[1]����Υ�������� 
	}//endfor 
}//HeapSort 
void Build_MaxHeap(SeqList &L) {
	for(int i=L.length/2; --i)	//��i=(n/2)~1,���������� 
		HeadAdjust(L);
}
//����HeadAdjust��Ԫ��kΪ�����������е��� 
void HeadAdjust(SeqList &L, int k) {
	L->data[0] = L->data[k];	//L[0]������������ 
	for(i=2*k; i<=L.length; i*=2) {	//��Key�ϴ���ӽ����±� 
		if(i<L.length && L->data[i]<L->data[i+1])
			i++;
		if(L->data[0]>=L->data[i])	//ɸѡ���� 
			break;
		else
			L->data[k] = L->data[i];	//��L[i]������˫�׽���� 
			k = i;		//�޸�Kֵ,�Ա��������ɸѡ 
	}
	L->data[k] = L->data[0]; //��ɸѡ����ֵ��������λ�� 
}



void bubble_sort(SeqList &L) {
	int i,j;
	for(i=1; i<L.length; ++i)
		for(j=1; j<L.length; ++j)
			if(L->data[j] > L->data[j+1])
				swap(&L->data[j], &L->data[j+1])
}//BubbleSort

void selection_sort(SeqList &L) {
	int i,j;
	
	//�������Ԫ�� 
//	for(i=0; i<L.length-1; ++i)
	for(i=1; i<L.length; ++i) {
		int min = i;
		
		//����δ�����Ԫ�� 
//		for(j=i+1; j<L.length; ++j)
		for(j=i; j<=L.length; ++j) {
			//�ҵ�Ŀǰ����Сֵ 
			if(L->data[j]  < L->data[min]) {
				//��¼��Сֵ 
				min = j;
				//����Ԫ�� 
				swap(&L->data[min], &L->data[i]);
			}
		}
	}
}

void insertion_sort(SeqList &L) {
	int i,j,temp;
	for(i=1; i<L.length; ++i) {
		temp = L->data[i];
		
		for(j=i; j>0 && L->data[j-1]>temp; ++j) {
			L->data[j] = L->data[j-1];
		}
		
		L->data[j] = temp;
	}
}

void shell_sort(SeqList &L) {
	int i,j;
	int temp, gap;
	
	//a>>=1�ж�a�Ƿ�>=1,a=a>>1�����ж��Ƿ����1,���ڵĻ�a=a��ֵ 
	for(gap=L.length>>1; gap>0; gap = gap>>1)
		for(i=gap; i<L.length; ++i) {
			temp = L->data[i];
			for(j=i-gap; j>=0 && L->data[j]>temp; j-=gap)
				L->data[j+gap] = L->data[j];
			L->data[j+gap] = temp;		
	}
}

//void shellsort(SeqList &L) {
//	int i,j,gap;
//	for(gap=L.length/2; gap>=1; gap/=2) {
//		for(i=gap; i<L.length; ++i) {
//			if(L->data[i]<L->data[i-gap])
//				L->data[0] = L->data[i];
//				for(j=i-gap; j>0&&L->data[0]<L->data[j]; j-=gap)
//					L->data[j+gap] = L->data[j];
//				L->data[j+gap] = L->data[0];
//		}
//	}
//}















