#include<bits/stdc++.h>
using namespace std;
#include<queue>
#define M 200001
#define inf 0x7fffffff
int n,m,s,a,b,c;
long long dis[M];//����
int vis[M];//����Ƿ��������
int head[M];//��ĳ��Ϊ���ڵ����������һ����
int cnt=0;//���±�
priority_queue< pair<int,int> > q; //������pair<int,int>ӳ��ṹΪ�������ȶ���,����pair<a,b>,a��s��b�ľ���

struct EDGE//��ʽǰ���Ǵ��
{
    int to,wei,next;
} edge[M];

void add(int a,int b,int c)//��ʽǰ���Ǵ��
{
    cnt++;
    edge[cnt].to=b;
    edge[cnt].wei=c;
    edge[cnt].next=head[a];
    head[a]=cnt;//����head
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
    q.push(make_pair(0,s));//s��s�ľ���Ϊ0
    while(!q.empty())//����Ϊ��
    {
        int x=q.top().second;q.pop();//ȡ���Ѷ�
        if(vis[x])continue;
        vis[x]=1;
        for(int i=head[x]; i!=0; i=edge[i].next)
        {
            int y=edge[i].to,v=edge[i].wei;
            if(vis[y] == 0&& dis[y]>dis[x]+v)
            {
                dis[y]=dis[x]+v;//����
                q.push(make_pair(-dis[y],y));
            }
        }
    }
    for(int i=1; i<=n; i++)
        cout<<dis[i]<<" ";
    return 0;
}
