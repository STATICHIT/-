/*
#include<bits/stdc++.h>
using namespace std;
#define M 500
#define inf 99999999
int n,s,e,a,b,c;
int ans[M][M];
int main()
{
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++)
            ans[i][j]=inf;
    cin>>n>>s>>e;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        ans[a][b]=min(c,ans[a][b]);
    }


    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
    if(ans[s][e]==inf)
        cout<<"-1";
    else
        cout<<ans[s][e];

    return 0;
}
*/

//8
/*
#include<bits/stdc++.h>
using namespace std;

int ans=0,f[1005],d[1005],n,m,a,b,c;

int getf(int i)
{
    if(f[i]==i)
        return i;
    else
        return f[i]=getf(f[i]);
}
int getd(int i)
{
    if(d[i]==i)
        return i;
    else
        return d[i]=getd(d[i]);
}
void hebing(int a,int b)
{
    if(getf(a)!=getf(b))
        f[getf(a)]=getf(b);
}
void hebing2(int a,int b)
{
    if(getd(a)!=getd(b))
        d[getd(a)]=getd(b);
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        f[i]=i;
    while(m--)
    {
        cin>>a>>b>>c;
        if(a==0)
            hebing(b,c);
        else if(a==1)
            hebing2(b,c);
    }

    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
        {
            if(getd(i)==getd(j)&&getd(i)!=i&&getd(j)!=j)
                hebing(i,j);
        }

    for(int i=1; i<=n; i++)
    {
        if(f[i]==i)
            ans++;
    }
    cout<<ans;

    return 0;
}
*/

//9
/*
#include<bits/stdc++.h>
using namespace std;
int n,m;
float f[1000005];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%f",&f[i]);
    sort(f,f+n);
    cin>>m;
    while(m--)
    {
        int nn;
        cin>>nn;
        if(nn<0||nn>=n)
            cout<<"-1"<<endl;
        else
            cout<<f[nn]<<endl;
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

struct students
{
    int id;
    int d,c;
    int sum;
    int grade;
} s[20000000];
int n,minl,hh,n5,n1,n2,n3,n4;
bool cmp1(students a,students b)
{
    return a.grade<b.grade;
}

bool cmp11(students a,students b)
{
    return (a.sum>b.sum)||(a.sum==b.sum&&a.d>b.d)||(a.sum==b.sum&&a.d==b.d&&a.id<b.id);
}

int main()
{
    cin>>n>>minl>>hh;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i].id>>s[i].d>>s[i].c;
        s[i].sum=s[i].d+s[i].c;
        if(s[i].d<minl||s[i].c<minl)
            {s[i].grade=5;n5++;}
        else{
            if(s[i].c>=hh&&s[i].d>=hh)
                {
                    s[i].grade=1;n1++;
                }
            else if(s[i].c<hh&&s[i].d>=hh)
                {
                    s[i].grade=2;n2++;
                }
            else if(s[i].c<hh&&s[i].d<hh&&s[i].d>=s[i].c)
                {
                    s[i].grade=3;n3++;
                }
            else
                {
                    s[i].grade=4;n4++;
                }
        }
    }

    sort(s+1,s+1+n,cmp1);
    sort(s+1,s+1+n1,cmp11);
    sort(s+1+n1,s+1+n1+n2,cmp11);
    sort(s+1+n1+n2,s+1+n1+n2+n3,cmp11);
    sort(s+1+n1+n2+n3,s+1+n1+n2+n3+n4,cmp11);

    int nnn=n-n5;
    cout<<nnn<<endl;
    for(int i=1;i<=nnn;i++)
        cout<<s[i].id<<" "<<s[i].d<<" "<<s[i].c<<endl;
    return 0;
}
*/

//之前没做出的题，嗨害嗨，做出来啦
//4
/*
#include<bits/stdc++.h>
using namespace std;

#define M 10
int n,q;
struct queuee
{
    int data[M];
    int rear,fornt;
} S;

void push(int e)
{
    if((S.rear+1)%M==S.fornt)
        cout<<"FULL ";
    else
    {
        S.data[S.rear]=e;

        S.rear=(S.rear+1)%M;
    }
}

int pop()
{
    if(S.rear==S.fornt)
        cout<<"EMPTY ";
    else
    {
        int e=S.data[S.fornt];
        S.fornt=(S.fornt+1)%M;
        cout<<e<<" ";
    }
}

int main()
{
    S.rear=S.fornt=0;
    cin>>n;
    while(n--)
    {
      cin>>q;
      if(q==0)pop();
      else push(q);

    }
    cout<<endl;
    while(S.rear!=S.fornt)
    {
        pop();
    }

    return 0;
}
*/

//5
/*
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    m=m%n;
    for(int i=m+1; i<=n; i++)
    {
        cout<<a[i];
        if(i==n&&m==0)
        {

        }
        else
        {
            cout<<" ";
        }
    }
    for(int i=1; i<=m; i++)
    {
        cout<<a[i];
        if(i!=m)cout<<" ";
    }
    return 0;
}
*/

//6，还有一种情况处理不了

#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<string> q;
    q.push("nnnnn");
    int n=0;

    string ss[100];
    for(int i=1;i<=100;i++)
    {

        cin>>ss[i];
        if(ss[i]==".")break;
        n++;
    }
    for(int j=1;j<=n;j++)
    {
        string s=(string)ss[j];
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
               q.push("(");
            else if(s[i]=='[')
                q.push("[");
            else if(s[i]=='{')
                q.push("{");
            else if(s[i]=='/'&&s[i+1]=='*')
                q.push("/*");
            else if(s[i]==')'){
                if(q.top()=="(")
                    q.pop();
                else
                {
                    cout<<"NO"<<endl;
                    cout<<"?-)";
                    return 0;
                }
            }
            else if(s[i]==']'){
                if(q.top()=="[")
                    q.pop();
                else
                {
                    cout<<"NO"<<endl;
                    cout<<"?-]";
                    return 0;
                }
            }
            else if(s[i]=='}'){
                 if(q.top()=="{")
                    q.pop();
                else
                {
                    cout<<"NO"<<endl;
                    cout<<"?-}";
                    return 0;
                }
            }
            else if(s[i]=='*'&&s[i+1]=='/'){
                if(q.top()=="/*")
                    q.pop();
                else
                {
                    cout<<"NO"<<endl;
                    cout<<"?-*/";
                    return 0;
                }
            }
        }
    }
    if(q.size()==1)
        cout<<"YES";
    else
    {
     cout<<"NO"<<endl;
     cout<<q.top()<<"-?";
    }
    return 0;
}
