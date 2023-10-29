/*
//2
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<a/b;

    return 0;
}
*/

/*
//3
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c1,c2;
    cin>>a>>b>>c1>>c2;
    if(c1>=a&&c2>=a)
    {
        cout<<c1<<"-Y "<<c2<<"-Y"<<endl;
        cout<<"huan ying ru guan";
    }
    if(c1>c2&&c1>=b&&c2<a)
    {
        cout<<c1<<"-Y "<<c2<<"-Y"<<endl;
        cout<<"qing 1 zhao gu hao 2";
    }
    if(c1<c2&&c2>=b&&c1<a)
    {
        cout<<c1<<"-Y "<<c2<<"-Y"<<endl;
        cout<<"qing 2 zhao gu hao 1";
    }
    if(c1<a&&c2<a)
    {
        cout<<c1<<"-N "<<c2<<"-N"<<endl;
        cout<<"zhang da zai lai ba";
    }
    if(c1>=a&&c1<b&&c2<a)
    {
        cout<<c1<<"-Y "<<c2<<"-N"<<endl;
        cout<<"1: huan ying ru guan";
    }
    if(c2>=a&&c2<b&&c1<a)
    {
        cout<<c1<<"-N "<<c2<<"-Y"<<endl;
        cout<<"2: huan ying ru guan";
    }

    return 0;
}
*/

/*
//4
#include<bits/stdc++.h>
using namespace std;

long long jiecheng(int n)
{
    if(n==1||n==0)
        return 1;
    else
        return n*jiecheng(n-1);
}
int main()
{
    int a,b;
    cin>>a>>b;
    int c=a+b;
    long long ans=jiecheng(c);
    cout<<ans;

    return 0;
}
*/

/*
//5
#include<bits/stdc++.h>
using namespace std;
int a[7],b[7],c[7],d[7],e[7],f[7],ans[7];
int main()
{
    int aa,bb,cc,dd,ee,ff,n;
    cin>>aa>>bb>>cc>>dd>>ee>>ff;
    cin>>n;
    a[aa]=1;
    b[bb]=1;
    c[cc]=1;
    d[dd]=1;
    e[ee]=1;
    f[ff]=1;
    while(n--)
    {
        for(int i=6; i>=1; i--)
        {

            if(a[i]==0)
            {

                a[i]=1;
                if(n==0)ans[1]=i;
                break;
            }
        }
        for(int i=6; i>=1; i--)
        {
            if(b[i]==0)
            {
                b[i]=1;
                if(n==0)ans[2]=i;
                break;
            }
        }
        for(int i=6; i>=1; i--)
        {
            if(c[i]==0)
            {
                c[i]=1;
                if(n==0)ans[3]=i;
                break;
            }
        }
        for(int i=6; i>=1; i--)
        {
            if(d[i]==0)
            {
                d[i]=1;
                if(n==0)ans[4]=i;
                break;
            }
        }
        for(int i=6; i>=1; i--)
        {
            if(e[i]==0)
            {
                e[i]=1;
                if(n==0)ans[5]=i;
                break;
            }
        }
        for(int i=6; i>=1; i--)
        {
            if(f[i]==0)
            {
                f[i]=1;
                if(n==0)ans[6]=i;
                break;
            }
        }
    }
    for(int i=1; i<=6; i++)
    {
        cout<<ans[i];
        if(i!=6)cout<<" ";
    }
    return 0;
}
*/

/*
//6
#include<bits/stdc++.h>
using namespace std;

int s1[10005],s2[10005];
int l1,l2;
string a,b;
bool check()
{
    if(l1==l2)
    {
        for(int i=0; i<l1; i++)
            if(s1[i]!=s2[i])
                return false;
    }
    else
        return false;
    return true;
}
int main()
{
    cin>>a;
    cin>>b;

    for(int i=1; i<a.length(); i++)
    {
        int n1=a[i]-'0';
        int n2=a[i-1]-'0';

        if(n1%2 == n2%2)
        {
            int n=max(n1,n2);
            s1[l1++]=n;
        }
    }
    for(int i=1; i<b.length(); i++)
    {
        int n1=b[i]-'0';
        int n2=b[i-1]-'0';

        if(n1%2 == n2%2)
        {
            int n=max(n1,n2);
            s2[l2++]=n;
        }
    }

    if(check())
    {
        for(int i=0; i<l1; i++)
            cout<<s1[i];
    }
    else
    {
        for(int i=0; i<l1; i++)
            cout<<s1[i];
        cout<<endl;

        for(int i=0; i<l2; i++)
            cout<<s2[i];
    }
    return 0;
}
*/

