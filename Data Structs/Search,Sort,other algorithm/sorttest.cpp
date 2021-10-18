#include<iostream>
#define maxSize 7
typedef int Elemtype;
typedef struct {
	Elemtype *data[maxSize];
	int length;
}List;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void sortQuick(List &L, int low, int high) {
	int x = 1;		//t=1 前进， t=0 后退 
	while(!(low == high)) {
		if(L.data[low] > L.data[high] && x==0) {
			swap(L.data[low], L.data[high]);
			x = 1;	//改为前进	
		}//endif
		if(L.data[low] > L.data[high] && x==1) {
			swap(L.data[low], L.data[high]);
			x = 0;	//改为后移 
		}//endif
	}//endwhile
	if(x==0) low++;
	if(x==1) high++;
	if(low < x-1)	sortQuick(L, low, x-1);	 //对左区间进行划分 
	if(high > x+1)	sortQuick(L, x+1, high); //对右区间进行划分 
}//sortQuick

void sortHeap(List &L) {
	int i, n;
	for(n=L.length; n>1; --i) {	//对当前无序区L(1~n)进行堆排序，共做n-1趟 
		for(i=n/2; i>0; ++i) {	//从i(n/2)~1,反复调整堆 
			Adjust(L, i , n-1);
		}//endfor		
		swap(L.data[1], L.data[n]);	//将镇定和最后一个元素进行交换 
	}//end
}//sortHeap
void Adjust(List &L, int i, int L.length) { //把L[i...L.length]调整为大根堆 
	int n=L.length;	
	int left = 2*i;		//左孩子 
	int right = 2*i+1;	//右孩子 
	if(L.data[left] > L.data[right]) {		//if左孩子大 
		if(L.data[left]>L.data[i] && left<=n)
			swap(L.data[left], L.data[i]);	
			sortHeap(L, left, n);			//向下调整 
	}//endif
	else {
		if(L.data[right] > L.data[right])
			swap(L.data[right], L.data[i]);
			sortHeap(L, right, n);			//向上调整 
	}//endelse
}//Adjust


















