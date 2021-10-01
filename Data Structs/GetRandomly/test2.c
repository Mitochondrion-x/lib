#include"stdio.h"
int main()
{
    double a,b,c,sum1=0,sum2=0,sum3=0,i,sum=0;
    scanf("%lf",&a);
    scanf("%lf",&b);
    scanf("%lf",&c);
    for(i=1;i<=a;i++)                 //?????????
    {
        sum1+=i;    
    }
    for(i=1;i<=b;i++)
    {
        sum2+=i*i;
    }
    for(i=1;i<=c;i++)
    {
        sum3+=1.0/i;                  //????1.0/i
    }
    printf("%.2lf,%.2lf,%.2lf",sum1,sum2,sum3);
	//sum=sum1+sum2+sum3;
    //printf("%.2lf",sum);
    return 0;
}
