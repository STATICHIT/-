#include<bits/stdc++.h>
using namespace std;
#define N 160
int n,m,x,y;
int v[N][N];
int num[N],low[N],flag[N],dex,o;
struct
{
    int x,y;
} ans[N];

void dfs(int cur,int father)
{
    dex++;
    num[cur]=dex;
    low[cur]=dex;
    for(int i=1; i<=n; i++)
    {
        if(v[cur][i] == 1)
        {
            if(num[i] == 0)
            {
                dfs(i,cur);
                low[cur]=min(low[i],low[cur]);
                if(low[i]>num[cur])
                {
                    ans[o].x=cur;
                    ans[o].y=i;
                    o++;
                }
            }
            else if(i != father)
            {
                low[cur]=min(low[cur],num[i]);
            }
        }
    }
}
int main()
{

    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        v[x][y]=1;
        v[y][x]=1;
    }
    int root=1;
    dfs(1,root);
    for(int i=0; i<o-1; i++)
        for(int j=i+1; j<o; j++)
           {
              if(ans[j].x<ans[i].x)
                {
                   int temp=ans[j].x;ans[j].x=ans[i].x;ans[i].x=temp;
                       temp=ans[j].y;ans[j].y=ans[i].y;ans[i].y=temp;
                }
              else if(ans[j].x == ans[i].x)
                     {
                        if(ans[j].y<ans[i].y)
                        {
                           int temp=ans[j].x;ans[j].x=ans[i].x;ans[i].x=temp;
                           temp=ans[j].y;ans[j].y=ans[i].y;ans[i].y=temp;
                         }
                      }
           }
    for(int i=0; i<o; i++)
        cout<<ans[i].x<<" "<<ans[i].y<<endl;
    return 0;
}
