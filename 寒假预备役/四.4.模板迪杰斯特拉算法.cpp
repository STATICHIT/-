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
    //��ʼ��
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(i == j)v[i][j]=0;
            else v[i][j]=inf;
        }
    cin>>n>>m>>s;
    //�����
    while(m--)
    {
        cin>>a>>b>>l;
        v[a][b]=l;
    }
    //��ʼ��dis����
    for(int i=1;i<=n;i++)
        dis[i]=v[s][i];
    //��ʼ��book����
    for(int i=1;i<=n;i++)
        book[i]=0;
    book[s]=1;

    //Dijkstra�㷨
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
int low[N];//����
int vis[N];//�������
int head[N],cnt;//�����

struct node
{
    int to,v,next;
} e[M];

//�ӱ�
void add(int a,int b,int v)
{
    cnt++;
    e[cnt].to=b;
    e[cnt].v=v;
    e[cnt].next=head[a];///next��¼��һ����
    head[a]=cnt;///head��¼���һ����
}
//Dijkstra
void Dij()
{
    int idx = s;
    low[s]=0;//�Լ����Լ�����Ϊ0
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
        if(idx == -1)break;//˵��û��û�������ĵ���
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
///����Ҳ��ac����
/*
#include<bits/stdc++.h>
using namespace std;
#define inf 2147483647
#define N 10005
#define M 500005
int n,m,s;
long long low[N];//����
int vis[N];//�������
int head[N],cnt;//�����

struct node
{
    int to,v,next;
} e[M];

//�ӱ�
void add(int a,int b,int v)
{
    cnt++;
    e[cnt].to=b;
    e[cnt].v=v;
    e[cnt].next=head[a];///next��¼��һ����
    head[a]=cnt;///head��¼���һ����
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
    low[s]=0;//�Լ����Լ�����Ϊ0
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
