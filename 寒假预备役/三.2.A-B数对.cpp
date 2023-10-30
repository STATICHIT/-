#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, c,ans;
ll a[200001];
int main ()
{
    cin>>n>>c;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+1+n); //排序数串
    ll r1=1,r2=1;//双指针
    for(int i=1; i<=n; i++)
    {
        while(r1 <= n && a[r1] - a[i] <= c)//下标不超过n的前提下如果a[r1]-a[i]<=c就右移动直到a[r1]-a[l]<= c的最后位置的下一位
            r1 ++;
        while(r2 <= n && a[r2] - a[i] < c )//下标不超过n的前提下如果a[r2]-a[i]<c就右移动直到a[r2]-a[l]<c最后一位
            r2 ++;

        if(a[r2]-a[i] == c&&a[r1-1]-a[i] == c&&r1-1>=1)
            ans+=r1-r2;
    }
    cout<<ans;
    return 0;
}
