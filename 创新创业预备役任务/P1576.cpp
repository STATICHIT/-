#include<bits/stdc++.h>
using namespace std;
#define N 2010
double a[N][N],d[N],maxn;
int t[N],n,m,x,y,k;

void Dij(int x)
{
    for(int i=1; i<=n; i++)
        d[i]=a[x][i];
    d[x]=1;t[x]=1;
    for(int i=1; i<n; i++)
    {
        maxn=0;
        for(int j=1; j<=n; j++)
            if(!t[j]&&maxn<d[j])
            {
                k=j;
                maxn=d[j];
            }
        t[k]=1;
        if(k==y) break;
        for(int j=1; j<=n; j++)
            if(!t[j]&&d[k]*a[k][j]>d[j])
                d[j]=d[k]*a[k][j];
    }
    printf("%.8lf",100/d[y]);
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int j,k;
        cin>>j>>k>>a[j][k];
        a[j][k]=(100-a[j][k])/100;
        a[k][j]=a[j][k];
    }
    cin>>x>>y;
    Dij(x);
    return 0;
}
