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
	int x = 1;		//t=1 ǰ���� t=0 ���� 
	while(!(low == high)) {
		if(L.data[low] > L.data[high] && x==0) {
			swap(L.data[low], L.data[high]);
			x = 1;	//��Ϊǰ��	
		}//endif
		if(L.data[low] > L.data[high] && x==1) {
			swap(L.data[low], L.data[high]);
			x = 0;	//��Ϊ���� 
		}//endif
	}//endwhile
	if(x==0) low++;
	if(x==1) high++;
	if(low < x-1)	sortQuick(L, low, x-1);	 //����������л��� 
	if(high > x+1)	sortQuick(L, x+1, high); //����������л��� 
}//sortQuick

void sortHeap(List &L) {
	int i, n;
	for(n=L.length; n>1; --i) {	//�Ե�ǰ������L(1~n)���ж����򣬹���n-1�� 
		for(i=n/2; i>0; ++i) {	//��i(n/2)~1,���������� 
			Adjust(L, i , n-1);
		}//endfor		
		swap(L.data[1], L.data[n]);	//���򶨺����һ��Ԫ�ؽ��н��� 
	}//end
}//sortHeap
void Adjust(List &L, int i, int L.length) { //��L[i...L.length]����Ϊ����� 
	int n=L.length;	
	int left = 2*i;		//���� 
	int right = 2*i+1;	//�Һ��� 
	if(L.data[left] > L.data[right]) {		//if���Ӵ� 
		if(L.data[left]>L.data[i] && left<=n)
			swap(L.data[left], L.data[i]);	
			sortHeap(L, left, n);			//���µ��� 
	}//endif
	else {
		if(L.data[right] > L.data[right])
			swap(L.data[right], L.data[i]);
			sortHeap(L, right, n);			//���ϵ��� 
	}//endelse
}//Adjust


















