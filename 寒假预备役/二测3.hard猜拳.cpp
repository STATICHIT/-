#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],b[200005];
int A[200005],B[200005];//把修改后的数存在数组A,B中
bool check(int x,int y)
{
    if(x==1&&y==2)return 1;
    if(x==2&&y==3)return 1;
    if(x==3&&y==1)return 1;
    return 0;
}//判断胜负
bool vis[200005];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=0,cntx=0,cnty=0;

        for(int i=1; i<=n*2; i++)
        {cin>>a[i];A[i]=a[i];vis[i]=0;}

        for(int i=1; i<=n*2; i++)
        {cin>>b[i];B[i]=b[i];}

        for(int i=1; i<=2*n; i++)
        {
            if(check(a[i],b[i]))continue;
            cnt++;
            if(cnt%2==1)
            {
                cntx++;
                A[i]=B[i]-1;
                if(A[i]==0)A[i]=3;
            }//改a
            else
            {
                cnty++;
                B[i]=A[i]+1;
                if(B[i]==4)B[i]=1;
            }//改b
            vis[i]=1;
        }
        //改为a必胜的局面
        for(int i=1; i<=2*n; i++)
        {
            if(vis[i])continue;
            if(cntx<n&&cnty<n)
            {
                A[i]+=1;
                if(A[i]==4)A[i]=1;
                B[i]+=1;
                if(B[i]==4)B[i]=1;
                cntx++,cnty++;
            }
            if(cntx==cnty&&cntx==n)break;
        }
        //消耗多余的操作次数
        if(cnty<n)
        {
            for(int i=1; i<=n*2; i++)
            {
                if(vis[i])
                {
                    for(int j=1; j<=3; j++)
                    {
                        for(int k=1; k<=3; k++)
                            if(j!=a[i]&&k!=b[i]&&check(j,k))A[i]=j,B[i]=k;
                    }
                    break;
                }
            }
        }
        cout<<n*2<<endl;
        for(int i=1; i<=n*2; i++)cout<<A[i]<<" ";
        cout<<endl;
        for(int i=1; i<=n*2; i++)cout<<B[i]<<" ";
        if(t!=0)
        cout<<endl;
    }
    return 0;
}
