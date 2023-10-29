/*
#include<bits/stdc++.h>
using namespace std;
int a[15][15],book[100000];
map<int,int>k;
map<int,int>g;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            k[a[i][j]]=0;
            g[a[i][j]]=0;
            if(i==j)
            {
                k[a[i][j]]=1;//k=1说明在主对角线上
            }
            if(i+j==n+1)
            {
                g[a[i][j]]=1;//g=1说明在副对角线上
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j||i+j==n+1)
            {
                if((k[a[i][j]]==1&&g[a[i][j]]!=1)||(k[a[i][j]]!=1&&g[a[i][j]]==1))
                {
                    ans+=a[i][j];
                }
                if(k[a[i][j]]==1&&g[a[i][j]]==1&&book[a[i][j]]==0)
                {
                    ans+=a[i][j];
                    book[a[i][j]]=1;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
*/


/*
//理解错题目意思了，气死我了
#include<bits/stdc++.h>
using namespace std;
int a[15][15];

int main()
{
    int n,o=0;
    cin>>n;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            if(i==j||i+j==n+1)
                ans+=a[i][j];
            if(i==j&&i+j==n+1)
                o=a[i][j];

        }
    }
    printf("%d",ans);
    return 0;
}
*/


/*
//第五题
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int isPrime(int n)
{
    if(n == 1||n == 0)
        return 0;
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
int ishuiwen(int n)
{
    int r,k=0;
    int s[100];
    while(n!=0)
    {
        s[k++]=n%10;
        n=n/10;
    }
    for(int j=0;j<k/2;j++)
    {
        if(s[j]!=s[k-j-1])
            return 0;
    }
    return 1;

}
int main()
{
    int m,l;
    cin>>m;
    while(m--)
    {

        cin>>l;
        int k=0;
        for(int n=l+1; n<77777; n++)
        {
            if(isPrime(n)==1&&ishuiwen(n)==1)
            {
                cout<<n;
                break;
            }
        }
        if(m!=0)
        cout<<endl;
    }
    return 0;
}
*/


/*
//7-6 最长上升子序列（时间超限）
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[10000];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int len=0;
    for(int i=1;i<=n;)
    {
        int l=0;
        for(int j=i;j<=n;j++)
        {
            if(a[j-1]>a[j])
                continue;
            l++;
        }
        if(l>len)len=l;
        i=i+l;
    }
    cout<<len;
    return 0;
}
*/

//如何以空白行为结束标志！！！！气死我了TnT
#include<bits/stdc++.h>
using namespace std;
map<string,string>z;
int main()
{

    while(1)
    {
        string s1,s2;
        cin>>s1>>s2;
        z[s2]=s1;
        getchar();
        if(getchar()=='\n')break;
    }

    while(1)
    {
        string s;
        cin>>s;
        if(z.count(s)==1)
            cout<<z[s];
        else
            cout<<"eh"<<endl;
    }
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
int m[10000][10000],book[20];
int main()
{
    int n,a;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>a;
                m[i][j]=a;
            }
        }
        for(int k=1;k<=n;k++)
            for(int i=2;i<=)
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int f[100000];
struct rode
{
    int a,b,c;
} r[100000];
bool cmp(rode x,rode y)
{
    return x.c<y.c;
}
int getf(int i)
{
    if(f[i]==i)
        return i;
    else
        return f[i]=getf(f[i]);
}
void hb(int x,int y)
{
    if(getf(x)!=getf(y))
        f[getf(y)]=getf(x);
}
int main()
{

    int n,m;
    cin>>n>>m;
    int p,q,v;
    //初始化
    for(int i=1; i<=n; i++)
        f[i]=i;

    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&r[i].a,&r[i].b,&r[i].c);
    }

    sort(r,r+m+1,cmp);

    int len=0,sum=0;
    for(int i=1; i<=m; i++)
    {
        if(getf(r[i].a)!=getf(r[i].b))
        {
            hb(r[i].a,r[i].b);
            sum+=r[i].c;

            len++;
        }
        else continue;
        if(len == n-1)
            break;
    }
    if(len ==n-1)
        cout<<sum;
    else
        cout<<"-1";
    return 0;
}
*/
