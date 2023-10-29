#include<bits/stdc++.h>
using namespace std;
int m[55][55];
int win[55]={0};
int main()
{
    int n,a,b;
    cin>>n;
    int t=n*(n-1)/2-1;
    while(t--)
    {
        cin>>a>>b;
        m[a][b]=1;
        m[b][a]=1;
        win[a]++;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j&&m[i][j]==0)
            {
                if(win[i]>win[j])cout<<i<<" "<<j;
                else cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
