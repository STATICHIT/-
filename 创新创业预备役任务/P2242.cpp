#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],b[1000010];
bool cmd(int a,int b){
    return a>b;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];//录入坑位
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];//所有坑共n-1个空隙
    }
    sort(b+1,b+n,cmd);//从大到小排序空隙(因为只有n-1个空隙，所以是b+1到b+1+n-1即b+n)
    int ans=a[n]-a[1]+1;
    for(int i=1;i<=m-1;i++)//减去最大的m-1个空隙
    {
        //因为m个领域有m-1个空隙
        ans-=b[i]-1;
    }
    cout<<ans;
    return 0;
}
