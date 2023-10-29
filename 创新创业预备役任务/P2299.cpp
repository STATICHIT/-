#include<bits/stdc++.h>
using namespace std;
int n,m,a[3000][3000],v[10001],dis[10001],x,y,z;
int main()
{
    cin>>n>>m;
    memset(a,0x7f,sizeof(a));//初始化矩阵为很大的值
    for(int i=1; i<=m; i++)//录入矩阵数据
    {
        cin>>x>>y>>z;
        if(z<a[x][y])
        {
            a[x][y]=z;
            a[y][x]=z;
        }
    }
    for(int i=1;i<=n;i++)
    {
        dis[i]=a[1][i];//初始化距离数组（点1到x的距离）
    }
    dis[1]=0;//首先1到本身的距离为0
    for(int i=1; i<=n; i++)//dijkstra
    {
        int k=0;
        int minn=0x7fffff;
        for(int j=1;j<=n;j++){
            if(v[j]==0&&dis[j]<minn){
                minn=dis[j];
                k=j;
            }
        }
        if(k==0)break;
        v[k]=1;
        for(int j=1;j<=n;j++){
            if(dis[k]+a[k][j]<dis[j])
                dis[j]=dis[k]+a[k][j];
        }
    }
    cout<<dis[n];
    return 0;
}
