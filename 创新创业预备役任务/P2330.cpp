#include<bits/stdc++.h>
using namespace std;
int n,m,f[100001],ans;
struct node
{
    int x,y,v;
} a[100001];
int getf(int i)
{
    if(i==f[i])return i;
    else return f[i]=getf(f[i]);
}
bool cmd(node a,node b)//自定义排序规则
{
    return a.v<b.v;
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)f[i]=i;//初始化
    for(int i=1; i<=m; i++)cin>>a[i].x>>a[i].y>>a[i].v;//录入数据
    int cnt=0;//已确认边的计数器
    sort(a+1,a+m+1,cmd);
    for(int i=0; i<=m; i++)//克鲁斯卡尔
    {
        int aa=getf(a[i].x);
        int bb=getf(a[i].y);
        if(aa!=bb)//将不联通的两点相连
        {
            ans=a[i].v;//更新分值最大的那条道路的分值
            f[aa]=bb;
            cnt++;//加边
        }
        if(cnt==n-1)//边数达到n-1条时说明已生成最小生成树
            break;
    }
    cout<<n-1<<" "<<ans;
    return 0;
}
