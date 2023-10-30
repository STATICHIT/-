#include<bits/stdc++.h>
using namespace std;
#include<queue>
#define M 200001
#define inf 0x7fffffff
int n,m,s,a,b,c;
long long dis[M];//距离
int vis[M];//标记是否做过起点
int head[M];//以某点为父节点引出的最后一条边
int cnt=0;//边下标
priority_queue< pair<int,int> > q; //创建以pair<int,int>映射结构为结点的优先队列,其中pair<a,b>,a是s到b的距离

struct EDGE//链式前向星存边
{
    int to,wei,next;
} edge[M];

void add(int a,int b,int c)//链式前向星存边
{
    cnt++;
    edge[cnt].to=b;
    edge[cnt].wei=c;
    edge[cnt].next=head[a];
    head[a]=cnt;//更新head
}

int main()
{
    cin>>n>>m>>s;
    for(int i=1; i<=n; i++)
        dis[i]=inf;
    dis[s]=0;
    while(m--)
    {
        cin>>a>>b>>c;
        add(a,b,c);
    }
    q.push(make_pair(0,s));//s到s的距离为0
    while(!q.empty())//队列为空
    {
        int x=q.top().second;q.pop();//取出堆顶
        if(vis[x])continue;
        vis[x]=1;
        for(int i=head[x]; i!=0; i=edge[i].next)
        {
            int y=edge[i].to,v=edge[i].wei;
            if(vis[y] == 0&& dis[y]>dis[x]+v)
            {
                dis[y]=dis[x]+v;//更新
                q.push(make_pair(-dis[y],y));
            }
        }
    }
    for(int i=1; i<=n; i++)
        cout<<dis[i]<<" ";
    return 0;
}
