#include<stdio.h>
#include<stdlib.h>
#include<time.h>


static int i,*p,a[10];
int getRandom() {
	srand((unsigned)time(NULL));
	for(p=a;p<a+10;++p) {
 		*p=rand()%90+10;
		//printf("%d  ",*p);
	}
	return *p;
}
main() {
	getRandom();
	for(i=1;i<10;++i)
		printf("%d  ",*p);
	return 0;
} 

static int i,*p,a[10];
void getRandom() {
	srand(time(NULL));
	for(p=a;p<a+10;++p) {
		*p=rand()%90+10;
	}
}

main() {
	getRandom();
	int i,temp;
	temp = *a;
	for(i=0;i<10;i++) {
		printf("%2d  ",*(a+i));
		if(temp<*(a+i)) {
			temp=*a;*p=*(a+1);*(a+1)=temp;
			printf("%d  ",temp);
		}
		//printf("%d",temp);
	}
/*	temp=*a;
	printf("\n****************************\n");
	for(i=*a;i<*(a+10);++i) {
		if(p<a+0) {
			temp=*a;*p=*(a+1);*(a+1)=temp;
		}
		printf("%d  ",temp);
	} */
	return 0;
}



















