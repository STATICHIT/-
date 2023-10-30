#include<bits/stdc++.h>
using namespace std;
int n,x,v[210][210];
int main()
{
    cin>>n;
    memset(v,999999,sizeof(v));
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
          {
            cin>>x;
            v[i][j]=x;
          }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(v[i][j]>v[i][k]+v[k][j])
                   v[i][j]=v[i][k]+v[k][j];
    cout<<v[1][n];
    return 0;
}
