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

//用分治法对L(low ~ high)进行二路归并排序
void merge_sort(SeqList &L, int low, int high) {	 
	 int mid;
	 //区间长度大于1 
	 if(low<high) {
	 	//分解 
	 	mid = (low+high)/2;
	 	//递归排序 
		merge_sort(L, low, mid);
	 	merge_sort(L, mid+1, high);
	 	//组合，将两个有序区合并成为一个有序区 
		merge(L, low, mid, high);
	}
}//MergeSortDC

//对L(low,high)快速排序 
void quick_sort(SeqList &L, int low, int high) {
	int pivotpos;	//划分后的基准记录的位置 
	if(low<high) {  //仅当区间长度大于1时才需排序 
		//对L(L, low, high)做划分 
		pivotpos = Partition(L, low, high);
		
		quick_sort(L, low, pivotpos-1);	//对左区间进行划分 
		quick_sort(L, pivotpos+1, high)	//对右区间进行划分 
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
	
	//已排序的元素 
//	for(i=0; i<L.length-1; ++i)
	for(i=1; i<L.length; ++i) {
		int min = i;
		
		//遍历未排序的元素 
//		for(j=i+1; j<L.length; ++j)
		for(j=i; j<=L.length; ++j) {
			//找到目前的最小值 
			if(L->data[j]  < L->data[min]) {
				//记录最小值 
				min = j;
				//交换元素 
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
	
	//a>>=1判断a是否>=1,a=a>>1是先判断是否大于1,大于的话a=a的值 
	for(gap=L.length>>1; gap>0; gap = gap>>1)
		for(i=gap; i<L.length; ++i) {
			temp = L->data[i];
			for(j=i-gap; j>=0 && L->data[j]>temp; j-=gap)
				L->data[j+gap] = L->data[j];
			L->data[j+gap] = temp;		
	}
}

















