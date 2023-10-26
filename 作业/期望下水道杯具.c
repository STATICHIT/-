//期望值，下水道
#include<stdio.h>
void main()
{
    int n,i;
    double E;
    while(~scanf("%d",&n))
    {
        long long int a[100010]={0};//多组循环这里要重新归0
        long long int sum=0;//多组循环这里也要重新归0
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            sum+=a[i];
        }
        E=(sum*1.0)/n;
        printf("%.10f\n",E);
    }
}

