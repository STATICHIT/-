#include<stdio.h>
int main()
{
    long long n,d,m,l,ans=0;
    scanf("%lld %lld %lld %lld",&n,&d,&m,&l);
    for(int k=1; k<=n; k++)//k代表第k块板子
    {
        if(ans<((k-1)*m))//如果本次青蛙跳跃后达不到板子左边缘则落入水中结束跳跃
            break;
        while(ans<=(k-1)*m+l)//跳的上板子就一直跳，直到跳出了板子右边缘
        {
            ans=(((k-1)*m+l)/d)*d+d;//*d/d是为了取整
        }
    }
    printf("%lld",ans);
    return 0;
}
