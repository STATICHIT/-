/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    while(1)
    {
        int ans=0,t=0;
    char a;
    int aa[10000];

    while(~scanf("%c",&a))
    {
        if(a==' ')
            continue;
        ver[t++]=a-'0';
        if(a=='\n')break;
    }
        for(int i=0; i<t-1; i++)
        {
            if(aa[i]>m)
            {
                ans++;
                m=aa[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

int main()
{


    return 0;
}
*/

//9
/*
//ÌáÈ¡ÕûÊý
#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    int ans=0,t=0;
    char a;
    int ver[10000];
    while(~scanf("%c",&a))
    {
        if(a=='\n')break;
        if(a==' ')
        {
            if(!q.empty())
            {
                int o=0,v=0;
                while(!q.empty())
                {
                    o+=(q.front())*pow(10,v);
                    //cout<<"o="<<o<<endl;
                    q.pop();
                    v++;
                }
                ver[t]=o;
                //cout<<"ver["<<t<<"]="<<o<<endl;
                t++;
            }
            continue;
        }
        q.push(a-'0');
    }
    if(!q.empty())
    {
        int o=0,v=0;
        while(!q.empty())
        {
            o+=(q.front())*pow(10,v);
            q.pop();
            v++;
        }
        ver[t]=o;
        //cout<<"ver["<<t<<"]="<<o<<endl;
        t++;
    }
    //cout<<"t="<<t<<endl;
    int ans1=0,ans2=0;
    for(int i=0; i<t; i++)
    {
        if(i%2==0)
            ans1+=ver[i];
        else
            ans2+=ver[i];
    }
    // cout<<"ans1="<<ans1<<" ans2="<<ans2<<endl;
    ans=max(ans1,ans2);
    cout<<ans;
    return 0;
}
*/

//13
/*
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],x,l,r;
void fun1()
{
    int m=a[l],x=l;
    for(int i=l;i<=r;i++)
    {
        if(a[i]>m)
        {
            m=a[i];
            x=i;
        }
    }
    cout<<x<<" "<<m<<endl;
}
void fun2()
{
    a[l]=r;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    while(m--)
    {
        cin>>x>>l>>r;
        if(x==1)fun1();
        if(x==0)fun2();
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
#define M 100000
char s[M],t[M];
int l1,l2;
int next_[M];
int nextval[M];

void get_next()
{
   int i=0,k=-1;
   next_[0]=-1;
   while(i<l2)
   {
       if(k==-1||t[k]==t[i])
       {
           ++i;
           ++k;
           nextval[i]=k;

           if(t[i]!=t[k])
               next_[i]=k;
            else
                next_[i]=next_[k];

       }
       else k=next_[k];
   }
}

void KMP()
{
   int i=0,j=0;
   get_next();

   while(i<l1)
   {
       if(j==-1||s[i]==t[j])
       {
           ++i;
           ++j;
       }
       else j=next_[j];

       if(j==l2)//匹配成功
       {
           printf("%d\n",i-l2+1);
           j=next_[j];
       }
   }
}
int  main()
{
    cin>>s>>t;
    l1=strlen(s);
    l2=strlen(t);
    KMP();
    for(int i=0;i<l2;i++)
        cout<<nextval[i]<<" ";
    return 0;
}
