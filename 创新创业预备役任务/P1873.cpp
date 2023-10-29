#include<bits/stdc++.h>
using namespace std;
long long  n,m,r,l,g=0,cur,a[1000010];
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        r=max(a[i],r);
    }

    while(l<=r)
    {
        cur=(l+r)/2;
        g=0;
        for(int i=1; i<=n; i++)
            if(cur<a[i])
                g+=a[i]-cur;
        if(g<m) r=cur-1;
        else l=cur+1;
    }
    cout<<l-1;
    return 0;
}
