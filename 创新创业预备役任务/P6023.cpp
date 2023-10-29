#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,maxV,ans[1000001];
struct node{
    ll day,must;
}a[1000001];
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        cin>>a[i].day>>a[i].must;
        if(n>a[i].must)
            ans[a[i].day]+=n-a[i].must;
    }
    for(int i=1;i<=m;i++)maxV=max(maxV,ans[i]);
    cout<<maxV;
    return 0;
}
