#include<bits/stdc++.h>
using namespace std;
long long n,m,mid,mxa,a[1000][1000];
int main()
{
    cin>>n>>m;
    mid=(n*m)%2==0?n*m/2:(n*m)/2+1;
    mxa=n*m;
    if(n+m<5&&(n!=1||m!=1))
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if((i+j)%2==1)cout<<mxa--<<" ";
            if((i+j)%2==0)cout<<mid--<<" ";
        }
        cout<<endl;
    }
    return 0;
}
