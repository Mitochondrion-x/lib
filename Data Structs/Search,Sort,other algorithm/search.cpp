
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
