/*
//1
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    int a[10005];
    for(int i=0;i<n;i++)
        cin>>a[i];
    while(q--)
    {
        int flag=0,sign1=0,sign2=0;
        int p;
        cin>>p;
        for(int i=0;i<n;i++)
        {
            if(a[i]==p&&sign1==0)
            {
                sign1=1;
                cout<<i<<" ";
            }
            if(a[i]==p&&a[i+1]!=p&&sign2==0)
            {
                cout<<i<<endl;
                sign2=1;
                flag=1;
            }
            if(i==n-1&&sign2==0&&sign1==1)
            {
                cout<<i<<endl;
                flag=1;
            }

        }
    if(flag==0)
    cout<<"-1 -1"<<endl;
    }
    return 0;
}
*/
/*
//2
#include<bits/stdc++.h>
using namespace std;

bool fun(int n)
{
    for(int i=1;i<=sqrt(n);i++)
    {
        if(i*i==n)
            return true;
    }
    return false;
}
int main()
{
    while(1)
    {
        int a,b;
        cin>>a>>b;
        if(a==0&&b==0)break;
        int ans=0;
        for(int i=a;i<=b;i++)
        {
            if(fun(i))
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/


//3
/*
#include<bits/stdc++.h>
using namespace std;
long long s,d;
int main()
{
    while(~scanf("%lld %lld",&s,&d))
    {
        int flag=0;
        long long sday=1,eday=s,stopday=s;

        while(1)
        {
            if(sday<=d&&d<=eday)
            {
                cout<<stopday<<endl;
                flag=1;
            }
            if(flag==1)
                break;
            sday=eday+1;
            stopday++;
            eday=eday+stopday;
        }
    }
    return 0;
}
*/


//4

#include<bits/stdc++.h>
using namespace std;

long long t,n,m;
long long a[1000005];
int main()
{

    for(int i=0;i<=1000005;i++)
        a[i]=i*(i+1);
    cin>>t;
    while(t--)
    {
        long long ans=0;
        cin>>n>>m;
        for(int i=n;i<=m;i++)
            ans+=a[i];
        cout<<ans<<endl;
    }

    return 0;
}


