#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,n1,n2;
int a[1010][1010];
int main()
{
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        a[x][y]=-1;
    }
    a[1][1]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==1&&j==1)continue;
            if(a[i][j]!=-1)
            {
                n1=0,n2=0;
                if(a[i][j-1]!=-1)
                    n1=a[i][j-1];
                if(a[i-1][j]!=-1)
                    n2=a[i-1][j];
                a[i][j]=(n1+n2)%100003;
            }
        }
    }
    cout<<a[n][n];
    return 0;
}
