
typedef struct {
	Elemtype *data;
	int length;
}SSTable;

//˳�����(�����ڱ�)
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
	S.data[0] = key; //���ؼ��ִ����0λ�ô�����ֹԽ�� 
	while(S.data[i]=key)
		i--;
	return i;
}//һ��Ϊ�򻯱߽�����������ĸ��ӽڵ���ɳ�Ϊ�ڱ� 
