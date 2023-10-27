
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int index[100];//下标
    int n=0;

} b[500010]; //下标为值
int n,nn,cnt,cn1,cn2,a[500010];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[a[i]].index[b[a[i]].n]=i;
        b[a[i]].n++;
        if(a[i]==i)cn1++;
    }
    cnt=(cn1*(cn1-1))/2;
    for(int i=1; i<=n; i++)
    {
        nn=b[a[i]].n;
        for(int j=0; j<n; j++)
        {
            if(b[a[i]].index[j] ==i)
            {
                cn2++;
            }
            if(nn>1){
                cnt-=nn;
            }
        }
    }
    cnt+=(cn2-cn1)/2;
    cout<<cnt;
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
int n,cnt,a,b,c,d,e,f,g;
string s;
int main()
{
    cin>>n;
    cin>>s;
    a=s.find("xtCpc");
    while(a>=0 && a<=n)
    {
        cnt++;
        //cout<<"a="<<a<<endl;
        s=s.erase(a,5);
        //cout<<s<<endl;
        a=s.find("xtCpc");
        n-=5;
    }

    a=s.find("x");
    b=s.find("tCpc");
    while(a>=0 && a<=n && b>=0 && b<=n && a<b)
    {
        cnt++;
        s=s.erase(a,1);
        s=s.erase(b,4);
        a=s.find("x");
        b=s.find("tCpc");
        n-=5;
    }

    a=s.find("xt");
    b=s.find("Cpc");
    while(a>=0 && a<=n && b>=0 && b<=n && a<b)
    {
        cnt++;
        s=s.erase(a,2);
        s=s.erase(b,3);
        a=s.find("xt");
        b=s.find("Cpc");
        n-=5;
    }

    a=s.find("xtC");
    b=s.find("pc");
    while(a>=0 && a<=n && b>=0 && b<=n && a<b)
    {
        cnt++;
        s=s.erase(a,3);
        s=s.erase(b,2);
        a=s.find("xtC");
        b=s.find("pc");
        n-=5;
    }

    a=s.find("xtCp");
    b=s.find("c");
    while(a>=0 && a<=n && b>=0 && b<=n && a<b)
    {
        cnt++;
        s=s.erase(a,4);
        s=s.erase(b,1);
        a=s.find("xtCp");
        b=s.find("c");
        n-=5;
    }
    a=s.find("x");
    b=s.find("t");
    c=s.find("C");
    d=s.find("p");
    e=s.find("c");
    while(a>=0 && a<=n && b>=0 && b<=n && c>=0 && c<=n && d>=0 && d<=n && e>=0 && e<=n && a<b &&b<c&&c<d&&d<e)
    {
        cnt++;
        s=s.erase(a,1);
        s=s.erase(b,1);
        s=s.erase(c,4);
        s=s.erase(d,4);
        s=s.erase(e,4);
        a=s.find("x");
        b=s.find("t");
        c=s.find("C");
        d=s.find("p");
        e=s.find("c");
        n-=5;
    }
    cout<<cnt;
    return 0;
}
*/
