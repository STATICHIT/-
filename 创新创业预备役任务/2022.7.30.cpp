/*
//1
#include<bits/stdc++.h>
using namespace std;
int h,w,r,c;
bool fun(int a,int b){
    bool f=false;
    if(a>=1 && a<=h && b>=1 && b<=w)f=true;
    return f;
}
int main()
{
    int ans=0;
    cin>>h>>w;
    cin>>r>>c;
    if(fun(r-1,c))ans++;
    if(fun(r+1,c))ans++;
    if(fun(r,c-1))ans++;
    if(fun(r,c+1))ans++;
    cout<<ans;
    return 0;
}
*/

/*
//2
#include<bits/stdc++.h>
using namespace std;
int n,a,b,num;
char c,s;
int main()
{
    cin>>n>>a>>b;
    int flag=1;
    c='.',s='#';
    int t=n;
    while(t--)
    {
        int x=a;
        while(x--)
        {
            int y=n;
            int ff=y%2;
            while(y--)
            {
                if(y%2!=ff){
                    num=b;
                while(num--)cout<<c;
                }else{
                    num=b;
                while(num--)cout<<s;
                }
            }
            cout<<endl;
        }
        if(flag%2==0)
        {
            c='.';
            s='#';
        }
        else
        {
            s='.';
            c='#';
        }
        flag++;
    }
    return 0;
}
*/

/*
//3
#include<bits/stdc++.h>
using namespace std;
int n,q,x,f,i,t;
int a[200100],b[200100],in[200100];

int main()
{
    cin>>n>>q;
    for(i=1; i<=n; i++)
    {
        a[i]=i;
        in[i]=i;
    }

    while(q--)
    {
        cin>>x;
        f=in[x];
        if(f==n){
            in[x]--;
            in[a[f-1]]++;
            swap(a[f],a[f-1]);
        }
        else
        {
            in[x]++;
            in[a[f+1]]--;
            swap(a[f],a[f+1]);
        }
    }
    for(int i=1; i<=n; i++)cout<<a[i]<<" ";
    return 0;
}
*/

#include<iostream>
#include<stdio.h>
using namespace std;
int a,b,num;
float u[10010],sum;
int fun(float me,float req)
{
    int num=0;
    return me/req;
}
int main()
{
    cin>>a>>b;
    for(int i=0; i<a; i++)
    {
        cin>>u[i];
        sum+=u[i];
    }
    float x=sum/(b*1.0);
    cout<<x<<endl;
    //x=x-(((x*1000.00)%10.0)*0.001);
    while(1)
    {
        num=0;
        for(int i=0; i<a; i++)
        {
            num+=fun(u[i],x);
        }
        if(num>=b)break;
        x-=0.01;
    }
    printf("%.2lf",x);
    return 0;
}
