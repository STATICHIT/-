#include<bits/stdc++.h>
using namespace std;
int n,k,sum,cnt,f[100010];
struct ll
{
    int i;//起
    int j;//终
    int m;//通畅值
}a[100010];

//自定义排序规则
bool cmp(ll x,ll y)
{
    return x.m<y.m;
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].i>>a[i].j>>a[i].m;
        sum+=a[i].m;
    }
    sort(a+1,a+1+k,cmp);
    for(int i=1; i<=n; i++)f[i]=i;//初始每个人的祖宗都是自己
    for(int i=1; i<=k; i++)
    {
        int l1=getf(a[i].i);
        int r1=getf(a[i].j);
        if(l1!=r1)
        {
            f[l1]=r1;
            sum-=a[i].m;
            cnt++;
        }
        if(cnt==n-1)break;
    }
    cout<<sum;
    return 0;
}
