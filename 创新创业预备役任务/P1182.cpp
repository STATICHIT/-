#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,mid,ans,a[1000001];

bool check(int x)
{
    int tot=0,cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(tot+a[i]<=x)
            tot+=a[i];
        else
        {
            tot=a[i];//新一轮
            cnt++;//分组+1
        }
    }
    return cnt>=m;
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        l=max(l,a[i]);//最小最大值不会小于最大元素
        r+=a[i];
    }

    while(l<=r)//最小最大和最大不能大于总和
    {
        mid=(l+r)>>1;
        if(check(mid))//组分多了，说明值太小了，多次重启，所以终值大一点吧
            l=mid+1;
        else
            r=mid-1;
    }
    cout<<l;
    return 0;
}
