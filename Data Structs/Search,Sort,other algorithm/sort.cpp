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

void heap_sort(SeqList &L) {
	int i;
	BuildHeap(L);
	for(i=n; i>1; --i) 
//		L->data[0] = L->data[1];
//		L->data[1] = L->data[i];
//		L->data[i] = L->data[0];
			swap(&L->data[1], &L->data[i]);
	Heapify(L, 1, i-1);
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

















