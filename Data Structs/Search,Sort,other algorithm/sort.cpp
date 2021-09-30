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
int Partition(SeqList &L, int low, int high){  //一趟划分 
	Elemtype privot = L->data[low];	//将当前表中第一个元素设为枢轴，对表进行划分 
	while(low<high) {	//循环跳出条件 
		for(; low<high&&L->data[high]>=pivot; --high)
			L->data[low] = L->data[high]; //将比枢轴小的元素移动到左端 
		for(; low<high&&A[low]<=pivot; ++low)
			L->data[high] = L->data[low]; //将比枢轴小的元素移动到右端 
	}
	L->data[low] = pivot; //枢轴元素的最终位置 
	return low;		//返回存放枢轴的最终位置 
}




//对L(1~n)建成初始堆 
void heap_sort(SeqList &L) {
	int i;
	Build_MaxHeap(L);	//将L(1~n)建成初始堆 
	for(i=L.length; i>1; --i)	{//对当前无序区L(1~n)进行堆排序,共做n-1趟 
//		L->data[0] = L->data[1];
//		L->data[1] = L->data[i];
//		L->data[i] = L->data[0];
		swap(&L->data[1], &L->data[i]);	//将栈顶和最后一个交换 
		Heapify(L, 1, i-1);	//将L(1~i-1)重新调整成堆,仅有L[1]可能违反堆性质 
	}//endfor 
}//HeapSort 
void Build_MaxHeap(SeqList &L) {
	for(int i=L.length/2; --i)	//从i=(n/2)~1,反复调整堆 
		HeadAdjust(L);
}
//函数HeadAdjust将元素k为根的子树进行调整 
void HeadAdjust(SeqList &L, int k) {
	L->data[0] = L->data[k];	//L[0]存放子树根结点 
	for(i=2*k; i<=L.length; i*=2) {	//沿Key较大的子结点的下标 
		if(i<L.length && L->data[i]<L->data[i+1])
			i++;
		if(L->data[0]>=L->data[i])	//筛选结束 
			break;
		else
			L->data[k] = L->data[i];	//将L[i]调整到双亲结点上 
			k = i;		//修改K值,以便继续向下筛选 
	}
	L->data[k] = L->data[0]; //被筛选结点的值放入最终位置 
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















