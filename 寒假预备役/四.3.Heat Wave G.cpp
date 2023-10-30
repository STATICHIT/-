#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
int n,m,s,t;
int a,b,l;
int v[2600][2600];
int dis[2600];
int book[2600];//初始化默认为0
int main()
{
    cin>>n>>m>>s>>t;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(i == j)v[i][j]=0;
            else v[i][j]=inf;
        }
    while(m--)
    {
        cin>>a>>b>>l;
        v[a][b]=l;
        v[b][a]=l;
    }
    for(int i=1;i<=n;i++)
        dis[i]=v[s][i];
    book[s]=1;
    for(int i=1;i<=n-1;i++)
    {
        int _min=inf,u;
        for(int j=1;j<=n;j++)//找到距离顶点最近的点
        {
            if(book[j] == 0 && dis[j] < _min)
            {
                _min=dis[j];
                u=j;//并记录其坐标
            }
        }
        book[u]=1;
        for(int j=0;j<=n;j++)
            dis[j]=min(dis[j],dis[u]+v[u][j]);//比较s点到j的距离和s点到u再从u到j的距离，如果距离变短就替换
    }
    cout<<dis[t];
    return 0;
}
