#include<stdio.h>
int qs(int n)//七转十
{
    int k=1,N,ans=0;
    while(n!=0)
    {
        N=n%10;
        n=n/10;
        ans+=N*k;//第一次循环此处k=1.即个位数乘7的0次方
        k=k*7;//个位数字乘1，十位数字乘7，百位数字乘7*7....即最后直接得到十进制形式结果
    }
    return(ans);
}
int sq(int n,int m)//十转m进制
{
    int k=1,N,a,ans=0;
    while(n!=0)
    {
        N=n%m;
        n=n/m;
        ans+=N*k;
        k=k*10;//个位数字乘1，十位数字乘10，百位数字乘100....即最后直接得到m进制形式结果
    }
    return(ans);
}
int main()
{
    int i,t,n,m,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        ans=qs(n);//先把七进制余额转为十进制
        ans=ans+m;//再加上要存的十进制钱数
        ans=sq(ans,7);//总体把钱总数转为七进制
        printf("%d\n",ans);
    }
    return 0;
}
