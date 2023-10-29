#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,k;
ll v[10010],t[1010],f[10000010];
int main()
{
    cin>>T>>k;
    for(int i=1; i<=k; i++)cin>>t[i]>>v[i];
    for(int i=1; i<=k; i++)
        for(int j=t[i]; j<=T; j++)
            f[j]=max(f[j],f[j-t[i]]+v[i]);
    cout<<f[T];
    return 0;
}
