#include<bits/stdc++.h>
using namespace std;
int mod=100003;
int n,m,x,y,tot=0;
const int N=1000005,M=4000005;
int head[N],to[M],nxt[M],d[N],ans[N];
int p[N];
queue<int> q;

void add(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}

int main()
{
	cin>>n>>m;
	while(m--){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){d[i]=1e9;p[i]=0;}

	d[1]=0;
	p[1]=1;
	ans[1]=1;
	q.push(1);

	while(q.size())
	{
		x=q.front();q.pop();
		p[x]=0;
		for(int i=head[x];i;i=nxt[i])
		{
			y=to[i];
			if(d[y]>d[x]+1)
			{
				d[y]=d[x]+1;
				ans[y]=ans[x];
				if(!p[y])
				{
					q.push(y);
					p[y]=1;
				}
			}
			else if(d[y]==d[x]+1)
			{
				ans[y]+=ans[x];
				ans[y]%=mod;
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
	return 0;
}
