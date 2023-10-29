#include<bits/stdc++.h>
using namespace std;
const int inf=999999999;
int f[210][210],vis[210],t[210];//二维数组存地图、标记、时间
int n,m,kk;
int u,v,w;
int main()
{
    cin>>n>>m;
    //初始化地图
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            f[i][j]=inf;
    //存时间，改变特殊位置值
    for(int i=0; i<n; i++)
    {
        cin>>t[i];//存重建时间
        f[i][i]=0;//顺便定义自己到自己的距离为0
    }
    //存路径
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v>>w;
        f[u][v]=w;
        f[v][u]=w;//双向
    }
    cin>>kk;//询问次数
    while(kk--)
    {
        cin>>u>>v>>w;
        for(int k=0; k<n; k++)
        {
            if(t[k]<=w&&!vis[k])//如果该点在该时间已经修好了且未来过该地
            {
                vis[k]=1;//标记
                for(int i=0; i<n; i++) //弗洛伊德
                {
                    for(int j=0; j<n; j++)
                    {
                        if(f[i][j]>f[i][k]+f[k][j])
                            f[i][j]=f[i][k]+f[k][j];
                    }
                }
            }
        }
        if(t[u]<=w&&t[v]<=w&&f[u][v]<inf)cout<<f[u][v]<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
