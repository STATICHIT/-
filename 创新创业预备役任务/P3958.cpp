#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    ll x,y,z;
} in[1010],all[1010];

ll t,n,h,r,s,flag;
bool cmp(Node a,Node b)
{
    if(a.z!=b.z) return a.z<b.z;//高度为第一依据
    if(a.x!=b.x) return a.x<b.x;
    if(a.y!=b.y) return a.y<b.y;
}

ll dis(ll x1,ll y1,ll z1,ll x2,ll y2,ll z2)//算距离
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>h>>r;
        s=0,flag=0;
        memset(in,0,sizeof(in));
        for(int i=1; i<=n; i++)
            cin>>all[i].x>>all[i].y>>all[i].z;
        sort(all+1,all+n+1,cmp);//从下到上排序
        for(int i=1; i<=n; i++)
        {
            flag=0;
            if(all[i].z-r<=0)//与底相连，入队a
            {
                s++;//队员数量+1,in数组是从1开始加数据的，得到的s也是数组in中的数量
                in[s].x=all[i].x;
                in[s].y=all[i].y;
                in[s].z=all[i].z;
            }
            for(int j=1; j<=s; j++)//与队员连接等同于与底部连接，入队
            {
                if(dis(all[i].x,all[i].y,all[i].z,in[j].x,in[j].y,in[j].z)<=4*r*r)
                {
                    s++;
                    in[s].x=all[i].x;
                    in[s].y=all[i].y;
                    in[s].z=all[i].z;
                    break;//只要与队中任何一个圆相连它就可以入队。
                }
            }
            if(in[s].z+r>=h)//队中有与顶相连的则会有通路
            {
                flag=1;
                break;//已找到通路，可得出结果
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
