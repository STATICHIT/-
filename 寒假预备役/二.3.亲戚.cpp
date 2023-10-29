#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int f[10000];
int findd(int x)//找祖宗
{
    if(f[x]==x)//自己就是自己的爸爸
        return x;
    else
        return f[x]=findd(f[x]);//顺便把内部结点的爸爸直接改成老大
}
void combine(int x,int y)
{
    if(findd(x)!=findd(y))
        f[findd(x)]=findd(y);
}
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)//初始化f数组
        f[i]=i;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        combine(a,b);
    }
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(findd(a) == findd(b))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