/*
//7
#include<bits/stdc++.h>
using namespace std;

int mapph[100005],mappl[100005];
int n,m,q,ans;
void fun1(int b)
{
        mapph[b]=1;
}
void fun2(int b)
{
        mappl[b]=1;
}
int main()
{
    cin>>n>>m>>q;
    while(q--)
    {
        int a, b;
        cin>>a>>b;
        if(a==0)
            fun1(b);//标记一整行
        else if(a==1)
            fun2(b);//标记一整列
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mapph[i]==0&&mappl[j]==0)
                ans++;
    cout<<ans;

    return 0;
}
*/


//10
#include<bits/stdc++.h>
using namespace std;

int n;
struct timee
{
    int h1,m1,s1;
    int h2,m2,s2;
} t[5000];


bool cmp(timee a,timee b)
{
    return (a.h1<b.h1||(a.h1==b.h1&&a.m1<b.m1)||(a.h1==b.h1&&a.m1==b.m1&&a.s1<b.s1));
}
int main()
{
    int v=0;
    cin>>n;
    getchar();
    while(n--)
    {
        string s;
        getline(cin,s);
        t[v].h1=(s[0]-'0')*10+(s[1]-'0');
        t[v].m1=(s[3]-'0')*10+(s[4]-'0');
        t[v].s1=(s[6]-'0')*10+(s[7]-'0');
        t[v].h2=(s[11]-'0')*10+(s[12]-'0');
        t[v].m2=(s[14]-'0')*10+(s[15]-'0');
        t[v].s2=(s[17]-'0')*10+(s[18]-'0');
        v++;
    }
    sort(t,t+v,cmp);
     cout<<"-------"<<endl;
     for(int i=0;i<v;i++)
        cout<<t[i].h1<<" "<<t[i].m1<<" "<<t[i].s1<<
         " "<<t[i].h2<<" "<<t[i].m2<<" "<<t[i].s2<<endl;

    if(v==1)
    {
        if(t[0].h1!=0||t[0].m1!=0||t[0].s1!=0)
        {
            printf("00:00:00 - ");
            printf("%02d:%02d:%02d\n",t[0].h1,t[0].m1,t[0].s1);
        }
        if(t[0].h2!=23||t[0].m2!=59||t[0].s2!=59)
        {
            printf("%02d:%02d:%02d - ",t[0].h2,t[0].m2,t[0].s2);
            printf("23:59:59");

        }
    }
    else
    {
        if(t[0].h1!=0||t[0].m1!=0||t[0].s1!=0)
        {
            printf("00:00:00 - ");
            printf("%02d:%02d:%02d",t[0].h1,t[0].m1,t[0].s1);
        }

        for(int i=1; i<v; i++)
        {
            if(i==v-1)
            {
                if(t[i].h2!=23||t[i].m2!=59||t[i].s2!=59)
                {
                    printf("%02d:%02d:%02d - ",t[i].h2,t[i].m2,t[i].s2);
                    printf("23:59:59");
                }
            }
            else
            {
                if(t[i].h2==t[i+1].h1&&t[i].m2==t[i+1].m1&&t[i].s2==t[i+1].s1)
                {

                }
                else
                {
                    printf("%02d:%02d:%02d - ",t[i].h2,t[i].m2,t[i].s2);
                    printf("%02d:%02d:%02d\n",t[i+1].h1,t[i+1].m1,t[i+1].s1);
                }
            }

        }
    }
    return 0;
}



/*
//8
#include<bits/stdc++.h>
using namespace std;
int n,k,s,ans,bjg;
struct student
{
    int t,p;
    int flag=0;
    int xl=0;
} stu[100005];
bool cmp(student a,student b)
{
    return a.t>b.t ||((a.t==b.t)&&a.p<b.p);
}
int main()
{
    int v=0;
    cin>>n>>k>>s;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        stu[v].t=a;
        stu[v].p=b;
        if(a<170)bjg++;
        if(stu[v].p>=s)stu[v].flag=1;
        v++;
    }
    //cout<<"bjg="<<bjg<<endl;
    sort(stu,stu+v,cmp);
    //for(int i=0;i<v-bjg;i++)
    //    cout<<stu[i].t<<" "<<stu[i].p<<" "<<stu[i].flag<<endl;
    int m=291;
    for(int i=0; i<v-bjg; i++)
    {
        if(stu[i].t<m)
        {
            stu[i].xl=1;
            m=stu[i].t;
            ans++;
        }
        else if((stu[i].t==stu[i-1].t)&&stu[i].flag==1)
        {
            ans++;
            stu[i].xl=1;
        }
    }
    return 0;
}
*/
