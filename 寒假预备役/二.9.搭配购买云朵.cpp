//这道题就是一个并查集加0/1背包的问题
#include<bits/stdc++.h>
using namespace std;
int n,m,w;//n：云朵数目，m：搭配数，w：钱（即背包容量）
int f[100000];//父亲数组
int dp[100000];
int v[100000],d[100000];//v:价格（即物品质量）d：价值
int findd(int x)//找祖宗
{
    if(f[x]==x)
        return f[x];
    else
        return f[x]=findd(f[x]);
}
void hb(int x,int y)
{
    if(findd(x)!=findd(y))
        f[findd(x)]=findd(y);
}
int main()
{
    cin>>n>>m>>w;
    //初始化并查集并输入每个云朵的价格和价值
    for(int i=1;i<=n;i++)
        {
            f[i]=i;
            cin>>v[i]>>d[i];
        }

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        hb(a,b);
    }
    for(int i=1;i<=n;i++)//集合价格&价值合并
    {
        if(findd(i)!=i)///这里很关键
        {
            v[findd(i)]+=v[i];
            v[i]=0;//把该云朵的价格加到其所在集合老大里面，原本的就清零
            d[findd(i)]+=d[i];
            d[i]=0;//同上
        }
    }

    //0/1背包
    for(int i=1;i<=n;i++)
    {
        for(int j=w;j>=1;j--)//滚动数组
        {
            if(j>=v[i])
                dp[j]=max(dp[j],dp[j-v[i]]+d[i]);
        }
    }
    cout<<dp[w];
    return 0;
}
