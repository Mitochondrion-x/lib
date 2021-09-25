#include<iostream>
//#define Maxsize 50
using namespace std;

typedef struct {	//static allocation
	ElemType data[MaxSize];
	int length;	
}Seqlist;

#define InitSize 100
typedef struct {	//dynamic allocation
	ElemType *data;
	int length,MaxSize;
}Seqlist2;
Seqlist2.data = (ElemType *) malloc (InitSize*sizeof(ElemType)); //C allocation memory space
Seqlist2.data = new ElemType[InitSize]; //C++ allocation memory space 



void judge_i(int i) {
	if(i<1 || i>SeqList.length+1) 
		cout<< "illegal postion" <<endl;
	if(SeqList.length == Maxsize)
		cout<< "List is Maxsize" <<endl;
	if(SeqList.length == 0)
		cout<< "List is empty" <<endl;
}

bool createList(int A[], int &length) {
	std:: cin>> length;
	if(length > Maxsize)
		return false;
	for(int i=0; i<length; ++i) {
		std:: cin>> A[i];
	}
	return true;
}

bool initList(SeqList &L,int initSize) {
	L.length = initSize;
	L.data = (Elemtype*) malloc (sizeof(Elemtype)*initSize);
	if(!L->data)
		return false;
	return true;
}

bool insertList(SeqList &L, int i, Elemtype e) {
	if(i<1 || i>L.length+1)
		return false;
	for(int j=L.length; j>i.length+1; --j)
		L.data[j] = L.data[j-1];
	L.data[i] = e;
	L.length++;
	return true;
} 

bool deleteList(SeqList &L, int i, Elemtye &e) {
	judge_i(i);
	*e = L.data[i];
	for(int j=i; j<L.length+1; ++j)
		L.data[j] = L.data[j+1];
	L.length--;
	return true;
}

bool locateList(SeqList &L,int i; Elemtype e) {
	if(L.length == 0)
		return false;
	for(i=0; i<L.length+1; ++i) {
		if(L.data[i] == e)
			return i+1;
	}
	return true;
}

bool getElem(SeqList &L, int i; Elemtype &e) {
	if(L.length == 0 || i<1 || i>L.length+1) 
		return false
	*e = L.data[i];
	return true;
}

void traverList(SeqList &L) {
	if(L.length == 0)
		cout<< "NULL\n"<<endl;
	for(int i=0; i<L.length; ++i) {
		cout<< "traverList: "<< L->data[i]<<endl;
	cout<< <<endl;
	}
}

void reverseLIst(SeqList &L) {
	Elemtype temp;
	for(int i=0; i<L.length/2; ++i) {
		temp = L.data[i];
		L.data[i] = L.data[L.length-(i+1)];
		L.data[L.length-(i+1)] = temp;
	}
}

// https://blog.csdn.net/qq_43039693/article/details/82819060?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522163193574016780261951908%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=163193574016780261951908&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-82819060.first_rank_v2_pc_rank_v29&utm_term=%E7%BA%BF%E6%80%A7%E8%A1%A8%E9%80%86%E7%BD%AE&spm=1018.2226.3001.4187
// https://blog.csdn.net/zag666/article/details/105252525/?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_utm_term~default-0.no_search_link&spm=1001.2101.3001.4242









