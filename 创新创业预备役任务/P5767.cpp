#include<bits/stdc++.h>
using namespace std;
int n,m,bus[1100][1100],a[2100],hd=1,tl=1;
char x;
struct abc
{
    int ans,zhan;
} f[10000010];
bool judge(int x,int y)
{
    if(!bus[x][y])return 0;
    if(a[y])return 0;
    return 1;
}
int main()
{
    cin>>m>>n;
    for(int i=0; i<=m; i++)
    {
        memset(a,0,sizeof(a));
        a[0]=1;
        do
        {
            x=getchar();
            if(isdigit(x))
                a[a[0]]=a[a[0]]*10+x-48;
            else
                a[0]++;
        }
        while(x!='\n'&&x!=EOF);
        a[0]--;
        for(int j=1; j<=a[0]-1; j++)
            for(int k=j+1; k<=a[0]; k++)
                bus[a[j]][a[k]]=1;
    }
    f[1].ans=-1;
    f[1].zhan=1;
    memset(a,0,sizeof(a));
    while(hd<=tl)
    {
        for(int i=1; i<=n; i++)
        {
            if(judge(f[hd].zhan,i))
            {
                tl++;
                f[tl].ans=f[hd].ans+1;
                f[tl].zhan=i;
                a[f[tl].zhan]=1;
                if(f[tl].zhan==n)
                {
                    cout<<f[tl].ans<<endl;
                    return 0;
                }
            }
        }
        hd++;
    }
    cout<<"NO"<<endl;
}
