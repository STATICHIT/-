#include<bits/stdc++.h>
using namespace std;
int n,m,f[100000];
int findd(int x)
{
    if(f[x] == x)
        return x;
    else
        return f[x]=findd(f[x]);
}
void hb(int x,int y)
{
    if(findd(x)!=findd(y))
        f[findd(x)]=findd(y);
}
int main()
{
    cin>>n>>m;
    //≥ı ºªØ
    for(int i=1;i<=n;i++)
        f[i]=i;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
            hb(findd(b),findd(c));
        if(a==2)
        {
            if(findd(b)==findd(c))
                cout<<"Y"<<endl;
            else
                cout<<"N"<<endl;
        }
    }
    return 0;
}
