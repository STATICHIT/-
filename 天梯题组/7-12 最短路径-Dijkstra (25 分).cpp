/*
//优先队列+链式前向星+迪杰斯特拉
#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
#define N 10005
#define M 500005
int n,m,s;
int low[N];//距离
int vis[N];//标记数组
int head[N],cnt;//存起点
int a[10000],b[10000],v[10000];

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
    for(int i=1; i<=n; i++)
    {
        if(low[i]<inf)
        {
            cout<<s<<"->"<<i<<":"<<low[i];
        }
        else
            cout<<s<<"->"<<i<<":no path";
        if(i!=n)cout<<endl;
    }
}
int main()
{
    int flag;
    cin>>n>>m>>flag;
    //初始化
    for(int i=1; i<=n; i++)
        low[i]=inf;

    for(int i=1; i<=m; i++)
        scanf("%d %d %d",&a[i],&b[i],&v[i]);

    cin>>s;
    if(flag == 0)//无向图
    {
        for(int i=1; i<=m; i++)
        {
            add(a[i],b[i],v[i]);
            add(b[i],a[i],v[i]);
        }
        Dij();
    }
    else if(flag == 1)
    {
        for(int i=1; i<=m; i++)
        {
            add(a[i],b[i],v[i]);
        }
        Dij();
    }
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
#define N 10
#define M 500
int n,m,s,flag;
int Map[N+10][N+10];

void add(int u,int v,int w)
{
    Map[u][v]=w;
}
int main()
{
    int flag;
    cin>>n>>m>>flag;
    //初始化
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(i == j)
                Map[i][j]=0;
            else
                Map[i][j]=inf;
        }

    while(m--)
    {
        int a,b,v;
        cin>>a>>b>>v;
        add(a,b,v);
        if(flag == 0)add(b,a,v);
    }

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(Map[i][j]>Map[i][k]+Map[k][j])
                    Map[i][j]=Map[i][k]+Map[k][j];

    cin>>s;
    for(int i=1; i<=n; i++)
    {
        if(Map[s][i]!=inf)
        {
            cout<<s<<"->"<<i<<":"<<Map[s][i];
        }
        else
            cout<<s<<"->"<<i<<":no path";
        if(i!=n)cout<<endl;
    }
    return 0;
}
