
typedef struct {
	Elemtype *data;
	int length;
}SSTable;

//顺序查找(不带哨兵)
int Seq_Search(SSTable &S, Elemtype key) {
	int i = 0;
	while(i<S.length && S.data[i]!=key)
		i++;
	if(S.data[i] == x)
		return i+1;
	else
		return 0;
}
int Seq_Search2(SSTable &S, Elemtype key) {
	int i = S.length;
	S.data[0] = key; //将关键字存放在0位置处，防止越界 
	while(S.data[i]=key)
		i--;
	return i;
}//一切为简化边界条件而引入的附加节点均可称为哨兵 
/*  哨兵的主要作用就是在查找循环中监视下表i是否越界,一旦越界(i=0)，因为可以和自己进行比较循环判断条件不成立就使得查找循环结束，就可以达到忽略判定边界调节的目的 */ 
