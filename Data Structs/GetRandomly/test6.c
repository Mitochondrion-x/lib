#include<stdio.h>

void getRandom() {
	srand((unsigned)time(NULL));
	int i,a[10];
	for(i=0;i<10;++i) {
		a[i]=rand()%90+10;
		printf("%d  ",a[i]);
	}
		
}
main() {
	getRandom();
	return 0;
}

static int sum=0;
int sumFunction(int a,int b) {
    sum = a + b;
    return sum;
}
main() {
	int a,b;
	scanf("%d%d",&a,&b);
	sumFunction(a,b);
	printf("%d",sum);
	return 0;
}
