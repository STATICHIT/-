#include<bits/stdc++.h>
using namespace std;
int n,m,p,q,numm,numh;
int f[1000000];
int findd(int x)//找祖宗（并查集必写函数）
{
    if(f[x] == x)
        return x;
    else
    return f[x]=findd(f[x]);//压缩路径
}
void hb(int x,int y)//合并集合（并查集必写函数）
{
    int fx=findd(x);
    int fy=findd(y);
    if(fx!=fy)
        f[fx]=fy;
}
int main()
{
    cin>>n>>m>>p>>q;

    for(int i=1;i<=n+m;i++)//不要忘了！！初始化并查集
        f[i]=i;//起初自己就是自己的老大

    for(int i=1;i<=p;i++)//根据提给信息合并小集合
    {
        int a,b;
        cin>>a>>b;
        hb(a,b);
    }

    for(int i=1;i<=q;i++)//处理全是女人的公司
    {
        int a,b;
        cin>>a>>b;//因为女性是用负数代表，而数组不存在负数下标
        a=-1*a+n;b=-1*b+n;//所以先把a，b变为正数，再加上n避免和男人编重合
        hb(a,b);
    }

    for(int i=1;i<=n;i++)
    {
        if(findd(i)==findd(1))//如果是与小明是朋友的男性
            numm++;
    }
    for(int i=n+1;i<=n+m;i++)
    {//n+1到n+m才是女人f数组
        if(findd(i)==findd(1+n))//如果是与小红是朋友的女性
            numh++;     //小红的编号是-1，转化为重合正数为-1*-1+n即1+n。
    }
    int ans=min(numm,numh);//短板效应，最终结果取决于少的那一方
    cout<<ans;
    return 0;
}
