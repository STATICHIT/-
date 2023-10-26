//求1到100之间的奇数之和，偶数之积。
#include<stdio.h>
void main()
{
    int i,j,sum=0;
    long long ji=1;
    for(i=1; i<=99; i=i+2)
    {
        sum=sum+i;
    }
    for(j=2; j<=100; j=j+2)
    {
        ji=ji*i;
    }
    printf("1到100之间的奇数之和为%d,偶数之积为%d。\n",sum,ji);
}
