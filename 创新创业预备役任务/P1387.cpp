#include <bits/stdc++.h>
using namespace std;
int n,m,maxAns;
int a[110][110],b[110][110];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                b[i][j]=min(min(b[i-1][j],b[i][j-1]),b[i-1][j-1])+1;
            }
            maxAns=max(maxAns,b[i][j]);
        }
    }
    cout<<maxAns;
    return 0;
}
