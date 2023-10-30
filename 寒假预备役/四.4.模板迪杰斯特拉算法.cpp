/*
#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
int n,m,s;
int a,b,l;
int u,_min;
int v[11000][11000];
int dis[11000];
int book[11000];
int main()
{
    //初始化
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(i == j)v[i][j]=0;
            else v[i][j]=inf;
        }
    cin>>n>>m>>s;
    //读入边
    while(m--)
    {
        cin>>a>>b>>l;
        v[a][b]=l;
    }
    //初始化dis数组
    for(int i=1;i<=n;i++)
        dis[i]=v[s][i];
    //初始化book数组
    for(int i=1;i<=n;i++)
        book[i]=0;
    book[s]=1;

    //Dijkstra算法
    for(int i=1;i<=n-1;i++)
    {
        _min=inf;
        for(int j=1;j<=n;j++)
        {
            if(book[j]==0&&dis[j]<_min)
               {
                 _min=dis[j];
                 u=j;
               }
        }
        book[u]=1;
        for(int k=1;k<=n;k++)
        {
            if(v[u][k]<inf)
            {
                if(dis[k]>dis[u]+v[u][k])
                    dis[k]=dis[u]+v[u][k];
            }
        }
    }
    dis[s]=0;
    for(int i=1; i<=n; i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
#define inf 2147483647
#define N 10005
#define M 500005
int n,m,s;
int low[N];//距离
int vis[N];//标记数组
int head[N],cnt;//存起点

struct node
{
    int to,v,next;
} e[M];

//加边
void add(int a,int b,int v)
{
    cnt++;
    e[cnt].to=b;
    e[cnt].v=v;
    e[cnt].next=head[a];///next记录上一条边
    head[a]=cnt;///head记录最后一条边
}
//Dijkstra
void Dij()
{
    int idx = s;
    low[s]=0;//自己到自己距离为0
    while(true)
    {
        int idx=-1;
        int Min=inf;
        for(int i=1; i<=n; i++)
        {
            if(vis[i] == 0 && low[i]<Min)
            {
                Min=low[i];
                idx=i;
            }
        }
        if(idx == -1)break;//说明没有没遍历过的点了
        vis[idx] = 1;
        for(int i=head[idx]; i!=0; i=e[i].next)
        {
            int a=idx,b=e[i].to,v=e[i].v;
            if(low[b]>low[a]+v)
                low[b]=low[a]+v;
        }
    }
      for(int i=1;i<=n;i++)
    {
        if(low[i]<inf)
        {
            cout<<"1->"<<i<<":"<<low[i]<<endl;
        }
        else
            cout<<"1->"<<i<<":no path"<<endl;
    }
}
int main( )
{
    cin>>n>>m>>s;
    for(int i=1; i<=n; i++)
        low[i]=inf;
    for(int i=1; i<=m; i++)
    {
        int a,b,v;
        cin>>a>>b>>v;
        add(a,b,v);
    }
    Dij();
    return 0;
}
///下面也是ac代码
/*
#include<bits/stdc++.h>
using namespace std;
#define inf 2147483647
#define N 10005
#define M 500005
int n,m,s;
long long low[N];//距离
int vis[N];//标记数组
int head[N],cnt;//存起点

struct node
{
    int to,v,next;
} e[M];

//加边
void add(int a,int b,int v)
{
    cnt++;
    e[cnt].to=b;
    e[cnt].v=v;
    e[cnt].next=head[a];///next记录上一条边
    head[a]=cnt;///head记录最后一条边
}


//Dijkstra
void Dij()
{
    int idx = s;
    while(vis[idx] == 0)
    {
        long long Min=inf;
        vis[idx] = 1;
        for(int i=head[idx]; i!=0; i=e[i].next)
        {
            int a=idx,b=e[i].to,v=e[i].v;
            if(vis[b] == 0 && low[b]>low[a]+v)
                low[b]=low[a]+v;
        }

        for(int i=1; i<=n; i++)
        {
            if(vis[i] == 0 && low[i]<Min)
            {
                Min=low[i];
                idx=i;
            }
        }
    }
    for(int i=1; i<=n; i++)
        cout<<low[i]<<" ";
}
int main( )
{
    cin>>n>>m>>s;
    for(int i=1; i<=n; i++)
        low[i]=inf;
    low[s]=0;//自己到自己距离为0
    for(int i=1; i<=m; i++)
    {
        int a,b,v;
        cin>>a>>b>>v;
        add(a,b,v);
    }
    Dij();
    return 0;
}
*/
